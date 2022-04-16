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


bsp_status_t ACT_init(void);

void ACT_turn_on_heater(void);

void ACT_turn_off_heater(void);

void ACT_turn_on_cooler(void);

void ACT_turn_off_cooler(void);


#endif /* BSP_INC_ACTUATORS_H_ */
