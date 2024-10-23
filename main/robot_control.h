#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H

#include <Wire.h>

#define I2C_ADDR        0x34

#define MOTOR_TYPE_ADDR               20
#define MOTOR_ENCODER_POLARITY_ADDR   21
#define MOTOR_FIXED_SPEED_ADDR        51

#define MOTOR_TYPE_JGB37_520_12V_110RPM   3

extern uint8_t MotorType;
extern uint8_t MotorEncoderPolarity;

extern int8_t robot_stop[4];

bool WireWriteByte(uint8_t val);
bool WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len);
void initializeMotors();
void move_robot(int8_t *movement, int8_t left_speed, int8_t right_speed, unsigned long duration);
void stop_robot(unsigned long duration);
void move_forward(int8_t left_speed, int8_t right_speed, unsigned long duration);
void move_backward(int8_t left_speed, int8_t right_speed, unsigned long duration);
void turn_left(int8_t left_speed, int8_t right_speed, unsigned long duration);
void turn_right(int8_t left_speed, int8_t right_speed, unsigned long duration);

#endif
