/**
 * @file    led.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Implementation of LED control functions
 *
 * This file contains the function implementations for configuring 
 * and controlling the onboard Green LED (LD2) connected to PA5.
 */

#include "led.h"

// Function to configure PA5 as an output pin for the LED// PA5  <--> Green LED (LD2)

void configure_LED_pin()
{
	// 1. Enable the clock to GPIO Port A
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

	// 2. Configure GPIO Mode to 'Output': Input(00), Output(01), AlterFunc(10), Analog(11)
	GPIOA->MODER &= ~GPIO_MODER_MODER5;	 // Clear Mode bits for PA5
	GPIOA->MODER |= GPIO_MODER_MODER5_0; // Set the Mode bits to 01

	// 3. Configure GPIO Output Type to 'Push-Pull': Output push-pull (0), Output open drain (1)
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_5; // Set PA5 as push-pull

	// 4. Configure GPIO Pull-Up/Pull-Down to 'No Pull-up or Pull-down': No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR5; // Clear PA5's pull-up/pull-down settings to 00
}

// Modular function to turn on the LD2 LED.
void turn_on_LED()
{
	GPIOA->ODR |= GPIO_ODR_OD5; // Set PA5 to 1 (LED ON)
}

// Modular function to turn off the LD2 LED.
void turn_off_LED()
{
	GPIOA->ODR &= ~GPIO_ODR_OD5; // Set PA5 to 0 (LED OFF)
}

// Modular function to toggle the LD2 LED.
void toggle_LED()
{
	GPIOA->ODR ^= GPIO_ODR_OD5; // Toggle PA5
}