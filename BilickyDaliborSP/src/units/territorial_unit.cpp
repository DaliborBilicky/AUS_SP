#include "units/territorial_unit.h"
#include "Algorithms.h"
#include <iostream>
#include <libds/heap_monitor.h>

TerritorialUnit::TerritorialUnit() {}

TerritorialUnit::TerritorialUnit(std::string &name, int code)
    : name(name), code(code) {}

TerritorialUnit::~TerritorialUnit() {}

const std::string &TerritorialUnit::getName() const { return this->name; }

const int TerritorialUnit::getCode() const { return this->code; }

void TerritorialUnit::print(std::ostream &os) const {
    os << this->name;
}

std::ostream &operator<<(std::ostream &os,
                         const TerritorialUnit &territorialUnit) {
    territorialUnit.print(os);
    return os;
}

bool operator==(const TerritorialUnit &me, const TerritorialUnit &other) {
    return me.code == other.code && me.name == other.name;
}
