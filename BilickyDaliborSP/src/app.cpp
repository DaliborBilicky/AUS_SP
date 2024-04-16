#include "app.h"
#include "algorithms.h"
#include "menu/current_state.h"
#include "menu/states.h"
#include "units/territorial_unit.h"
#include "units/units.h"
#include "manual_iterator.h"
#include <functional>
#include <iostream>
#include <libds/amt/implicit_sequence.h>
#include <libds/amt/explicit_hierarchy.h>
#include <string>

App::App()
    : mainMenu(MainMenu(&currentState)), typeMenu(TypeMenu(&currentState)),
      mItMenu(ManualIteratorMenu(&currentState)),
      containsStringMenu(ContainsStringMenu(&currentState)),
      startsWithStrMenu(StartsWithStrMenu(&currentState)) {
    std::string name = "ÈESKÁ REPUBLIKA";
	TerritorialUnit *cr = new TerritorialUnit(name, 0);
	this->czechia.emplaceRoot().data_ = cr;
    this->manualIt = ManualIterator(&this->czechia);
}

App::~App() {
    this->czechia.processPostOrder(czechia.accessRoot(), 
	[&](ds::amt::MultiWayExplicitHierarchyBlock<TerritorialUnit*> *block) { 
		delete block->data_;
		block->data_ = nullptr;
	});
}

void App::start() {
    // Algorithms::parseCSV(csv_path, this->settlements, this->soorps, this->regions);
    Algorithms::parseCSV("./res/CR_win1250.csv", this->czechia);
}

void App::mainLoop() {
    while (true) {
        std::cout << std::endl << "* " << this->manualIt << std::endl;
        switch (this->currentState.getState()) {
        case State::EXIT:
           return;
        case State::MAIN_MENU:
            this->mainMenu.show();
            break;
        case State::MANUAL_ITERATOR_MENU:
            this->mItMenu.show();
            if (this->mItMenu.getOption() == 1) {
                this->manualIt.moveUp();
            } else if (this->mItMenu.getOption() == 2){
                this->manualIt.moveDown(1);
            }
            break;
        case State::STARTS_WITH_STR_MENU:
            this->startsWithStrMenu.show();
            if (!this->startsWithStrMenu.isExiting()) {
                this->processStartsWithString(
                    this->startsWithStrMenu.getSearchedString());
                this->printOutput();
            }
            break;
        case State::CONTAINS_STR_MENU:
            this->containsStringMenu.show();
            if (!this->containsStringMenu.isExiting()) {
                this->processContainsString(
                    this->containsStringMenu.getSearchedString());
                this->printOutput();
            }
            break;
        case State::TYPE_MENU:
            this->typeMenu.show();
            if (this->typeMenu.getOption() != 0) {
				this->processIsType(this->typeMenu.getOption());
				this->printOutput();
            }
            break;
        default:
            break;
        }
    }
}

void App::processStartsWithString(std::string &searchedString) {
    std::string strLover = Algorithms::lowerCase(searchedString);
    std::string strUpper = Algorithms::upperCase(searchedString);

    std::function<bool(TerritorialUnit *)> predicate =
        [&](TerritorialUnit *unit) {
            for (int i = 0; i < strUpper.size(); i++) {
                if (strLover[i] != unit->getName()[i] &&
                    strUpper[i] != unit->getName()[i]) {
                    return false;
                }
            }
            return true;
        };
 
    auto begin = PreOrderIterator(
        &this->czechia, this->manualIt.getCurrentPos());
    Algorithms::process(begin, this->czechia.end(),
                        predicate, this->results);
}

void App::processContainsString(std::string &searchedString) {
    std::string strLover = Algorithms::lowerCase(searchedString);
    std::string strUpper = Algorithms::upperCase(searchedString);

    std::function<bool(TerritorialUnit *)> predicate =
        [&](TerritorialUnit *unit) {
            int index = 0;
            int i = 0;
            while (i < unit->getName().size() && index < strLover.size()) {
                if (strLover[index] == unit->getName()[i] ||
                    strUpper[index] == unit->getName()[i]) {
                    index++;
                } else {
                    index = 0;
                }
                i++;
            }
            return index == strLover.size();
        };

    Algorithms::process(this->czechia.begin(), this->czechia.end(),
                        predicate, this->results);
}

void App::processIsType(int wantedType) {
    std::function<bool(TerritorialUnit *)> predicate =
        [&](TerritorialUnit *unit) {
            switch (wantedType) {
            case 1:
                return dynamic_cast<const Region *>(unit) != nullptr;
            case 2:
                return dynamic_cast<const Soorp *>(unit) != nullptr;
            case 3:
                return dynamic_cast<const Settlement *>(unit) != nullptr;
            }
            return false;
        };

    Algorithms::process(this->czechia.begin(), this->czechia.end(), predicate,
                        this->results);
}

void App::printOutput() {
    std::cout << "\n[\033[95mOUTPUT\033[0m]\n";

    if (results.size() == 0) {
        std::cout << " \033[95m*\033[0m There is nothing with this option."
                  << std::endl;
    } else {
        std::cout << " \033[95m*\033[0m Number of results: " << results.size()
                  << std::endl
                  << std::endl;

        for (int i = 0; i < results.size(); i++) {
            std::cout << *(results.access(i)->data_) << std::endl;
        }
    }
    this->results.clear();
}
