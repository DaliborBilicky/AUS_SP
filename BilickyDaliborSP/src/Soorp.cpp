#include "Soorp.h"
#include "TerritorialUnit.h"

Soorp::Soorp() {}

Soorp::Soorp(string name, string code) : TerritorialUnit(name, code) {}

Soorp::~Soorp() {}

std::ostream &operator<<(std::ostream &os, const Soorp &soorp) {
    return os << soorp.getName() << " " << soorp.getCode();
}
