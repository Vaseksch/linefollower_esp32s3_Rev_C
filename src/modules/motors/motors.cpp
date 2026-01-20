#include <Arduino.h>
#include "../include/modules/motors/motor.h"
#include "../include/config/board_config.h"

#define MOTOR_A_CHANNEL 2
#define MOTOR_B_CHANNEL 3

void motor_init()
{
    ledcSetup(2, 20000, 8);
    ledcSetup(3, 20000, 8);

    digitalWrite(motor_a_1, LOW);
    digitalWrite(motor_a_2, LOW);

    digitalWrite(motor_b_1, LOW);
    digitalWrite(motor_b_2, LOW);

    ledcAttachPin(motor_a_pwm, MOTOR_A_CHANNEL);
    ledcAttachPin(motor_b_pwm, MOTOR_B_CHANNEL);
}

void motorA(int speed)
{

    int pwm = speed >= 0 ? speed : -speed;
    pwm = (pwm * 255) / 100;

    if (speed >= 0)
    {
        digitalWrite(motor_a_1, HIGH);
        digitalWrite(motor_a_2, LOW);

        ledcWrite(MOTOR_A_CHANNEL, pwm);
    }
    else
    {
        digitalWrite(motor_a_1, LOW);
        digitalWrite(motor_a_2, HIGH);

        ledcWrite(MOTOR_A_CHANNEL, pwm);
    }
}

void motorB(int speed)
{

    int pwm = speed >= 0 ? speed : -speed;
    pwm = (pwm * 255) / 100;

    if (speed >= 0)
    {
        digitalWrite(motor_b_1, HIGH);
        digitalWrite(motor_b_2, LOW);

        ledcWrite(MOTOR_B_CHANNEL, pwm);
    }
    else
    {
        digitalWrite(motor_b_1, LOW);
        digitalWrite(motor_b_2, HIGH);

        ledcWrite(MOTOR_B_CHANNEL, pwm);
    }
}

void motor_brake(int miliseconds)
{
    digitalWrite(motor_a_1, HIGH);
    digitalWrite(motor_a_2, HIGH);
    ledcWrite(MOTOR_A_CHANNEL, 255);

    digitalWrite(motor_b_1, HIGH);
    digitalWrite(motor_b_2, HIGH);
    ledcWrite(MOTOR_B_CHANNEL, 255);

    delay(miliseconds);
}