#pragma once
#include "TerritorialUnit.h"

using namespace std;

class Soorp : private TerritorialUnit {
  public:
    Soorp();
    Soorp(string name, string code);
    ~Soorp();

    friend std::ostream &operator<<(std::ostream &os,
                                    const Soorp &soorp);
};

