/*
 * API_debounce.h
 *
 *  Created on: Mar 26, 2022
 *      Author: gianfranco
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "API_delay.h"
#include "API_uart.h"
#include "stm32f4xx_nucleo_144.h"

/**
  * @brief  Initializes the de-bounce machine state.
  */
void debounceFSM_init(void);

/**
  * @brief  Update the de-bounce machine state.
  */
void debounceFSM_update(void);

/**
  * @brief  Indicates if the button has been pressed.
  * @retval  True if the button has been pressed else false.
  */
bool_t readKey(void);

#endif /* API_INC_API_DEBOUNCE_H_ */
