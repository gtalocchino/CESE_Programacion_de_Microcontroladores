/*
 * BSP_actuators.h
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#ifndef BSP_INC_ACTUATORS_H_
#define BSP_INC_ACTUATORS_H_


#include <stdint.h>

#include "stm32f4xx_hal.h"
#include "error.h"

/**
 * @brief Initializes actuators.
 *
 * @retval BSP status
 *
 */
bsp_status_t ACT_init(void);

/**
 * @brief Turns on heater.
 *
 */
void ACT_turn_on_heater(void);

/**
 * @brief Turns off heater.
 *
 */
void ACT_turn_off_heater(void);

/**
 * @brief Turns on cooler.
 *
 */
void ACT_turn_on_cooler(void);

/**
 * @brief Turns off cooler.
 *
 */
void ACT_turn_off_cooler(void);


#endif /* BSP_INC_ACTUATORS_H_ */
