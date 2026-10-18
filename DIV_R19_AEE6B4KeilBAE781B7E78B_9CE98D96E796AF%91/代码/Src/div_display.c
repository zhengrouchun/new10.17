/* R18：OLED显示模块。只保存标量快照，避免结构体旧值/字段错位导致串口与OLED不一致。 */
#include "main.h"
#include "usart.h"
#include "div_config.h"
#include "div_diagnosis.h"
#include "div_app_types.h"
#include "div_power.h"
#include "div_display.h"
#include "oled_display.h"
#include "OLED.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    int state;
    uint32_t cycle_id;
    uint32_t vb_mv;
    uint32_t va_mv;
    uint8_t vb_valid;
    uint8_t va_valid;
    uint8_t error_ok;
} DisplaySnapshot;

static volatile int display_dirty = 1;
static DisplaySnapshot snapshot = {DIV_UNKNOWN, 0, 0, 0, 0, 0};
static int has_measurement = 0;
static int measurement_in_progress = 0;
static uint32_t active_cycle_id = 0;
static int oled_reported_init_state = -1;
#if OLED_DISPLAY_ENABLE
static uint32_t last_status_ms = 0;
#endif

void DivDisplay_RequestRefresh(void)
{
    display_dirty = 1;
}

void DivDisplay_BeginMeasurement(uint32_t cycle_id)
{
    /* 一轮检测开始，旧工况不能再在OLED上伪装成本轮结果。 */
    active_cycle_id = cycle_id;
    measurement_in_progress = 1;
    has_measurement = 0;
    display_dirty = 1;
}

void DivDisplay_SetMeasurement(const DivMeasurement *measurement)
{
    if (measurement == NULL)
    {
        return;
    }

    /* 一次检测只接受对应轮次的记录，避免未来异步路径覆盖新数据。 */
    if (measurement->cycle_id < active_cycle_id)
    {
        return;
    }
    active_cycle_id = measurement->cycle_id;
    snapshot.cycle_id = measurement->cycle_id;
    measurement_in_progress = 0;
    /* 逐字段复制，不再整体 memcpy 一个含指针成员的结构体。 */
    snapshot.state = measurement->state;
    snapshot.vb_mv = measurement->vb_mv;
    snapshot.va_mv = measurement->va_mv;
    snapshot.vb_valid = measurement->vb_valid ? 1U : 0U;
    snapshot.va_valid = measurement->va_valid ? 1U : 0U;
    snapshot.error_ok = (measurement->error != NULL && strcmp(measurement->error, "OK") == 0) ? 1U : 0U;
    has_measurement = 1;
    display_dirty = 1;
}

void DivDisplay_Initialize(void)
{
#if OLED_PROGRESS_TRACE_ENABLE
    Oled_SetProgressCallback(DivDisplay_ReportProgress);
#else
    Oled_SetProgressCallback(NULL);
#endif
    Oled_Init();
    display_dirty = 1; /* 初始化完成后强制显示此前已缓存的首轮测量。 */
}

#if OLED_DISPLAY_ENABLE
void DivDisplay_ServiceStatus(void)
{
    uint32_t now_ms = HAL_GetTick();
    static char line[REPORT_BUFFER_SIZE];
    char measured_state[20] = "WAITING";
    int written;

    if (now_ms - last_status_ms < STATUS_INTERVAL_MILLISECONDS)
    {
        return;
    }
    last_status_ms = now_ms;

    if (DivPower_StopIsActive())
    {
        snprintf(measured_state, sizeof(measured_state), "STOPPED");
    }
    else if (has_measurement && !snapshot.error_ok)
    {
        snprintf(measured_state, sizeof(measured_state), "ERROR");
    }
    else if (has_measurement && snapshot.state >= 0)
    {
        snprintf(measured_state, sizeof(measured_state), "DIV%d", snapshot.state);
    }
    else if (has_measurement)
    {
        snprintf(measured_state, sizeof(measured_state), "UNKNOWN");
    }

    written = snprintf(line, sizeof(line),
        "HB=%lu STATE=%s RUN=%s TEST=%s OLED=%s CYCLE=%lu FW=DIV_SYNC_R19\r\n",
        (unsigned long)now_ms,
        measured_state,
        HAL_GPIO_ReadPin(GPIOB, RUN_POWER_PIN) == GPIO_PIN_SET ? "HIGH" : "LOW",
        HAL_GPIO_ReadPin(GPIOB, TEST_POWER_PIN) == GPIO_PIN_SET ? "HIGH" : "LOW",
        Oled_IsInitialized() ? "DONE" : "PENDING",
        (unsigned long)active_cycle_id);

    if (written <= 0 || written >= (int)sizeof(line))
    {
        Error_Handler();
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)line, (uint16_t)written, UART_TIMEOUT_MILLISECONDS) != HAL_OK)
    {
        Error_Handler();
    }
}

