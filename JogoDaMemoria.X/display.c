#include "display.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

const uint8_t digit_map[10] = {
    0x3F, 0x06, 0x5B, 0x4F,
    0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F
};

void display_init(void) {
    TRISC = 0x00;
    LATC = 0x00;
}

void display_show_digit(uint8_t digit) {
    LATC = digit_map[digit % 10];
}