#pragma once
#include "current_state.h"
#include "units/territorial_unit.h"
#include <libds/heap_monitor.h>
#include <string>

class MainMenu {
  private:
    const std::string TITLE = "\n[\033[31mMAIN MENU\033[0m]\n";
    const std::string INFO = " \033[31m*\033[0m Choose predicate to print "
                             "specific territorial units.\n";
    CurrentState *currentState;

  public:
    MainMenu(CurrentState *currentState);
    ~MainMenu();

    void update();
};

class ManualIteratorMenu {
  private:
    const std::string TITLE = "\n[\033[95mMANUAL ITERATOR MENU\033[0m]\n";
    const std::string INFO =
        " \033[95m*\033[0m Choose if you want to go up or down in hierarchy.\n";
    const std::string SUB_INFO =
        " \033[95m*\033[0m Choose which node you want to access.\n";
    CurrentState *currentState;
    int option = 0;

  public:
    ManualIteratorMenu(CurrentState *currentState);
    ~ManualIteratorMenu();

    void update();
    int getOption();
};

class TableMenu {
  private:
    const std::string TITLE = "\n[\033[93mTABLE MENU\033[0m]\n";
    const std::string INFO =
        " \033[93m*\033[0m Choose type of table to work with.\n";
    CurrentState *currentState;
    int option = 0;
    std::string searchedString = "";

  public:
    TableMenu(CurrentState *currentState);
    ~TableMenu();

    void update();
    int getOption();
    std::string &getSearchedString();
};

class TypeMenu {
  private:
    const std::string TITLE = "\n[\033[94mTYPE MENU\033[0m]\n";
    const std::string INFO = " \033[94m*\033[0m Choose the type of "
                             "territorial unit you want to print out.\n";
    CurrentState *currentState;
    int option = 0;
    bool exiting = false;

  public:
    TypeMenu(CurrentState *currentState);
    ~TypeMenu();

    void update();
    int getOption();
    bool isExiting();
};

class ContainsStringMenu {
  private:
    const std::string TITLE = "\n[\033[96mCONTAINS STRING MENU\033[0m]\n";
    const std::string INFO = " \033[96m*\033[0m Type to select the territorial "
                             "units which contains typed string.\n";
    CurrentState *currentState;
    std::string searchedString = "";

  public:
    ContainsStringMenu(CurrentState *currentState);
    ~ContainsStringMenu();

    void update();
    std::string &getSearchedString();
};

class StartsWithStrMenu {
  private:
    const std::string TITLE = "\n[\033[92mSTARTS WITH STRING MENU\033[0m]\n";
    const std::string INFO = " \033[92m*\033[0m Type to select the territorial "
                             "units which starts with typed string.\n";
    CurrentState *currentState;
    std::string searchedString = "";

  public:
    StartsWithStrMenu(CurrentState *currentState);
    ~StartsWithStrMenu();

    void update();
    std::string &getSearchedString();
};
