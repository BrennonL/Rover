// CHATGPT generated the class boilerplate

#ifndef MOTORS_H
#define MOTORS_H

class Motors
{
public:
    // Constructor
    Motors();

    // Rule of 5
    ~Motors();
    Motors(const Motors& other);
    Motors& operator=(const Motors& other);
    Motors(Motors&& other) noexcept;
    Motors& operator=(Motors&& other) noexcept;

    // Motors interface
    void begin();

    void forward();
    void reverse();
    void stop();

    void setSpeed(int speed);

private:
    int _speed;
};

#endif