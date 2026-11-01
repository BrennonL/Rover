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
  PORTB |= (1 << PB3);
  delay_us(10);
  PORTB &= ~(1 << PB3);
  
  int duration = 0;
  // while (PINB & (1 << PB2)){
  //   // if (duration >= 1000) {
  //   //   led_off();
  //   // } else {
  //   //   led_on();
  //   // }
  //   led_off();
  //   duration ++;
  // }

  if (PINB & (1 << PB2)) {
    led_off();
  } else {
    led_on();
  }
  // led_off();
  // led_on();
  // duration = 0;
  // led_on();
  // delay_ms(10);
  // led_off();
  // delay_ms(10);

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