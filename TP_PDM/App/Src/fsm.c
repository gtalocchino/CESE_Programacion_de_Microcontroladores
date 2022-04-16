/*
 * fsm.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */


#include "fsm.h"


static fsm_state_t state;

static float heater_on;
static float heater_off;
static float cooler_on;
static float cooler_off;


void FSM_init(void)
{
   state = STATE_IDLE;
}

void FSM_update(void)
{
   /* Obtaining the temperature value. */
   float temp;
   bsp_status_t status = SENSOR_get_measure(&temp);

   if (status != BSP_OK)
   {
      return;
   }

   uint8_t *msg = NULL;

   switch (state) {
   case STATE_IDLE:
      if (temp > cooler_on)
      {
         msg = "status> cooler on, temp: %+06.2fC\n";
         ACT_turn_on_cooler();
         state = STATE_COOLING;
      }
      else if (temp < heater_on)
      {
         msg = "status> heater on, temp: %+06.2fC\n";
         state = STATE_HEATING;
      }
      else
      {
         ACT_turn_off_heater();
         ACT_turn_off_cooler();
      }

      break;
   case STATE_HEATING:
      if (temp > heater_off)
      {
         msg = "status> heater off, temp: %+06.2fC\n";
         ACT_turn_off_heater();
         state = STATE_IDLE;
      }
      else
      {
         ACT_turn_on_heater();
      }

      break;
   case STATE_COOLING:
      if (temp < cooler_off)
      {
         msg = "status> cooler off, temp: %+06.2fC\n";
         ACT_turn_off_heater();
         state = STATE_IDLE;
      }
      else
      {
         ACT_turn_on_cooler();
      }

      break;
   default:
      msg = "error> fsm failed, temp: %+06.2fC\n";
      FSM_init();
      break;
   }

   /*
    * If msg is a NULL pointer there is no msg assigned to be
    * sent by the state machine since the msg variable is
    * initialized with a NULL pointer when declared.
    *
    */

   if (msg != NULL)
   {
      uint8_t buffer[128];
      snprintf(buffer, sizeof(buffer), msg, temp);
      status = LOG_send_msg(buffer, strlen(buffer));

      if (status != BSP_OK)
      {
         BSP_error_handler();
      }
   }
}

fsm_state_t FSM_get_state(void)
{
   return state;
}


void FSM_set_limits(float h_on, float h_off, float c_on, float c_off)
{
   heater_on = h_on;
   heater_off = h_off;
   cooler_on = c_on;
   cooler_off = c_off;
}