void DivDisplay_ReportProgress(int completed_pages)
{
    char message[64];
    int length = snprintf(message, sizeof(message), "OLED_WRITE_PAGE=%d/8 ACK=UNCHECKED\r\n", completed_pages);
    if (length <= 0 || length >= (int)sizeof(message))
    {
        Error_Handler();
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)message, (uint16_t)length, UART_TIMEOUT_MILLISECONDS) != HAL_OK)
    {
        Error_Handler();
    }
}

void DivDisplay_Service(void)
{
#if OLED_DISPLAY_ENABLE
    char line[OLED_TEXT_COLUMNS + 1];
    char message[96];
    int written;

    if (Oled_IsInitialized() && display_dirty)
    {
        display_dirty = 0;

        if (DivPower_StopIsActive())
        {
            Oled_SetLine(0, "DIV STOPPED");
        }
        else if (measurement_in_progress)
        {
            Oled_SetLine(0, "DIV TESTING");
        }
        else if (!has_measurement)
        {
            Oled_SetLine(0, "DIV READY");
        }
        else if (!snapshot.error_ok)
        {
            Oled_SetLine(0, "DIV MEASURE ERR");
        }
        else if (snapshot.state < 0)
        {
            Oled_SetLine(0, "DIV UNKNOWN");
        }
        else
        {
            snprintf(line, sizeof(line), "DIV%d %s", snapshot.state, DivStateNameAscii(snapshot.state));
            Oled_SetLine(0, line);
        }

        /* STOP状态下旧电压不是当前节点读数，故OLED不再显示为实时值。 */
        if (DivPower_StopIsActive())
        {
            Oled_SetLine(1, "VB:NA STOPPED");
            Oled_SetLine(2, "VA:NA STOPPED");
        }
        else if (measurement_in_progress)
        {
            Oled_SetLine(1, "VB:MEASURING");
            Oled_SetLine(2, "VA:MEASURING");
        }
        else
        {
            if (has_measurement && snapshot.vb_valid)
            {
                snprintf(line, sizeof(line), "VB:%lu mV", (unsigned long)snapshot.vb_mv);
                Oled_SetLine(1, line);
            }
            else
            {
                Oled_SetLine(1, "VB:NA");
            }

            if (has_measurement && snapshot.va_valid)
            {
                snprintf(line, sizeof(line), "VA:%lu mV", (unsigned long)snapshot.va_mv);
                Oled_SetLine(2, line);
            }
            else
            {
                Oled_SetLine(2, "VA:NA");
            }
        }
        /* T/R只表示GPIO命令状态；是否真的1V/3V需观察负载节点。 */
        snprintf(line, sizeof(line), "T:%s R:%s",
            HAL_GPIO_ReadPin(GPIOB, TEST_POWER_PIN) == GPIO_PIN_SET ? "ON" : "OFF",
            HAL_GPIO_ReadPin(GPIOB, RUN_POWER_PIN) == GPIO_PIN_SET ? "ON" : "OFF");
        Oled_SetLine(3, line);
        Oled_Flush();
    }

    if (oled_reported_init_state != Oled_IsInitialized())
    {
        oled_reported_init_state = Oled_IsInitialized();
        written = snprintf(message, sizeof(message),
            "OLED_INIT=%s ADDRESS_CONFIGURED_7BIT=0x%02X ACK=UNCHECKED FW=DIV_SYNC_R19\r\n",
            oled_reported_init_state ? "DONE" : "PENDING",
            (unsigned int)Oled_Address());
        if (written > 0 && written < (int)sizeof(message))
        {
            if (HAL_UART_Transmit(&huart1, (uint8_t *)message, (uint16_t)written, UART_TIMEOUT_MILLISECONDS) != HAL_OK)
            {
                Error_Handler();
            }
        }
    }
#else
    if (display_dirty)
    {
        display_dirty = 0;
    }
#endif
}
#endif
