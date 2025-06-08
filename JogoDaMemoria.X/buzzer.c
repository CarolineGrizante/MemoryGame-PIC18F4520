#include "buzzer.h"
#include "sensors.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

void buzzer_init(void) {
    TRISEbits.TRISE0 = 0;
    LATEbits.LATE0 = 0;
}

void buzzer_play_success(void) {
    LATEbits.LATE0 = 1;
    __delay_ms(100);
    LATEbits.LATE0 = 0;
}

void buzzer_play_error(void) {
    for (int i = 0; i < 3; i++) {
        LATEbits.LATE0 = 1;
        __delay_ms(100);
        LATEbits.LATE0 = 0;
        __delay_ms(100);
    }
}
