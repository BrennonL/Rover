#include "statemachine.h"


StateMachine::StateMachine() {
  currState = STATIONARY;
}
StateMachine::~StateMachine() {}
StateMachine::StateMachine(const StateMachine& other) {}
StateMachine& StateMachine::operator=(const StateMachine& other) {}
StateMachine::StateMachine(StateMachine&& other) noexcept {}
StateMachine& StateMachine::operator=(StateMachine&& other) noexcept {}

/**
 * I want this function to take in a system class which it will then use to 
 * determine if the state needs to be update.
 */
void StateMachine::changeState(state newState) {
  currState = newState;
}

state StateMachine::getState() {
  return currState;
}