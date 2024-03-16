#include "Region.h"
#include "TerritorialUnit.h"

Region::Region() {}

Region::Region(string name, string code) : TerritorialUnit(name, code) {}

Region::~Region() {}

std::ostream &operator<<(std::ostream &os, const Region &region) {
    return os << region.getName() << " " << region.getCode();
}
