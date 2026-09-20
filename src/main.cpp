#include <avr/io.h>
#include <util/delay.h>

void led_on() {
  PORTB |= (1<<PB5);
}
void led_off() {
  PORTB &= ~(1<<PB5);
}

void delay_us(int us) {
  while (us --) {
    _delay_us(1);
  }
}

void delay_ms(int ms) {
  while (ms --) {
    _delay_ms(1);
  }
}

void sense() {
  // Reset sensor to low
  // PORTB &= ~(1 << PB3);

  // Send sensor logic
  PORTB |= (1 << PB3);
  delay_us(10);
  PORTB &= ~(1 << PB3);
  int duration;
  while (PINB & (1 << PB2)){
    duration ++;
  }
  led_on();
  delay_ms(duration);
  led_off();
  delay_ms(10);

}

int main() {
  DDRB |= (1 << PB5); // Arduino output to light

  DDRB |= (1 << PB3); // Arduino output to sensor
  DDRB &= ~(1 << PB2); // Arduino input from sensor

  // MAIN LOOP 
  while (true) {
    sense();

    // led_on();
    // delay_ms(500);
    // led_off();
    // delay_ms(500);
  }
  return 0;
}