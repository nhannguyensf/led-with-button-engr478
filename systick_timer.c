/**
 * @file    systick_timer.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Implementation of SysTick timer configuration
 *
 * This file configures SysTick to generate an interrupt
 * every 1 second based on the 4 MHz system clock.
 */

#include "systick_timer.h"
#include "led.h"

// Define external LED variable (initialized in main)
extern LED_t led1;
extern volatile uint8_t button_override;  // Defined in button.c

// Function to configure SysTick for 1s interval
void SysTick_Init(uint32_t Reload) {
    // 1. Disable SysTick Counter before configuration
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    
    // 2. Set reload value (counts per interrupt)
    SysTick->LOAD = Reload - 1;
    
    // 3. Clear current value
    SysTick->VAL = 0;
    
    // 4. Enable SysTick exception request
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
    
    // 5. Select SysTick clock source (use processor clock)
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    
    // 6. Enable SysTick Timer
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

// SysTick Interrupt Handler (Automatically called every 1s)
void SysTick_Handler(void) {
if (button_override == 0) {  // Only toggle LED if button is NOT pressed
        toggle_LED(led1);
    }
}
