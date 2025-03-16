/**
 * @file    timer.h
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Header file for Timer (TIM2) interrupt-based LED blinking
 *
 * This file provides the function prototypes to configure TIM2
 * to generate periodic interrupts for LED toggling every 1 second.
 */

#ifndef TIMER_H
#define TIMER_H

#include "stm32l476xx.h"

// Function prototypes
void configure_TIM2(void);

#endif // TIMER_H
