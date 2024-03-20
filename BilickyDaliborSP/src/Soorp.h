#pragma once
#include "TerritorialUnit.h"

using namespace std;

class Soorp : public TerritorialUnit {
  public:
    Soorp();
    Soorp(string& name, int code);
    ~Soorp();

    virtual void print(ostream &os) const;
};

