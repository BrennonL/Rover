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
  while (true) {
    led_on();
    delay_ms(3000000);
    led_off();
    delay_ms(3000000);
  }
  return 0;
}