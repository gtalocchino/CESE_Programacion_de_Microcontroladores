/*
 * BSP_serial.h
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#ifndef BSP_INC_SERIAL_H_
#define BSP_INC_SERIAL_H_


#include <stdint.h>
#include <string.h>

#include "stm32f4xx_hal.h"
#include "error.h"


typedef struct {
   UART_HandleTypeDef *handle;
} serial_port_t;

/**
 * @brief Initializes serial port.
 *
 * @retval BSP status.
 *
 */
bsp_status_t SERIAL_init(void);

/**
 * @brief Reads value received to serial port.
 *
 * @retval BSP status.
 *
 */
bsp_status_t SERIAL_get_input(uint8_t *buffer, size_t size, uint16_t *received);

/**
 * @brief Gets the current serial port.
 *
 * @retval Serial port used.
 *
 */
serial_port_t *SERIAL_get_port(void);


#endif /* BSP_INC_SERIAL_H_ */
