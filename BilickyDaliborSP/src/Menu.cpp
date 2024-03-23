#include <string>
#include <iostream>
#include "Menu.h"

Menu::Menu() {}

Menu::~Menu() {}

void Menu::mainMenu() {
	std::string input = "";

    std::cout << std::endl << "#####  Menu  #####" << std::endl;
	std::cout << "[0] End program" << std::endl;
	std::cout << "[1] Search in everything" << std::endl;
	std::cout << "[2] Search in regions" << std::endl;
	std::cout << "[3] Search in SOORPS" << std::endl;
	std::cout << "[4] Search in Settlements" << std::endl;
	std::cout << "> ";

	std::getline(std::cin, input); 

	if (input == "0") {	
		this->option = Options::EXIT;
	} else if (input == "1") {
        this->option = Options::EVERYTHING;
	} else if (input == "2") {
        this->option = Options::REGIONS;	
	} else if (input == "3") {
        this->option = Options::SOORPS;	
	} else if (input == "4") {
        this->option = Options::SETTLEMENTS;	
	} else {
        this->option = Options::WRONG_INPUT;
	}

}

Predicates Menu::subMenu() { 
	std::string input = "";

    std::cout << std::endl << "#####  Pick predicate #####" << std::endl;
	std::cout << "[0] Go back" << std::endl;
	std::cout << "[1] Starts with string" << std::endl;
	std::cout << "[2] Contains string" << std::endl;
	std::cout << "> ";

	std::getline(std::cin, input); 

	if (input == "0") {	
		this->option = Options::NONE;
	} else if (input == "1") {
		return Predicates::STARTS_WITH_STRING; 
	} else if (input == "2") {
		return Predicates::CONTAINS_STRING; 
	} else {
		std::cout << "Try again." << std::endl;
        this->option = Options::WRONG_INPUT;
	}
    return Predicates::NOTHING;
}

int Menu::getOption() { return this->option; }
