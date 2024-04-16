#pragma once
#include <string>
#include <libds/heap_monitor.h>

class Prompt {
  public:
    static std::string getStringInput();
    static int getInput(int upperBound);
};
