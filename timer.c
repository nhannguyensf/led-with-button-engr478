/**
 * @file    timer.h
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Timer (TIM2) configuration for periodic LED blinking
 *
 * This file configures TIM2 to generate an interrupt every 1 second.
 * The interrupt service routine (ISR) toggles the onboard LED (LD2)
 * connected to PA5. The timer uses the default system clock (4 MHz).
 */

#include "timer.h"
#include "led.h"

void configure_TIM2(void) {
    // 1. Enable the clock for TIM2
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;

    // 2. Set Prescaler and Auto-reload for 1-second interval
    TIM2->PSC = 3999;   // Prescaler: 4MHz / 4000 = 1 kHz (1 ms per tick)
    TIM2->ARR = 999;    // Auto-reload: 1000 ticks = 1 second

    // 3. Enable update interrupt for TIM2
    TIM2->DIER |= TIM_DIER_UIE;

    // 4. Enable TIM2 in NVIC (Interrupt Controller)
    NVIC_EnableIRQ(TIM2_IRQn);
    NVIC_SetPriority(TIM2_IRQn, 1);

    // 5. Start TIM2
    TIM2->CR1 |= TIM_CR1_CEN;
}

// TIM2 Interrupt Service Routine (ISR)
void TIM2_IRQHandler(void) {
    if (TIM2->SR & TIM_SR_UIF) { // Check if update interrupt flag is set
        TIM2->SR &= ~TIM_SR_UIF; // Clear interrupt flag
        toggle_LED(); // Toggle LED state
    }
}
