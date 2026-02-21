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
#include "../include/utils/logger/logger.h"
#include "../include/config/constants.h"


uint16_t sensor_values = 0;
int32_t error = 0;

void setup()
{
  pin_setup();
  motor_init();
  adc_init();
  Wire.begin(esp_sda, esp_scl);
  oled_begin();
  Serial.begin(115200);
  config_complete();
  calibrate_sensor();
  imu_init();
  calibration_complete_screen();

  Serial.println("press button SW1 on ");
  while (!digitalRead(switch_1))
    ;
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
  case 0:
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
