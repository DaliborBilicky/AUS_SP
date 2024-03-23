#include "Region.h"
#include "units/territorial_unit.h"
#include <string>

Region::Region() {}

Region::Region(std::string &name, int code) : TerritorialUnit(name, code) {}

Region::~Region() {}

std::string Region::getFullCode() { return "CZ0" + std::to_string(this->getCode()); }

void Region::print(std::ostream &os) const {
    os << this->getName() << " - CZ0" << this->getCode();
}
