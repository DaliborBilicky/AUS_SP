#pragma once
#include "current_state.h"
#include "units/territorial_unit.h"
#include <string>
#include <libds/heap_monitor.h>

class MainMenu {
  private:
    const std::string TITLE = "\n[\033[95mMAIN MENU\033[0m]\n";
    const std::string INFO = " \033[95m*\033[0m Choose predicate to print "
                             "specific territorial units.\n";
    CurrentState *currentState;

  public:
    MainMenu(CurrentState *currentState);
    ~MainMenu();

    void show();
};

class ManualIteratorMenu {
  private:
    const std::string TITLE = "\n[\033[94mMANUAL ITERATOR MENU\033[0m]\n";
    const std::string INFO =
        " \033[94m*\033[0m Choose if you want to go up or down in hierarchy.\n";
    CurrentState *currentState;
    int option = 0;

  public:
    ManualIteratorMenu(CurrentState *currentState);
    ~ManualIteratorMenu();

    void show();
    int getOption();
};

class TypeMenu {
  private:
    const std::string TITLE = "\n[\033[93mTYPE MENU\033[0m]\n";
    const std::string INFO = " \033[93m*\033[0m Choose the type of "
                             "territorial unit you want to print out.\n";
    CurrentState *currentState;
    int option = 0;
    bool exiting = false;

  public:
    TypeMenu(CurrentState *currentState);
    ~TypeMenu();

    void show();
    int getOption();
    bool isExiting();
};

class ContainsStringMenu {
  private:
    const std::string TITLE = "\n[\033[92mCONTAINS STRING MENU\033[0m]\n";
    const std::string INFO = " \033[92m*\033[0m Type to select the territorial "
                             "units which contains typed string.\n";
    CurrentState *currentState;
    std::string searchedString = "";
    bool exiting = false;

  public:
    ContainsStringMenu(CurrentState *currentState);
    ~ContainsStringMenu();

    void show();
    std::string &getSearchedString();
    bool isExiting();
};

class StartsWithStrMenu {
  private:
    const std::string TITLE = "\n[\033[96mSTARTS WITH STRING MENU\033[0m]\n";
    const std::string INFO = " \033[96m*\033[0m Type to select the territorial "
                             "units which starts with typed string.\n";
    CurrentState *currentState;
    std::string searchedString = "";
    bool exiting = false;

  public:
    StartsWithStrMenu(CurrentState *currentState);
    ~StartsWithStrMenu();

    void show();
    std::string &getSearchedString();
    bool isExiting();
};
