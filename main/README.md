# Arduino Robot Control Project

This project involves controlling a robot using multiple subsystems such as stepper motors and IMU (BNO055 sensor). The system reads sensor data, applies control logic, and drives the robot's components accordingly.

## Project Structure

- `MAIN_ARC.ino`: The main control loop for the robot. Coordinates subsystems and handles the overall robot control logic.
- `imu_control.ino` & `imu_control.h`: Handles the interaction with the BNO055 IMU sensor, including calibration and data retrieval.
- `robot_control.ino` & `robot_control.h`: Implements the robot's movement control, including the interaction between different motors and sensors.
- `stepper_control.ino` & `stepper_control.h`: Manages the control of the stepper motors, which are responsible for the robot’s precise movements.

## Features

- IMU calibration and sensor data integration.
- Control logic for stepper motors.
- Modularized control structure, separating functionality into distinct components.
- EEPROM-based calibration storage for the IMU.

## Setup

1. Clone the repository or download the project files.
2. Make sure you have the required hardware:
   - BNO055 IMU sensor.
   - Stepper motors.
3. Upload the code to your Arduino-compatible board.
4. Monitor the serial output for system status and debugging.

## Dependencies

The following libraries are required:
- Adafruit BNO055 library for IMU control: [GitHub Repo](https://github.com/adafruit/Adafruit_BNO055)
- EEPROM library: [Arduino Documentation](https://www.arduino.cc/en/Reference/EEPROM)

## How to Use

- Upload the project to your Arduino.
- Open the Serial Monitor (115200 baud rate) to check calibration status and control feedback.
- Ensure the IMU is calibrated properly, and the system can save/load calibration data.
- Use the provided functions to control the robot via stepper motors and IMU readings.

## Future Enhancements

- Add more sophisticated control logic, such as PID or other advanced algorithms.
- Integrate additional sensors and actuators for more precise robot control.

## License

This project is open-source and can be used and modified freely.
