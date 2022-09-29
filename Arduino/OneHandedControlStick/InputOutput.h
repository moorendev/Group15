#pragma once

#include <XInput.h>

//Bitmask for serial data from shift register
#define DPAD_UP_MASK    0b00000001
#define DPAD_DOWN_MASK  0b00000010
#define DPAD_LEFT_MASK  0b00000100
#define DPAD_RIGHT_MASK 0b00001000
#define FACE_Y_MASK     0b10000000
#define FACE_A_MASK     0b01000000
#define FACE_X_MASK     0b00100000
#define FACE_B_MASK     0b00010000

//Get rumble information from XInput, output PWM to rumble motor. Pin must be PWM capable.
void HandleRumble(uint8_t pin) {
  static uint8_t averageRumble = ( XInput.getRumbleLeft()+XInput.getRumbleRight() ) / 2;

  analogWrite(pin, averageRumble);
}

//Get DPAD information from shift register input
void HandleDPAD(uint8_t shiftRegisterInput) {
  XInput.setDpad(
    DPAD_UP_MASK^shiftRegisterInput,
    DPAD_DOWN_MASK^shiftRegisterInput,
    DPAD_LEFT_MASK^shiftRegisterInput,
    DPAD_RIGHT_MASK^shiftRegisterInput
  );
}

//Get face button information from shift register input
void HandleFaceButtons(uint8_t shiftRegisterInput) {
  XInput.setButton(BUTTON_A, FACE_A_MASK^shiftRegisterInput);
  XInput.setButton(BUTTON_B, FACE_B_MASK^shiftRegisterInput);
  XInput.setButton(BUTTON_X, FACE_X_MASK^shiftRegisterInput);
  XInput.setButton(BUTTON_Y, FACE_Y_MASK^shiftRegisterInput);
}