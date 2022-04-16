/*
 * delay.h
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_


#include <stdint.h>
#include <stdbool.h>

#include "bsp.h"


typedef struct {
   uint32_t duration;
   uint32_t start;
   bool running;
} delay_t;


void DELAY_init(delay_t *delay, uint32_t duration);

bool DELAY_read(delay_t *delay);

void DELAY_write(delay_t *delay, uint32_t duration);


#endif /* INC_DELAY_H_ */
