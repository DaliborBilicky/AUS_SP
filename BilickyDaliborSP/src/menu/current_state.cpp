#include <iostream>
#include "current_state.h"

CurrentState::CurrentState() {}

CurrentState::~CurrentState() {}

State CurrentState::getState() { return this->state; }

void CurrentState::setState(State state) { this->state = state; }
