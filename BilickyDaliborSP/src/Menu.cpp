#include "menu.h"
#include "units/territorial_unit.h"
#include "units/settlement.h"
#include "units/region.h"
#include "units/soorp.h"
#include "algorithms.h"
#include <functional>
#include <iostream>
#include <string>

Menu::Menu() {}

Menu::~Menu() {}

void Menu::mainMenu() {
    std::string input = "";

    std::cout << std::endl << "#####  Pick predicate #####" << std::endl;
    std::cout << "[0] End program" << std::endl;
    std::cout << "[1] Starts with string" << std::endl;
    std::cout << "[2] Contains string" << std::endl;
    std::cout << "[3] Is type" << std::endl;
    std::cout << "> ";

    std::getline(std::cin, input);

    if (input == "0") {
    } else if (input == "1") {
    } else if (input == "2") {
    } else if (input == "3") {
        this->inputType = InputType::NUM_INPUT;
    } else {
        std::cout << std::endl << "* Try again." << std::endl;
        this->currentState = State::MAIN_MENU;
    }
}

void Menu::takeInput() { 
    if (this->inputType == InputType::STRING_INPUT) {
		std::cout << "* Enter string you want to search: ";
		std::getline(std::cin, this->wantedString);
		Algorithms::lowerCase(this->wantedString);
		this->wantedStringUpper = this->wantedString;
		Algorithms::upperCase(this->wantedStringUpper);
    } else if (this->inputType == InputType::NUM_INPUT) {
        std::string input = "";

		std::cout << "[1] Region" << std::endl;
		std::cout << "[2] SOORP" << std::endl;
		std::cout << "[3] Settlement" << std::endl;
		std::cout << "> ";

        std::getline(std::cin, input);

        this->typePick = std::atoi(input.c_str()); 
    } else {
        std::cout << std::endl << "* Try again." << std::endl;
        this->currentState = State::SUB_MENU;
        this->inputType = InputType::NONE;
    }
}

void Menu::subMenu() {
    std::string input = "";

    std::cout << std::endl << "#####  Pick where to search  #####" << std::endl;
    std::cout << "[0] Go back" << std::endl;
    std::cout << "[1] Search in everything" << std::endl;
    std::cout << "[2] Search in regions" << std::endl;
    std::cout << "[3] Search in SOORPS" << std::endl;
    std::cout << "[4] Search in settlements" << std::endl;
    std::cout << "> ";

    std::getline(std::cin, input);

    if (input == "0") {
        this->currentState = State::MAIN_MENU;
    } else if (input == "1") {
        this->inputType = InputType::SEARCH_EVERYTHING;
    } else if (input == "2") {
        this->inputType = InputType::SEARCH_REGION;
    } else if (input == "3") {
        this->inputType = InputType::SEARCH_SOORP;
    } else if (input == "4") {
        this->inputType = InputType::SEARCH_SETTLEMENT;
    } else {
        std::cout << std::endl << "* Try again." << std::endl;
        this->currentState = State::SUB_MENU;
        return;
    }
    this->currentState = State::MAIN_MENU;
    this->inputType = InputType::STRING_INPUT;
}

State Menu::getCurrentState() { return this->currentState; }

InputType Menu::getInputType() { 
    if (this->inputType != InputType::NUM_INPUT &&
        this->inputType != InputType::STRING_INPUT) {
        return this->inputType;
    }
    return InputType::NONE;
}

std::function<bool(TerritorialUnit)>& Menu::getPredicate() {
    return this->predicate;
}
