#include "../../../include/modules/board/buttons.h"
#include <Arduino.h>

void wait_for_button(int pin){
    while (!digitalRead(pin))
    ;
}