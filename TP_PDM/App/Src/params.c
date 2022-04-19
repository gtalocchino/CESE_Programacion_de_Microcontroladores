/*
 * input.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */


#include "params.h"


void parse_input(void)
{
   /* Clearing input buffer. */
   char input_buffer[128];
   memset(input_buffer, 0, sizeof(input_buffer));

   float heater_on = 0;
   float heater_off = 0;
   float cooler_on = 0;
   float cooler_off = 0;

   while (true) {
      /* Waiting for input. */
      uint16_t bytes_received = 0;
      bsp_status_t status = SERIAL_get_input(input_buffer, 31, &bytes_received);

      if (status != BSP_OK)
      {
         BSP_error_handler();
      }

      if (bytes_received != 31)
      {
         continue;
      }

      /* Getting input parameters. */
      uint8_t *fmt = "%f, %f, %f, %f";
      int32_t retval = sscanf(input_buffer, fmt, &heater_on, &heater_off, &cooler_on, &cooler_off);

      /*
       * We expect 4 items successfully matched and assigned by sscanf. They are
       * heater_on, heater_off, cooler_on and cooler_off. Since the function
       * sscanf returns the number of arguments processed correctly, if it is different
       * from 4, the input format is not correct, so we remain in the loop.
       *
       */

      if (retval == 4)
      {
         break;
      }

      uint8_t *msg = "error> wrong input format!\n";
      status = LOG_send_msg(msg, strlen(msg));

      if (status != BSP_OK)
      {
         BSP_error_handler();
      }
   }

   /* Setting up parameters. */
   FSM_set_limits(heater_on, heater_off, cooler_on, cooler_off);
}
