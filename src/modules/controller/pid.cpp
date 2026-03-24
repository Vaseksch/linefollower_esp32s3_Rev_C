#include "../include/modules/motors/motor.h"
#include "../include/config/board_config.h"
#include "../include/config/constants.h"
#include "../include/modules/sensors/sensor.h"
#include "../include/modules/imu/imu.h"
#include "../include/utils/logger/logger.h"
#include <Arduino.h>

double_t new_time = 0;
double_t old_time = 0;
float_t dt = 0;

float_t last_error = 0;
float_t integral = 0;
float_t derivative = 0;
float_t last_derivative = 0;

float_t correction;

float_t speed;
int32_t motor_a_speed;
int32_t motor_b_speed;


void pid_control(float_t * error){
    new_time = micros();
    dt = (new_time - old_time) * 10e-6;
    old_time = new_time;

    derivative = (*error - last_error) / dt;
    derivative = (1.0f - DERIVATIVE_FILTER_RATIO) * derivative + DERIVATIVE_FILTER_RATIO * last_derivative;

    correction = (KP * *error) + (KD * derivative);

    last_error = *error;
    last_derivative = derivative;

    motor_a_speed = BASE_SPEED - correction;
    motor_b_speed = BASE_SPEED + correction;

    motor_a_speed = constrain(motor_a_speed, -MAX_SPEED, MAX_SPEED);
    motor_b_speed = constrain(motor_b_speed, -MAX_SPEED, MAX_SPEED);

    motorA(motor_a_speed);
    motorB(motor_b_speed);

    if(LOGGING){
        logger.log_pid(&new_time, error, &correction, &derivative, &motor_a_speed, &motor_b_speed);
    }
}