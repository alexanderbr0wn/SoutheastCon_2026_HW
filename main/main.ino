#include <Wire.h>
#include "robot_control.h"
#include "stepper_control.h"

void setup()
{
  Wire.begin();
  Wire.setClock(400000);
  delay(200);
  Serial.begin(9600);
    while (!Serial) {
        ;
    }
  initializeMotors();
  initializeIMU();
  // initializeSteppers();
}

void loop()
{
  move_forward(25, 25, 2750); // move to red button
  stop_robot(500);
  turn_right(23, 23, 500); // turn toward keypad
  // stop_robot(500);
  // move_forward(23, 23, 8000); // move to keypad
  // stop_robot(500);
  // turn_right(23, 23, 1500); // turn toward keypad
  

  // moveStepper(stepper8834, 200, 500);
  // delay(500);
  // moveStepper(stepper8825, -200, 500);
  // delay(500);
  
  while(1);
}
