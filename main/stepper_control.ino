// #include "stepper_control.h"

// AccelStepper stepper8834(AccelStepper::DRIVER, STEP_PIN_8834, DIR_PIN_8834);
// AccelStepper stepper8825(AccelStepper::DRIVER, STEP_PIN_8825, DIR_PIN_8825);

// /**
//  * @brief Initializes the stepper motors.
//  * 
//  * This function sets up the stepper motors, configuring the pins for step,
//  * direction, and enable, and ensuring that the motor driver is ready for 
//  * movement commands.
//  */
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

// /**
//  * @brief Moves the stepper motor by a specific number of steps.
//  * 
//  * @param stepper The stepper motor object (AccelStepper instance).
//  * @param steps The number of steps to move the motor.
//  * @param speed The speed at which the motor should move.
//  * 
//  * This function commands the stepper motor to move a specified number of steps
//  * at a given speed.
//  */
// void moveStepper(AccelStepper &stepper, int steps, int speed) {
//   stepper.setSpeed(speed);
//   stepper.move(steps);
//   while (stepper.distanceToGo() != 0) {
//     stepper.runSpeedToPosition();
//   }
// }

// /**
//  * @brief Moves the stepper motor to a specified position.
//  * 
//  * @param stepper The stepper motor object (AccelStepper instance).
//  * @param position The target position for the motor.
//  * @param speed The speed at which the motor should move.
//  * 
//  * This function moves the stepper motor to a specific position at a set speed.
//  */
// void moveToPosition(AccelStepper &stepper, long position, int speed) {
//   stepper.setMaxSpeed(speed);
//   stepper.moveTo(position);
//   while (stepper.distanceToGo() != 0) {
//     stepper.run();
//   }
// }

// /**
//  * @brief Enables the stepper motor.
//  * 
//  * @param stepper The stepper motor object (AccelStepper instance).
//  * @param enablePin The pin used to enable the stepper motor.
//  * 
//  * This function enables the stepper motor by pulling the enable pin low.
//  */
// void enableStepper(AccelStepper &stepper, int enablePin) {
//   digitalWrite(enablePin, LOW);
// }

// /**
//  * @brief Disables the stepper motor.
//  * 
//  * @param stepper The stepper motor object (AccelStepper instance).
//  * @param enablePin The pin used to disable the stepper motor.
//  * 
//  * This function disables the stepper motor by pulling the enable pin high.
//  */
// void disableStepper(AccelStepper &stepper, int enablePin) {
//   digitalWrite(enablePin, HIGH);
// }
