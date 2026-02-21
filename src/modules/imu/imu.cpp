#include "../include/modules/imu/imu.h"
#include "../include/config/constants.h"
#include <Wire.h>
#include <TinyMPU6050.h>

MPU6050 mpu(Wire);

void imu_init(){
    if(IMU_AVALIBLE){
        Serial.println("initializing IMU");
        mpu.Initialize();
        Serial.println("Calibrating IMU");
        mpu.Calibrate();
        Serial.println("IMU calibration complete");
    }else{
        Serial.println("IMU not avalible.");
    }
}

float imu_get_orientation(){
    if(IMU_AVALIBLE){
        mpu.Execute();
        return mpu.GetAngGyroX();
    }else{
        Serial.println("ERROR: IMU not avalible.");
        return 0;
    }
}