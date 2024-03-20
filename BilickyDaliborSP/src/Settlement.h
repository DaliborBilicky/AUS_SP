#pragma once
#include "TerritorialUnit.h"
#include <iostream>


using namespace std;
class Settlement : public TerritorialUnit {
  private:
    string type = "";
    int cadastralArea = 0;
    int numOfResidents = 0; 
    int residentsUnder14 = 0;
    int residentsOver65 = 0;
    char canalization = '-';
    char water = '-';
    char gas = '-';

  public:
    Settlement();
    Settlement(string &name, int code, string &type, int cadastralArea,
               int numOfResidents, int residentsUnder14, int residentsOver65,
               char canalization, char water, char gas);
    ~Settlement();
    string& getType();
    int getCadastralArea();
    int getNumOfResidents();
    int getResidentsUnder14();
    int getResidentsOver65();
    char getCanalization();
    char getWater();
    char getGas();

    virtual void print(ostream &os) const;
};
