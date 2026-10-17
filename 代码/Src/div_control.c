/* 解决按键消抖和业务调度堆在 main.c：控制模块实现。 */
#include "main.h"
#include "usart.h"
#include "div_config.h"
#include "div_power.h"
#include "div_control.h"
#include "div_measurement.h"
#include "div_display.h"
#include <stdio.h>
#include "div_diagnosis.h"
typedef struct /* 保存复测按钮的消抖状态，持续按下只触发一次。 */
{
    GPIO_PinState raw_level; /* 最近一次读到的按钮电平。 */
    GPIO_PinState stable_level; /* 已连续稳定足够时间的按钮电平。 */
    uint32_t changed_ms; /* 原始电平最后变化的时刻。 */
} RetestButton; /* 为复测按钮的状态定义类型名。 */

static int detection_pending = 0; /* 启动后安排一次初始测量。 */
static int stop_reported = 0; /* 防止同一次停止重复输出。 */
static RetestButton retest_button = {GPIO_PIN_SET, GPIO_PIN_SET, 0}; /* 保存PA4消抖状态。 */
static volatile int buttons_ready = 0; /* SysTick按键服务初始化标志。 */
static volatile int retest_event_pending = 0; /* 锁存待处理的复测事件。 */
static volatile int retest_armed = 1; /* 复测事件布防状态。 */
static volatile uint32_t button_scan_count = 0; /* 累计按键扫描次数。 */
static volatile uint32_t retest_low_count = 0; /* 累计PA4低电平采样次数。 */
static volatile uint32_t retest_longest_low_ms = 0; /* 最长连续按下时长。 */
static volatile uint32_t retest_press_count = 0; /* 累计通过软件条件并交付主循环的复测次数。 */
static volatile uint32_t retest_raw_irq_count = 0; /* EXTI4原始进入次数：用于区分“没触发中断”和“中断后被软件过滤”。 */
static volatile uint32_t last_retest_irq_ms = 0; /* 上一次接受的RETEST下降沿时刻。 */
static volatile uint8_t retest_irq_seen = 0; /* 0=尚未接受过下降沿，允许第一次立即触发。 */
static volatile uint16_t retest_low_streak = 0; /* 连续低电平样本数。 */
static volatile uint16_t retest_high_streak = 0; /* 连续高电平样本数。 */
static volatile uint8_t retest_seen_released = 0; /* 启动后是否确认过释放。 */
static volatile uint8_t retest_latched_press = 0; /* 防止长按重复触发。 */
#if AUTO_MEASURE_INTERVAL_MILLISECONDS > 0 /* 自动复测启用时才需要记录时间。 */
static uint32_t last_auto_measure_ms = 0; /* 最近一次自动检测完成时刻。 */
#endif /* 结束按需复测模式的条件编译。 */
void DivControl_InitializeButtons(void) /* 初始化RETEST外部中断事件状态。 */
{
    retest_button.raw_level = HAL_GPIO_ReadPin(GPIOA, RETEST_BUTTON_PIN); /* 仅用于诊断显示当前PA4电平。 */
    retest_button.stable_level = retest_button.raw_level; /* 保持诊断字段与当前输入一致。 */
    retest_button.changed_ms = HAL_GetTick(); /* 保存初始化时刻。 */
    retest_event_pending = 0; /* 启动时没有待处理复测事件。 */
    retest_press_count = 0; /* 清零本次启动以来的有效复测次数。 */
    retest_raw_irq_count = 0; /* 清零EXTI4原始中断计数。 */
    last_retest_irq_ms = 0; /* 清零下降沿消抖基准。 */
    retest_irq_seen = 0; /* 第一次有效下降沿不受时间差限制。 */
    retest_armed = 1; /* 诊断字段：当前允许接收复测。 */
    buttons_ready = 1; /* 从此允许EXTI4回调锁存RETEST事件。 */
}

