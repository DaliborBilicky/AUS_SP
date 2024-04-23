#include "menu/states.h"
#include "menu/prompt.h"
#include <iostream>
#include <libds/heap_monitor.h>
#include <string>
#include <cstdlib>

// LevelMenu class ------------------------------------------------------
LevelMenu::LevelMenu(CurrentState *currentState) : currentState(currentState) {}

LevelMenu::~LevelMenu() {}

void LevelMenu::update() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [0] - Exit program\n"
              << "  [1] - Level 1\n"
              << "  [2] - Level 2\n";
    int option = Prompt::getInput(2);
    this->currentState->setState(State::MAIN_MENU);
    switch (option) {
    case 0:
        this->currentState->setState(State::EXIT);
        this->currentState->setLevel(Level::LEVEL_0);
        break;
    case 1:
        this->currentState->setLevel(Level::LEVEL_1);
        break;
    case 2:
        this->currentState->setLevel(Level::LEVEL_2);
        break;
    }
    std::system("cls");
}

// MainMenu class ------------------------------------------------------
MainMenu::MainMenu(CurrentState *currentState) : currentState(currentState) {}

MainMenu::~MainMenu() {}

void MainMenu::update() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[95m0\033[0m] - Go back\n"
              << "  [\033[95m1\033[0m] - Starts with string\n"
              << "  [\033[95m2\033[0m] - Contains string\n"
              << "  [\033[95m3\033[0m] - Is specific territorial type\n";

    if (this->currentState->getLevel() == Level::LEVEL_2) {
        std::cout << "  [\033[95m4\033[0m] - Move in hierarchy\n";
    } else if (this->currentState->getLevel() == Level::LEVEL_1) {
        std::cout << "  [\033[95m4\033[0m] - Pick type of sequence\n";
    }

    int option = Prompt::getInput(4);
    switch (option) {
    case 0:
        this->currentState->setState(State::LEVEL_MENU);
        break;
    case 1:
        this->currentState->setState(State::STARTS_WITH_STR_MENU);
        break;
    case 2:
        this->currentState->setState(State::CONTAINS_STR_MENU);
        break;
    case 3:
        this->currentState->setState(State::TYPE_MENU);
        break;
    case 4:
        if (this->currentState->getLevel() == Level::LEVEL_2) {
            this->currentState->setState(State::MANUAL_ITERATOR_MENU);
        } else if (this->currentState->getLevel() == Level::LEVEL_1) {
            this->currentState->setState(State::SEQUENCE_MENU);
        }
        break;
    }
    std::system("cls");
}

// IsTypeMenu class ------------------------------------------------------
TypeMenu::TypeMenu(CurrentState *currentState) : currentState(currentState) {}

TypeMenu::~TypeMenu() {}

void TypeMenu::update() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[92m0\033[0m] - Go back\n"
              << "  [\033[92m1\033[0m] - Type region\n"
              << "  [\033[92m2\033[0m] - Type SOORP\n"
              << "  [\033[92m3\033[0m] - Type settlement\n";
    int option = Prompt::getInput(3);
    switch (option) {
    case 0:
        this->currentState->setState(State::MAIN_MENU);
        this->option = option;
        break;
    default:
        this->option = option;
        break;
    }
    std::system("cls");
}

int TypeMenu::getOption() { return this->option; }

bool TypeMenu::isExiting() { return this->exiting; }

// HierarchyMenu class ------------------------------------------------------
ManualIteratorMenu::ManualIteratorMenu(CurrentState *currentState)
    : currentState(currentState) {}

ManualIteratorMenu::~ManualIteratorMenu() {}

void ManualIteratorMenu::update() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[93m0\033[0m] - Go back\n"
              << "  [\033[93m1\033[0m] - Up in hierarchy\n"
              << "  [\033[93m2\033[0m] - Down in hierarchy\n";
    int option = Prompt::getInput(2);
    switch (option) {
    case 0:
        this->currentState->setState(State::MAIN_MENU);
        this->option = option;
        std::system("cls");
        break;
    case 1:
        this->option = option;
        break;
    case 2:
        this->option = option;
        std::cout << this->SUB_INFO;
        break;
    }
}

int ManualIteratorMenu::getOption() { return this->option; }

// StringMenu class ------------------------------------------------------
ContainsStringMenu::ContainsStringMenu(CurrentState *currentState)
    : currentState(currentState) {}

ContainsStringMenu::~ContainsStringMenu() {}

void ContainsStringMenu::update() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[96m0\033[0m] - Go back\n"
              << "  [\033[96m1\033[0m] - Write string\n";
    int option = Prompt::getInput(1);
    switch (option) {
    case 0:
        this->currentState->setState(State::MAIN_MENU);
        this->searchedString = "~";
        break;
    case 1:
        this->searchedString = Prompt::getStringInput();
        break;
    }
    std::system("cls");
}

std::string &ContainsStringMenu::getSearchedString() {
    return this->searchedString;
}

// StringMenu class ------------------------------------------------------
StartsWithStrMenu::StartsWithStrMenu(CurrentState *currentState)
    : currentState(currentState) {}

StartsWithStrMenu::~StartsWithStrMenu() {}

void StartsWithStrMenu::update() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[94m0\033[0m] - Go back\n"
              << "  [\033[94m1\033[0m] - Write string\n";
    int option = Prompt::getInput(1);
    switch (option) {
    case 0:
        this->currentState->setState(State::MAIN_MENU);
        this->searchedString = "~";
        break;
    case 1:
        this->searchedString = Prompt::getStringInput();
        break;
    }
    std::system("cls");
}

std::string &StartsWithStrMenu::getSearchedString() {
    return this->searchedString;
}

// SequenceMenu class ------------------------------------------------------
SequenceMenu::SequenceMenu(CurrentState *currentState)
    : currentState(currentState) {}

SequenceMenu::~SequenceMenu() {}

void SequenceMenu::update() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[93m0\033[0m] - Go back\n"
              << "  [\033[93m1\033[0m] - Region sequence\n"
              << "  [\033[93m2\033[0m] - SOORP sequence\n"
              << "  [\033[93m3\033[0m] - Settlement sequence\n";
    int option = Prompt::getInput(3);
    switch (option) {
    case 0:
        this->currentState->setState(State::MAIN_MENU);
        this->option = option;
        break;
    default:
        this->option = option;
        break;
    }
    std::system("cls");
}

int SequenceMenu::getOption() { return this->option; }
