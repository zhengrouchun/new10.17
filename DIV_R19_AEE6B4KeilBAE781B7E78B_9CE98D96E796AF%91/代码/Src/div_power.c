/* 解决停止处理和电源互锁堆在主程序：电源模块实现。 */
#include "main.h"
#include "div_config.h"
#include "div_power.h"
#include "div_display.h"
#include "div_control.h" /* RETEST EXTI4只把事件交给控制模块。 */
static volatile int power_gpio_ready = 0; /* GPIO未就绪前禁止写输出。 */
static volatile int stop_requested = 0; /* 锁存停止中断和紧急停机状态。 */
void DivPower_Initialize(void) /* GPIO初始化后进入双路断电状态。 */
{
    power_gpio_ready = 1; /* 允许本模块访问电源控制脚。 */
    DivPower_AllOff(); /* 启动时同时关闭两路电源。 */
}
void DivPower_AllOff(void) /* 同一次 GPIO 写操作关闭两个开关，不在中断里延时。 */
{
    if (power_gpio_ready) /* 初始化未完成时由外部下拉电阻维持断电。 */
    {
        HAL_GPIO_WritePin(GPIOB, TEST_POWER_PIN | RUN_POWER_PIN, GPIO_PIN_RESET); /* 将 PB12 和 PB13 一起拉低。 */
    }
}

int DivPower_StopIsActive(void) /* 同时检查锁存事件和按钮实时电平，包含上电时已按住的情况。 */
{
    return stop_requested || HAL_GPIO_ReadPin(GPIOA, STOP_BUTTON_PIN) == GPIO_PIN_RESET; /* 任一条件成立就禁止上电。 */
}

void DivEmergencyStop(void) /* 停止中断和故障处理共用紧急断电路径。 */
{
    stop_requested = 1; /* 锁存停止状态，松开STOP不会自动恢复。 */
    DivPower_AllOff(); /* 立即关闭两路电源。 */
    DivDisplay_RequestRefresh(); /* 请求主循环更新STOPPED画面。 */
}

void HAL_GPIO_EXTI_Callback(uint16_t pin) /* PA5负责紧急停止，PA4负责请求复测。 */
{
    if (pin == STOP_BUTTON_PIN) /* STOP必须最高优先级，按下立即断电。 */
    {
        DivEmergencyStop();
    }
    else if (pin == RETEST_BUTTON_PIN) /* RETEST只锁存事件，绝不在中断里做ADC/OLED/串口。 */
    {
        DivControl_OnRetestInterrupt();
    }
}

int DivPower_WaitWithoutStop(uint32_t milliseconds) /* 在稳定等待和互锁等待期间也允许停止取消检测。 */
{
    uint32_t started_ms = HAL_GetTick(); /* 保存等待开始时刻。 */
    while (HAL_GetTick() - started_ms < milliseconds) /* 无符号差值允许毫秒计数器回绕。 */
    {
        if (DivPower_StopIsActive()) /* 检查等待期间是否出现停止。 */
        {
            DivEmergencyStop(); /* 即使按钮没有产生新下降沿，也保证立即断电。 */
            return 0; /* 告诉调用方本次等待被停止取消。 */
        }
        HAL_Delay(CONTROL_POLL_MILLISECONDS); /* 等待一个毫秒，保持 SysTick 正常更新。 */
    }
    if (DivPower_StopIsActive()) /* 在等待结束的边界再检查一次停止。 */
    {
        DivEmergencyStop(); /* 保证边界出现的停止也关闭两路。 */
        return 0; /* 禁止继续合闸。 */
    }
    return 1; /* 等待完成且没有停止请求。 */
}

int DivPower_Select(uint16_t selected_pin) /* 只允许在两个开关均关闭并等待之后开启其中一路。 */
{
    uint32_t previous_interrupt_mask; /* 保存调用前的中断屏蔽状态，不能擅自开启原本关闭的中断。 */
    int enabled = 0; /* 默认没有合闸，只有通过所有检查才置为成功。 */
    DivPower_AllOff(); /* 每次切换首先断开旧电源和另一条电源。 */
    if (selected_pin != TEST_POWER_PIN && selected_pin != RUN_POWER_PIN) /* 拒绝同时开启两路或传入其他引脚。 */
    {
        return 0; /* 保持双路关闭并报告未合闸。 */
    }
    if (!DivPower_WaitWithoutStop(POWER_BREAK_MILLISECONDS)) /* 至少保持两路断开 5 ms，并接受停止取消。 */
    {
        return 0; /* 被停止后不允许合闸。 */
    }
    previous_interrupt_mask = __get_PRIMASK(); /* 保存当前中断状态。 */
    __disable_irq(); /* 将停止检查和单路合闸作为不可被打断的一组操作。 */
    if (!DivPower_StopIsActive()) /* 若停止已发生或按钮仍按住，就维持断电。 */
    {
        HAL_GPIO_WritePin(GPIOB, selected_pin, GPIO_PIN_SET); /* 只拉高选中的一根控制线。 */
        enabled = 1; /* 记录已经发出单路开启命令。 */
    }
    __set_PRIMASK(previous_interrupt_mask); /* 恢复原中断状态，已挂起的停止中断将立即关闭电源。 */
    return enabled; /* 后续步骤仍会检查停止标志，避免接受已被取消的检测。 */
}

void DivPower_ClearStopRequest(void) /* 仅在有效复测事件中解除停止锁存。 */
{
    stop_requested = 0; /* 允许按用户请求重新执行检测。 */
}
