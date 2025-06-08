#include "sensors.h"
#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 8000000

void sensors_init(void) {
    TRISAbits.TRISA0 = 1; // Potenciômetro
    TRISAbits.TRISA1 = 1; // LDR
    ADCON1 = 0x0E;         // AN0 e AN1 analógicos
}

uint16_t adc_read(uint8_t channel) {
    ADCON0 = (channel << 2) | 0x01; // Canal e liga ADC
    __delay_us(10);
    GO_nDONE = 1;
    while (GO_nDONE);
    return ((ADRESH << 8) + ADRESL);
}

uint8_t ldr_dark_detected(void) {
    return adc_read(1) < 128;
}

uint8_t read_potentiometer(void) {
    return adc_read(0) >> 2; // Converte para 8 bits
}