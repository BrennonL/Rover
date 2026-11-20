// ChatGPT generated file structure but I implemented function logic
#include "sensors.h"
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <utilities.h> // delay_us, sendHIGH, sendLOW

// Sensors::Sensors()
Sensors::Sensors(uint8_t triggerBit, uint8_t echoBit):_triggerBit(triggerBit), _echoBit(echoBit)
{
  DDRB |= (1 << triggerBit);
  DDRB &= ~(1 << echoBit);
}

Sensors::~Sensors()
{
  // TODO: Clean up resources if necessary
}

// Copy constructor
Sensors::Sensors(const Sensors& other)
{
  // TODO: Copy data from other
}

// Copy assignment operator
Sensors& Sensors::operator=(const Sensors& other)
{
    if (this != &other)
    {
        // TODO: Copy data from other
    }

    return *this;
}

// Move constructor
Sensors::Sensors(Sensors&& other) noexcept
{
    // TODO: Move data from other
}

// Move assignment operator
Sensors& Sensors::operator=(Sensors&& other) noexcept
{
    if (this != &other)
    {
        // TODO: Move data from other
    }

    return *this;
}

void Sensors::begin()
{
    // TODO: Configure Arduino/ESP32 sensor pins
}

/**
 * Sends a HIGH signal through the sensor's trigger pin. The
 * sensor will send 8 pulses out and then waits for an echo. It uses the time
 * for the echo to come back to calculate the distance in cm.
 * 
 * Atribution:  https://github.com/attar2580/HC-SR04_atmega32_Driver/blob/main/ultrasonic.c 
 *
 * @return The distance of the sensed object in cm
 */
uint16_t Sensors::getDistance()
{

  uint16_t distance;
  // PORTB &= ~(1 << PB3); // reset sensor to low
  sendLOW(this->_triggerBit);

  // STEP 1: send trigger pulse
  sendHIGH(this->_triggerBit);
  delay_us(10);
  sendLOW(this->_triggerBit);

  // STEP 2: Select input register
  //! Done in class constructor

  // STEP 3: Wait for echo to start
  uint16_t timeout = 40000;
  while(!(PINB & (1 << this->_echoBit))) {
    if (--timeout <= 0) {
      printf("IS IT SIMPLY GETTING HERE?");
      return 0; //! This might create some problems, figure out what else I should return other than 0 cm
    }
  }

  // STEP 4: Start timer
  startTimer1();

  // STEP 5: Wait for echo to end and calculate distance
  timeout = 30000;
  while ((PINB & (1 << this->_echoBit))) {
    if (--timeout <= 0) break;
  }
  stopTimer1();
  uint16_t ticks = getTimer1Ticks();
  if (ticks > 30000) distance = 400;
  /* Calculation
    Speed of sound = 343m/s = 0.0343 cm/us
    Time = Ticks * 0.5us
    Distance = (Time * Speed) / 2 (Because round trip)
    Distance = (Ticks * 0.5 * 0.0343) / 2
    Distance = Ticks / 116.6
    Use 117 for integer division accuacy
  */
  else distance = ticks / 117;
  return distance;
}

bool Sensors::isValid()
{
    // TODO: Determine whether the sensor reading is valid

    return false;
}