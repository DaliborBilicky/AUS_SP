#include "units/Soorp.h"
#include "units/territorial_unit.h"

Soorp::Soorp() {}

Soorp::Soorp(std::string &name, int code) : TerritorialUnit(name, code) {}

Soorp::~Soorp() {}

void Soorp::print(std::ostream &os) const {
    os << this->getName() << " - " << this->getCode();
}
