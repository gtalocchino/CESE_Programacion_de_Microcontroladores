/*
 * fsm.h
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_


#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "bsp.h"


typedef enum {
   STATE_IDLE = 0,
   STATE_HEATING,
   STATE_COOLING,
} fsm_state_t;

/**
 * @brief Initializes hysteresis state machine.
 *
 */
void FSM_init(void);

/**
 * @brief Updates hysteresis state machine.
 *
 */
void FSM_update(void);

/**
 * @brief Sets the limits to be used by the state machine.
 *
 * @param[in] h_on Heater on temperature in Celsius degrees.
 * @param[in] h_off Heater off temperature in Celsius degrees.
 * @param[in] c_on Cooler on temperature in Celsius degrees.
 * @param[in] c_off Cooler off temperature in Celsius degrees.
 *
 */
void FSM_set_limits(float h_on, float h_off, float c_on, float c_off);


#endif /* INC_FSM_H_ */
