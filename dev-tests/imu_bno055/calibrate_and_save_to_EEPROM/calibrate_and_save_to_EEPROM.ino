#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <EEPROM.h>

#define calibrationSize 22
#define eeAddress 0

Adafruit_BNO055 myIMU = Adafruit_BNO055();

void setup() {
  Serial.begin(115200);
  myIMU.begin();
  delay(1000);

  loadCalibrationData();

  myIMU.setExtCrystalUse(true);
}

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

void saveCalibrationData() {
  uint8_t calData[calibrationSize];
  myIMU.getSensorOffsets(calData);

  for (int i = 0; i < calibrationSize; i++) {
    EEPROM.update(eeAddress + i, calData[i]);
  }
  Serial.println("Calibration data saved to EEPROM.");
}

void loop() {
  uint8_t system, gyro, accel, mag;
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
    Serial.println("System fully calibrated! Saving calibration data.");
    saveCalibrationData();
  } else {
    Serial.println("System NOT fully calibrated. Data not saved.");
  }

  delay(100);
}
