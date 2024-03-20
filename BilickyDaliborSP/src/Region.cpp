#include <string>
#include "Region.h"
#include "TerritorialUnit.h"

using namespace std;

Region::Region() {}

Region::Region(string& name, int code) : TerritorialUnit(name, code) {}

Region::~Region() {}

string Region::getFullCode() {
    return "CZ0" + to_string(this->getCode()); }

void Region::print(ostream &os) const {
    os << this->getName() << " - CZ0" << this->getCode();
}
