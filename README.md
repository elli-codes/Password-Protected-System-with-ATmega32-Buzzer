Password-Protected System with ATmega32

This project implements a simple password authentication system using an ATmega32 microcontroller, an LCD display, and an external interrupt (INT0) for keypad input.
When the correct password is entered, the system activates an output (e.g., LED/buzzer on PC0). If the password is incorrect, another output (e.g., LED/buzzer on PC1) is triggered.

✨ Features

4-digit password authentication.

Password input handled through external interrupt (INT0).

LCD displays masked password input (*).

Correct password → Activates PC0 (success indicator).

Incorrect password → Activates PC1 (error indicator).

Automatic reset after each attempt.

🛠️ Hardware Requirements

ATmega32 microcontroller

16x2 LCD (HD44780-compatible)

Keypad or input buttons connected to Port A (lower 4 bits)

LEDs/buzzer on PC0 (correct) and PC1 (wrong)

Power supply (5V)

⚙️ Software Details

Written in C using CodeVisionAVR compiler.

LCD controlled via <alcd.h> library.

External interrupt (INT0) configured for falling edge trigger.

Simple timing handled with <delay.h>.
💻 Code Written using CodeVisionAVR.

📽️ Video YouTube video link: https://youtu.be/WQyju0DLdqU
