#include "../include/config/constants.h"
#include "../include/modules/motors/motor.h"
#include "../include/config/board_config.h"
#include "../include/utils/logger/logger.h"
#include <Arduino.h>

int sampling_interval = 1000000 / SAMPLE_RATE_HZ;
int sample_count = 0;

double_t log_inserted_at[MAX_SAMPLES];
float_t log_error[MAX_SAMPLES];
float_t log_correction[MAX_SAMPLES];
float_t log_derivative[MAX_SAMPLES];
int32_t log_motor_a_speed[MAX_SAMPLES];
int32_t log_motor_b_speed[MAX_SAMPLES];
char32_t flag[MAX_SAMPLES];

void Logger::logger_init()
{
    for (int sample = 0; sample < MAX_SAMPLES; sample++)
    {
        log_inserted_at[sample] = 0;
        log_error[sample] = 0;
        log_correction[sample] = 0;
        log_motor_a_speed[sample] = 0;
        log_motor_b_speed[sample] = 0;
        flag[sample] = ' ';
    }
    sample_count = 0;
    Serial.println("logger init complete");
}

void Logger::log_flag(char32_t *new_flag)
{
    flag[sample_count] = *new_flag;
}

void Logger::stream_data()
{
    Serial.println("data_start");
    for (int sample = 0; sample < MAX_SAMPLES; sample++)
    {
        Serial.print(log_inserted_at[sample]);
        Serial.print(";");
        Serial.print(log_error[sample]);
        Serial.print(";");
        Serial.print(log_correction[sample]);
        Serial.print(";");
        Serial.print(log_derivative[sample]);
        Serial.print(";");
        Serial.print(log_motor_a_speed[sample]);
        Serial.print(";");
        Serial.print(log_motor_b_speed[sample]);
        Serial.print(";");
        Serial.println(flag[sample]);
    }
    Serial.println("data_end");
    sample_count = 0;
}

void Logger::log_pid(
    double_t *new_log_inserted_at,
    float_t *new_error,
    float_t *new_log_correction,
    float_t *new_log_derivative,
    int32_t *new_log_motor_a_speed,
    int32_t *new_log_motor_b_speed
    )
{
    if (sample_count < MAX_SAMPLES)
    {
        if ((*new_log_inserted_at - log_inserted_at[sample_count - 1]) > sampling_interval)
        {
            log_inserted_at[sample_count] = *new_log_inserted_at;
            log_error[sample_count] = *new_error;
            log_correction[sample_count] = *new_log_correction;
            log_derivative[sample_count] = *new_log_derivative;
            log_motor_a_speed[sample_count] = *new_log_motor_a_speed;
            log_motor_b_speed[sample_count] = *new_log_motor_b_speed;
            sample_count++;
        }
    }
    else
    {
        full_stop();
        Serial.println("logger full, press SW3 to stream data");
        while (!digitalRead(switch_2))
            ;
        stream_data();
        Serial.println("press SW3 to continue");
        while (!digitalRead(switch_2))
            ;
    }
}