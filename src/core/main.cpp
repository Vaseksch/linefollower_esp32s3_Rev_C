#include <Wire.h>
#include <math.h>
#include <TinyMPU6050.h>
#include "../include/config/board_config.h"
#include "../include/modules/sensors/sensor.h"
#include "../include/modules/motors/motor.h"
#include "../include/modules/controller/special_cases.h"
#include "../include/modules/controller/pid.h"
#include "../include/modules/imu/imu.h"
#include "../include/modules/display/display.h"
#include "../include/modules/board/buttons.h"
#include "../include/utils/logger/logger.h"
#include "../include/config/constants.h"


uint16_t sensor_values = 0;
float_t error = 0;
double_t start_time;

void setup()
{
  comms_init();
  hardware_init();
  peripherals_init();
  init_complete();

  if(LOGGING){
    logger.logger_init();
  }

  calibrate_sensor();
  calibration_complete_screen();

  Serial.println("press button SW1 on ");
  wait_for_button(switch_1);
  digitalWrite(sensor_led, HIGH);

  while (DEBUG_MODE)
  {
    sensor_read(&sensor_values, &error);
    //Serial.println(sensor_values, BIN);
  }
}

void loop()
{
  sensor_read(&sensor_values, &error);

  switch (sensor_values)
  {
  case NO_LINE:
    forward_slow();
    break;

  case LEFT_EDGE:
    left_90_corner(&sensor_values, &error);
    break;

  case RIGHT_EDGE:
    right_90_corner(&sensor_values, &error);
    break;

  default:
    pid_control(&error);
    break;
  }
}
