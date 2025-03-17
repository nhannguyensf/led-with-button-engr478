/**
 * @file    button.c
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Implementation of generic Push Button handling
 *
 * This file configures push buttons as external interrupts
 * and allows the button press to override SysTick LED control.
 */

#include "button.h"
#include "led.h"
#include "systick_timer.h"

// Define external LED variable (initialized in main)
extern LED_t led1;

// Global flag to track button state (0 = SysTick controls LED, 1 = Button controls LED)
volatile uint8_t button_override = 0;

// Function to configure any button as an external interrupt
void configure_Button_interrupt(Button_t button) {
    // 1. Enable clock for the selected GPIO port
    if (button.port == GPIOA) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    } else if (button.port == GPIOB) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    } else if (button.port == GPIOC) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    }

    // 2. Set the pin as input mode
    button.port->MODER &= ~(0b11 << (button.pin * 2));  // Clear mode bits (set as input)

    // 3. Enable SYSCFG clock for EXTI configuration
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // 4. Configure EXTI source for the selected GPIO and pin
    SYSCFG->EXTICR[button.exti_line / 4] &= ~(0b1111 << ((button.exti_line % 4) * 4)); // Clear mapping
    if (button.port == GPIOA) {
        SYSCFG->EXTICR[button.exti_line / 4] |= (0b0000 << ((button.exti_line % 4) * 4));  // Set to GPIOA
    } else if (button.port == GPIOB) {
        SYSCFG->EXTICR[button.exti_line / 4] |= (0b0001 << ((button.exti_line % 4) * 4));  // Set to GPIOB
    } else if (button.port == GPIOC) {
        SYSCFG->EXTICR[button.exti_line / 4] |= (0b0010 << ((button.exti_line % 4) * 4));  // Set to GPIOC
    }

    // 5. Enable rising and falling edge triggers for detecting press and release
    EXTI->RTSR1 |= (1 << button.exti_line);  // Rising edge trigger (release)
    EXTI->FTSR1 |= (1 << button.exti_line);  // Falling edge trigger (press)

    // 6. Enable EXTI interrupt for the button
    EXTI->IMR1 |= (1 << button.exti_line);  // Unmask EXTI line
    NVIC_EnableIRQ(button.irq_num);         // Enable corresponding EXTI interrupt
    NVIC_SetPriority(button.irq_num, 2);    // Set priority lower than SysTick
}

// EXTI Interrupt Handler for Button
void EXTI15_10_IRQHandler(void) {
    if (EXTI->PR1 & EXTI_PR1_PIF13) {  // Check if PC13 caused the interrupt
        if (GPIOC->IDR & (1 << 13)) {  // If button is released
            button_override = 0;       // Allow SysTick to control LED
        } else {  // If button is pressed
            button_override = 1;       // Override SysTick, LED follows button
            turn_on_LED(led1);         // Turn LED ON while pressed
        }

        // Clear the interrupt flag
        EXTI->PR1 |= EXTI_PR1_PIF13;
    }
}
