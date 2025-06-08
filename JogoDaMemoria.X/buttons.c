#include "buttons.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

void buttons_init(void) {
    TRISB |= 0x0F; // RB0-RB3 como entrada
}

int8_t buttons_read(void) {
    if (!PORTBbits.RB0) return 0;
    if (!PORTBbits.RB1) return 1;
    if (!PORTBbits.RB2) return 2;
    if (!PORTBbits.RB3) return 3;
    return -1;
}