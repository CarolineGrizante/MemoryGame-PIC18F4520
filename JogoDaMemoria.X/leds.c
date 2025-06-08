#include "leds.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

void leds_init(void) {
    TRISD &= 0xF0; // RD0-RD3 como saída
    LATD &= 0xF0;  // Apaga LEDs
}

void leds_flash(uint8_t index) {
    LATD = (1 << index);
    __delay_ms(300);
    LATD = 0;
}

void leds_show_sequence(uint8_t* seq, uint8_t len) {
    for (uint8_t i = 0; i < len; i++) {
        leds_flash(seq[i]);
        __delay_ms(200);
    }
}