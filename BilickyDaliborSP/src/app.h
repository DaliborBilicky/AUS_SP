#pragma once
#include "algorithms.h"
#include "units/units.h"
#include "units/territorial_unit.h"
#include "menu/prompt.h"
#include "menu/current_state.h"
#include "menu/states.h"
#include <chrono>
#include <crtdbg.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

class App {
  private:
	std::vector<TerritorialUnit *> results;
	std::vector<Settlement> settlements;
	std::vector<Soorp> soorps;
	std::vector<Region> regions;
	CurrentState currentState;
	MainMenu mainMenu;
	TypeMenu typeMenu;
	HierarchyMenu hierarchyMenu;
	ContainsStringMenu containsStringMenu;
	StartsWithStrMenu startsWithStrMenu; 

    void processStartsWithString(std::string& searchedString);
    void processContainsString(std::string& searchedString);
    void processIsType(int wantedType);
    void printOutput();


  public:
    App();
    ~App();

    void start();
    void mainLoop();
};

