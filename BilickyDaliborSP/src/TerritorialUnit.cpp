#include "TerritorialUnit.h"

TerritorialUnit::TerritorialUnit() {}

TerritorialUnit::TerritorialUnit(string &name, string &code) : name(name), code(code) {}

TerritorialUnit::~TerritorialUnit() {}

const string& TerritorialUnit::getName() const { return name; }

const string& TerritorialUnit::getCode() const { return code; }

std::ostream &operator<<(std::ostream &os, const TerritorialUnit &territorialUnit) {
	os << territorialUnit.name << " " << territorialUnit.code;
	return os;
}
