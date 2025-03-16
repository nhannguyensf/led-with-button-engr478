/**
 * @file    main.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Main program for LED blinking using SysTick
 *
 * This program configures SysTick to generate periodic
 * interrupts every 1 second, toggling an LED automatically.
 */

#include "led.h"
#include "systick_timer.h"

// Define LED
LED_t led1 = {GPIOA, 5};  // Onboard Green LED (PA5)

int main(void) {
    configure_LED(led1);  // Initialize the LED

    // SysTick Reload Value Calculation:
    // SYSCLK = 4 MHz, Time = 1s → RELOAD = (4,000,000 - 1)
    SysTick_Init(4000000);

    while (1) {
        // Main loop does nothing, LED toggles via SysTick exceptions
    }
}
