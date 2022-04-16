/*
 * bsp.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */


#include "bsp.h"


bsp_status_t BSP_init()
{
   HAL_StatusTypeDef hal_status = HAL_Init();

   if (hal_status != HAL_OK)
   {
      return BSP_ERROR;
   }

   bsp_status_t status =  SENSOR_init();

   if (status != BSP_OK)
   {
      return status;
   }

   status = IND_init();

   if (status != BSP_OK)
   {
      return status;
   }

   status = ACT_init();

   if (status != BSP_OK)
   {
      return status;
   }

   status = SERIAL_init();

   if (status != BSP_OK)
   {
      return status;
   }

   status = LOG_set_port(SERIAL_get_port());

   if (status != BSP_OK)
   {
      return status;
   }

   return BSP_OK;
}

uint32_t BSP_get_timer(void)
{
   return HAL_GetTick();
}

void BSP_error_handler(void)
{
   while (true)
   {

   }
}
