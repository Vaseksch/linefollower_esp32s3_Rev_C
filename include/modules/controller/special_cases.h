#ifndef SPECIAL_CASES_H
#define SPECIAL_CASES_H

#include <stdint.h>

void left_90_corner(uint16_t * sensor_values, int * error);
void right_90_corner(uint16_t * sensor_values, int * error);
void slow_straight();

#endif