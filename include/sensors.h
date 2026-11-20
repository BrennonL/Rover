#pragma once

#include<stdint.h>

class Sensors
{
public:
    // Constructor
    Sensors(uint8_t inputBit, uint8_t outputBit);
    // Sensors();


    // Rule of 5
    ~Sensors();
    Sensors(const Sensors& other);
    Sensors& operator=(const Sensors& other);
    Sensors(Sensors&& other) noexcept;
    Sensors& operator=(Sensors&& other) noexcept;

    // Sensor interface
    void begin();

    uint16_t getDistance();

    bool isValid();

private:
    float _distance;
    int _triggerBit;
    int _echoBit;
};
