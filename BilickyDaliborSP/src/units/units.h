#pragma once
#include "units/territorial_unit.h"
#include <iostream>
#include <libds/heap_monitor.h>
#include <string>

class Region : public TerritorialUnit {
  public:
    Region();
    Region(std::string &name, int code);
    ~Region();
    std::string getFullCode();

    void print(std::ostream &os) const override;
};

class Soorp : public TerritorialUnit {
  public:
    Soorp();
    Soorp(std::string &name, int code);
    ~Soorp();

    void print(std::ostream &os) const override;
};

class Settlement : public TerritorialUnit {
  private:
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

    void print(std::ostream &os) const override;
};
