#ifndef MOTOR_H
#define MOTOR_H


void motor_init();
void motorA(int speed);
void motorB(int speed);
void motor_brake(int miliseconds);
void full_stop();

#endif