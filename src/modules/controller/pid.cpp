#include "../include/modules/motors/motor.h"
#include "../include/config/board_config.h"
#include "../include/config/constants.h"
#include "../include/modules/sensors/sensor.h"
#include <Arduino.h>

unsigned long new_time = 0;
unsigned long old_time = 0;
unsigned long dt = 0;

int32_t last_error = 0;
float_t integral = 0;
int16_t derivative = 0;

int32_t correction;

int32_t speed;
int32_t motor_a_speed;
int32_t motor_b_speed;


void pid_control(int32_t * error){
    new_time = millis();
    dt = (new_time - old_time) / 1000;
    old_time = new_time;

    derivative = (*error - last_error) / dt;

    correction = (KP * *error) + (KD * derivative);

    last_error = *error;

    motor_a_speed = BASE_SPEED - correction;
    motor_b_speed = BASE_SPEED + correction;

    motor_a_speed = constrain(motor_a_speed, -MAX_SPEED, MAX_SPEED);
    motor_b_speed = constrain(motor_b_speed, -MAX_SPEED, MAX_SPEED);

    motorA(motor_a_speed);
    motorB(motor_b_speed);
}