#pragma once
#include <string>
#include "current_state.h"
#include "units/territorial_unit.h"

class MainMenu {
  private:
    const std::string TITLE = "\n[\033[95mMAIN MENU\033[0m]\n";
    const std::string INFO = " \033[95m*\033[0m Choose predicate to print specific territorial unit.\n";
    CurrentState* currentState;

  public:
    MainMenu(CurrentState *currentState);
    ~MainMenu();

    void show();
};

class HierarchyMenu {
  private:
    const std::string TITLE = "\n[\033[94mHIERARCHY MENU\033[0m]\n";
    const std::string INFO = " \033[94m*\033[0m Choose if you want to go up or down in hierarchy.\n";
    CurrentState* currentState;

  public:
    HierarchyMenu(CurrentState* currentState);
    ~HierarchyMenu();

    void show();
};

class TypeMenu {
  private:
    const std::string TITLE = "\n[\033[93mTYPE MENU\033[0m]\n";
    const std::string INFO = " \033[93m*\033[0m Choose what type of territorial unit you want to print.\n";
    CurrentState* currentState;
    int option = 0;
    bool exiting = false;

  public:
    TypeMenu(CurrentState* currentState);
    ~TypeMenu();

    void show();
    int getOption();
    bool isExiting();
};

class ContainsStringMenu {
  private:
    const std::string TITLE = "\n[\033[92mCONTAINS STRING MENU\033[0m]\n";
    const std::string INFO = " \033[92m*\033[0m Choose what units will print base on containing string.\n";
    CurrentState* currentState;
    std::string searchedString = "";
    bool exiting = false;

  public:
    ContainsStringMenu(CurrentState* currentState);
    ~ContainsStringMenu();

    void show();
    std::string &getSearchedString();
    bool isExiting();
};

class StartsWithStrMenu {
  private:
    const std::string TITLE = "\n[\033[96mSTARTS WITH STRING MENU\033[0m]\n";
    const std::string INFO = " \033[96m*\033[0m Choose what units will print base on string it starts with.\n";
    CurrentState* currentState;
    std::string searchedString = "";
    bool exiting = false;

  public:
    StartsWithStrMenu(CurrentState* currentState);
    ~StartsWithStrMenu();

    void show();
    std::string &getSearchedString();
    bool isExiting();
};
