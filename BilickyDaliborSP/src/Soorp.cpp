#include "Soorp.h"
#include "TerritorialUnit.h"

Soorp::Soorp() {}

Soorp::Soorp(string& name, int code) : TerritorialUnit(name, code) {}

Soorp::~Soorp() {}

void Soorp::print(ostream &os) const {
    os << this->getName() << " - " << this->getCode();
}

