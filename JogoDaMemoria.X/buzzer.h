#include <stdint.h>

#ifndef BUZZER_H
#define BUZZER_H

void buzzer_init(void);
void buzzer_play_success(void);
void buzzer_play_error(void);
void buzzer_set_volume(uint8_t level);

#endif