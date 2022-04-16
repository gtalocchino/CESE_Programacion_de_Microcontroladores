 /**
  ******************************************************************************
  * @file
  * @author
  * @brief

  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */
/* Private function prototypes -----------------------------------------------*/
static void error_handler(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
   bsp_status_t status = BSP_init();

   if (status != BSP_OK)
   {
      error_handler();
   }

   parse_input();

   delay_t delay_led;
   DELAY_init(&delay_led, 500);

   delay_t delay_fsm;
   DELAY_init(&delay_fsm, 50);

   delay_t delay_log_temp;
   DELAY_init(&delay_log_temp, 1000);

   FSM_init();

   while (true)
   {
      if (DELAY_read(&delay_fsm))
      {
         FSM_update();
      }

      if (DELAY_read(&delay_log_temp))
      {
         LOG_send_temp();
      }

      if (DELAY_read(&delay_led))
      {
         IND_toggle_led();
      }
   }

   return 0;
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void error_handler(void)
{
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
