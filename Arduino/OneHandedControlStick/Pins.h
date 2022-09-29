#pragma once

/*
 *  Arduino Micro Digital IO pins
 *
 *  A* pins are capable of analogue input. PWM are capable of "analogue" output.
 *
 *  A0 - 
 *  A1 -
 *  A2 -
 *  A3 -
 *  A4 -
 *  A5 -
 *  0  - RX (Reserved for Serial port)
 *  1  - TX (Reserved for Serial port)
 *  2  - SDA
 *  3  - PWM 980 Hz / SCL
 *  4  - A6
 *  5  - PWM 490 Hz
 *  6  - PWM 490 Hz / A7
 *  7  -
 *  8  - A8
 *  9  - PWM 490 Hz / A9
 *  10 - PWM 490 Hz / A10
 *  11 - PWM 980 Hz
 *  12 - A11
 *  13 - PWM 490 Hz
 *
 */

enum class PINS {
  RX = 0, //These pins are reserved for serial port communication, and should not be used.
  TX = 1, //^

  SHIFT_DATA = 3,   //Pins 3 and 11 are the high-frequency (980Hz) PWM pins, reserve them for serial data for the shift register.
  SHIFT_CLOCK = 11, //^

  PWM_VIBRATION = 5 //A PWM capable pin so that we can write a PWM signal to the motor.
};