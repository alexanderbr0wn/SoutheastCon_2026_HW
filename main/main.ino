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

  Serial.println("Serial communication initialized!"); 
  initializeMotors();
  initializeIMU();
  // initializeSteppers();
}

void loop()
{
  move_forward(100, 100, 2000);
  stop_robot(500);
  move_forward(50, 50, 2000);

  // moveStepper(stepper8834, 200, 500);
  // delay(500);
  // moveStepper(stepper8825, -200, 500);
  // delay(500);
  
  while(1);
}
