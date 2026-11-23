#define F_CPU 16000000UL
#define BAUD 9600UL

#include <avr/io.h>
#include <util/delay.h>
#include <utilities.h> // delay_us, sendHigh, sendLOW, delay_ms
#include <stdint.h> // unit16_t, utin8_t, unit32_t
#include <stdio.h> // FDEV_SETUP_STREAM
#include <avr/io.h>
#include <avr/interrupt.h>

#include "serial.h"
#include "sensors.h"

int main() {
  printfSetup();
  Sensors sensor(PB3, PB2);
  printf("Hello World");
  while (true) {
    uint16_t distance = sensor.getDistance();
    printf("distance ==  %d \n", distance);
  }
  return 0;
}