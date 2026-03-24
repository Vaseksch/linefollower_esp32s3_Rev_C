#ifndef IMU_H
#define IMU_H

#include <math.h>

#define IMU_ADDRESS 0x68
#define IMU_KP 1
#define IMU_KI 0.2

extern bool imu_avalible;

void imu_init();
void calibrate_imu();
float imu_get_orientation();
void imu_steer(float_t angle);

#endif