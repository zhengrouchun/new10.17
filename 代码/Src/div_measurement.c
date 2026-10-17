/* R18：DIV测量。PA0固定读VB、PA1固定读VA；不再依赖扫描序列的隐式顺序。 */
#include "main.h"
#include "adc.h"
#include "usart.h"
#include "div_config.h"
#include "div_app_types.h"
#include "div_diagnosis.h"
#include "div_power.h"
#include "div_display.h"
#include "div_measurement.h"
#include <stdio.h>
#include <string.h>

/*
 * R18：不再依赖 ADC 扫描 + 间断模式的“第几次转换对应哪个 Rank”。
 * 每次采样前都显式把 Rank1 配成指定物理通道：
 *   PA0 / ADC_CHANNEL_0 = DIV_VB
 *   PA1 / ADC_CHANNEL_1 = DIV_VA
 * 这样每轮 RETEST 都从确定的通道开始，避免不同轮次出现顺序/状态残留。
 */
static const char *ReadAdcChannel(uint32_t channel, uint32_t *raw, uint32_t *conversions)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    if (raw == NULL || conversions == NULL)
    {
        return "ADC_ARGUMENT_FAILED";
    }
    if (DivPower_StopIsActive())
    {
        return "STOP_REQUESTED";
    }

    /* 确保上一轮/上一通道已经停止，再改 Rank1 的通道。 */
    (void)HAL_ADC_Stop(&hadc1);

    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    {
        return channel == ADC_CHANNEL_0 ? "ADC_CONFIG_VB_FAILED" : "ADC_CONFIG_VA_FAILED";
    }

    __HAL_ADC_CLEAR_FLAG(&hadc1, ADC_FLAG_EOC);

    if (HAL_ADC_Start(&hadc1) != HAL_OK)
    {
        return channel == ADC_CHANNEL_0 ? "ADC_START_VB_FAILED" : "ADC_START_VA_FAILED";
    }
    if (HAL_ADC_PollForConversion(&hadc1, ADC_TIMEOUT_MILLISECONDS) != HAL_OK)
    {
        (void)HAL_ADC_Stop(&hadc1);
        return channel == ADC_CHANNEL_0 ? "ADC_POLL_VB_FAILED" : "ADC_POLL_VA_FAILED";
    }

    *raw = HAL_ADC_GetValue(&hadc1);
    ++(*conversions);

    if (HAL_ADC_Stop(&hadc1) != HAL_OK)
    {
        return "ADC_STOP_FAILED";
    }
    if (*raw > DIV_ADC_MAX_CODE)
    {
        return "ADC_RANGE_FAILED";
    }
    return "OK";
}

static const char *ReadAdcPair(uint32_t *vb_raw, uint32_t *va_raw, uint32_t *conversions)
{
    const char *error;

    if (vb_raw == NULL || va_raw == NULL || conversions == NULL)
    {
        return "ADC_ARGUMENT_FAILED";
    }

    /* 物理定义固定：PA0=VB，PA1=VA。 */
    error = ReadAdcChannel(ADC_CHANNEL_0, vb_raw, conversions);
    if (strcmp(error, "OK") != 0)
    {
        return error;
    }
    if (DivPower_StopIsActive())
    {
        return "STOP_REQUESTED";
    }

    error = ReadAdcChannel(ADC_CHANNEL_1, va_raw, conversions);
    if (strcmp(error, "OK") != 0)
    {
        return error;
    }

    return "OK";
}

static void SendTestSample(const DivMeasurement *result)
{
    char line[REPORT_BUFFER_SIZE];
    char state_text[16] = "UNKNOWN";
    const char *case_name = "UNKNOWN";
    int written;

    if (result->state >= 0)
    {
        snprintf(state_text, sizeof(state_text), "DIV%d", result->state);
        case_name = DivStateNameAscii(result->state);
    }

    written = snprintf(line, sizeof(line),
        "TEST_SAMPLE STATE=%s CASE=%s VB_RAW=%lu VB_MV=%lu VA_RAW=%lu VA_MV=%lu "
        "TEST_GPIO=%s RUN_GPIO=%s ADC_MODE=EXPLICIT_CH0_VB_CH1_VA HOLD_MS=%lu ERROR=%s FW=DIV_REQ_R18\r\n",
        state_text,
        case_name,
        (unsigned long)result->vb_raw,
        (unsigned long)result->vb_mv,
        (unsigned long)result->va_raw,
        (unsigned long)result->va_mv,
        HAL_GPIO_ReadPin(GPIOB, TEST_POWER_PIN) == GPIO_PIN_SET ? "HIGH" : "LOW",
        HAL_GPIO_ReadPin(GPIOB, RUN_POWER_PIN) == GPIO_PIN_SET ? "HIGH" : "LOW",
        (unsigned long)TEST_SAMPLE_HOLD_MILLISECONDS,
        result->error);

    if (written <= 0 || written >= (int)sizeof(line))
    {
        Error_Handler();
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)line, (uint16_t)written, UART_TIMEOUT_MILLISECONDS) != HAL_OK)
    {
        Error_Handler();
    }
}

