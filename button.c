/**
 * @file    button.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Implementation of Push Button handling functions
 *
 * This file contains the function implementations for configuring 
 * and reading the onboard User Push Button connected to PC13.
 */

#include "button.h"

void configure_Button_pin()
{
	// 1. Enable the clock to GPIO Port C
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

	// 2. Configure GPIO Mode to 'Input': Input(00), Output(01), AlterFunc(10), Analog(11)
	GPIOC->MODER &= ~GPIO_MODER_MODER13; // Clear Mode bits for PC13 to 00 (Input)

	// 3. No need to configure OTYPER for input mode

	// 4. Configure GPIO Pull-Up/Pull-Down to 'No Pull-up or Pull-down': No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR13; // Clear PC13's pull-up/pull-down settings to 00
}

// Function to read the button state (returns 1 if pressed, 0 otherwise)
int is_Button_Pressed()
{
	return !(GPIOC->IDR & GPIO_IDR_ID13); // PC13 is active-low (pressed = 0)
}