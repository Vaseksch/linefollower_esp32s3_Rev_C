#ifndef PID_H
#define PID_H

#include <stdint.h>

void get_delta();
void pid(int32_t * error);

#endif