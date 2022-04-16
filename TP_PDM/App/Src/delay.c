/*
 * delay.c
 *
 *  Created on: Apr 9, 2022
 *      Author: gianfranco
 */


#include "delay.h"


void DELAY_init(delay_t *delay, uint32_t duration)
{
   if (delay == NULL)
   {
      return;
   }

   delay->running = false;
   delay->duration = duration;
}

bool DELAY_read(delay_t *delay)
{
   bool retval = false;

   if (delay->running)
   {
      if ((BSP_get_timer() - delay->start) > delay->duration)
      {
         delay->start = BSP_get_timer();
         retval = true;
      }
   }
   else
   {
      delay->running = true;
      delay->start = BSP_get_timer();
   }

   return retval;
}

void DELAY_write(delay_t *delay, uint32_t duration)
{
   delay->duration = duration;
   delay->start = BSP_get_timer();
   delay->running = true;
}
