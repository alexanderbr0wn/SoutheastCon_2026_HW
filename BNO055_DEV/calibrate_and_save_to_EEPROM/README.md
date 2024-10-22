# BNO055 Sensor Calibration with EEPROM

**Warning:** This code should only be run with the intention of recalibrating the IMU. <br>If you simply want to verify that the calibration stored in EEPROM is valid, use the `retrieve_apply_verify_IMU_cal` function instead.

This project demonstrates how to use an Adafruit BNO055 sensor with an Arduino to load and save calibration data to EEPROM. <br>The code uses the Adafruit BNO055 and EEPROM libraries to retain the calibration data, ensuring that the sensor remains calibrated across power cycles.

## Table of Contents
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Libraries](#libraries)
- [Wiring](#wiring)
- [Code Explanation](#code-explanation)
- [How to Use](#how-to-use)
- [References](#references)

## Features
- Load BNO055 sensor calibration data from EEPROM on startup.
- Automatically apply saved calibration data to the sensor.
- Continuously monitor the calibration status of the sensor.
- Save calibration data back to EEPROM when the system is fully calibrated.
  
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

### `setup()`
- Initializes the BNO055 sensor and establishes communication using the `begin()` method.
- Loads saved calibration data from EEPROM.
- Enables the external crystal for accurate orientation measurements.

### `loadCalibrationData()`
- Reads 22 bytes of calibration data from EEPROM and applies them to the BNO055 sensor.
- Prints the calibration data to the Serial monitor for debugging purposes.

### `saveCalibrationData()`
- When the sensor is fully calibrated (system, gyro, accelerometer, and magnetometer all at level 3), the function saves the current calibration offsets to EEPROM.
- Calibration data is saved byte by byte using the `EEPROM.update()` function.

### `loop()`
- Continuously checks the calibration status of the sensor.
- If the system is fully calibrated, it saves the calibration data to EEPROM. If not, it notifies the user that calibration is incomplete.

## How to Use
1. Upload the code to your Arduino board.
2. Open the Serial Monitor (115200 baud).
3. The program will automatically load any saved calibration data on startup.
4. Move the sensor around to calibrate it. When fully calibrated, the program will save the calibration data to EEPROM.
   - The gyroscope will calibrate itself from a stationary position.
   - The mangnetometer is calibrated via various random movements through space.
   - To calibrate the accelerometer turn the IMU at a 45-degree angle from the X/Y-plane and hold it there for ~10 seconds.  Repeat this process rotating 90-degrees around the Z-plane until the calibration value in the serial monitor becomes '3'.
   - The system calibration will become '3' once the independent devices are calibrated.
6. Reset the board to see how the calibration data is retained and loaded.

## References
1. Adafruit BNO055 Sensor Library: [Adafruit GitHub Repository](https://github.com/adafruit/Adafruit_BNO055)
2. Arduino EEPROM Library: [Arduino Documentation](https://www.arduino.cc/en/Reference/EEPROM)
3. BNO055 Sensor Datasheet: [BNO055 Datasheet (PDF)](https://cdn-shop.adafruit.com/datasheets/BST_BNO055_DS000_12.pdf)
4. Adafruit BNO055 Calibration Guide: [Adafruit Learn Guide](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/device-calibration)
