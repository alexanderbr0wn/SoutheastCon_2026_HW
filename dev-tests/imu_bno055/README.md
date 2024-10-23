# BNO055 Sensor Calibration and Testing with EEPROM

This project demonstrates how to calibrate, save, load, and verify calibration data for the Adafruit BNO055 sensor using an Arduino. It includes three key functions: calibration, saving and loading calibration data from EEPROM, and verifying the calibration status.

**Note:** The code should only be run with the intention of recalibrating the IMU if necessary. If the calibration data is already stored, use the retrieval and verification function to ensure the IMU is operating correctly.

## Table of Contents
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Libraries](#libraries)
- [Wiring](#wiring)
- [Code Explanation](#code-explanation)
- [How to Use](#how-to-use)
- [References](#references)

## Features
- Calibrate the BNO055 sensor and save the calibration data to EEPROM.
- Load saved calibration data from EEPROM on startup.
- Apply the loaded calibration data to the BNO055 sensor.
- Verify the accuracy and completeness of the calibration data.
- Continuously monitor the sensor's calibration status in real time.

## Hardware Requirements
- Arduino-compatible board (e.g., Arduino Uno, Mega, etc.)
- Adafruit BNO055 Absolute Orientation Sensor
- EEPROM (built-in on most Arduino boards)

## Libraries
The following libraries are required for this project:
1. [Adafruit Sensor](https://github.com/adafruit/Adafruit_Sensor)
2. [Adafruit BNO055](https://github.com/adafruit/Adafruit_BNO055)
3. [EEPROM](https://www.arduino.cc/en/Reference/EEPROM)

Install these libraries using the Arduino Library Manager or download them from the respective links.

## Wiring
- Connect the BNO055 sensor to the Arduino board using I2C:
  - BNO055 VIN to Arduino 5V
  - BNO055 GND to Arduino GND
  - BNO055 SCL to Arduino SCL
  - BNO055 SDA to Arduino SDA

## Code Explanation

### 1. `calibrate_and_save_to_EEPROM.ino`
- This file handles the initial calibration of the BNO055 sensor and saves the calibration offsets to EEPROM once the sensor is fully calibrated.
- The `saveCalibrationData()` function saves the calibration data to EEPROM once the system achieves full calibration (all systems reach level 3).
  
### 2. `retrieve_apply_verify_IMU_cal.ino`
- This script loads the calibration data from EEPROM on startup and applies it to the BNO055 sensor. It then verifies that the calibration data is valid and correctly applied, ensuring consistent performance without the need to recalibrate manually after each power cycle.

### 3. `check_imu_values.ino`
- This script reads and prints real-time sensor data from the IMU (including orientation and motion values) and displays them for verification. This is useful for checking if the sensor is operating correctly after applying the calibration data.

## How to Use

1. **Calibrate the Sensor**: 
   - Upload `calibrate_and_save_to_EEPROM.ino` to the Arduino to perform the initial calibration and save the data to EEPROM. Move the sensor around as needed to complete the calibration process.
   - Calibration steps:
     - The gyroscope will self-calibrate while stationary.
     - The magnetometer requires moving the sensor in various directions.
     - To calibrate the accelerometer, hold the IMU at 45-degree angles in multiple positions until calibration reaches level 3.

2. **Load Calibration and Verify**: 
   - Upload `retrieve_apply_verify_IMU_cal.ino` to load and apply the calibration data stored in EEPROM. The system will check if the calibration data is valid and apply it to the sensor.

3. **Monitor Sensor Values**:
   - Upload `check_imu_values.ino` to read and verify the live sensor data from the IMU. This is useful for confirming that the sensor is providing accurate readings after calibration.

## References
1. Adafruit BNO055 Sensor Library: [Adafruit GitHub Repository](https://github.com/adafruit/Adafruit_BNO055)
2. Arduino EEPROM Library: [Arduino Documentation](https://www.arduino.cc/en/Reference/EEPROM)
3. BNO055 Sensor Datasheet: [BNO055 Datasheet (PDF)](https://cdn-shop.adafruit.com/datasheets/BST_BNO055_DS000_12.pdf)
4. Adafruit BNO055 Calibration Guide: [Adafruit Learn Guide](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/device-calibration)
