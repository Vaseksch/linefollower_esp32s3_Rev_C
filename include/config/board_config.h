#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

extern const int esp_sda;
extern const int esp_scl;

extern const int analog_0;
extern const int analog_1;
extern const int analog_2;
extern const int analog_3;
extern const int analog_4;
extern const int analog_5;
extern const int analog_6;
extern const int analog_7;
extern const int analog_8;
extern const int analog_9;
extern const int analog_10;

extern const int motor_standby;

extern const int motor_a_1;
extern const int motor_a_2;
extern const int motor_a_pwm;

extern const int motor_b_1;
extern const int motor_b_2;
extern const int motor_b_pwm;

extern const int sensor_led;
extern const int status_led;

extern const int switch_1;
extern const int switch_2;

void pin_setup();
void config_complete();
void adc_init();

#endif