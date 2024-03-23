#pragma once
#include "units/territorial_unit.h"

class Region : public TerritorialUnit {
  public:
    Region();
    Region(std::string &name, int code);
    ~Region();
    std::string getFullCode();

    virtual void print(std::ostream &os) const;
};
