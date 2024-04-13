#pragma once
#include "menu/states.h"
#include "units/units.h"
#include <libds/amt/implicit_sequence.h>
#include <libds/amt/explicit_hierarchy.h>
#include <string>

class App {
  private:
    ds::amt::ImplicitSequence<TerritorialUnit *> results;
    ds::amt::ImplicitSequence<Settlement> settlements;
    ds::amt::ImplicitSequence<Soorp> soorps;
    ds::amt::ImplicitSequence<Region> regions;
    ds::amt::MultiWayExplicitHierarchy<TerritorialUnit*> czechia;
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
