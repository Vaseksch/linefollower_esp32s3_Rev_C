#ifndef IMU_H
#define IMU_H

#define IMU_ADDRESS 0x68

extern bool imu_avalible;

void imu_init();
float imu_get_orientation();

#endif