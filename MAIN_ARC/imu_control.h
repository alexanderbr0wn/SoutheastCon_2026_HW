#ifndef IMU_CONTROL_H
#define IMU_CONTROL_H

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <EEPROM.h>

extern Adafruit_BNO055 bno;

void initializeIMU();
float getYaw();
void loadAndApplyCalibrationData();
// void saveCalibrationData();

#endif
