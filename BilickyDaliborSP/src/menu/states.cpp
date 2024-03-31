#include "menu/states.h"
#include "menu/prompt.h"


// MainMenu class ------------------------------------------------------
MainMenu::MainMenu() {}

MainMenu::MainMenu(CurrentState currentState) 
    : currentState(currentState) {}

MainMenu::~MainMenu() {}

void MainMenu::show() {
    std::cout << "\033[33m" << this->TITLE << "\033[0m" << std::endl;
    std::cout << " " << this->INFO << std::endl << std::endl;
    std::cout << "  [0] - Exit program" << std::endl;
    std::cout << "  [1] - Move in hierarchy" << std::endl;
    std::cout << "  [2] - Starts with string" << std::endl;
    std::cout << "  [3] - Contains string" << std::endl;
    std::cout << "  [4] - Is specific territorial type" << std::endl;
    int option = Prompt::getInput(4);
    switch (option) { 
        case 0:
            this->currentState.setState(State::EXIT);
            break;
        case 1:
            this->currentState.setState(State::HIERARCHY_MENU);
            break;
        case 2:
            this->currentState.setState(State::STARTS_WITH_STR_MENU);
            break;
        case 3:
            this->currentState.setState(State::CONTAINS_STR_MENU);
            break;
        case 4:
            this->currentState.setState(State::TYPE_MENU);
            break;
        default:
            break;
    }
}


// IsTypeMenu class ------------------------------------------------------
TypeMenu::TypeMenu() {}

TypeMenu::TypeMenu(CurrentState currentState) 
	: currentState(currentState) {}

TypeMenu::~TypeMenu() {}

void TypeMenu::show() {
    std::cout << "\033[33m" << this->TITLE << "\033[0m" << std::endl;
    std::cout << " " << this->INFO << std::endl;
    std::cout << "  [0] - Go back" << std::endl;
    std::cout << "  [1] - Type region" << std::endl;
    std::cout << "  [2] - Type SOORP" << std::endl;
    std::cout << "  [3] - Type settlement" << std::endl;
    int option = Prompt::getInput(3);
    switch (option) {
        case 0:
            this->currentState.setState(State::MAIN_MENU);     
            break;
        case 1:
            this->pickedType = TerrUnitType::REGION;
            break;
        case 2:
            this->pickedType = TerrUnitType::SOORP;
            break;
        case 3:
            this->pickedType = TerrUnitType::SETTLEMENT;
            break;
		default:
			break;
    }
}

TerrUnitType TypeMenu::getPickedType() { return this->pickedType; }


// HierarchyMenu class ------------------------------------------------------
HierarchyMenu::HierarchyMenu() {}

HierarchyMenu::HierarchyMenu(CurrentState currentState) {}

HierarchyMenu::~HierarchyMenu() {}

void HierarchyMenu::show() {
    std::cout << "\033[33m" << this->TITLE << "\033[0m" << std::endl;
    std::cout << " " << this->INFO << std::endl;
    std::cout << "  [0] - Go back" << std::endl;
    std::cout << "  [1] - Up in hierarchy" << std::endl;
    std::cout << "  [2] - Down in hierarchy" << std::endl;
    int option = Prompt::getInput(2);
    switch (option) {
        case 0:
            this->currentState.setState(State::MAIN_MENU);     
            break;
        case 1:
            std::cout << "Up in hierarchy" << std::endl;
            break;
        case 2:
            std::cout << "Down in hierarchy" << std::endl;
            break;
		default:
			break;
    }
}


// StringMenu class ------------------------------------------------------
StringMenu::StringMenu() {}

StringMenu::StringMenu(CurrentState currentState) {}

StringMenu::~StringMenu() {}

void StringMenu::show() {
    std::cout << "\033[33m" << this->TITLE << "\033[0m" << std::endl;
    std::cout << " " << this->INFO << std::endl;
    std::cout << "  [0] - Go back" << std::endl;
    std::cout << "  [1] - Write string" << std::endl;
    int option = Prompt::getInput(1);
    switch (option) {
        case 0:
            this->currentState.setState(State::MAIN_MENU);     
            break;
        case 1:
            this->searchedString = Prompt::getStringInput();
            break;
		default:
			break;
    }
}
