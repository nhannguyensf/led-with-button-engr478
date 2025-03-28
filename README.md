# ENGR 478 – Lab 4
# Controlling Onboard LED and Push Button via GPIO; Focus on the Use of the Oscilloscope

This repository contains the source code and documentation for Lab 4 of the ENGR 478: Design with Microprocessors course (Spring 2025).
The lab focuses on using the SysTick timer and external interrupts (EXTI) to control an LED on the STM32L476RG Nucleo-64 board, with additional implementation of software debouncing for push-button input.

---

## 🛠 Features

- Toggle LD2 (PA5) using **SysTick** every 1 second.
- Detect **PC13 button press** using EXTI interrupt.
- **Override SysTick** behavior while the button is pressed (LED stays ON).
- **Resume blinking** once the button is released.
- **Software debouncing** implemented to filter mechanical bounce (adaptive delay).
- Modular code: `led.c`, `systick_timer.c`, and `button.c` for clarity and reuse.

---

## ✅ Hardware
- STM32L476RG Nucleo-64 board

---

## 🧰 Tools
- STM32CubeIDE or Keil uVision
- ST-Link or built-in USB debugger
- Oscilloscope

---

## 📖 Reference Materials

- STM32L476RG Datasheet
- STM32L4 Reference Manual
- ENGR 478 Lab 4 Handouts
- Lecture Slides: Interrupts & Debouncing

---

## ✍️ Author

**The Nucleo Team – ENGR 478 – Spring 2025** - San Francisco State University
- Nhan Nguyen
- Vi Gallegos

---

## 📌 License

This project is for academic use only as part of ENGR 478 coursework. All rights reserved.
