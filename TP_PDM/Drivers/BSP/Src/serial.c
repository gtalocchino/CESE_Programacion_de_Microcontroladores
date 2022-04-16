/*
 * BSP_serial.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#include "serial.h"


static UART_HandleTypeDef UART_handle;

static serial_port_t serial_port = {
   .handle = &UART_handle
};


bsp_status_t SERIAL_init(void)
{
   UART_handle.Instance = USART3;
   UART_handle.Init.BaudRate = 9600;
   UART_handle.Init.WordLength = UART_WORDLENGTH_8B;
   UART_handle.Init.StopBits = UART_STOPBITS_1;
   UART_handle.Init.Parity = UART_PARITY_NONE;
   UART_handle.Init.Mode = UART_MODE_TX_RX;
   UART_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
   UART_handle.Init.OverSampling = UART_OVERSAMPLING_16;

   HAL_StatusTypeDef status = HAL_UART_Init(&UART_handle);

   if (status != HAL_OK)
   {
      return BSP_ERROR;
   }

   uint8_t *msg = "status> UART OK\n";
   status = HAL_UART_Transmit(&UART_handle, msg, strlen(msg), 100);

   if (status != HAL_OK)
   {
      return BSP_ERROR;
   }

   return BSP_OK;
}

bsp_status_t SERIAL_get_input(uint8_t *buffer, size_t size, uint16_t *received)
{
   HAL_StatusTypeDef status = HAL_UARTEx_ReceiveToIdle(&UART_handle, buffer, size, received, HAL_MAX_DELAY);

   if (status != HAL_OK)
   {
      return BSP_ERROR;
   }

   return BSP_OK;
}

serial_port_t *SERIAL_get_port(void)
{
   return &serial_port;
}
