#pragma once
#include "menu/states.h"
#include "units/units.h"
#include <string>
#include <vector>

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

    void processStartsWithString(std::string &searchedString);
    void processContainsString(std::string &searchedString);
    void processIsType(int wantedType);
    void printOutput();

  public:
    App();
    ~App();

    void start();
    void mainLoop();
};
