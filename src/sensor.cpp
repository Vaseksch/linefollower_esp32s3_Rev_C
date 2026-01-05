#include "../lib/sensor.h"
#include "../lib/board_config.h"
#include <Arduino.h>
#include <stdint.h>

#define SENSOR_COUNT 11

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
const int sensor_position_weight[11] = {-8, -6, -4, -3, -1, 0, 1, 3, 4, 6, 8};
int sensor_treshold[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


void sensor_read(uint16_t *sensor_values, int *error){
    *sensor_values = 0;
    int32_t num = 0;
    int32_t den = 0;

    for(uint_fast8_t sensor = 0; sensor < SENSOR_COUNT; sensor++){
        int sensor_filtered_value = sensor_treshold[sensor] - analogReadRaw(sensors_pin[sensor]);
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
    Serial.println("Calibration: place robot on white surface and press button SW1 on the board");
    while(!digitalRead(switch_1));

    digitalWrite(sensor_led, HIGH);
    delay(100);

    for(int sensor = 0; sensor < SENSOR_COUNT; sensor++){
        for(int read = 0; read < 3; read++){
            sensor_treshold[sensor] += analogReadRaw(sensors_pin[sensor]);
            delay(15);
        }
        sensor_treshold[sensor] = sensor_treshold[sensor] / 6;
        Serial.println(sensor_treshold[sensor]);
    }

    delay(10);
    digitalWrite(sensor_led, LOW);
    Serial.print("Calibration complete.");
    status_led_blink(2);
}