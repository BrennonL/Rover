// Brennon Laney wrote this by hand
#ifndef STATEMACHINE_H;
#define STATEMACHINE_H;

enum state {
  Forward = 0,
  Right = 1,
  Left = 2,
  LowPower = 3, // I might want this somewhere else
};

class StateMachine {
  public:
    StateMachine();
    // Rule of 5
    ~StateMachine();
    StateMachine(const StateMachine& other);
    StateMachine& operator=(const StateMachine& other);
    StateMachine(StateMachine&& other) noexcept;
    StateMachine& operator=(StateMachine&& other) noexcept;

    state getState();
    void changeState();

  private: 
};

#endif