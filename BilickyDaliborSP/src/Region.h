#pragma once
#include "TerritorialUnit.h"


using namespace std;

class Region : private TerritorialUnit {
  public:
    Region();
    Region(string name, string code);
    ~Region();

    friend std::ostream &operator<<(std::ostream &os,
                                    const Region &region);
};
