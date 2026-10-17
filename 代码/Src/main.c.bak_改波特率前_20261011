/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h> /* 将真实读数格式化为串口文本。 */
#include "div_diagnosis.h" /* 引入参数 2.0 的电压换算和九工况判别。 */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct /* 保存一次检测结果，初始化时所有有效标志为假。 */
{
    uint32_t vb_raw; /* VB 的真实 ADC 原码，仅在 vb_valid 为真时可用。 */
    uint32_t va_raw; /* VA 的真实 ADC 原码，仅在 va_valid 为真时可用。 */
    uint32_t vb_mv; /* VB 四舍五入后的 mV 值。 */
    uint32_t va_mv; /* VA 四舍五入后的 mV 值。 */
    uint32_t adc_conversions; /* 每次 Poll 成功并 GetValue 后递增。 */
    uint32_t feature_reads; /* 实际获得有效读数的不同节点数。 */
    uint32_t elapsed_ms; /* 从本次开始采样到判别结束的 HAL 毫秒节拍差。 */
    int vb_valid; /* VB 已有效采样时为真，未读时输出 NA。 */
    int va_valid; /* VA 已有效采样时为真，未读时输出 NA。 */
    int state; /* 唯一工况编号，或 DIV_UNKNOWN。 */
    const char *error; /* OK 或明确的 ADC 错误阶段。 */
} DivMeasurement; /* 为本次采集记录定义类型名。 */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ADC_TIMEOUT_MILLISECONDS 20 /* 最多等待一次 ADC 转换 20 ms。 */
#define UART_TIMEOUT_MILLISECONDS 100 /* 一条报告最多发送 100 ms。 */
#define REPORT_PERIOD_MILLISECONDS 500 /* 报告之间等待 500 ms，不计入检测耗时。 */
#define REPORT_BUFFER_SIZE 384 /* 容纳整条带状态和错误信息的报告。 */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
static const char *ReadAdcChannel(uint32_t channel, uint32_t *raw, uint32_t *conversions); /* 声明真实采样函数。 */
static void SendReport(const DivMeasurement *result); /* 声明报告函数。 */
static void RunDivDetection(void); /* 声明一次完整检测。 */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
static const char *ReadAdcChannel(uint32_t channel, uint32_t *raw, uint32_t *conversions) /* 失败返回阶段名，成功返回 OK。 */
{
    ADC_ChannelConfTypeDef selected = {0}; /* 全部配置字段清零，随后明确设置所需字段。 */
    selected.Channel = channel; /* 选择 PA0 的通道 0 或 PA1 的通道 1。 */
    selected.Rank = ADC_REGULAR_RANK_1; /* 单次转换只使用序列第一个位置。 */
    selected.SamplingTime = ADC_SAMPLETIME_239CYCLES_5; /* 给分压节点 239.5 个 ADC 周期采样时间。 */
    if (HAL_ADC_ConfigChannel(&hadc1, &selected) != HAL_OK) /* 在 ADC 停止期间切换通道。 */
    {
        return "ADC_CONFIG_FAILED"; /* 配置失败，没有启动转换。 */
    }
    if (HAL_ADC_Start(&hadc1) != HAL_OK) /* 软件触发一次真实转换。 */
    {
        if (HAL_ADC_Stop(&hadc1) != HAL_OK) /* 启动失败也尝试让 ADC 回到停止状态。 */
        {
            return "ADC_START_AND_STOP_FAILED"; /* 同时报告启动与清理失败。 */
        }
        return "ADC_START_FAILED"; /* 不把启动失败记作完成转换。 */
    }
    if (HAL_ADC_PollForConversion(&hadc1, ADC_TIMEOUT_MILLISECONDS) != HAL_OK) /* 等待真实完成标志，最多 20 ms。 */
    {
        if (HAL_ADC_Stop(&hadc1) != HAL_OK) /* 超时或错误后也关闭 ADC。 */
        {
            return "ADC_POLL_AND_STOP_FAILED"; /* 明确报告等待和停止均失败。 */
        }
        return "ADC_POLL_FAILED"; /* 未确认完成的转换不计入成功转换数。 */
    }
    *raw = HAL_ADC_GetValue(&hadc1); /* 唯一的原码来源：读取 ADC 数据寄存器。 */
    ++(*conversions); /* 确认完成并取值后记录一次，停止失败也不会抹去已经发生的转换。 */
    if (HAL_ADC_Stop(&hadc1) != HAL_OK) /* 每次取值后停止，再允许下一次切换通道。 */
    {
        return "ADC_STOP_FAILED"; /* ADC 状态不可靠，本轮不接受为正常测量。 */
    }
    if (*raw > DIV_ADC_MAX_CODE) /* 检查返回值与 12 位右对齐配置一致。 */
    {
        return "ADC_RANGE_FAILED"; /* 不对越界原码套用电压换算。 */
    }
    return "OK"; /* 本次配置、启动、等待、取值和停止全部成功。 */
}

