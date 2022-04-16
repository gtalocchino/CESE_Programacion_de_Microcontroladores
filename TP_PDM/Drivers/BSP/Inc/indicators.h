/*
 * BSP_indicators.h
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#ifndef BSP_INC_INDICATORS_H_
#define BSP_INC_INDICATORS_H_


#include "stm32f4xx_hal.h"
#include "error.h"


/**
 * @brief Initializes indicators.
 *
 * @retval BSP status
 *
 */
bsp_status_t IND_init(void);

/**
 * @brief Toggle indicator LED.
 *
 */
void IND_toggle_led(void);


#endif /* BSP_INC_INDICATORS_H_ */
