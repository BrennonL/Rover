#include <avr/io.h>
#include <util/delay.h>
#include <utilities.h> // delay_us, sendHigh, sendLOW
#include <stdint.h>

void led_on() {
  PORTB |= (1<<PB5);
}
void led_off() {
  PORTB &= ~(1<<PB5);
}

void sense() {

  PORTB &= ~(1 << PB3); // reset sensor to low.

  // Trigger sense
  PORTB |= (1 << PB3); // send HIGH
  delay_us(10);
  PORTB &= ~(1 << PB3); // send LOW
  led_off();
  // Wait for echo to start
  if (!(PINB & (1 << PB2))) {
    led_on();
  } else {
    led_off();
  }

  // Start timer measurements
  TCNT1 = 0; // Set the timer to 0
  TCCR1B = (1 << CS11); // Start the timer. Remember 1 tick = 0.5 microseconds

  // Wait for echo to start
  uint8_t timeout = 40000;
  // A while loop while the signal is high, breaks when timeout or low
  while (!(PINB & (1 << PB2))) {
    if (-- timeout == 0) break;
  }

  // Stop timer and calculate distance
  TCCR1B = 0; // top the timer


}

int main() {
  DDRB |= (1 << PB5); // Arduino output to light

  DDRB |= (1 << PB3); // Arduino output to sensor
  DDRB &= ~(1 << PB2); // Arduino input from sensor

  while (true) {
    sense();
  }
  return 0;
}