// #include "stepper_control.h"

// AccelStepper stepper8834(AccelStepper::DRIVER, STEP_PIN_8834, DIR_PIN_8834);
// AccelStepper stepper8825(AccelStepper::DRIVER, STEP_PIN_8825, DIR_PIN_8825);

// void initializeSteppers() {
//   pinMode(ENABLE_PIN_8834, OUTPUT);
//   digitalWrite(ENABLE_PIN_8834, LOW);
//   stepper8834.setMaxSpeed(1000);
//   stepper8834.setAcceleration(500);

//   pinMode(ENABLE_PIN_8825, OUTPUT);
//   digitalWrite(ENABLE_PIN_8825, LOW);
//   stepper8825.setMaxSpeed(1000);
//   stepper8825.setAcceleration(500);
// }

// void moveStepper(AccelStepper &stepper, int steps, int speed) {
//   stepper.setSpeed(speed);
//   stepper.move(steps);
//   while (stepper.distanceToGo() != 0) {
//     stepper.runSpeedToPosition();
//   }
// }

// void moveToPosition(AccelStepper &stepper, long position, int speed) {
//   stepper.setMaxSpeed(speed);
//   stepper.moveTo(position);
//   while (stepper.distanceToGo() != 0) {
//     stepper.run();
//   }
// }

// void enableStepper(AccelStepper &stepper, int enablePin) {
//   digitalWrite(enablePin, LOW);
// }

// void disableStepper(AccelStepper &stepper, int enablePin) {
//   digitalWrite(enablePin, HIGH);
// }
