/*
 * input.h
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#ifndef INC_PARAMS_H_
#define INC_PARAMS_H_


#include <stdio.h>
#include <string.h>

#include "bsp.h"
#include "fsm.h"


/**
 * @brief Parse the configuration parameters received through UART.
 *
 */
void parse_input(void);


#endif /* INC_PARAMS_H_ */
