#include "app.h"
#include "algorithms.h"
#include "menu/current_state.h"
#include "menu/states.h"
#include "units/territorial_unit.h"
#include "units/units.h"
#include <functional>
#include <iostream>
#include <libds/amt/implicit_sequence.h>
#include <string>

App::App()
    : mainMenu(MainMenu(&currentState)), typeMenu(TypeMenu(&currentState)),
      hierarchyMenu(HierarchyMenu(&currentState)),
      containsStringMenu(ContainsStringMenu(&currentState)),
      startsWithStrMenu(StartsWithStrMenu(&currentState)) {}

App::~App() {}

void App::start() {
    std::string csv_path = "./res/CR_win1250.csv";
    Algorithms::parseCSV(csv_path, this->settlements, this->soorps,
                         this->regions);
}

void App::mainLoop() {
    while (true) {
        switch (this->currentState.getState()) {
        case State::EXIT:
            return;
        case State::MAIN_MENU:
            this->mainMenu.show();
            break;
        case State::HIERARCHY_MENU:
            this->hierarchyMenu.show();
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
            if (!this->typeMenu.isExiting()) {
                this->processIsType(this->typeMenu.getOption());
                this->printOutput();
            }
            break;
        default:
            break;
        }
        this->results.clear();
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

    Algorithms::process(this->regions.begin(), this->regions.end(),
                        predicate, this->results);
    Algorithms::process(this->settlements.begin(), this->settlements.end(),
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

    Algorithms::process(this->settlements.begin(), this->settlements.end(),
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

    Algorithms::process(this->regions.begin(), this->regions.end(), predicate,
                        this->results);

    Algorithms::process(this->soorps.begin(), this->soorps.end(), predicate,
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
}
