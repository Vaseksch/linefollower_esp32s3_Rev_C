#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_ADDRESS 0x3c

extern bool display_avalible;

void oled_begin();
void wait_screen(void);
void calibration_complete_screen(void);
void press_sw2_screen(void);

#endif