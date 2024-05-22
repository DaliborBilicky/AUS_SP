#include "current_state.h"
#include <libds/heap_monitor.h>

CurrentState::CurrentState() {}

CurrentState::~CurrentState() {}

State CurrentState::getState() { return this->state; }

void CurrentState::setState(State state) { this->state = state; }

AppType CurrentState::getAppType() { return this->appType; }

void CurrentState::setAppType(AppType type) { this->appType = type; }