void DivControl_OnRetestInterrupt(void) /* PA4下降沿中断入口：只锁存事件，不做ADC/OLED/串口。 */
{
    uint32_t now_ms;

    ++retest_raw_irq_count; /* 一进入EXTI4回调就计数，不受后续软件条件影响。 */

    if (!buttons_ready) /* 初始化尚未完成时忽略业务事件，但原始IRQ计数仍保留。 */
    {
        return;
    }

    if (HAL_GPIO_ReadPin(GPIOA, STOP_BUTTON_PIN) == GPIO_PIN_RESET) /* STOP物理按住时，停止优先。 */
    {
        return;
    }

    /*
     * 不再在EXTI4回调中再次要求PA4“此刻仍为LOW”。
     * 进入本函数本身已经证明EXTI4检测到过下降沿；Proteus/机械按键若脉冲较短，
     * 再读一次PA4可能已经恢复HIGH，从而把真实下降沿误丢弃。
     */
    now_ms = HAL_GetTick();
    if (retest_irq_seen && (uint32_t)(now_ms - last_retest_irq_ms) < BUTTON_DEBOUNCE_MILLISECONDS) /* 忽略20ms内的重复下降沿。 */
    {
        return;
    }

    last_retest_irq_ms = now_ms; /* 记录这次被接受的下降沿。 */
    retest_irq_seen = 1;
    retest_event_pending = 1; /* 真正的业务仍由主循环DivControl_Service执行。 */
    ++retest_press_count;
    retest_armed = 0; /* 仅用于诊断；事件被主循环取走后重新置1。 */
}

void DivButtonsTick(void) /* 兼容旧接口：RETEST已改由EXTI4触发，不再在SysTick里采样。 */
{
    /* intentionally empty */
}

static int RetestWasPressed(void) /* 主循环原子取走消抖后的按下事件。 */
{
    uint32_t saved_mask = __get_PRIMASK(); /* 保存进入临界区前的中断状态。 */
    int pressed; /* 保存要交付的事件状态。 */
    __disable_irq(); /* 防止读取期间被SysTick修改。 */
    pressed = retest_event_pending; /* 读取已经锁存的复测事件。 */
    retest_event_pending = 0; /* 清除事件，防止主循环重复执行。 */
    if (pressed)
    {
        retest_armed = 1; /* EXTI下降沿本身保证下一次按下前必须先释放；这里只恢复诊断状态。 */
    }
    __set_PRIMASK(saved_mask); /* 恢复原中断状态。 */
    return pressed; /* 返回是否收到复测事件。 */
}
void DivControl_Trace(const char *event) /* 输出当前RETEST/STOP、电源控制相关的调试快照。 */
{
    static char line[BUTTON_TRACE_BUFFER_SIZE];
    uint32_t input_snapshot = GPIOA->IDR;
    int written = snprintf(line, sizeof(line),
        "EV=%s T=%lu PA4=%s PA5=%s PEND=%s STOP=%s IDR=0x%04lX RAW_IRQ=%lu ACCEPT=%lu FW=DIV_REQ_R16\r\n",
        event, (unsigned long)HAL_GetTick(),
        (input_snapshot & RETEST_BUTTON_PIN) ? "HIGH" : "LOW",
        (input_snapshot & STOP_BUTTON_PIN) ? "HIGH" : "LOW",
        retest_event_pending ? "YES" : "NO",
        DivPower_StopIsActive() ? "YES" : "NO",
        (unsigned long)input_snapshot,
        (unsigned long)retest_raw_irq_count,
        (unsigned long)retest_press_count);

    if (written <= 0 || written >= (int)sizeof(line))
    {
        Error_Handler();
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)line, (uint16_t)written, UART_TIMEOUT_MILLISECONDS) != HAL_OK)
    {
        Error_Handler();
    }
}

static void SendStopEvent(void) /* 报告停止事件，与用于填写 CSV 的 STATE 检测记录分开。 */
{
#if DIV_REFERENCE_SERIAL_MODE /* 停止时拉低PB12/PB13并暂停采样，但不能冒称已断开图中的手动SW1。 */
    const char stopped[] = "EVENT=STOP RUN_POWER=NOT_IMPLEMENTED MODE=WAIT_RETEST\r\n"; /* 不将外接电源误报为已断电。 */
#else /* 原受控电源模式保留断电事件格式。 */
    const char stopped[] = "EVENT=STOP RUN_POWER=OFF TEST_POWER=OFF MODE=WAIT_RETEST\r\n"; /* 表明停止后必须重新按复测。 */
#endif /* 结束停止事件格式选择。 */
    if (HAL_UART_Transmit(&huart1, (uint8_t *)stopped, sizeof(stopped) - 1, UART_TIMEOUT_MILLISECONDS) != HAL_OK) /* 在主循环里发送，中断只负责断电。 */
    {
        Error_Handler(); /* 通信失败也维持双路断电并停机。 */
    }
}

