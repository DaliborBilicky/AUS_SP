#pragma once
#include "TerritorialUnit.h"

using namespace std;

class Soorp : public TerritorialUnit {
  public:
    Soorp();
    Soorp(string& name, int code);
    ~Soorp();

    friend std::ostream &operator<<(std::ostream &os,
                                    const Soorp &soorp);
};

