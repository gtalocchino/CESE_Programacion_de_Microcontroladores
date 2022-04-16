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


/**
 * @brief Initializes the delay.
 *
 * @param[in] delay Pointer to a delay.
 * @param[in] duration Duration of a delay in ms.
 *
 */
void DELAY_init(delay_t *delay, uint32_t duration);

/**
 * @brief Checks if the delay time has passed.
 *
 * @param[in] delay Pointer to a delay.
 * @retval True if delay time has elapsed else false.
 *
 */
bool DELAY_read(delay_t *delay);

/**
 * @brief Updates hysteresis state machine.
 *
 * @param[in] delay pointer to a delay.
 * @param[in] duration Duration of a delay in ms.
 *
 */
void DELAY_write(delay_t *delay, uint32_t duration);


#endif /* INC_DELAY_H_ */
