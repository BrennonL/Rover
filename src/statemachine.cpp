
#include <stdio.h> 

#include "statemachine.h"
#include "config.h"
// #define MIN_DISTANCE_CM 10 // ! If constant speed, this works. 

StateMachine::StateMachine() {
  // TODO -- Add configuration file and state changing logic
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
void StateMachine::changeState(carState& state) {
  if (state.distance < MIN_DISTANCE_CM) {
    printf("STOP: you need to turn \n");
  }
}

state StateMachine::getState() {
  return currState;
}