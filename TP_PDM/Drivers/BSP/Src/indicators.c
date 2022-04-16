/*
 * BSP_indicators.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */


#include "indicators.h"


#define PIN_INDICATOR GPIO_PIN_0
#define GPIO_INDICATOR GPIOB


bsp_status_t IND_init(void)
{
   __GPIOB_CLK_ENABLE();

   GPIO_InitTypeDef GPIO_ind = {
         .Pin = PIN_INDICATOR,
         .Mode = GPIO_MODE_OUTPUT_PP,
         .Pull = GPIO_NOPULL,
         .Speed = GPIO_SPEED_LOW,
   };

   HAL_GPIO_Init(GPIO_INDICATOR, &GPIO_ind);
   HAL_GPIO_WritePin(GPIO_INDICATOR, PIN_INDICATOR, GPIO_PIN_RESET);

   return BSP_OK;
}

void IND_toggle_led(void)
{
   HAL_GPIO_TogglePin(GPIO_INDICATOR, PIN_INDICATOR);
}
