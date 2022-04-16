/**
  ******************************************************************************
  * @file    stm32f4xx_hal_msp_template.c
  * @author  MCD Application Team
  * @brief   This file contains the HAL System and Peripheral (PPP) MSP initialization
  *          and de-initialization functions.
  *          It should be copied to the application folder and renamed into 'stm32f4xx_hal_msp.c'.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/** @addtogroup STM32F4xx_HAL_Driver
  * @{
  */

/** @defgroup HAL_MSP HAL MSP
  * @brief HAL MSP module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions HAL MSP Private Functions
  * @{
  */

/**
  * @brief  DeInitializes the ADC MSP.
  * @note   This functiona is called from HAL_ADC_DeInit() function to perform
  *         ADC system level initialization (GPIOs, clock, DMA, interrupt)
  * @retval None
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
   if (hadc->Instance == ADC1)
   {
      __ADC1_CLK_ENABLE();
      __GPIOA_CLK_ENABLE();

      GPIO_InitTypeDef adc_input = {
            .Pin = GPIO_PIN_3,
            .Mode = GPIO_MODE_ANALOG,
            .Pull = GPIO_NOPULL,
      };

      HAL_GPIO_Init(GPIOA, &adc_input);
   }
}

/**
  * @brief  DeInitializes the uart MSP.
  * @note   This functiona is called from HAL_UART_DeInit() function to perform
  *         UART system level initialization (GPIOs, clock, DMA, interrupt)
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
   if (huart->Instance == USART3)
   {
     __USART3_CLK_ENABLE();
     __GPIOD_CLK_ENABLE();

      GPIO_InitTypeDef uart_pins = {
            .Pin = GPIO_PIN_8 | GPIO_PIN_9,
            .Mode = GPIO_MODE_AF_PP,
            .Pull = GPIO_NOPULL,
            .Speed = GPIO_SPEED_FREQ_LOW,
            .Alternate = GPIO_AF7_USART3
      };

      HAL_GPIO_Init(GPIOD, &uart_pins);
   }
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
