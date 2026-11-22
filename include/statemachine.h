// Brennon Laney wrote this by hand
// States: stop, go, turn left, turn right.
#pragma once

enum state {
  FORWARD,
  RIGHT,
  LEFT,
  LOWPOWER, // I might want this somewhere else
  BACKWARDS,
  STATIONARY, // Hold for a few seconds and then move forward once button is pushed
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
    void changeState(state newState);

  private: 
    state currState;
};
