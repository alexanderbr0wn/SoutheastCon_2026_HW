# BNO055 Sensor Calibration with EEPROM Storage

This repository contains code to initialize and calibrate an Adafruit BNO055 IMU sensor, load calibration data from EEPROM, and continuously monitor its calibration status.

## Overview

This code sets up a BNO055 sensor using the Adafruit library and retrieves saved calibration data from EEPROM. The calibration data is applied during startup to avoid needing to recalibrate the sensor after each power cycle. The current calibration status of the sensor is then printed to the serial monitor during the main loop.

### Key Features:
- **EEPROM Calibration Data Storage**: The BNO055 calibration data is stored and loaded from EEPROM, reducing the need to recalibrate the sensor each time it is powered on.
- **Continuous Calibration Monitoring**: The code provides real-time feedback on the calibration status of the system, including the gyroscope, accelerometer, and magnetometer.
- **External Crystal Support**: The sensor is configured to use an external crystal for better accuracy.

## Hardware Requirements

- Adafruit BNO055 sensor
- Arduino-compatible board
- EEPROM (used internally by Arduino boards)

## Installation

1. **Libraries**: Ensure that you have the required libraries installed. You can install them via the Arduino Library Manager:
   - `Adafruit_Sensor`
   - `Adafruit_BNO055`
   - `Wire`

2. **Connections**: Connect the BNO055 sensor to your board as per the standard I2C connection:
   - `VIN` to 3.3V/5V
   - `GND` to GND
   - `SCL` to A5 (for most Arduino boards)
   - `SDA` to A4 (for most Arduino boards)

## Code Functionality

### `setup()`
- Initializes the serial communication at 115200 baud.
- Initializes the BNO055 sensor.
- Loads the calibration data from EEPROM and applies it to the sensor.
- Enables the external crystal for the BNO055 for improved timing accuracy.

### `loadCalibrationData()`
- Reads 22 bytes of calibration data from EEPROM starting at address `0`.
- Applies the calibration data to the sensor.
- Prints the loaded calibration data to the serial monitor for verification.

### `loop()`
- Continuously loads the calibration data and checks the current calibration status of the system.
- Prints the calibration status of the system, gyroscope, accelerometer, and magnetometer every 0.1 seconds.

## How to Use

1. **Upload**: Upload the code to your Arduino-compatible board.
2. **Serial Monitor**: Open the Serial Monitor at a baud rate of 115200 to view the calibration status and loaded calibration data.
3. **Sensor Calibration**: If the system is not fully calibrated, move the sensor as per the Adafruit BNO055 calibration instructions. Once fully calibrated, save the calibration data to EEPROM (a separate script might be needed for this step).

## Important Notes

- This code only reads calibration data from EEPROM. To save calibration data, you will need a separate script that writes the current sensor offsets to EEPROM after calibration.
- The delay times between loading calibration data and applying the offsets help ensure the sensor is properly initialized before calibration data is applied.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

## References

1. Adafruit BNO055 Sensor Library: [Adafruit GitHub Repository](https://github.com/adafruit/Adafruit_BNO055)
2. Arduino EEPROM Library: [Arduino Documentation](https://www.arduino.cc/en/Reference/EEPROM)
3. BNO055 Sensor Datasheet: [BNO055 Datasheet (PDF)](https://cdn-shop.adafruit.com/datasheets/BST_BNO055_DS000_12.pdf)
4. Adafruit BNO055 Calibration Guide: [Adafruit Learn Guide](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/device-calibration)