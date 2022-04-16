/*
 * BSP_sensor.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */


#include "sensor.h"


#define ADC_MAX_VALUE (4095.0f)
#define ADC_VOLTAGE_MAX (3.3f)
#define TEMP_SENSOR_CONST (130.0f / ADC_VOLTAGE_MAX)
#define TEMP_SENSOR_OFFSET (30.0f)
#define FILTER_LENGTH (10U)

static ADC_HandleTypeDef ADC_handle;


bsp_status_t SENSOR_init(void)
{
   ADC_handle.Instance = ADC1;
   ADC_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
   ADC_handle.Init.Resolution = ADC_RESOLUTION_12B;
   ADC_handle.Init.ScanConvMode = DISABLE;
   ADC_handle.Init.ContinuousConvMode = ENABLE;
   ADC_handle.Init.DiscontinuousConvMode = DISABLE;
   ADC_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
   ADC_handle.Init.NbrOfConversion = 1;
   ADC_handle.Init.DMAContinuousRequests = DISABLE;
   ADC_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;

   HAL_StatusTypeDef status = HAL_ADC_Init(&ADC_handle);

   if (status != HAL_OK) {
       return BSP_ERROR;
    }

   ADC_ChannelConfTypeDef ADC_channel_confing = {
         .Channel = ADC_CHANNEL_3,
         .Rank = 1,
         .SamplingTime = ADC_SAMPLETIME_480CYCLES,
   };

   status = HAL_ADC_ConfigChannel(&ADC_handle, &ADC_channel_confing);

   if (status != HAL_OK) {
      return BSP_ERROR;
   }

   return BSP_OK;
}

bsp_status_t SENSOR_get_measure(float *temp)
{
   if (temp == NULL)
   {
      return BSP_ERROR;
   }

   HAL_StatusTypeDef status = HAL_ADC_Start(&ADC_handle);

   if (status != HAL_OK)
   {
      return BSP_ERROR;
   }

   float average_temperature = 0.0f;

   for (size_t i = 0; i < FILTER_LENGTH; i++)
   {
      status = HAL_ADC_PollForConversion(&ADC_handle, 200);

      if (status != HAL_OK)
      {
         return BSP_ERROR;
      }

      uint32_t adc_value = HAL_ADC_GetValue(&ADC_handle);
      float voltage = (adc_value / ADC_MAX_VALUE) * ADC_VOLTAGE_MAX;
      float temperature = (voltage * TEMP_SENSOR_CONST) - TEMP_SENSOR_OFFSET;

      average_temperature += temperature / FILTER_LENGTH;
   }

   *temp = average_temperature;

   status = HAL_ADC_Stop(&ADC_handle);

   if (status != HAL_OK)
   {
      return BSP_ERROR;
   }

   return BSP_OK;
}

