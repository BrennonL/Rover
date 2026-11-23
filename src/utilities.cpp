#include<utilities.h>
#include<util/delay.h>
#include <avr/io.h>
#include <stdint.h>
#include<avr/io.h>
#include<stdio.h> // size_t

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
void ledOn() {
  PORTB |= (1<<PB5);
}

/**
 * Turns the built-in led off on the Arduino (port B pin 5)
 */
void ledOff() {
  PORTB &= ~(1<<PB5);
}

/**
 * Flashes the built in led on the Arduino a defined number of times
 * 
 * @param number: The number of times the light flashes
 */
void flashCount(uint16_t number) {
  ledOff();
  for (size_t i = 0; i < number; i++) {
    ledOn();
    delay_ms(50);
    ledOff();
    delay_ms(50);
  }
}

/**
 * Starts timer 1 on the ATMEGA328P. Remember 1 tick = 0.5 microseconds
 */
void startTimer1() {
  TCNT1 = 0; // set timer1 register to 0
  if (TCCR1B == (1 << CS11)) { // verify timer wasn't already started
    printf("timer already started");
    return;
  }
  TCCR1B = (1 << CS11);  // Start the timer.
}

/**
 * Stops timer 1 on the ATMEGA328P
 */
void stopTimer1() {
  // TODO -- What if timer was already stopped?
  TCCR1B = 0;
}

/**
 * Gets the number of ticks stored in the timer 1 on ATMEGA328P
 */
uint16_t getTimer1Ticks() {
  uint16_t ticks = TCNT1;
  return ticks;
}