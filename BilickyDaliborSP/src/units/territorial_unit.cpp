#include "units/territorial_unit.h"
#include "Algorithms.h"

TerritorialUnit::TerritorialUnit() {}

TerritorialUnit::TerritorialUnit(std::string &name, int code) 
    : name(name), code(code), unitType(TerrUnitType::NONE) {}

TerritorialUnit::~TerritorialUnit() {}

const std::string &TerritorialUnit::getName() const { return this->name; }

const int TerritorialUnit::getCode() const { return this->code; }

const TerrUnitType TerritorialUnit::getUnitType() const { return this->unitType; }

void TerritorialUnit::print(std::ostream &os) const {
    os << this->name << " - " << this->code;
}

std::ostream &operator<<(std::ostream &os, const TerritorialUnit &territorialUnit) {
    territorialUnit.print(os);
	return os;
}
