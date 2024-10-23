#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <EEPROM.h>

#define calibrationSize 22
#define eeAddress 0

Adafruit_BNO055 myIMU = Adafruit_BNO055();

/**
 * @brief Setup for initializing the BNO055 sensor and applying saved calibration data.
 * 
 * This function initializes the BNO055 sensor, loads calibration data from EEPROM, 
 * applies it to the sensor, and enables the external crystal for improved accuracy.
 * It also sets up serial communication at a baud rate of 115200.
 */
void setup() {
  Serial.begin(115200);

  if (!myIMU.begin()) {
    Serial.println("Failed to initialize BNO055! Check your wiring.");
    while (1);
  }
  delay(2000);
  loadCalibrationData();
  myIMU.setExtCrystalUse(true);
  delay(500);  
}

/**
 * @brief Loads calibration data from EEPROM and applies it to the BNO055 sensor.
 * 
 * This function reads 22 bytes of calibration data from the EEPROM, starting at address 0,
 * and applies it to the BNO055 sensor. It prints the loaded calibration data to the
 * Serial monitor for verification.
 */
void loadCalibrationData() {
  uint8_t calData[calibrationSize];

  for (int i = 0; i < calibrationSize; i++) {
    calData[i] = EEPROM.read(eeAddress + i);
  }

  Serial.println("Calibration data loaded from EEPROM:");
  for (int i = 0; i < calibrationSize; i++) {
    Serial.print("Byte ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(calData[i]);
  }

  myIMU.setSensorOffsets(calData);
  delay(500);
  Serial.println("Calibration data applied to BNO055.");
}

/**
 * @brief Main loop to check and display the current calibration status of the BNO055 sensor.
 * 
 * This function reads the calibration data from the EEPROM, applies it to the BNO055 sensor,
 * and then checks the calibration status of the system, gyroscope, accelerometer, and magnetometer.
 * The status is printed to the Serial monitor every 0.1 seconds.
 */
void loop() {
  uint8_t system, gyro, accel, mag;
  
  uint8_t calData[calibrationSize];
  for (int i = 0; i < calibrationSize; i++) {
    calData[i] = EEPROM.read(eeAddress + i);
  }
  myIMU.setSensorOffsets(calData);

  myIMU.getCalibration(&system, &gyro, &accel, &mag);

  Serial.print("S: ");
  Serial.print(system);
  Serial.print(" | G: ");
  Serial.print(gyro);
  Serial.print(" | A: ");
  Serial.print(accel);
  Serial.print(" | M: ");
  Serial.println(mag);

  if (system == 3 && gyro == 3 && accel == 3 && mag == 3) {
    Serial.println("System is fully calibrated.");
  } else {
    Serial.println("System is NOT fully calibrated.");
  }

  delay(100);
}
