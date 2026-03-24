#include "../include/modules/motors/motor.h"
#include "../include/config/board_config.h"
#include "../include/config/constants.h"
#include "../include/modules/sensors/sensor.h"
#include "../include/modules/controller/pid.h"
#include "../include/modules/imu/imu.h"

void left_90_corner(uint16_t * sensor_values, float_t * error){
    motor_brake(BRAKE_TIME_MILISECONDS);
    while (*sensor_values < LEFT_CENTER_TRESHOLD || *sensor_values > RIGHT_CENTER_TRESHOLD)
    {
      motorA(CORNER_SPEED);
      motorB(-CORNER_SPEED);
      sensor_read(sensor_values, error);
    }
}

void right_90_corner(uint16_t * sensor_values, float_t * error){
    motor_brake(BRAKE_TIME_MILISECONDS);
    while (*sensor_values < LEFT_CENTER_TRESHOLD || *sensor_values > RIGHT_CENTER_TRESHOLD)
    {
      motorA(-CORNER_SPEED);
      motorB(CORNER_SPEED);
      sensor_read(sensor_values, error);
    }
}

void no_line(){
  if(imu_avalible){
    //recovery procedure not implemented yet
    motorA(MIN_SPEED);
    motorB(MIN_SPEED);
  }else{
    motorA(MIN_SPEED);
    motorB(MIN_SPEED);
  }
}