/*
 * BSP_sensor.h
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */

#ifndef BSP_INC_SENSOR_H_
#define BSP_INC_SENSOR_H_


#include <stdint.h>

#include "stm32f4xx_hal.h"
#include "error.h"


bsp_status_t SENSOR_init(void);

bsp_status_t SENSOR_get_measure(float *temp);


#endif /* BSP_INC_SENSOR_H_ */
