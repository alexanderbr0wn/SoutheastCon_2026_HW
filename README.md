
# IEEE SoutheastCon 2026 Hardware Competition

## Project Overview
The **Autonomous Robotic Chargers (ARC)** project is developed for the **IEEE SoutheastCon 2026 Hardware Competition**. Our team is tasked with designing a fully autonomous robot capable of completing a series of complex tasks under competition rules, such as navigation, signal detection, mechanical task execution, and object manipulation. The project focuses on evaluating the practicality, feasibility, and clarity of the competition's ruleset by testing key tasks and subsystems through a modular robot design.

## Key Features
- **Modular Design**: A flexible and modular robot system that can adapt to various tasks and subsystems.
- **Autonomous Navigation**: The robot is capable of navigating a predefined course, avoiding obstacles, and aligning for task completion.
- **Actuation Tasks**: Includes mechanical actions such as button pressing, crank rotation, keypad entry, and object removal.
- **Task Evaluation**: Focuses on testing key elements of the competition ruleset, including navigation, mechanical tasks, and signal communication.

## Competition Requirements
The robot must:
- Fit within a 12"x12"x12" starting area.
- Weigh no more than 25 lbs.
- Be fully autonomous, with safety features such as an emergency stop.

### Tasks Breakdown:
1. **Restore Antenna Power**:
   - Press a button.
   - Rotate a crank 360 degrees.
   - Enter a sequence on a keypad.
   - Remove an object (Astro-jedi-duck) from a pressure plate.
2. **Signal Communication**:
   - Detect and transmit color signals.
3. **Object Identification**:
   - Locate and return objects (ducks).
4. **Autonomous Navigation**:
   - Navigate the environment while avoiding obstacles.

## Hardware Overview
The ARC robot is built using:
- **Chassis & Motors**: Supports movement and navigation with a durable frame.
- **Actuators**: Stepper motors provide precise control for actions like button pressing and crank rotation.
- **Sensors**: Includes an IMU (BNO055), ultrasonic sensors for object detection, and an onboard camera for navigation and signal detection.

### Main Components:
- **Microcontroller**: Arduino Mega 2560
- **Motors**: 520 Encoder DC Gear Motors
- **Sensors**: BNO055 IMU, ultrasonic sensors, and an OpenMV camera.

## Software Overview
The software controls motor functions (movement, rotation, stopping), sensor data processing, and task automation. The key features include:
- **Motor Control**: Includes forward, backward, turn, and stop functions.
- **IMU Data Processing**: Handles yaw (orientation) calculations to assist with precise navigation.
- **Task Automation**: Automates task completion based on sensor input, including object detection and path correction.

### Libraries Used:
- **AccelStepper**: Used for stepper motor control.
- **I2C**: For motor communication.

## Installation Instructions
To run the ARC project on your local machine:
1. **Clone the repository**:
   ```bash
   git clone https://github.com/alexanderbr0wn/SoutheastCon_2026_HW.git
   cd SoutheastCon_2026_HW
   ```
2. **Compile and upload** the code using the Arduino IDE.
3. **Wiring**: Follow the wiring guide to connect the actuators, sensors, and microcontroller as specified in the documentation.

## Usage
Once the robot is powered on and running the code:
- **Autonomous Mode**: The robot will navigate autonomously, detect signals, and execute tasks such as button pressing and crank rotation.
- **Testing Mode**: Individual tasks can be triggered for testing, allowing detailed evaluation of each function (navigation, signal processing, etc.).

## Testing and Evaluation
The project includes rigorous testing plans, with **30 trials per task** to ensure statistical significance in:
- **Time to Complete Tasks**: How long the robot takes to perform each task.
- **Accuracy**: How precisely the robot completes each task.
- **Success Rate**: Percentage of tasks completed successfully.

Key tasks tested include:
- **Red Button Pressing**: Minimum force required is 5.14 N.
- **Crank Rotation**: Minimum torque required is 0.24 N⋅m.
- **Keypad Entry**: Minimum force required is 1.61 N.

## Known Issues and Future Work
- **Ultrasonic Sensor & Camera Integration**: The integration of these components is still pending.
- **Navigation Tuning**: Further testing is required to fine-tune the navigation algorithms for precision and obstacle avoidance.
- **Signal Communication**: The hardware for signal communication is under evaluation.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
