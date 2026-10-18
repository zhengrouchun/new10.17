/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32f1xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
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
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_AFIO_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /** DISABLE: JTAG-DP Disabled and SW-DP Disabled
  */
  __HAL_AFIO_REMAP_SWJ_DISABLE();

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/* USER CODE BEGIN 1 */
#ifdef HAL_I2C_MODULE_ENABLED
void HAL_I2C_MspInit(I2C_HandleTypeDef *bus) /* 配置OLED的I2C1底层时钟与开漏引脚。 */
{
    GPIO_InitTypeDef pins = {0}; /* 先清空GPIO配置。 */
    if (bus->Instance == I2C1) /* 只处理本项目使用的I2C1。 */
    {
        __HAL_RCC_GPIOB_CLK_ENABLE(); /* 打开PB6和PB7所在端口时钟。 */
        pins.Pin = GPIO_PIN_6 | GPIO_PIN_7; /* PB6为SCL，PB7为SDA。 */
        pins.Mode = GPIO_MODE_AF_OD; /* I2C使用复用开漏输出，外接4.7kΩ上拉。 */
        pins.Pull = GPIO_NOPULL; /* 总线上拉由电路中的电阻提供。 */
        pins.Speed = GPIO_SPEED_FREQ_HIGH; /* 为100kHz总线提供足够的GPIO边沿速度。 */
        HAL_GPIO_Init(GPIOB, &pins); /* 应用PB6/PB7配置。 */
        __HAL_RCC_I2C1_CLK_ENABLE(); /* 打开I2C1外设时钟。 */
    }
}
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *bus) /* 支持正常释放显示总线资源。 */
{
    if (bus->Instance == I2C1) /* 不干涉其他外设。 */
    {
        __HAL_RCC_I2C1_CLK_DISABLE(); /* 关闭I2C1时钟。 */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6 | GPIO_PIN_7); /* 释放SCL和SDA引脚。 */
    }
}
#endif

/* USER CODE END 1 */
