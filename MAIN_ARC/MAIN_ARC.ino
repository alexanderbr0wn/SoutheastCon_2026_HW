#include <Wire.h>
#include "robot_control.h"
#include "stepper_control.h"

void setup()
{
  Wire.begin();
  delay(200);
  initializeMotors();
  // initializeSteppers();
}

void loop()
{
  move_forward(23, 23, 2000);
  stop_robot(500);
  // move_backward(23, 23, 2000);
  // stop_robot(500);
  // turn_left(20, 20, 90);
  // stop_robot(500);
  // turn_right(20, 20, 90);
  // stop_robot(500);

  // moveStepper(stepper8834, 200, 500);
  // delay(500);
  // moveStepper(stepper8825, -200, 500);
  // delay(500);
  
  while(1);
}
