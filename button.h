/**
 * @file    button.h
 * @author  The Nucleo Team - ENGR 478 - Spring 2025
 * @brief   Header file for Push Button handling on STM32L476RG
 *
 * This file provides function prototypes for configuring and 
 * reading the onboard User Push Button connected to PC13.
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "stm32l476xx.h"

// Function prototypes
void configure_Button_pin(void);
int is_Button_Pressed(void);

#endif // BUTTON_H
