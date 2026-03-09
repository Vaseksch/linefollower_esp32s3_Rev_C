#include "../include/modules/sensors/sensor.h"
#include "../include/modules/status_led/status_led.h"
#include "../include/modules/display/display.h"
#include "../include/modules/motors/motor.h"
#include "../include/config/board_config.h"
#include "../include/config/constants.h"
#include <Arduino.h>
#include <stdint.h>

const int sensor_count = 9;
const int sensors_pin[11] = {
    analog_0,
    analog_1,
    analog_2,
    analog_3,
    analog_4,
    analog_5,
    analog_6,
    analog_7,
    analog_8,
    analog_9,
    analog_10
};
const int sensor_position_weight[11] = {-16, -8, -4, -2, -1, 0, 1, 2, 4, 8, 16};
int sensor_treshold[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int sensor_raw_value[11];
int sensor_max_value[11];
int sensor_min_value[11];


void sensor_read(uint16_t *sensor_values, int *error){
    *sensor_values = 0;
    int32_t num = 0;
    int32_t den = 0;

    for(uint_fast8_t sensor = 0; sensor < SENSOR_COUNT; sensor++){
        sensor_raw_value[sensor] = analogRead(sensors_pin[sensor]);
        if(sensor < SENSOR_COUNT - 1){
            Serial.print(sensor_raw_value[sensor]);
            Serial.print(";");
        }else{
           Serial.println(sensor_raw_value[sensor]);
        }
        int sensor_filtered_value = sensor_treshold[sensor] - sensor_raw_value[sensor];
        if(sensor_filtered_value > 0){
            *sensor_values = *sensor_values | (1 << sensor);
            num += sensor_filtered_value * sensor_position_weight[sensor];
            den += sensor_filtered_value;
        }
    }
    if(den > 0){
        *error = num / den;
    }
}

void calibrate_sensor(){
    press_sw2_screen();
    Serial.println("Calibration: place robot on the calibration pad and press button SW1 on the board");
    while(!digitalRead(switch_1));
    
    wait_screen();
    digitalWrite(sensor_led, HIGH);
    delay(100);

    for(int sensor = 0; sensor < SENSOR_COUNT; sensor++){
        for(int read = 0; read < SENSOR_CALIBRATION_READING_COUNT; read++){
            sensor_min_value[sensor] += analogRead(sensors_pin[sensor]);
            delay(15);
        }
        sensor_min_value[sensor] = sensor_min_value[sensor] / SENSOR_CALIBRATION_READING_COUNT;
    }

    motorA(-15);
    motorB(-15);
    delay(500);
    full_stop();

    for(int sensor = 0; sensor < SENSOR_COUNT; sensor++){
        for(int read = 0; read < SENSOR_CALIBRATION_READING_COUNT; read++){
            sensor_max_value[sensor] += analogRead(sensors_pin[sensor]);
            delay(15);
        }
        sensor_max_value[sensor] = sensor_max_value[sensor] / SENSOR_CALIBRATION_READING_COUNT;
        sensor_treshold[sensor] = (sensor_max_value[sensor] - sensor_min_value[sensor]) / 2;
        Serial.print("sensor: ");
        Serial.print(sensor);
        Serial.print(" | min: ");
        Serial.print(sensor_min_value[sensor]);
        Serial.print(" | max: ");
        Serial.print(sensor_max_value[sensor]);
        Serial.print(" | treshold: ");
        Serial.println(sensor_treshold[sensor]);
    }

    delay(10);
    digitalWrite(sensor_led, LOW);
    Serial.println("Calibration complete.");
    status_led_blink(2);
}