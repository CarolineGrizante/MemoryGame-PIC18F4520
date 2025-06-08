#include "game.h"
#include "leds.h"
#include "buttons.h"
#include "display.h"
#include "buzzer.h"
#include "sensors.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000


#define MAX_LEVEL 9

static uint8_t sequence[MAX_LEVEL];
static uint8_t current_level;

void generate_sequence(void) {
    for (uint8_t i = 0; i < MAX_LEVEL; i++) {
        sequence[i] = rand() % 4;
    }
}

void game_init(void) {
    leds_init();
    buttons_init();
    display_init();
    buzzer_init();
    sensors_init();
    
    game_reset();
}

void game_reset(void) {
    current_level = 1;
    display_show_digit(0);
    generate_sequence();
}

void game_loop(void) {
    if (!ldr_dark_detected()) return;

    __delay_ms(500); // Debounce do LDR

    for (uint8_t i = 0; i < current_level; i++) {
        leds_flash(sequence[i]);
        __delay_ms(300);
    }

    for (uint8_t i = 0; i < current_level; i++) {
        int8_t btn = -1;
        while (btn == -1) {
            btn = buttons_read();
        }
        leds_flash(btn);
        if (btn != sequence[i]) {
            buzzer_play_error();
            game_reset();
            return;
        }
    }

    buzzer_play_success();
    display_show_digit(current_level);
    
    if (current_level < MAX_LEVEL) {
        current_level++;
        __delay_ms(800);
    } else {
        // Vitória: reiniciar
        __delay_ms(1000);
        game_reset();
    }
}