static void SendReport(const DivMeasurement *result) /* 只发送已经保存的检测结果，不再进行 ADC 转换。 */
{
    char line[REPORT_BUFFER_SIZE]; /* 保存完整的一行串口报告。 */
    char state_text[16] = "UNKNOWN"; /* 未确认唯一匹配前使用未知状态。 */
    char vb_raw_text[12] = "NA"; /* 未取得有效 VB 原码时不发送伪造的零。 */
    char va_raw_text[12] = "NA"; /* 未取得有效 VA 原码时显示未读。 */
    char vb_mv_text[12] = "NA"; /* VB 未读时没有可用的毫伏值。 */
    char va_mv_text[12] = "NA"; /* VA 未读时没有可用的毫伏值。 */
    const char *kind = "UNKNOWN"; /* 将正常、已知故障、未知分开显示。 */
    int written; /* 保存 snprintf 实际需要的字符数。 */
    if (result->state >= 0) /* 只有唯一匹配才输出 DIV 编号。 */
    {
        snprintf(state_text, sizeof(state_text), "DIV%d", result->state); /* 将内部编号转换为 DIV0 至 DIV8。 */
        kind = result->state == 0 ? "NORMAL" : "FAULT"; /* DIV0 为正常，其他已知工况为故障。 */
    }
    if (result->vb_valid) /* 只有有效 VB 采样才能进入报告。 */
    {
        snprintf(vb_raw_text, sizeof(vb_raw_text), "%lu", (unsigned long)result->vb_raw); /* 格式化真实 VB 原码。 */
        snprintf(vb_mv_text, sizeof(vb_mv_text), "%lu", (unsigned long)result->vb_mv); /* 格式化 VB 换算值。 */
    }
    if (result->va_valid) /* 独立判断 VA，避免沿用上一轮数据。 */
    {
        snprintf(va_raw_text, sizeof(va_raw_text), "%lu", (unsigned long)result->va_raw); /* 格式化真实 VA 原码。 */
        snprintf(va_mv_text, sizeof(va_mv_text), "%lu", (unsigned long)result->va_mv); /* 格式化 VA 换算值。 */
    }
    written = snprintf(line, sizeof(line), /* 按固定字段名组成便于保存与核对的串口记录。 */
        "STATE=%s KIND=%s VB_RAW=%s VB_MV=%s VA_RAW=%s VA_MV=%s " /* 先输出状态和两点原码、电压。 */
        "FEATURE_READS=%lu ADC_CONVERSIONS=%lu ELAPSED_MS=%lu " /* 分别输出节点数、转换数和检测耗时。 */
        "RUN_POWER=NOT_IMPLEMENTED ERROR=%s\r\n", /* 本阶段没有受控运行电源，明确报告未实现。 */
        state_text, kind, vb_raw_text, vb_mv_text, va_raw_text, va_mv_text, /* 对应前六个文本字段。 */
        (unsigned long)result->feature_reads, (unsigned long)result->adc_conversions, /* 使用本轮实际累加的计数。 */
        (unsigned long)result->elapsed_ms, result->error); /* 输出计时结果和错误阶段。 */
    if (written < 0 || written >= (int)sizeof(line)) /* 检查格式化失败和缓冲区不足。 */
    {
        Error_Handler(); /* 不发送截断或损坏的记录。 */
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)line, (uint16_t)written, UART_TIMEOUT_MILLISECONDS) != HAL_OK) /* 由 PA9 发往终端 RXD。 */
    {
        Error_Handler(); /* 串口发送失败时停止，避免伪称已交付数据。 */
    }
}

