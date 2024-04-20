#include "current_state.h"
#include <libds/heap_monitor.h>

CurrentState::CurrentState() {}

CurrentState::~CurrentState() {}

State CurrentState::getState() { return this->state; }

void CurrentState::setState(State state) { this->state = state; }

Level CurrentState::getLevel() { return this->level; }

void CurrentState::setLevel(Level level) { this->level = level; }
