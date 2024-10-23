#include <Wire.h>
#include "robot_control.h"
#include "stepper_control.h"

void setup()
{
  Wire.begin();
  delay(200);
  Serial.begin(9600);
    while (!Serial) {
        ;  // Wait for the serial port to connect (only needed on some boards)
    }

  Serial.println("Serial communication initialized!"); 
  initializeMotors();
  initializeIMU();
  // initializeSteppers();
}

void loop()
{
  move_robot(robot_forward, 2000);
  move_robot(robot_stop, 500);
  move_robot(robot_backward, 2000);
  move_robot(robot_stop, 500);
  move_robot(robot_turn_left, 900);
  move_robot(robot_stop, 500);
  move_robot(robot_turn_right, 900);
  move_robot(robot_stop, 500);

  // moveStepper(stepper8834, 200, 500);
  // delay(500);
  // moveStepper(stepper8825, -200, 500);
  // delay(500);
  
  while(1);
}
