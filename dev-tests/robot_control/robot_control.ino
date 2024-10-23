#include "robot_control.h"
#include "imu_control.h"

uint8_t MotorType = MOTOR_TYPE_JGB37_520_12V_110RPM;
uint8_t MotorEncoderPolarity = 0;

int8_t robot_stop[4] = {0, 0, 0, 0};

/**
 * @brief Initialize the motors for the robot.
 * 
 * This function sets up the motor type and encoder polarity using I2C communication.
 * It sends the motor type and encoder polarity configuration to the respective motor control hardware.
 */
void initializeMotors() {
    WireWriteDataArray(MOTOR_TYPE_ADDR, &MotorType, 1);
    delay(5);
    WireWriteDataArray(MOTOR_ENCODER_POLARITY_ADDR, &MotorEncoderPolarity, 1);
}

/**
 * @brief Write a data array to a specific I2C register.
 * 
 * This function sends a series of bytes to the specified I2C register address.
 * It is used to configure motor control registers over I2C.
 * 
 * @param reg The I2C register address to write to.
 * @param val Pointer to the data array to send.
 * @param len The length of the data array to write.
 * @return true if the transmission is successful, false otherwise.
 */
bool WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len) {
    Wire.beginTransmission(I2C_ADDR);
    Wire.write(reg);
    for (unsigned int i = 0; i < len; i++) {
        Wire.write(val[i]);
    }
    uint8_t error = Wire.endTransmission();
    return (error == 0);
}

/**
 * @brief Write a single byte to a specific I2C register.
 * 
 * This function sends a single byte to the specified I2C register address.
 * It is used for simple I2C write operations to the motor control hardware.
 * 
 * @param val The byte value to write.
 * @return true if the transmission is successful, false otherwise.
 */
bool WireWriteByte(uint8_t val) {
    Wire.beginTransmission(I2C_ADDR);
    Wire.write(val);
    uint8_t error = Wire.endTransmission();
    return (error == 0);
}

/**
 * @brief Control the robot's movement.
 * 
 * This function sends speed values to the motors and moves the robot in the specified direction.
 * It applies the left and right motor speeds, then stops the robot after the given duration.
 * 
 * @param movement Pointer to an array containing movement speed values.
 * @param left_speed Speed of the left motor.
 * @param right_speed Speed of the right motor.
 * @param duration Duration for which the robot will move before stopping (in milliseconds).
 */
void move_robot(int8_t *movement, int left_speed, int right_speed, unsigned long duration) {
    movement[0] = left_speed;
    movement[1] = right_speed;
    WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR, movement, 4);
    delay(duration);
    WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR, robot_stop, 4);
}

/**
 * @brief Stop the robot's movement.
 * 
 * This function stops all motors by sending zero speed values. It also delays for the specified duration 
 * to allow the stop command to take effect.
 * 
 * @param duration Duration to wait after stopping the robot (in milliseconds).
 */
void stop_robot(unsigned long duration) {
    WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR, robot_stop, 4);
    delay(duration);
}

/**
 * @brief Move the robot forward.
 * 
 * This function moves the robot forward by applying speed values to the left and right motors.
 * The movement lasts for the specified duration before stopping.
 * 
 * @param left_speed Speed of the left motor.
 * @param right_speed Speed of the right motor.
 * @param duration Duration to move the robot forward (in milliseconds).
 */
void move_forward(int left_speed, int right_speed, unsigned long duration) {
    int8_t movement[4] = {left_speed, right_speed, 0, 0};
    move_robot(movement, left_speed, right_speed, duration);
}

/**
 * @brief Move the robot backward.
 * 
 * This function moves the robot backward by reversing the speed values for the left and right motors.
 * The movement lasts for the specified duration before stopping.
 * 
 * @param left_speed Speed of the left motor.
 * @param right_speed Speed of the right motor.
 * @param duration Duration to move the robot backward (in milliseconds).
 */
void move_backward(int left_speed, int right_speed, unsigned long duration) {
    int8_t movement[4] = {left_speed, right_speed, 0, 0};
    move_robot(movement, -left_speed, -right_speed, duration);
}

/**
 * @brief Turn the robot to the left.
 * 
 * This function rotates the robot to the left by adjusting the left and right motor speeds.
 * It continuously checks the IMU's yaw value until the specified angle is reached, then stops the robot.
 * 
 * @param left_speed Speed of the left motor.
 * @param right_speed Speed of the right motor.
 * @param angle The angle (in degrees) to turn the robot.
 */
void turn_left(int left_speed, int right_speed, float angle) {
    Serial.println("Turn Left function with IMU called");

    // Get initial yaw and calculate target yaw
    float initial_yaw = getYaw();
    Serial.print("Initial Yaw: ");
    Serial.println(initial_yaw);

    float target_yaw = initial_yaw - angle;
    if (target_yaw < 0) target_yaw += 360;  // Handle wraparound at 0 degrees
    Serial.print("Target Yaw: ");
    Serial.println(target_yaw);

    // Define the movement array
    int8_t movement[4] = {left_speed, right_speed, 0, 0};

    // Command the robot to start turning left
    move_robot(movement, left_speed, -right_speed, 0);  // Start moving, no duration (IMU controls the stop)

    // Continuously monitor the yaw until the target is reached
    while (true) {
        float current_yaw = getYaw();
        Serial.print("Current Yaw: ");
        Serial.println(current_yaw);

        // Stop the robot when the yaw reaches the target, accounting for wraparound
        if ((initial_yaw >= target_yaw && current_yaw <= target_yaw) || 
            (initial_yaw < target_yaw && (current_yaw <= target_yaw || current_yaw >= initial_yaw))) {
            Serial.println("Target Yaw reached, stopping motors");
            stop_robot(500);  // Stop the robot after reaching the target
            break;
        }

        delay(10);  // Small delay for smooth control loop
    }

    Serial.println("Turn Left with IMU completed");
}

/**
 * @brief Turn the robot to the right.
 * 
 * This function rotates the robot to the right by adjusting the left and right motor speeds.
 * It continuously checks the IMU's yaw value until the specified angle is reached, then stops the robot.
 * 
 * @param left_speed Speed of the left motor.
 * @param right_speed Speed of the right motor.
 * @param angle The angle (in degrees) to turn the robot.
 */
void turn_right(int left_speed, int right_speed, float angle) {
    float initial_yaw = getYaw();
    float target_yaw = initial_yaw + angle;
    if (target_yaw >= 360) target_yaw -= 360;

    int8_t movement[4] = {left_speed, -right_speed, 0, 0};  // Set speeds for turning right
    move_robot(movement, left_speed, right_speed, 0);

    while (true) {
        float current_yaw = getYaw();

        // Check if the yaw has reached the target considering wraparound at 0/360
        if ((initial_yaw <= target_yaw && current_yaw >= target_yaw) || 
            (initial_yaw > target_yaw && (current_yaw >= target_yaw || current_yaw <= initial_yaw))) {
            break;
        }

        delay(10);  // Small delay for smooth control loop
    }

    //stop_robot(500);  // Stop the robot after reaching the target yaw
}
