#ifndef SPECIAL_CASES_H
#define SPECIAL_CASES_H

#define NO_LINE 0b00000000000
#define RIGHT_EDGE 0b10000000000
#define LEFT_EDGE 0b00000000001

#include <stdint.h>

void left_90_corner(uint16_t * sensor_values, float_t * error);
void right_90_corner(uint16_t * sensor_values, float_t * error);
void no_line();

#endif