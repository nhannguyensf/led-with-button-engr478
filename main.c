/**
 * @file    main.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Main program for LED control using Button Interrupt and SysTick
 *
 * This program configures SysTick to toggle an LED every second,
 * but allows a button press to override SysTick and control the LED directly.
 */

#include "led.h"
#include "systick_timer.h"
#include "button.h"

// Define LED and Button structures
LED_t led1 = {GPIOA, 5};                            // Onboard Green LED (PA5)
Button_t button1 = {GPIOC, 13, 13, EXTI15_10_IRQn}; // User Button (PC13)

int main(void)
{
    configure_LED(led1);                 // Initialize the LED
    configure_Button_interrupt(button1); // Configure PC13 as an interrupt

    turn_on_LED(led1); // Turn on the LED initially

    // Enable SysTick interrupt
    // SysTick Reload Value Calculation:
    // SYSCLK = 4 MHz, Time = 1s → RELOAD = (4,000,000 - 1)
    // SysTick_Init(4000000);

    while (1)
    {
        // Main loop does nothing, LED toggles via SysTick
        // and responds to button presses via EXTI13
    }
}
