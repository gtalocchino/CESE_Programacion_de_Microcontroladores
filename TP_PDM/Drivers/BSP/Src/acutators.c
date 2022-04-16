/*
 * BSP_acutators.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */


#include "actuators.h"


#define PIN_HEATER GPIO_PIN_14
#define PIN_COOLER GPIO_PIN_7

#define GPIO_HEATER GPIOB
#define GPIO_COOLER GPIOB


bsp_status_t ACT_init(void)
{
   __GPIOB_CLK_ENABLE();

   GPIO_InitTypeDef GPIO_cooler = {
         .Pin = PIN_COOLER,
         .Mode = GPIO_MODE_OUTPUT_PP,
         .Pull = GPIO_NOPULL,
         .Speed = GPIO_SPEED_LOW,
   };

   HAL_GPIO_Init(GPIO_COOLER, &GPIO_cooler);
   HAL_GPIO_WritePin(GPIO_COOLER, PIN_COOLER, GPIO_PIN_RESET);

   GPIO_InitTypeDef GPIO_heater = {
         .Pin = GPIO_PIN_14,
         .Mode = GPIO_MODE_OUTPUT_PP,
         .Pull = GPIO_NOPULL,
         .Speed = GPIO_SPEED_LOW,
   };

   HAL_GPIO_Init(GPIO_HEATER, &GPIO_heater);
   HAL_GPIO_WritePin(GPIO_HEATER, PIN_HEATER, GPIO_PIN_RESET);

   return BSP_OK;
}

void ACT_turn_on_heater(void)
{
   HAL_GPIO_WritePin(GPIO_HEATER, PIN_HEATER, GPIO_PIN_SET);
}

void ACT_turn_off_heater(void)
{
   HAL_GPIO_WritePin(GPIO_HEATER, PIN_HEATER, GPIO_PIN_RESET);
}

void ACT_turn_on_cooler(void)
{
   HAL_GPIO_WritePin(GPIO_COOLER, PIN_COOLER, GPIO_PIN_SET);
}

void ACT_turn_off_cooler(void)
{
   HAL_GPIO_WritePin(GPIO_COOLER, PIN_COOLER, GPIO_PIN_RESET);
}
