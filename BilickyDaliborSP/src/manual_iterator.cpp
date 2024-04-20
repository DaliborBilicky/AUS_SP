#include "manual_iterator.h"
#include "units/territorial_unit.h"
#include <libds/heap_monitor.h>
#include <libds/amt/explicit_hierarchy.h>
#include <iostream>
#include <string>


ManualIterator::ManualIterator() {}

ManualIterator::ManualIterator(Hierarchy *hierarchy) 
    : hierarchy(hierarchy), currentPos(hierarchy->accessRoot()) {}

ManualIterator::~ManualIterator() {}

void ManualIterator::moveUp() {
    Node* pos = this->hierarchy->accessParent(*this->currentPos);
    if (pos != nullptr) {
        this->currentPos = pos;
        this->level--;
    }
}

void ManualIterator::moveDown(int index) {
    Node* pos = this->hierarchy->accessSon(*this->currentPos, index);
    if (pos != nullptr) {
        this->currentPos = pos;
        this->level++;
    }
}

Node *ManualIterator::getCurrentPos() { return this->currentPos; }

void ManualIterator::printOptions() { 
}


std::ostream &operator<<(
    std::ostream &os, const ManualIterator &mIt) { 
    std::string levelName = "";
    switch (mIt.level) {
        case 0:
            levelName = "ROOT";
            break;
        case 1:
            levelName = "REGION";
            break;
        case 2:
            levelName = "SOORP";
            break;
        case 3:
            levelName = "SETTLEMENT";
            break;
    }
	os << std::endl
	   << "[\033[95m" << levelName << "\033[0m]\n"
	   << " \033[95m*\033[0m Current position of manual iterator: "
	   << "\033[95m" << mIt.currentPos->data_->getName() << "\033[0m";
    return os;
}

