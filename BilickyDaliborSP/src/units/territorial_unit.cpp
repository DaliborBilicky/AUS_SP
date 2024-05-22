#include "units/territorial_unit.h"
#include "Algorithms.h"
#include <iostream>
#include <libds/heap_monitor.h>
#include <string>

TerritorialUnit::TerritorialUnit() {}

TerritorialUnit::TerritorialUnit(std::string &name, int code)
    : name(name), code(code) {}

TerritorialUnit::~TerritorialUnit() {}

const std::string &TerritorialUnit::getName() const { return this->name; }

const int TerritorialUnit::getCode() const { return this->code; }

void TerritorialUnit::print(std::ostream &os) const { os << this->name; }

std::ostream &operator<<(std::ostream &os,
                         const TerritorialUnit &territorialUnit) {
    territorialUnit.print(os);
    return os;
}

std::ostream &operator<<(std::ostream &os,
                         const UnitType &unitType) {
    std::string currentSeqName = "";
    switch (unitType) {
    case UnitType::REGION:
            currentSeqName = "REGION";
            break;
    case UnitType::SOORP:
            currentSeqName = "SOORP";
            break;
    case UnitType::SETTLEMENT:
            currentSeqName = "SETTLEMENT";
            break;
    }
	os << std::endl
	   << "[\033[95mCURRENT SEQUENCE\033[0m]\n"
	   << " \033[95m*\033[0m Current sequence is: "
	   << "\033[95m" << currentSeqName << "\033[0m";
    return os;
}
