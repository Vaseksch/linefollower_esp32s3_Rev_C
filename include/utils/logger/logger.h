#ifndef LOGGER_H
#define LOGGER_H

#include <math.h>
#include "../include/config/constants.h"

class Logger {
public:
    void logger_init();
    void log_flag(char32_t * new_flag);
    void log_pid(double_t * new_inserted_at, float_t * new_error, float_t * new_correction, float_t * derivative, int32_t * new_motor_a_speed, int32_t * new_motor_b_speed);
    void stream_data();
};

#endif