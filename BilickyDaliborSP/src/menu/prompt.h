#pragma once
#include <libds/heap_monitor.h>
#include <string>

class Prompt {
  public:
    static std::string getStringInput();
    static int getInput(int upperBound);
};
