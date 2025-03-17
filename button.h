/**
 * @file    button.h
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Header file for generic Push Button handling on STM32L476RG
 *
 * This file provides function prototypes for configuring and handling 
 * buttons with external interrupts.
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "stm32l476xx.h"

// Define structure for Button configuration
typedef struct {
    GPIO_TypeDef *port;  // GPIO port (e.g., GPIOA, GPIOB, GPIOC)
    uint32_t pin;        // GPIO pin number
    uint32_t exti_line;  // EXTI Line number
    IRQn_Type irq_num;   // Interrupt Number (e.g., EXTI15_10_IRQn)
} Button_t;

// Function prototype
void configure_Button_interrupt(Button_t button);

#endif // BUTTON_H
