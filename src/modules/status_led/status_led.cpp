#include "../../../include/modules/status_led/status_led.h"
#include "../../../include/config/board_config.h"
#include <Arduino.h>

void status_led_blink(int blinks_total){
    for(int blink = 0; blink < blinks_total; blink++){
        digitalWrite(status_led, HIGH);
        delay(50);
        digitalWrite(status_led, LOW);
        delay(150);
    }
}

void status_led_pulse(int blinks_total){
    for(int blink = 0; blink < blinks_total; blink++){
        for(int duty = 0; duty < 255; duty++){
            analogWrite(status_led, duty);
            delay(25);
        }
        for(int duty = 0; duty < 255; duty++){
            analogWrite(status_led, 225 - duty);
            delay(25);
        }
    }
}