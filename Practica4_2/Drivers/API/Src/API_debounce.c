/*
 * API_debounce.c
 *
 *  Created on: Mar 26, 2022
 *      Author: gianfranco
 */


#include "API_debounce.h"

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

static delay_t delay_button;
static debounceState_t buttonState;
static bool_t buttonPressed = false;

/**
  * @brief  Initializes the de-bounce machine state.
  */
void debounceFSM_init(void) {
	buttonState = BUTTON_UP;
}

/**
  * @brief  Update the de-bounce machine state.
  */
void debounceFSM_update(void)
{
	switch (buttonState)
	{
	case BUTTON_UP:
		delayInit(&delay_button, 40);
		if (BSP_PB_GetState(BUTTON_USER))
		{
			buttonState = BUTTON_FALLING;
		}
		break;
	case BUTTON_FALLING:
		if (delayRead(&delay_button))
		{
			if (BSP_PB_GetState(BUTTON_USER))
			{
				buttonState = BUTTON_DOWN;
			}
			else
			{
				buttonState = BUTTON_UP;
			}
		}
		break;
	case BUTTON_DOWN:
		delayInit(&delay_button, 40);
		if (!BSP_PB_GetState(BUTTON_USER))
		{
			buttonState = BUTTON_RAISING;
		}
		break;
	case BUTTON_RAISING:
		if (delayRead(&delay_button))
		{
			if (!BSP_PB_GetState(BUTTON_USER))
			{
				buttonPressed = true;
				buttonState = BUTTON_UP;
			}
			else
			{
				buttonState = BUTTON_DOWN;
			}
		}
		break;
	default:
		debounceFSM_init();
		break;
	}
}

/**
  * @brief  Indicates if the button has been pressed.
  * @retval  True if the button has been pressed else false.
  */
bool_t readKey(void)
{
	bool_t retval = false;

	if (buttonPressed)
	{
		retval = true;
		buttonPressed = false;
	}

	return retval;
}