static void RunDivDetection(void) /* 完整执行一次固定两点检测，不实现 RC 或按需补测优化。 */
{
    DivMeasurement result = {0}; /* 清空这一轮记录；两个有效标志均为假。 */
    uint32_t started_ms = HAL_GetTick(); /* 在通道配置之前开始计时。 */
    result.state = DIV_UNKNOWN; /* 在读完两点并成功判别之前维持未知。 */
    result.error = ReadAdcChannel(ADC_CHANNEL_0, &result.vb_raw, &result.adc_conversions); /* 从 PA0 读取 VB。 */
    if (result.error[0] == 'O' && result.error[1] == 'K') /* 只在第一次采样完整成功后使用该值。 */
    {
        result.vb_valid = 1; /* 标记本轮 VB 已读取。 */
        result.vb_mv = DivCodeToMillivolts(result.vb_raw); /* 由原码换算 VB 的毫伏值。 */
        ++result.feature_reads; /* VB 是本轮第一个有效节点。 */
        result.error = ReadAdcChannel(ADC_CHANNEL_1, &result.va_raw, &result.adc_conversions); /* 切到 PA1 读取 VA。 */
        if (result.error[0] == 'O' && result.error[1] == 'K') /* VA 采样成功才允许两点判别。 */
        {
            result.va_valid = 1; /* 标记本轮 VA 已读取。 */
            result.va_mv = DivCodeToMillivolts(result.va_raw); /* 由原码换算 VA 的毫伏值。 */
            ++result.feature_reads; /* VA 是本轮第二个有效节点。 */
            result.state = DivClassify((int32_t)result.vb_mv, (int32_t)result.va_mv); /* 用电压闭区间确定唯一工况。 */
        }
    }
    result.elapsed_ms = HAL_GetTick() - started_ms; /* 在串口发送和循环延时之前停止计时，允许真实结果为 0 ms。 */
    SendReport(&result); /* 发送本轮报告；这一步不包含在 ELAPSED_MS 中。 */
    if (!(result.error[0] == 'O' && result.error[1] == 'K')) /* ADC 错误已有报告时保留现场。 */
    {
        Error_Handler(); /* 停止后由用户复位重试，不自动制造更多不可靠结果。 */
    }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
const char startup[] = "BOOT=DIV_20261011 MODE=TWO_NODES VREF_MV=3300 ADC_BITS=12 BAUD=115200 RUN_POWER=NOT_IMPLEMENTED\r\n"; /* 自报固件版本和换算假设。 */
  const char calibration_error[] = "STATE=UNKNOWN ERROR=ADC_CALIBRATION_FAILED RUN_POWER=NOT_IMPLEMENTED\r\n"; /* 校准失败时明确说明原因。 */
  if (HAL_UART_Transmit(&huart1, (uint8_t *)startup, sizeof(startup) - 1, UART_TIMEOUT_MILLISECONDS) != HAL_OK) /* 上电先验证终端链路。 */
  {
    Error_Handler(); /* 启动信息发送失败时停止。 */
  }
  if (HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK) /* 所有外设初始化之后只校准一次。 */
  {
    HAL_UART_Transmit(&huart1, (uint8_t *)calibration_error, sizeof(calibration_error) - 1, UART_TIMEOUT_MILLISECONDS); /* 尽力报告校准故障。 */
    Error_Handler(); /* 校准失败不得继续采样判别。 */
  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) /* 持续执行循环；错误处理中的空循环用于停机。 */
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
RunDivDetection(); /* 两点采样、判别、计数、计时并发送本轮结果。 */
    HAL_Delay(REPORT_PERIOD_MILLISECONDS); /* 给终端留出观察时间，不计入本轮检测耗时。 */
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq(); /* 错误时关闭中断，保留失败现场供检查。 */
  while (1) /* 持续执行循环；错误处理中的空循环用于停机。 */
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
