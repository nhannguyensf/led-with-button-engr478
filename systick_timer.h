/**
 * @file    systick_timer.h
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Header file for SysTick timer configuration
 *
 * This file declares the function to configure SysTick to
 * generate periodic exceptions every 1 second.
 */

#ifndef SYSTICK_TIMER_H
#define SYSTICK_TIMER_H

#include "stm32l476xx.h"

// Function prototype
void SysTick_Init(uint32_t Reload);
void SysTick_Handler(void);

#endif // SYSTICK_TIMER_H
