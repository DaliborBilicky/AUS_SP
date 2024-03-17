#include "Settlement.h"

Settlement::Settlement() {}

Settlement::Settlement(
    string& name, int code, string& type, int cadastralArea, 
    int numOfResidents, int residentsUnder14, int residentsOver65, 
    char canalization, char water, char gas
)
    : TerritorialUnit(name, code), type(type), 
    cadastralArea(cadastralArea), numOfResidents(numOfResidents), 
    residentsUnder14(residentsUnder14), residentsOver65(residentsOver65), 
    canalization(canalization), water(water), gas(gas) {}

Settlement::~Settlement() {}

string& Settlement::getType() { return type; }

int Settlement::getCadastralArea() { return  cadastralArea; }

int Settlement::getNumOfResidents() { return  numOfResidents; }

int Settlement::getResidentsUnder14() { return residentsUnder14; }

int Settlement::getResidentsOver65() { return residentsOver65; }

char Settlement::getCanalization() { return canalization; }

char Settlement::getWater() { return water; }

char Settlement::getGas() { return gas; }


std::ostream &operator<<(std::ostream &os, const Settlement &settlement) {
    os << settlement.getName() 
       << " | " << settlement.getCode() 
       << " | " << settlement.type 
       << " | " << settlement.cadastralArea 
	   << " | " << settlement.numOfResidents 
	   << " | " << settlement.residentsUnder14 
	   << " | " << settlement.residentsOver65
	   << " | " << settlement.canalization 
	   << " | " << settlement.water 
	   << " | " << settlement.gas;
	return os;
}
