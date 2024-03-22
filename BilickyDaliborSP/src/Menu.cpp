#include <string>
#include <iostream>
#include "Menu.h"

int Menu::mainMenu() {
    std::cout << std::endl << "#####  Menu  #####" << std::endl;
	std::string option = "";
	std::cout << "[0] End program" << std::endl;
	std::cout << "[1] Search in whole csv" << std::endl;
	std::cout << "[2] Search only one type" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, option); 
	if (option == "0") {
        return 0;
	} else if (option == "1") {
        Menu::subMenu();
	} else if (option == "2") {
        Menu::typeMenu();
	} else {
		std::cout << "Try again." << std::endl;
		return -1;		
	}
}

int Menu::subMenu() {
    std::cout << std::endl << "#####  Sub menu #####" << std::endl;
	std::string option = "";
	std::cout << "[0] Go back" << std::endl;
	std::cout << "[1] Starts with string" << std::endl;
	std::cout << "[2] Contains string" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, option); 
	if (option == "0") {
        return Menu::mainMenu();
	} else if (option == "1") {
		return 1;
	} else if (option == "2") {
		return 2;
	} else {
		std::cout << "Try again." << std::endl;
		return -1;		
	}
}

int Menu::typeMenu() {
    std::cout << std::endl << "#####  Type menu  #####" << std::endl;
	std::string option = "";
	std::cout << "[0] Go back" << std::endl;
	std::cout << "[1] Regions" << std::endl;
	std::cout << "[2] SOORPS" << std::endl;
	std::cout << "[3] Settlements" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, option); 
	if (option == "0") {
        return Menu::mainMenu();
	} else if (option == "1") {
		return 1;
	} else if (option == "2") {
		return 2;
	} else if (option == "3") {
		return 3;
	} else {
		std::cout << "Try again." << std::endl;
		return -1;		
	}
}
