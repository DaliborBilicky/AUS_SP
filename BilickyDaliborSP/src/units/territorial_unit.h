#pragma once
#include <iostream>
#include <libds/heap_monitor.h>
#include <locale>
#include <string>

class TerritorialUnit {
  private:
    std::string name = "";
    int code = 0;

  public:
    TerritorialUnit();
    TerritorialUnit(std::string &name, int code);
    virtual ~TerritorialUnit();
    const std::string &getName() const;
    const int getCode() const;
    virtual void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os,
                                    const TerritorialUnit &territorialUnit);
};

enum UnitType {
    REGION = 1, SOORP = 2, SETTLEMENT = 3
};

std::ostream &operator<<(std::ostream &os, const UnitType &unitType);
