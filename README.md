# Software for IEEE SoutheastCon 2026 Rule Validation Prototype

## Project Overview

This repository contains the software developed for the **Autonomous Robotic Chargers (ARC)** project, designed to validate the ruleset of the **IEEE SoutheastCon 2026 Hardware Competition**. The ARC robot is a fully autonomous system capable of completing a series of tasks as outlined in the competition ruleset, including navigation and mechanical task execution.

The primary focus of this software is to control the robot’s movements, sensor data processing, task automation, and testing against competition requirements.

## Key Features

- **Autonomous Navigation**: The software allows the robot to navigate a defined arena, avoiding obstacles while completing tasks.
- **Modular Task Execution**: Each task (e.g., button pressing, crank rotation) is handled by separate modules for easy modification and testing.
- **IMU-Based Orientation**: The robot uses an IMU to track its orientation, ensuring precise movement during task execution.
- **Task Automation**: Automatically completes tasks outlined in the competition requirements.

## Software Structure

- **`main/`**: Contains the main control software for ARC, including modules for motor control, sensor integration, and task execution.
- **`dev-tests/`** (or `prototype-testing/`): Contains test and development scripts used to prototype features before finalizing them for the competition.
<!-- - **`config/`**: Configuration files for robot parameters, including motor speeds and sensor calibration data. -->

## Software Modules

### Motor Control
- Provides functions for forward, backward, and turn movements.
- Speed control is managed via PWM signals to the motors.

### IMU Integration
- The software uses the BNO055 IMU to track the robot’s yaw, pitch, and roll.
- Calibration data is stored and loaded at runtime for consistent orientation.

### Task Automation
- Each mechanical task (e.g., crank turning, button pressing) is handled by a specific function, triggered by sensor inputs or time-based logic.

### Signal Detection and Communication
- Detects LED colors on competition antennas and sends signals to the Death Star using a photodiode.

## Installation

To run the ARC project on your local development environment:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/alexanderbr0wn/SoutheastCon_2026_HW.git
   cd SoutheastCon_2026_HW
2. **Upload Code to the Robot**:
    - Use the Arduino IDE to compile and upload the software to the microcontroller.
    - Ensure all dependencies and libraries (e.g., AccelStepper, I2C) are installed.

3. **Wiring**:
    - Connect motors, sensors, and actuators as per the configuration in the `config/` directory.

## Usage

Once the software is uploaded to the robot:

- **Autonomous Mode**: The robot will autonomously navigate the arena, detect signals, and complete assigned tasks.
- **Development Mode**: Use the scripts in the `dev-tests/` directory to test individual subsystems (e.g., motor control, sensor readings) in isolation before full integration.

## Testing and Validation

<!-- The software is tested through:

- **Simulation and Physical Trials**: Development is guided by testing modules to validate movements and task execution.
- **Statistical Analysis**: Each task is tested over multiple trials (e.g., 30 trials) to ensure consistency, accuracy, and reliability. -->

## Contributions

Feel free to contribute to the development by submitting pull requests or reporting issues. All contributions should focus on improving the modularity, accuracy, or efficiency of the software.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
