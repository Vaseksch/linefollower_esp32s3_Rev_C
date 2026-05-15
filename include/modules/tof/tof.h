#ifndef TOF_H
#define TOF_H

#include <math.h>
#include "../include/config/constants.h"
#include <SparkFun_VL53L5CX_Library.h>

#define TOF_ADDRESS 0x29

extern bool tof_sensor_avalible;

class Tof {
public:
    SparkFun_VL53L5CX sensor;
    VL53L5CX_ResultsData measurementData;

    bool object_detected;
    int depth_map[8][8];
    int edge_map[8][8];
    int imageResolution;
    int imageWidth;
    
    void tof_init();
    void get_image();
};

#endif