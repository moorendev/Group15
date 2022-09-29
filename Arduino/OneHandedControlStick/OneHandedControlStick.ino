#include <XInput.h>

#include "Pins.h"
#include "InputOutput.h"

//Runs once on startup
void setup() {
  //Use the serial port for XInput communication.
  XInput.begin();

  //Re-map joysticks for Arduino's 10-bit ADC. (Handles some input processing for us)
  XInput.setJoystickRange(0, 1024);
}

//Runs repeatedly
void loop() {
  //Don't bother processing 
  if (XInput.connected()) {
    
    //TODO: Read input from PISO shift register
    uint8_t shiftInput = 0b00000000;

    //Process shift register data to get DPAD and face button states.
    HandleDPAD(shiftInput);
    HandleFaceButtons(shiftInput);

    //Handle the controller rumble.
    HandleRumble(static_cast<uint8_t>(PINS::PWM_VIBRATION));

  } else {
    //TODO: Provide feedback when controller is not connected.
  }
}
