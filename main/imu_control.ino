#include "imu_control.h"

#define calibrationSize 22
#define eeAddress 0

Adafruit_BNO055 bno = Adafruit_BNO055(55);

/**
 * @brief Load the IMU calibration data from EEPROM.
 * 
 * Reads the IMU calibration data from EEPROM and applies it to the sensor. 
 * This allows the system to retain calibration settings across power cycles.
 */
void initializeIMU() {
    if (!bno.begin()) {
        while (1);  // Loop indefinitely if BNO055 is not detected
    }
    bno.setExtCrystalUse(true);

    // Load and apply calibration data after initializing the IMU
    loadAndApplyCalibrationData();
}

/**
 * @brief Retrieves the current yaw angle from the IMU.
 * 
 * @return The yaw angle in degrees as a float.
 * 
 * This function reads the current yaw (orientation) data from the IMU sensor.
 */
float getYaw() {
    sensors_event_t event;
    bno.getEvent(&event);
    return event.orientation.x;
}

/**
 * @brief Load the IMU calibration data from EEPROM.
 * 
 * Reads the IMU calibration data from EEPROM and applies it to the sensor. 
 * This allows the system to retain calibration settings across power cycles.
 */
void loadAndApplyCalibrationData() {
    uint8_t calData[calibrationSize];

    // Read calibration data from EEPROM
    for (int i = 0; i < calibrationSize; i++) {
        calData[i] = EEPROM.read(eeAddress + i);
    }

    // Apply calibration data to BNO055
    bno.setSensorOffsets(calData);
    delay(500);  // Allow time for calibration to take effect
}

// /**
//  * @brief Save the IMU calibration data to EEPROM.
//  * 
//  * Saves the current IMU calibration offsets to EEPROM for later retrieval, 
//  * ensuring that the sensor remains calibrated after reboot.
//  */
// void saveCalibrationData() {
//     uint8_t calData[calibrationSize];

//     // Retrieve calibration data from BNO055
//     bno.getSensorOffsets(calData);

//     // Save calibration data to EEPROM
//     for (int i = 0; i < calibrationSize; i++) {
//         EEPROM.update(eeAddress + i, calData[i]);
//     }
// }