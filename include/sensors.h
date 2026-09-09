#ifndef SENSORS_H
#define SENSORS_H

class Sensors
{
public:
    // Constructor
    Sensors();

    // Rule of 5
    ~Sensors();
    Sensors(const Sensors& other);
    Sensors& operator=(const Sensors& other);
    Sensors(Sensors&& other) noexcept;
    Sensors& operator=(Sensors&& other) noexcept;

    // Sensor interface
    void begin();

    float getDistance();

    bool isValid();

private:
    float _distance;
};

#endif