#include <avr/io.h>
#include <util/delay.h>

void led_on() {
  PORTB |= (1<<PB5);
}
void led_off() {
  PORTB &= ~(1<<PB5);
}

void delay_ms(int ms) {
  while (ms --) {
    _delay_ms(1);
  }
}

int main() {
  DDRB |= (1 << PB5);

  DDRB |= (1 << PB3); // Arduino output to sensor
  DDRB |= (1 << PB2); // Arduino input from sensor

  // MAIN LOOP 
  while (true) {
    led_on();
    delay_ms(500);
    led_off();
    delay_ms(500);
  }
  return 0;
}