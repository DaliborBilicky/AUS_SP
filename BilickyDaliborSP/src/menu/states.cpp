#include "menu/states.h"
#include "menu/prompt.h"


// MainMenu class ------------------------------------------------------
MainMenu::MainMenu(CurrentState* currentState) 
    : currentState(currentState) {}

MainMenu::~MainMenu() {}

void MainMenu::show() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[95m0\033[0m] - Exit program\n"
              << "  [\033[95m1\033[0m] - Move in hierarchy\n"
              << "  [\033[95m2\033[0m] - Starts with string\n"
              << "  [\033[95m3\033[0m] - Contains string\n"
              << "  [\033[95m4\033[0m] - Is specific territorial type\n";
    int option = Prompt::getInput(4);
    switch (option) { 
        case 0:
            this->currentState->setState(State::EXIT);
            break;
        case 1:
            this->currentState->setState(State::HIERARCHY_MENU);
            break;
        case 2:
            this->currentState->setState(State::STARTS_WITH_STR_MENU);
            break;
        case 3:
            this->currentState->setState(State::CONTAINS_STR_MENU);
            break;
        case 4:
            this->currentState->setState(State::TYPE_MENU);
            break;
        default:
            break;
    }
}


// IsTypeMenu class ------------------------------------------------------
TypeMenu::TypeMenu(CurrentState *currentState)
	: currentState(currentState) {}

TypeMenu::~TypeMenu() {}

void TypeMenu::show() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[93m0\033[0m] - Go back\n"
              << "  [\033[93m1\033[0m] - Type region\n"
              << "  [\033[93m2\033[0m] - Type SOORP\n"
              << "  [\033[93m3\033[0m] - Type settlement\n";
    int option = Prompt::getInput(3);
    switch (option) {
        case 0:
            this->currentState->setState(State::MAIN_MENU);     
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
HierarchyMenu::HierarchyMenu(CurrentState *currentState)
	: currentState(currentState) {}

HierarchyMenu::~HierarchyMenu() {}

void HierarchyMenu::show() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[94m0\033[0m] - Go back\n"
              << "  [\033[94m1\033[0m] - Up in hierarchy\n"
              << "  [\033[94m2\033[0m] - Down in hierarchy\n";
    int option = Prompt::getInput(2);
    switch (option) {
        case 0:
            this->currentState->setState(State::MAIN_MENU);     
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
ContainsStringMenu::ContainsStringMenu(CurrentState* currentState)
	: currentState(currentState) {}

ContainsStringMenu::~ContainsStringMenu() {}

void ContainsStringMenu::show() {
    std::cout << this->TITLE << this->INFO;
	std::cout << "  [\033[92m0\033[0m] - Go back\n"
			  << "  [\033[92m1\033[0m] - Write string\n";
    int option = Prompt::getInput(1);
    switch (option) {
        case 0:
            this->currentState->setState(State::MAIN_MENU);     
            break;
        case 1:
            this->searchedString = Prompt::getStringInput();
            break;
		default:
			break;
    }
}


// StringMenu class ------------------------------------------------------
StartsWithStrMenu::StartsWithStrMenu(CurrentState *currentState) 
    : currentState(currentState) {}

StartsWithStrMenu::~StartsWithStrMenu() {}

void StartsWithStrMenu::show() {
    std::cout << this->TITLE << this->INFO;
    std::cout << "  [\033[96m0\033[0m] - Go back\n"
              << "  [\033[96m1\033[0m] - Write string\n";
    int option = Prompt::getInput(1);
    switch (option) {
    case 0:
        this->currentState->setState(State::MAIN_MENU);
        break;
    case 1:
        this->searchedString = Prompt::getStringInput();
        break;
    default:
        break;
    }
}
