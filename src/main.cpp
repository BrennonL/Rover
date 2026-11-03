#include <avr/io.h>
#include <util/delay.h>
#include <utilities.h>

void led_on() {
  PORTB |= (1<<PB5);
}
void led_off() {
  PORTB &= ~(1<<PB5);
}

void sense() {
  // Reset sensor to low
  // PORTB &= ~(1 << PB3);

  // // Send sensor logic
  // PORTB |= (1 << PB3); // HIGH signal
  // delay_us(10);
  // PORTB &= ~(1 << PB3); // LOW signal

  // // Measure duration: https://forum.arduino.cc/t/pulsein-function-source-code/102995 
  // // Also see github link: https://github.com/attar2580/HC-SR04_atmega32_Driver/blob/main/ultrasonic.c 
  

  // if (PINB & (1 << PB2)) { 
  //   led_off();
  // } else {
  //   led_on();
  // }

  // Trigger sense
  PORTB |= (1 << PB3); // send HIGH
  delay_us(10);
  PORTB &= ~(1 << PB3); // send LOW

  // Wait for echo to start

  // Start time mesurement

  // Stop timer and calculate distance

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