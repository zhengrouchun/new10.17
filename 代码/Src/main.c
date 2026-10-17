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
#include "adc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "div_config.h" /* 读取应用参数。 */
#include "div_power.h" /* 初始化和紧急断电接口。 */
#include "div_control.h" /* 按键和检测调度接口。 */
#include "div_display.h" /* OLED初始化和刷新接口。 */
#include "div_measurement.h" /* 启动后先执行首轮检测，再初始化OLED。 */
#include "oled_display.h" /* 提供OLED_DISPLAY_ENABLE编译开关。 */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART1_UART_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
DivPower_Initialize(); /* GPIO初始化后确保两路电源均关闭。 */
HAL_Delay(TERMINAL_STARTUP_WAIT_MILLISECONDS); /* 等待虚拟终端进入接收状态。 */
{
    const char startup[] = "FW=DIV_REQ_R18 OLED_MODE=TEXT4X16 ACK=UNCHECKED MODE=ON_DEMAND VREF_MV=3300 ADC_BITS=12 BAUD=57600\r\n"; /* 标记固件版本并保留原启动字段。 */
    if (HAL_UART_Transmit(&huart1, (uint8_t *)startup, sizeof(startup) - 1, UART_TIMEOUT_MILLISECONDS) != HAL_OK) /* 发送启动状态。 */
    {
        Error_Handler(); /* 串口启动失败时进入断电停机。 */
    }
}
if (HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK) /* 在测量前校准ADC。 */
{
    const char calibration_error[] = "STATE=UNKNOWN ERROR=ADC_CALIBRATION_FAILED RUN_POWER=OFF TEST_POWER=OFF\r\n"; /* 准备校准失败报告。 */
    HAL_UART_Transmit(&huart1, (uint8_t *)calibration_error, sizeof(calibration_error) - 1, UART_TIMEOUT_MILLISECONDS); /* 尽力输出校准故障。 */
    Error_Handler(); /* 校准失败时禁止继续检测。 */
}
DivControl_InitializeButtons(); /* 初始化RETEST外部中断事件状态。 */
DivControl_Trace("INITIAL_DETECTION_START"); /* 启动后先测当前电路，避免OLED先显示旧默认DIV0。 */
DivMeasurement_Run(); /* 首轮检测结果先缓存并通过串口输出。 */
DivControl_Trace("OLED_INIT_BEGIN"); /* 记录OLED初始化前的控制状态。 */
DivDisplay_Initialize(); /* OLED初始化完成后会强制显示刚缓存的首轮结果。 */
DivControl_Trace("OLED_INIT_END"); /* 记录OLED初始化函数已返回。 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) /* 持续执行循环；错误处理中的空循环用于停机。 */
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
DivControl_Service(); /* 处理停止、复测及ADC检测调度。 */
#if OLED_DISPLAY_ENABLE /* OLED启用时刷新显示并输出状态。 */
DivDisplay_Service(); /* 刷新最近一次测量结果。 */
DivDisplay_ServiceStatus(); /* 定时输出主循环和I2C状态。 */
#endif /* 结束OLED服务条件编译。 */
HAL_Delay(CONTROL_POLL_MILLISECONDS); /* 控制轮询节拍；RETEST由EXTI4产生事件。 */
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
  DivEmergencyStop(); /* 在关闭中断和停机之前，先关闭被测电路的两路电源。 */
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
