#pragma once
#include <string>

class Prompt {
  public:
    static std::string getStringInput();
    static int getInput(int upperBound);
};
