#include <Wire.h>
#include <math.h>
#include <TinyMPU6050.h>
#include "../lib/board_config.h"
#include "../lib/sensor.h"
#include "../lib/motor.h"
#include "../lib/logger.h"
#include "../lib/constants.h"

MPU6050 mpu(Wire);

int32_t last_error = 0;
float_t integral = 0;
int16_t derivative = 0;

uint16_t sensor_values = 0;
int32_t error = 0;


void setup()
{
  pin_setup();
  motor_init();
  adc_init();
  Serial.begin(115200);

  config_complete();
  calibrate_sensor();

  Wire.begin(esp_sda, esp_scl);

  Serial.println("press button SW1 on ");
  while (!digitalRead(switch_1))
    ;
  digitalWrite(sensor_led, HIGH);
  while (DEBUG_MODE)
  {
    sensor_read(&sensor_values, &error);
    Serial.println(sensor_values, BIN);
  }
}

void loop()
{
  sensor_read(&sensor_values, &error);
  if (sensor_values == LEFT_EDGE)
  {
    motor_brake(BRAKE_TIME_MILISECONDS);
    while (sensor_values < LEFT_CENTER_TRESHOLD || sensor_values > RIGHT_CENTER_TRESHOLD)
    {
      motorA(CORNER_SPEED);
      motorB(-CORNER_SPEED);
      sensor_read(&sensor_values, &error);
    }
  }
  else if (sensor_values == RIGHT_EDGE)
  {
    motor_brake(BRAKE_TIME_MILISECONDS);
    while (sensor_values < LEFT_CENTER_TRESHOLD || sensor_values > RIGHT_CENTER_TRESHOLD)
    {
      motorA(-CORNER_SPEED);
      motorB(CORNER_SPEED);
      sensor_read(&sensor_values, &error);
    }
  }
  else
  {
    derivative = (error - last_error);

    int correction = (KP * error) + (KD * derivative);

    last_error = error;

    int motor_a_speed = BASE_SPEED - correction;
    int motor_b_speed = BASE_SPEED + correction;

    motor_a_speed = constrain(motor_a_speed, -MAX_SPEED, MAX_SPEED);
    motor_b_speed = constrain(motor_b_speed, -MAX_SPEED, MAX_SPEED);

    motorA(motor_a_speed);
    motorB(motor_b_speed);
  }
}
