#include "../include/modules/imu/imu.h"
#include <Wire.h>
#include <TinyMPU6050.h>

MPU6050 mpu(Wire);

void imu_init(bool imu_avalible){
    if(imu_avalible){
        Serial.println("initializing IMU");
        mpu.Initialize();
        Serial.println("Calibrating IMU");
        mpu.Calibrate();
        Serial.println("IMU calibration complete");
    }
}

float get_orientation(){
    mpu.Execute();
    return mpu.GetAngGyroX();
}