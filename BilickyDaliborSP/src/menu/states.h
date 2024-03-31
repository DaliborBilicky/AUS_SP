#pragma once
#include <string>
#include "current_state.h"
#include "units/territorial_unit.h"

class MainMenu {
  private:
    const std::string TITLE = "***** Main menu *****";
    const std::string INFO = "* Choose predicate to print specific territorial unit.";
    CurrentState currentState;

  public:
    MainMenu();
    MainMenu(CurrentState currentState);
    ~MainMenu();

    void show();
};

class HierarchyMenu {
  private:
    const std::string TITLE = "***** Hierarchy menu *****";
    const std::string INFO = "* Choose if you want to go up or down in hierarchy.";
    CurrentState currentState;

  public:
    HierarchyMenu();
    HierarchyMenu(CurrentState currentState);
    ~HierarchyMenu();

    void show();
};

class TypeMenu {
  private:
    const std::string TITLE = "***** Is type menu *****";
    const std::string INFO = "* Choose what type of territorial unit you want to print.";
    CurrentState currentState;
    TerrUnitType pickedType = TerrUnitType::NONE;

  public:
    TypeMenu();
    TypeMenu(CurrentState currentState);
    ~TypeMenu();

    void show();
    TerrUnitType getPickedType();
};


class StringMenu {
  private:
    const std::string TITLE = "***** Contains string menu *****";
    const std::string INFO = "* Choose what units will print base on containing string.";
    CurrentState currentState;
    std::string searchedString = "";

  public:
    StringMenu();
    StringMenu(CurrentState currentState);
    ~StringMenu();

    void show();
};
