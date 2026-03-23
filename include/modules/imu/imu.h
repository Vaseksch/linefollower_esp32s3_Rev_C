#ifndef IMU_H
#define IMU_H

#define IMU_ADDRESS 0x68

void imu_init();
float imu_get_orientation();

#endif