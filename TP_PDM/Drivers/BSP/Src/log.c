/*
 * BSP_log.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */


#include "log.h"


static serial_port_t *serial_port = NULL;


bsp_status_t LOG_set_port(serial_port_t *port)
{
   if (port == NULL)
   {
      return BSP_ERROR;
   }

   serial_port = port;

   return BSP_OK;
}


bsp_status_t LOG_send_msg(uint8_t *msg, size_t size)
{
   if (serial_port->handle == NULL)
   {
      return BSP_ERROR;
   }

   HAL_StatusTypeDef status = HAL_UART_Transmit(serial_port->handle, msg, size, 100);

   if (status != HAL_OK)
   {
      return BSP_ERROR;
   }

   return BSP_OK;
}

bsp_status_t LOG_send_temp(void)
{
   float temp = 0;
   bsp_status_t status = SENSOR_get_measure(&temp);

   if (status != BSP_OK)
   {
      return BSP_ERROR;
   }

   char msg[100];
   snprintf(msg, sizeof(msg), "status> temp: %+06.2fC\n", temp);

   status = LOG_send_msg(msg, strlen(msg));

   if (status != BSP_OK)
   {
      return BSP_ERROR;
   }

   return BSP_OK;
}

