#include "../include/config/board_config.h"
#include <Arduino.h>


const int esp_sda = 1;
const int esp_scl = 2;

const int analog_0 = 7;
const int analog_1 = 15;
const int analog_2 = 16;
const int analog_3 = 17;
const int analog_4 = 3;
const int analog_5 = 9;
const int analog_6 = 10;
const int analog_7 = 11;
const int analog_8 = 12;
const int analog_9 = 13;
const int analog_10 = 14;

const int motor_standby = 42;

const int motor_a_1 = 18;
const int motor_a_2 = 8;
const int motor_a_pwm = 6;

const int motor_b_1 = 39;
const int motor_b_2 = 38;
const int motor_b_pwm = 4;


const int sensor_led = 47;
const int status_led = 5;

const int switch_1 = 40;
const int switch_2 = 41;

void pin_setup(){
    pinMode(motor_standby, OUTPUT);
    pinMode(motor_a_1, OUTPUT);
    pinMode(motor_a_2, OUTPUT);
    pinMode(motor_a_pwm, OUTPUT);
    pinMode(motor_b_1, OUTPUT);
    pinMode(motor_b_2, OUTPUT);
    pinMode(motor_b_pwm, OUTPUT);

    pinMode(status_led, OUTPUT);
    pinMode(sensor_led, OUTPUT);

    pinMode(analog_0, INPUT);
    pinMode(analog_1, INPUT);
    pinMode(analog_2, INPUT);
    pinMode(analog_3, INPUT);
    pinMode(analog_4, INPUT);
    pinMode(analog_5, INPUT);
    pinMode(analog_6, INPUT);
    pinMode(analog_7, INPUT);
    pinMode(analog_8, INPUT);
    pinMode(switch_1, INPUT);
    pinMode(switch_2, INPUT);

    digitalWrite(motor_a_1, LOW);
    digitalWrite(motor_a_2, LOW);
    digitalWrite(motor_b_1, LOW);
    digitalWrite(motor_b_2, LOW);
    digitalWrite(motor_standby, HIGH);
}

void config_complete(){
    status_led_blink(3);
    delay(1000);
    Serial.println("Configuration complete");
}

void adc_init()
{
    analogReadResolution(8);
    analogSetAttenuation(ADC_0db);
}

void status_led_blink(int blinks_total){
    for(int blink = 0; blink < blinks_total; blink++){
        digitalWrite(status_led, HIGH);
        delay(50);
        digitalWrite(status_led, LOW);
        delay(150);
    }
}