#include <stdint.h>

#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

void leds_init(void);
void leds_flash(uint8_t index);
void leds_show_sequence(uint8_t* seq, uint8_t len);

#endif