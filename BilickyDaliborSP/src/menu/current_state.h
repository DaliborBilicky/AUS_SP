#pragma once
#include <libds/heap_monitor.h>

enum State {
    EXIT,
    MAIN_MENU,
    TABEL_MENU,
    STARTS_WITH_STR_MENU,
    CONTAINS_STR_MENU,
    TYPE_MENU,
    MANUAL_ITERATOR_MENU
};

class CurrentState {
  private:
    State state = State::MAIN_MENU;

  public:
    CurrentState();
    ~CurrentState();

    State getState();
    void setState(State state);
};