void DivControl_Service(void) /* 停止优先；按需模式只在启动和有效复测后安排检测。 */
{
    static GPIO_PinState previous_retest_level = GPIO_PIN_SET; /* 保存主循环上次看到的 PA4 电平，用于只报告按下沿。 */
    static uint32_t previous_trace_ms = 0; /* 保存上次主循环存活报告的时刻。 */
    GPIO_PinState current_retest_level = HAL_GPIO_ReadPin(GPIOA, RETEST_BUTTON_PIN); /* 直接读取 PA4，区分引脚变化与消抖事件。 */
    if (current_retest_level != previous_retest_level) /* 仅在 PA4 读数变化时更新边沿记录。 */
    {
        previous_retest_level = current_retest_level; /* 保存新电平，避免长按时重复报告。 */
        if (current_retest_level == GPIO_PIN_RESET) /* 按下 SW8 应让 PA4 变低。 */
        {
            DivControl_Trace("RETEST_PIN_LOW"); /* 证明主循环读到了复测输入的低电平。 */
        }
    }
    if (HAL_GetTick() - previous_trace_ms >= RETEST_TRACE_INTERVAL_MILLISECONDS) /* 每隔一秒确认主循环和 HAL 时钟都仍在推进。 */
    {
        previous_trace_ms = HAL_GetTick(); /* 从本次报告开始计时，限制串口诊断频率。 */
        DivControl_Trace("MAIN_LOOP_ALIVE"); /* 若启动 STATE 后始终没有此行，应检查停机或 UART 错误。 */
    }
    if (DivPower_StopIsActive()) /* 停止按钮优先于任何复测操作。 */
    {
        DivEmergencyStop(); /* 锁存停止并确保两路关闭。 */
        detection_pending = 0; /* 取消未执行的自动检测。 */
        if (!stop_reported) /* 同一次停止只报告一次。 */
        {
            SendStopEvent(); /* 让终端看到停止后供电关闭。 */
            stop_reported = 1; /* 后续循环不重复发送。 */
        }
    }
    if (RetestWasPressed() && HAL_GPIO_ReadPin(GPIOA, STOP_BUTTON_PIN) == GPIO_PIN_SET) /* 停止按钮松开后，新的复测按下事件才有效。 */
    {
        uint32_t previous_interrupt_mask = __get_PRIMASK(); /* 保存进入临界区前的中断状态。 */
        __disable_irq(); /* 防止解除旧停止标志时丢失同时出现的新停止。 */
        if (HAL_GPIO_ReadPin(GPIOA, STOP_BUTTON_PIN) == GPIO_PIN_SET) /* 在临界区内再次确认停止按钮没有按下。 */
        {
            DivPower_ClearStopRequest(); /* 只通过用户明确的复测动作解除停止锁存。 */
            detection_pending = 1; /* 安排新一轮采样和判别，供电动作由模式选择。 */
            stop_reported = 0; /* 允许下一次独立停止事件再次报告。 */
        }
        __set_PRIMASK(previous_interrupt_mask); /* 新挂起的停止中断随后仍可取消这一轮。 */
        if (detection_pending && !DivPower_StopIsActive()) /* 仅在复测请求仍有效时报告已被接受。 */
        {
            DivControl_Trace("RETEST_ACCEPTED"); /* 区分 PA4 电平变化和真正安排新检测。 */
        }
    }
#if AUTO_MEASURE_INTERVAL_MILLISECONDS > 0 /* 只在明确启用周期检测时编译定时判断。 */
    if (!DivPower_StopIsActive() && HAL_GetTick() - last_auto_measure_ms >= AUTO_MEASURE_INTERVAL_MILLISECONDS) /* 到达自动周期时安排新一轮。 */
    {
        detection_pending = 1; /* 定时到期后重新读ADC，不重复打印上轮缓存。 */
    }
#endif /* 按需复测时不产生周期检测，也不进行无意义的零值比较。 */
    if (detection_pending && !DivPower_StopIsActive()) /* 只有有检测请求且未停止才进行 ADC 检测。 */
    {
        detection_pending = 0; /* 执行前先清除请求，防止同一圈重复测量。 */
        DivControl_Trace("DETECTION_START"); /* 证明已经进入本轮供电与采样流程，包括启动测量。 */
        DivMeasurement_Run(); /* 按所选模式采样并发出一条完整报告。 */
#if AUTO_MEASURE_INTERVAL_MILLISECONDS > 0 /* 周期检测模式需要记录发送完成时刻。 */
        last_auto_measure_ms = HAL_GetTick(); /* 从发送完成时刻开始计算下一次检测间隔。 */
#endif /* 按需复测模式仅等待下一次按钮事件。 */
    }
}

