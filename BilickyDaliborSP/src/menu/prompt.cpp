#include "menu/prompt.h"
#include <iostream>
#include <string>
#include <sstream>


std::string& Prompt::getStringInput() { 
    std::string input = "";
    std::cout << "Input string: ";
    std::getline(std::cin, input);
    return input;
}

int Prompt::getInput(int upperBound) {
    std::string input = "";
    int intInput = 0;
    bool wrongInput = true;

    while (wrongInput) {
        std::cout << "> ";
		std::getline(std::cin, input); 
		std::stringstream sStream(input);

		if (sStream >> intInput) {
			if (0 <= intInput && intInput <= upperBound) {
				wrongInput = false;
				return intInput;
			}
			std::cout << "\033[31m"
					  << "Wrong input! Try numbers from options."
					  << "\033[0m"
					  << std::endl;
		} else {
			std::cout << "\033[31m"
					  << "Wrong input! Try again."
					  << "\033[0m"
					  << std::endl;
		} 
    }
}

