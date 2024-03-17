#pragma once
#include "TerritorialUnit.h"


using namespace std;

class Region : public TerritorialUnit {
  public:
    Region();
    Region(string& name, int code);
    ~Region();
	string getFullCode();

    friend std::ostream &operator<<(std::ostream &os,
                                    const Region &region);
};
