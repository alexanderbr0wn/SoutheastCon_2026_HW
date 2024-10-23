#include "robot_control.h"

uint8_t MotorType = MOTOR_TYPE_JGB37_520_12V_110RPM;
uint8_t MotorEncoderPolarity = 0;

int8_t robot_forward[4] = {23, 23, 0, 0};
int8_t robot_backward[4] = {-23, -23, 0, 0};
int8_t robot_turn_left[4] = {20, -20, 0, 0};
int8_t robot_turn_right[4] = {-20, 20, 0, 0};
int8_t robot_stop[4] = {0, 0, 0, 0};

bool WireWriteByte(uint8_t val)
{
    Wire.beginTransmission(I2C_ADDR);
    Wire.write(val);
    return Wire.endTransmission() == 0;
}

bool WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len)
{
    Wire.beginTransmission(I2C_ADDR);
    Wire.write(reg);
    for (unsigned int i = 0; i < len; i++)
    {
        Wire.write(val[i]);
    }
    return Wire.endTransmission() == 0;
}

void initializeMotors()
{
    WireWriteDataArray(MOTOR_TYPE_ADDR, &MotorType, 1);
    delay(5);
    WireWriteDataArray(MOTOR_ENCODER_POLARITY_ADDR, &MotorEncoderPolarity, 1);
}

void move_robot(int8_t *movement, unsigned long duration)
{
    WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR, movement, 4);
    delay(duration);
    WireWriteDataArray(MOTOR_FIXED_SPEED_ADDR, robot_stop, 4);
}
