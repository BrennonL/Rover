#include<utilities.h>
#include<util/delay.h>
#include <avr/io.h>
#include <stdint.h>

// miliseconds
void delay_ms(int ms) {
  _delay_ms(ms);
}

// Microseconds
void delay_us(int us) {
  _delay_us(us);
}

void sendHIGH(uint8_t pinBit) {
  PORTB |= (1 << pinBit);
}

void sendLOW(uint8_t pinBit) {
  PORTB &= ~(1 << pinBit);
}

void led_on() {
  PORTB |= (1<<PB5);
}

void led_off() {
  PORTB &= ~(1<<PB5);
}