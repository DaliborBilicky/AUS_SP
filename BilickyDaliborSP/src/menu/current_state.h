#pragma once
#include <libds/heap_monitor.h>

enum State {
    EXIT, 
    APP_TYPE_MENU,
    MAIN_MENU,
    TABEL_MENU,
    STARTS_WITH_STR_MENU,
    CONTAINS_STR_MENU,
    UNIT_TYPE_MENU,
    MANUAL_ITERATOR_MENU,
    SEQ_MENU
};

enum AppType {
    HIERARCHICAL,
    SEQUENTIAL
};

class CurrentState {
  private:
    State state = State::APP_TYPE_MENU;
    AppType appType = AppType::HIERARCHICAL;

  public:
    CurrentState();
    ~CurrentState();

    State getState();
    void setState(State state);
    AppType getAppType();
    void setAppType(AppType type);
};
