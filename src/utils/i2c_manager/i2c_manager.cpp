#include <Wire.h>

bool probe_i2c_device(int address){
    Wire.beginTransmission(address);
        uint8_t err = Wire.endTransmission();

    if(err == 0){
        return true;
    }else{
        return false;
    }
}