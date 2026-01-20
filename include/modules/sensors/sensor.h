#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

void sensor_read(uint16_t *, int *);
void calibrate_sensor();

#endif