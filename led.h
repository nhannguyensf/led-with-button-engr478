/**
 * @file    led.h
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Header file for LED control on STM32L476RG
 *
 * This file provides function prototypes for configuring and 
 * controlling the onboard Green LED (LD2) connected to PA5.
 */

#ifndef LED_H
#define LED_H

#include "stm32l476xx.h"

// Function prototypes
void configure_LED_pin(void);
void turn_on_LED(void);
void turn_off_LED(void);

#endif // LED_H
