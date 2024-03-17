#include "TerritorialUnit.h"

TerritorialUnit::TerritorialUnit() {}

TerritorialUnit::TerritorialUnit(string &name, int &code) : name(name), code(code) {}

TerritorialUnit::~TerritorialUnit() {}

const string& TerritorialUnit::getName() const { return name; }

const int& TerritorialUnit::getCode() const { return code; }

std::ostream &operator<<(std::ostream &os, const TerritorialUnit &territorialUnit) {
	os << territorialUnit.name << " " << territorialUnit.code;
	return os;
}
