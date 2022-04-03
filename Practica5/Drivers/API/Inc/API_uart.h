/*
 * API_uart.h
 *
 *  Created on: Apr 2, 2022
 *      Author: gianfranco
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include "API_debounce.h"
#include "stm32f4xx_hal_uart.h"

/**
  * @brief  Initializes UART3. Parameters: 9600,8,N,1
  * @retval  True if initialized correctly otherwise false.
  *
  */
bool_t uartinit(void);

/**
  * @brief  Send string over UART
  * @param  pstring: Pointer to the string to be sent.
  *
  */
void uartsendString(uint8_t *pstring);

/**
  * @brief  Send string over UART with size limit
  * @param  pstring: Pointer to the string to be sent.
  * @param  size: Number of bytes to be sent.
  *
  */
void uartSendStringSize(uint8_t *pstring, uint16_t size);

/**
  * @brief  Send string over UART with size limit
  * @param  pstring: Pointer to the buffer to receive data.
  * @param  size: Number of bytes to be received.
  *
  */
void uartReceiveStringSize(uint8_t *pstring, uint16_t size);

#endif /* API_INC_API_UART_H_ */
