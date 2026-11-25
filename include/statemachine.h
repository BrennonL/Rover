// Brennon Laney wrote this by hand
// States: stop, go, turn left, turn right.
#pragma once
#include <stdint.h> 
#include <ArduinoJson.h>

enum state {
  FORWARD,
  RIGHT,
  LEFT,
  LOWPOWER, // I might want this somewhere else
  BACKWARDS,
  STATIONARY, // Hold for a few seconds and then move forward once button is pushed
};

/**
 * The idea behind this structure is to pass it into the state machine it and
 * it would use it to determine if the class is able to change states or not
 * depending on the data stored on .statemachineconfig.toml file
 */
struct carState {
  uint16_t distance;
  // int power;
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
