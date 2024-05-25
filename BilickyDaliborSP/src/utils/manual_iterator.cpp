#include "utils/manual_iterator.h"
#include "menu/prompt.h"
#include "units/territorial_unit.h"
#include <iostream>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/heap_monitor.h>
#include <string>

ManualIterator::ManualIterator() {}

ManualIterator::ManualIterator(Hierarchy *hierarchy)
    : hierarchy(hierarchy), currentPos(hierarchy->accessRoot()) {}

ManualIterator::~ManualIterator() {}

void ManualIterator::moveUp() {
    Node *pos = this->hierarchy->accessParent(*this->currentPos);
    if (pos != nullptr) {
        this->currentPos = pos;
        this->level--;
    }
}

void ManualIterator::moveDown(int index) {
    Node *pos = this->hierarchy->accessSon(*this->currentPos, index);
    if (pos != nullptr) {
        this->currentPos = pos;
        this->level++;
    }
}

Node *ManualIterator::getCurrentPos() { return this->currentPos; }

void ManualIterator::printOptions(int option) {
    Node *son = nullptr;
    int degree = this->hierarchy->degree(*this->currentPos);

    if (option == 1 && this->level > 0) {
        this->moveUp();
    } else if (option == 2 && this->level < 3) {
        for (int i = 0; i < degree; i++) {
            son = this->hierarchy->accessSon(*this->currentPos, i);
            std::cout << "  [" << "\033[95m" << i << "\033[0m" << "] - "
                      << son->data_->getName() << std::endl;
        }
        int index = Prompt::getInput(--degree);
        this->moveDown(index);
    }
    std::system("cls");
}

std::ostream &operator<<(std::ostream &os, const ManualIterator &mIt) {
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
