#pragma once
#include "units/territorial_unit.h"

class Soorp : public TerritorialUnit {
  public:
    Soorp();
    Soorp(std::string &name, int code);
    ~Soorp();

    virtual void print(std::ostream &os) const;
};
