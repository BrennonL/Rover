#ifndef UTILITIES
#define UTILITIES
#include <stdint.h>

void delay_ms(int ms);

void delay_us(int us);

void sendHIGH(uint8_t pinBit);

void sendLOW(uint8_t pinBit);

void led_on();

void led_off();

#endif