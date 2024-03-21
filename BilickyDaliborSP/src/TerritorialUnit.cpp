#include "TerritorialUnit.h"
#include "Algorithms.h"

TerritorialUnit::TerritorialUnit() {}

TerritorialUnit::TerritorialUnit(string &name, int code) : name(name), code(code) {}

TerritorialUnit::~TerritorialUnit() {}

const string &TerritorialUnit::getName() const { return name; }

const int &TerritorialUnit::getCode() const { return code; }

void TerritorialUnit::print(ostream &os) const {
    os << this->name << " - " << this->code;
}

ostream &operator<<(ostream &os, const TerritorialUnit &territorialUnit) {
    territorialUnit.print(os);
	return os;
}
