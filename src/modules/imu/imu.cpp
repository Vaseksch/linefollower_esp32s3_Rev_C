#include "../include/modules/imu/imu.h"
#include "../include/utils/i2c_manager/i2c_manager.h"
#include "../include/config/constants.h"
#include "../include/modules/motors/motor.h"
#include <Wire.h>
#include <TinyMPU6050.h>

MPU6050 mpu(Wire);

bool imu_avalible = false;

void imu_init(){
    imu_avalible = probe_i2c_device(IMU_ADDRESS);

    if(imu_avalible){
        Serial.println("initializing IMU");
        mpu.Initialize();
        Serial.println("IMU avalible.");
    }else{
        Serial.println("IMU not avalible.");
    }
}

void calibrate_imu(){
    if(imu_avalible){
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

void imu_steer(float_t angle){
    float_t new_angle;
    float_t initial_orientarion = imu_get_orientation();
    float_t error = (initial_orientarion + angle) - initial_orientarion;
    float_t integral;
    float_t last_error;
    float_t correction;
    int32_t motor_a_speed;
    int32_t motor_b_speed;


    while(imu_avalible && abs(error) > 1){
    new_angle = imu_get_orientation();
    error = (initial_orientarion - angle) - new_angle;

    if (error > 180)  error -= 360;
    if (error < -180) error += 360;

    integral += last_error;
    integral = constrain(integral, -MIN_SPEED, MIN_SPEED);
    last_error = error;

    correction = (IMU_KP * error) + (IMU_KI * integral);

    motor_a_speed =   +correction;
    motor_b_speed =   -correction;

    motor_a_speed = constrain(motor_a_speed, -MIN_SPEED, MIN_SPEED);
    motor_b_speed = constrain(motor_b_speed, -MIN_SPEED, MIN_SPEED);

    motorA(motor_a_speed);
    motorB(motor_b_speed); 
    }
}
