#include "../include/modules/imu/imu.h"
#include "../include/utils/i2c_manager/i2c_manager.h"
#include "../include/config/constants.h"
#include <Wire.h>
#include <TinyMPU6050.h>

MPU6050 mpu(Wire);

bool imu_avalible = false;

void imu_init(){
    imu_avalible = probe_i2c_device(IMU_ADDRESS);

    if(imu_avalible){
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
    if(imu_avalible){
        mpu.Execute();
        return mpu.GetAngGyroX();
    }else{
        Serial.println("ERROR: IMU not avalible.");
        return 0;
    }
}