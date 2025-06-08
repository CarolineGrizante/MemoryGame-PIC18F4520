#include <xc.h>
#include "game.h"
#include <stdint.h>
#define _XTAL_FREQ 8000000

// CONFIG
#pragma config OSC = HS     // Oscillator Selection bits (HS oscillator)
#pragma config WDT = OFF    // Watchdog Timer (WDT disabled)
#pragma config LVP = OFF    // Low Voltage ICSP (Disabled)
#pragma config PBADEN = OFF // PORTB<4:0> digital on reset
#pragma config BOREN = OFF  // Brown-out Reset disabled
#pragma config MCLRE = ON   // MCLR pin enabled

#define _XTAL_FREQ 8000000  // Frequência do oscilador

void main(void) {
    game_init();

    while (1) {
        game_loop();
    }
}