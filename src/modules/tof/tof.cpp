#include <math.h>
#include "../include/config/constants.h"
#include "../include/utils/i2c_manager/i2c_manager.h"
#include "../include/modules/tof/tof.h"
#include <SparkFun_VL53L5CX_Library.h>

bool tof_sensor_avalible = false;

void Tof::tof_init()
{
    if(!probe_i2c_device(TOF_ADDRESS)){
        Serial.println(F("Tof sensor not avalible"));
        return;
    }
    for (int retry = 0; retry < 3 && tof_sensor_avalible == false; retry++)
    {
        if (Tof::sensor.begin() == false)
        {
            tof_sensor_avalible = false;
        }
        else
        {
            tof_sensor_avalible = true;
            sensor.setResolution(8 * 8); // Enable all 64 pads
            imageResolution = sensor.getResolution(); // Query sensor for current resolution - either 4x4 or 8x8
            imageWidth = sqrt(imageResolution);       // Calculate printing width
            sensor.setRangingFrequency(15);
            sensor.startRanging();
            Serial.println(F("Tof sensor avalible"));
            return;
        }
        Serial.println(F("Tof sensor not avalible"));
        delay(300);
    }
}

void Tof::get_image()
{
    if (tof_sensor_avalible && sensor.isDataReady())
    {
        if (sensor.getRangingData(&measurementData))
        {
            Serial.println(measurementData.distance_mm[0]);
        }
    }
}