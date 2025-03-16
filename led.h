/**
 * @file    led.h
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Header file for LED control on STM32L476RG
 *
 * This file provides function prototypes for configuring and controlling
 * multiple LEDs connected to different GPIO pins.
 */

#ifndef LED_H
#define LED_H

#include "stm32l476xx.h"

// Define structure for LED pin configuration
typedef struct {
    GPIO_TypeDef *port;   // GPIO port (e.g., GPIOA, GPIOB, GPIOC)
    uint32_t pin;         // GPIO pin (e.g., GPIO_PIN_5)
} LED_t;

// Function prototypes
void configure_LED(LED_t led);
void turn_on_LED(LED_t led);
void turn_off_LED(LED_t led);
void toggle_LED(LED_t led);

#endif // LED_H
