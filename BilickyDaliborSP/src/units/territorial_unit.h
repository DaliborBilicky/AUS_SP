#pragma once
#include <iostream>
#include <string>

enum TerrUnitType {
    NONE,
    REGION,
    SOORP,
    SETTLEMENT
};

class TerritorialUnit {
  private:
    TerrUnitType unitType = TerrUnitType::NONE;
    std::string name = "";
    int code = 0;

  public:
    TerritorialUnit();
    TerritorialUnit(std::string &name, int code);
    ~TerritorialUnit();
    const std::string &getName() const;
    const int getCode() const;
    const TerrUnitType getUnitType() const;

    friend std::ostream &operator<<(std::ostream &os,
                                    const TerritorialUnit &territorialUnit);
    virtual void print(std::ostream &os) const;
};
