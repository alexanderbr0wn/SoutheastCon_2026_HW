#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <EEPROM.h>

// Create BNO055 object
Adafruit_BNO055 bno = Adafruit_BNO055(55);

void setup() {
  Serial.begin(115200);
  
  // Initialize BNO055
  if (!bno.begin()) {
    Serial.print("Failed to start BNO055! Check wiring.");
    while (1);
  }
  
  delay(1000); // Time for sensor to settle
  
  // Load calibration data from EEPROM
  if (!loadCalibrationData()) {
    Serial.println("Calibration data not found or invalid.");
  }

  bno.setExtCrystalUse(true);
  Serial.println("BNO055 initialized.");
}

void loop() {
  // Get the sensor event for orientation
  sensors_event_t event;
  bno.getEvent(&event);

  // Get Euler angles (yaw, pitch, roll)
  float yaw = event.orientation.x;
  float pitch = event.orientation.y;
  float roll = event.orientation.z;

  // Output orientation in degrees
  Serial.print("Yaw: ");
  Serial.print(yaw);
  Serial.print(" Pitch: ");
  Serial.print(pitch);
  Serial.print(" Roll: ");
  Serial.println(roll);

  // Calculate forward/backward movement based on pitch angle
  if (pitch > 10) {
    Serial.println("Moving Forward");
  } else if (pitch < -10) {
    Serial.println("Moving Backward");
  } else {
    Serial.println("Stationary");
  }

  // Delay before the next reading
  delay(100);
}

// Function to load calibration data from EEPROM
bool loadCalibrationData() {
  uint8_t calibrationData[22]; // 22 bytes for calibration
  EEPROM.get(0, calibrationData); // Read from EEPROM
  
  // Apply the calibration data to the BNO055
  bno.setSensorOffsets(calibrationData);
  
  // Verify calibration data (this part may need adjusting)
  return verifyCalibration();
}

// Function to verify if the calibration is applied successfully
bool verifyCalibration() {
  uint8_t system, gyro, accel, mag;
  bno.getCalibration(&system, &gyro, &accel, &mag);
  Serial.print("System Calibration: ");
  Serial.println(system);
  return system >= 3; // Return true if system calibration is good (>= 3)
}
