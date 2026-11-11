#include <avr/io.h>
#include <util/delay.h>
#include <utilities.h> // delay_us, sendHigh, sendLOW, delay_ms
#include <stdint.h>



void sense() {
  // TODO -- Move this function to the sensor class
  // Attribution: https://github.com/attar2580/HC-SR04_atmega32_Driver/blob/main/ultrasonic.c
  uint16_t distance;
  PORTB &= ~(1 << PB3); // reset sensor to low.

  // Trigger sense
  PORTB |= (1 << PB3); // send HIGH
  delay_us(10);
  PORTB &= ~(1 << PB3); // send LOW

  // Start timer measurements
  TCNT1 = 0; // Set the timer to 0
  TCCR1B = (1 << CS11); // Start the timer. Remember 1 tick = 0.5 microseconds

  // Wait for echo to start
  uint8_t timeout = 30000;
  // A while loop while the signal is high, breaks when timeout or low
  while (!(PINB & (1 << PB2))) {
    if (-- timeout == 0) break;
    // led_on();
  }
  // led_off();

  // Stop timer and calculate distance
  // TCCR1A = 0;
  TCCR1B = 0; // top the timer
  uint16_t ticks = TCNT1; // Read number of ticks
  if (ticks > 3000) distance = 400; // If ticks exceed maximum return max disctance
	/* Calculation:
	   Speed of sound = 343m/s = 0.0343 cm/us
	   Time = Ticks * 0.5us
	   Distance = (Time * Speed) / 2 (Round trip)
	   Distance = (Ticks * 0.5 * 0.0343) / 2
	   Distance = Ticks / 116.6
	   Used 117 for integer division accuracy. */
  else distance = ticks / 117; // Otherwise calculate disctance

  // distance = 10;
  // flash_count(distance);
  // delay_ms(5000);
  if (ticks > 20) {
    led_on();
    delay_ms(1000);
    led_off();
  } else {
    led_off();
    delay_ms(1000);

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