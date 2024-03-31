#pragma once
#include "units/territorial_unit.h"
#include <iostream>

class Region : public TerritorialUnit {
  private:
    TerrUnitType unitType = TerrUnitType::REGION;
  public:
    Region();
    Region(std::string &name, int code);
    ~Region();
    std::string getFullCode();

    virtual void print(std::ostream &os) const;
};



class Soorp : public TerritorialUnit {
  private:
    TerrUnitType unitType = TerrUnitType::SOORP;
  public:
    Soorp();
    Soorp(std::string &name, int code);
    ~Soorp();

    virtual void print(std::ostream &os) const;
};



class Settlement : public TerritorialUnit {
  private:
    TerrUnitType unitType = TerrUnitType::SETTLEMENT;
    std::string type = "";
    int cadastralArea = 0;
    int numOfResidents = 0;
    int residentsUnder14 = 0;
    int residentsOver65 = 0;
    char canalization = '-';
    char water = '-';
    char gas = '-';

  public:
    Settlement();
    Settlement(std::string &name, int code, std::string &type,
               int cadastralArea, int numOfResidents, int residentsUnder14,
               int residentsOver65, char canalization, char water, char gas);
    ~Settlement();
    std::string &getType();
    int getCadastralArea();
    int getNumOfResidents();
    int getResidentsUnder14();
    int getResidentsOver65();
    char getCanalization();
    char getWater();
    char getGas();

    virtual void print(std::ostream &os) const;
};
