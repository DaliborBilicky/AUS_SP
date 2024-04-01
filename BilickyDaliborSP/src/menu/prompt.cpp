#include "menu/prompt.h"
#include <iostream>
#include <sstream>
#include <string>

std::string Prompt::getStringInput() {
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
        if (input[0] == '0') {
            return 0;
        }
        std::stringstream sStream(input);

        if (sStream >> intInput) {
            if (0 <= intInput && intInput <= upperBound) {
                wrongInput = false;
                return intInput;
            }
            std::cout << "[\033[31mWRONG INPUT"
                      << "\033[0m]\n"
                      << " \033[31m*\033[0m Number out of range." << std::endl;
        } else {
            std::cout << "[\033[31mWRONG INPUT"
                      << "\033[0m]\n"
                      << " \033[31m*\033[0m Not a number." << std::endl;
        }
    }
    return 0;
}
