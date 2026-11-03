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

  // Send sensor logic
  PORTB |= (1 << PB3); // HIGH signal
  delay_us(10);
  PORTB &= ~(1 << PB3); // LOW signal

  // Measure duration: https://forum.arduino.cc/t/pulsein-function-source-code/102995 
  

  if (PINB & (1 << PB2)) { 
    led_off();
  } else {
    led_on();
  }

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