#include <stdint.h>

#ifndef SENSORS_H
#define SENSORS_H

#include <stdint.h>

void sensors_init(void);
uint8_t ldr_dark_detected(void);
uint8_t read_potentiometer(void);

#endif