static void SendReport(const DivMeasurement *result)
{
    char line[REPORT_BUFFER_SIZE];
    char state_text[16] = "UNKNOWN";
    char vb_raw_text[12] = "NA";
    char va_raw_text[12] = "NA";
    char vb_mv_text[12] = "NA";
    char va_mv_text[12] = "NA";
    const char *kind = "UNKNOWN";
    const char *case_name = "UNKNOWN";
    int written;

    if (result->state >= 0)
    {
        snprintf(state_text, sizeof(state_text), "DIV%d", result->state);
        kind = result->state == DIV_NORMAL_CASE ? "NORMAL" : "FAULT";
        case_name = DivStateNameAscii(result->state);
    }
    if (result->vb_valid)
    {
        snprintf(vb_raw_text, sizeof(vb_raw_text), "%lu", (unsigned long)result->vb_raw);
        snprintf(vb_mv_text, sizeof(vb_mv_text), "%lu", (unsigned long)result->vb_mv);
    }
    if (result->va_valid)
    {
        snprintf(va_raw_text, sizeof(va_raw_text), "%lu", (unsigned long)result->va_raw);
        snprintf(va_mv_text, sizeof(va_mv_text), "%lu", (unsigned long)result->va_mv);
    }

    written = snprintf(line, sizeof(line),
        "STATE=%s KIND=%s CASE=%s VB_RAW=%s VB_MV=%s VA_RAW=%s VA_MV=%s "
        "FEATURE_READS=%lu ADC_CONVERSIONS=%lu ELAPSED_MS=%lu "
        "RUN_POWER=%s TEST_POWER=%s POWER_SOURCE=GPIO_LEVEL ERROR=%s FW=DIV_REQ_R18\r\n",
        state_text, kind, case_name,
        vb_raw_text, vb_mv_text, va_raw_text, va_mv_text,
        (unsigned long)result->feature_reads,
        (unsigned long)result->adc_conversions,
        (unsigned long)result->elapsed_ms,
        HAL_GPIO_ReadPin(GPIOB, RUN_POWER_PIN) == GPIO_PIN_SET ? "ON" : "OFF",
        HAL_GPIO_ReadPin(GPIOB, TEST_POWER_PIN) == GPIO_PIN_SET ? "ON" : "OFF",
        result->error);

    if (written <= 0 || written >= (int)sizeof(line))
    {
        Error_Handler();
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)line, (uint16_t)written, UART_TIMEOUT_MILLISECONDS) != HAL_OK)
    {
        Error_Handler();
    }
}

void DivMeasurement_Run(void)
{
    DivMeasurement result = {0};
    uint32_t started_ms = HAL_GetTick();

    result.state = DIV_UNKNOWN;
    result.error = "STOP_REQUESTED";

    /* 先断3V并打开1V测试。 */
    if (!DivPower_Select(TEST_POWER_PIN) ||
        !DivPower_WaitWithoutStop(TEST_POWER_OBSERVATION_MILLISECONDS))
    {
        DivPower_AllOff();
        result.elapsed_ms = HAL_GetTick() - started_ms;
        DivDisplay_SetMeasurement(&result);
        SendReport(&result);
        return;
    }

    /* 当前正处于1V测试阶段，读取PA0(VB)和PA1(VA)。 */
    result.error = ReadAdcPair(&result.vb_raw, &result.va_raw, &result.adc_conversions);
    if (strcmp(result.error, "OK") == 0)
    {
        result.vb_valid = 1;
        result.va_valid = 1;
        result.vb_mv = DivCodeToMillivolts(result.vb_raw);
        result.va_mv = DivCodeToMillivolts(result.va_raw);
        result.feature_reads = 2;
        result.state = DivClassify((int32_t)result.vb_mv, (int32_t)result.va_mv);

        /* 这条日志发生在TEST仍为HIGH时，用来和Proteus电压表同一阶段比对。 */
        SendTestSample(&result);

        /* R18：把本轮1V检测快照立刻交给OLED，并在电源仍为TEST=ON、RUN=OFF时刷新。
         * 这样在接下来的5秒观察窗口里，Proteus电压表、串口TEST_SAMPLE、OLED三者可直接比较。
         * 初次上电检测发生在OLED初始化之前时，这次Service会安全跳过；之后每次RETEST都可观察。 */
        DivDisplay_SetMeasurement(&result);
        DivDisplay_Service();

        if (!DivPower_WaitWithoutStop(TEST_SAMPLE_HOLD_MILLISECONDS))
        {
            result.state = DIV_UNKNOWN;
            result.error = "STOP_REQUESTED";
        }
    }

    if (DivPower_StopIsActive())
    {
        result.state = DIV_UNKNOWN;
        result.error = "STOP_REQUESTED";
        DivPower_AllOff();
    }
    else if (strcmp(result.error, "OK") == 0 &&
             result.vb_valid && result.va_valid &&
             result.state == DIV_NORMAL_CASE)
    {
        /* 文件要求：DIV0检测结束后 1V关闭、3V开启。 */
        if (!DivPower_Select(RUN_POWER_PIN) || DivPower_StopIsActive())
        {
            result.state = DIV_UNKNOWN;
            result.error = "STOP_REQUESTED";
            DivPower_AllOff();
        }
    }
    else
    {
        /* 文件要求：R1断路/R1=20k等异常检测结束后 1V关闭、3V关闭。 */
        DivPower_AllOff();
    }

    result.elapsed_ms = HAL_GetTick() - started_ms;

    /* 先把本轮最终结果和最终电源状态交给OLED，再发同一轮串口。 */
    DivDisplay_SetMeasurement(&result);
    SendReport(&result);
}
