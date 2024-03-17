#include <string>
#include "Region.h"
#include "TerritorialUnit.h"

using namespace std;

Region::Region() {}

Region::Region(string& name, int code) : TerritorialUnit(name, code) {}

Region::~Region() {}

string Region::getFullCode() {
    return "CZ0" + to_string(this->getCode());
}

std::ostream &operator<<(std::ostream &os, const Region &region) {
    return os << region.getName() << " - CZ0" << region.getCode();
}
