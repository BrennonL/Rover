#pragma once
#include <stdint.h>

void delay_ms(int ms);

void delay_us(int us);

void sendHIGH(uint8_t pinBit);

void sendLOW(uint8_t pinBit);

void ledOn();

void ledOff();

void flashCount(uint16_t number);
