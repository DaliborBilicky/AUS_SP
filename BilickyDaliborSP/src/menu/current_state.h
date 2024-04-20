#pragma once
#include <libds/heap_monitor.h>
enum State {
    EXIT,
    LEVEL_MENU,
    MAIN_MENU,
    STARTS_WITH_STR_MENU,
    CONTAINS_STR_MENU,
    TYPE_MENU,
    MANUAL_ITERATOR_MENU,
    SEQUENCE_MENU
};

enum Level { LEVEL_1, LEVEL_2 };

class CurrentState {
  private:
    State state = State::LEVEL_MENU;
    Level level = Level::LEVEL_2;

  public:
    CurrentState();
    ~CurrentState();

    State getState();
    void setState(State state);

    Level getLevel();
    void setLevel(Level level);
};
