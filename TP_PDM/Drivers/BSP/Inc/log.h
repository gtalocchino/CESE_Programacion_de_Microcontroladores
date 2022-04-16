/*
 * BSP_log.h
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#ifndef BSP_INC_LOG_H_
#define BSP_INC_LOG_H_

#include <stdint.h>
#include <stdio.h>

#include "stm32f4xx_hal.h"
#include "error.h"
#include "serial.h"
#include "sensor.h"


/**
 * @brief Sets serial port to send log.
 *
 * @retval BSP status.
 *
 */
bsp_status_t LOG_set_port(serial_port_t *port);

/**
 * @brief Sends message to log serial port.
 *
 * @retval BSP status
 *
 */
bsp_status_t LOG_send_msg(uint8_t *msg, size_t size);

/**
 * @brief Sends temperature log to log serial port.
 *
 * @retval BSP status
 *
 */
bsp_status_t LOG_send_temp(void);


#endif /* BSP_INC_LOG_H_ */
