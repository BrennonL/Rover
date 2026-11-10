#include<utilities.h>
#include<util/delay.h>
#include <avr/io.h>
#include <stdint.h>

/**
 * Delay specifed number of milliseconds
 * 
 * @param ms number of milliseconds to be delayed by
 */
void delay_ms(int ms) {
  _delay_ms(ms);
}

/**
 * Delay specified number of microseconds
 * 
 * @param us number of microseconds to be delayed by
 */
void delay_us(int us) {
  _delay_us(us);
}


/**
 * Sends a high signal through the specified pin bit
 * 
 * @param pinBit the bit to send the signal through
 */
void sendHIGH(uint8_t pinBit) {
  PORTB |= (1 << pinBit);
}

/**
 * Sends a low signal through the specified pin bit
 * 
 * @param pinBit the bit to send the signal through
 */
void sendLOW(uint8_t pinBit) {
  PORTB &= ~(1 << pinBit);
}

/**
 * Turns the built-in led on the Arduino (port B pin 5)
 */
void led_on() {
  PORTB |= (1<<PB5);
}

/**
 * Turns the built-in led off on the Arduino (port B pin 5)
 */
void led_off() {
  PORTB &= ~(1<<PB5);
}

/**
 * Flashes the built in led on the Arduino a defined number of times
 * 
 * @param number: The number of times the light flashes
 */
void flash_count(uint16_t number) {
  led_off();
  for (int i = 0; i < number; i++) {
    led_on();
    delay_ms(50);
    led_off();
    delay_ms(50);
  }
}