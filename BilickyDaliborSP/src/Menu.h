#pragma once
#include "units/territorial_unit.h"
#include <functional>


enum InputType {
    NONE,
    NUM_INPUT,
    STRING_INPUT,
    SEARCH_REGION,
    SEARCH_SOORP,
    SEARCH_SETTLEMENT,
    SEARCH_EVERYTHING
};

class Menu {
  private:
    std::function<bool(TerritorialUnit)> predicate;
    State currentState = State::MAIN_MENU;
    InputType inputType = InputType::NONE;
	std::string wantedString = "";
	std::string wantedStringUpper = "";
    int typePick = 0;

  public:
    Menu();
    ~Menu();
    void mainMenu();
    void subMenu();
    void takeInput();
    State getCurrentState();
    InputType getInputType();
    std::function<bool(TerritorialUnit)>& getPredicate(); 

};
