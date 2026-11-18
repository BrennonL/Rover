// ChatGPT generated file structure but I implemented function logic
#include "sensors.h"
#include <avr/io.h>
#include <stdint.h>
#include<utilities.h> // delay_us, sendHIGH, sendLOW

// Sensors::Sensors()
Sensors::Sensors(uint8_t inputBit, uint8_t outputBit):_triggerBit(inputBit), _echoBit(outputBit)
{
  // inputBit is Arduino -> Sensor
  // outputBit is Seneor -> Arduino
  // TODO: Initialize member variables
  // Set up sensor input and output
  DDRB |= (1 << inputBit);
  DDRB |= (1 << outputBit);
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

float Sensors::getDistance()
{

    // TODO: Trigger HC-SR04 and calculate distance
  // Send sensing signal to HC-SR04
  // PORTB |= (1 << this->_outputBit);
  sendHIGH(this->_triggerBit);
  delay_us(10);
  sendLOW(this->_triggerBit);

  // Select input register

  // Read duration of sense signal
  
  return 0.0f;
}

bool Sensors::isValid()
{
    // TODO: Determine whether the sensor reading is valid

    return false;
}