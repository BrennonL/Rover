#include<utilities.h>
#include<util/delay.h>
#include <avr/io.h>
// #include <stdint.h>

void delay_ms(int ms) {
  _delay_ms(ms);
}

void delay_us(int us) {
  _delay_us(us);
}

void sendHight(int pinBit) {
  PORTB |= (1 << pinBit);
}

void sendLow(int pinBit) {
  PORTB &= ~(1 << pinBit);
}