#include "../include/utils/i2c_manager/i2c_manager.h"
#include <Wire.h>
#include <Arduino.h>

bool probe_i2c_device(int address){
    Wire.beginTransmission(address);
        uint8_t err = Wire.endTransmission();
        Serial.print("I2C device: 0x");
        Serial.print(address, HEX);
        Serial.print(" response: ");
        Serial.println(err);

    if(err == 0){
        return true;
    }else{
        return false;
    }
}