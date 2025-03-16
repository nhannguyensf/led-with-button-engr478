/**
 * @file    main.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Main program for controlling LED and Push Button
 *
 * This file contains the main function that initializes the LED 
 * and Push Button, and continuously monitors the button state 
 * to control the LED accordingly.
 */

#include "led.h"
#include "button.h"

int main(void)
{
	int i;
	// 1. Configure PA5 as Output (LED) and PC13 as Input (Button)
	configure_LED_pin();
	configure_Button_pin();

	// 2. Ensure LED starts OFF
	turn_off_LED(); // If button is pressed, turn on LED

	while (1)
	{
		if (is_Button_Pressed())
		{
			turn_on_LED(); // If button is pressed, turn on LED
		}
		else
		{
			turn_off_LED();
		}
		// for (i = 0; i < 125; i++); // Simple delay to control the bounce
	}
}
