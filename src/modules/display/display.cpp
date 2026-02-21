#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

static const unsigned char image_hourglass1_bits[] = {0x00,0x00,0x00,0xe0,0xff,0x0f,0x20,0x00,0x08,0xc0,0xff,0x07,0x80,0x00,0x02,0x80,0x00,0x02,0x80,0xfe,0x02,0x80,0x7c,0x02,0x00,0x39,0x01,0x00,0x92,0x00,0x00,0x44,0x00,0x00,0x28,0x00,0x00,0x28,0x00,0x00,0x44,0x00,0x00,0x92,0x00,0x00,0x01,0x01,0x80,0x10,0x02,0x80,0x7c,0x02,0x80,0xfe,0x02,0x80,0x00,0x02,0xc0,0xff,0x07,0x20,0x00,0x08,0xe0,0xff,0x0f,0x00,0x00,0x00};

void oled_begin(){
    u8g2.begin();
}

void wait_screen(void){
    u8g2.clearBuffer();
    u8g2.setFontMode(1);
    u8g2.setBitmapMode(1);
    u8g2.drawXBM(0, 4, 24, 24, image_hourglass1_bits);

    u8g2.setFont(u8g2_font_profont17_tr);
    u8g2.drawStr(26, 21, "Please wait");

    u8g2.sendBuffer();
}

void calibration_complete_screen(void){
    u8g2.clearBuffer();
    u8g2.setFontMode(1);
    u8g2.setBitmapMode(1);
    u8g2.setFont(u8g2_font_profont17_tr);
    u8g2.drawStr(16, 14, "Calibration");

    u8g2.drawStr(28, 28, "complete");

    u8g2.sendBuffer();

    delay(2000);
    u8g2.clearBuffer();
    u8g2.sendBuffer();
}

void press_sw2_screen(void){
    u8g2.clearBuffer();
    u8g2.setFontMode(1);
    u8g2.setBitmapMode(1);
    u8g2.setFont(u8g2_font_profont17_tr);
    u8g2.drawStr(25, 15, "Press SW2");

    u8g2.setFont(u8g2_font_profont12_tr);
    u8g2.drawStr(5, 27, "to start calibration");

    u8g2.sendBuffer();
}

