/**
 * @file    led.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Implementation of multi-LED control functions
 *
 * This file configures and controls multiple LEDs using a generic approach.
 * LEDs can be connected to different GPIO ports and pins.
 */

#include "led.h"

// Function to configure a GPIO pin as an output for an LED
void configure_LED(LED_t led) {
    // Enable clock for the appropriate GPIO port
    if (led.port == GPIOA) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    } else if (led.port == GPIOB) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    } else if (led.port == GPIOC) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    }

    // Set GPIO pin as output
    led.port->MODER &= ~(0b11 << (led.pin * 2));  // Clear mode bits
    led.port->MODER |= (0b01 << (led.pin * 2));   // Set as output (01)

    // Set output type as push-pull
    led.port->OTYPER &= ~(1 << led.pin);

    // No pull-up, pull-down
    led.port->PUPDR &= ~(0b11 << (led.pin * 2));
}

// Function to turn on an LED
void turn_on_LED(LED_t led) {
    led.port->ODR |= (1 << led.pin);
}

// Function to turn off an LED
void turn_off_LED(LED_t led) {
    led.port->ODR &= ~(1 << led.pin);
}

// Function to toggle an LED
void toggle_LED(LED_t led) {
    led.port->ODR ^= (1 << led.pin);
}
