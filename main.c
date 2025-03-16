/**
 * @file    main.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Main program to blink LED using TIM2 interrupt
 *
 * This file configures the LED and TIM2 to generate periodic
 * interrupts, toggling the LED every 1 second.
 */

#include "led.h"
#include "timer.h"

int main(void) {
    configure_LED_pin();  // Initialize LED on PA5
    configure_TIM2();     // Configure TIM2 to trigger every 1 second

    while (1) {
        // Main loop does nothing - LED blinks via interrupt
    }
}
