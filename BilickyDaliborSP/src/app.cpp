#include "app.h"
#include "algorithms.h"
#include "manual_iterator.h"
#include "menu/current_state.h"
#include "menu/states.h"
#include "units/territorial_unit.h"
#include "units/units.h"
#include "menu/prompt.h"
#include <functional>
#include <iostream>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/amt/implicit_sequence.h>
#include <libds/heap_monitor.h>
#include <libds/adt/sorts.h>
#include <string>

App::App()
    : typeMenu(TypeMenu(&this->currentState)),
      tableMenu(TableMenu(&this->currentState)),
      mItMenu(ManualIteratorMenu(&this->currentState)),
      containsStringMenu(ContainsStringMenu(&this->currentState)),
      startsWithStrMenu(StartsWithStrMenu(&this->currentState)) {

    std::string name = "ÈESKÁ REPUBLIKA";
    TerritorialUnit *cr = new TerritorialUnit(name, 0);
    this->czechia.emplaceRoot().data_ = cr;
    this->manualIt = ManualIterator(&this->czechia);

    Algorithms::parseCSV(
        "./res/CR_win1250.csv", this->dsHandler, this->czechia);
}

App::~App() {
    this->czechia.processPostOrder(
        czechia.accessRoot(),
        [&](ds::amt::MultiWayExplicitHierarchyBlock<TerritorialUnit *> *node) {
            delete node->data_;
            node->data_ = nullptr;
        });
}

void App::mainLoop() {
    MainMenu mainMenu(&this->currentState);
    AppTypeMenu appTypeMenu(&this->currentState);
    SequenceMenu seqMenu(&this->currentState);

    while (true) {
        switch (this->currentState.getState()) {
        case State::EXIT:
            return;
        case State::APP_TYPE_MENU:
            appTypeMenu.update();
            break;
        case State::MAIN_MENU:
            mainMenu.update();
            break;
        case State::TABEL_MENU:
            this->tableMenu.update();
            this->searchInTable();
            this->printOutput();
            break;
        case State::MANUAL_ITERATOR_MENU:
            this->mItMenu.update();
            this->moveManualIterator();
            break;
        case State::SEQ_MENU:
            seqMenu.update();
            if (seqMenu.getOption() == 0) {
                break;
            }
            this->currentSeq = static_cast<UnitType>(seqMenu.getOption());
            break;
        case State::STARTS_WITH_STR_MENU:
            this->startsWithStrMenu.update();
            this->processStartsWithString();
            break;
        case State::CONTAINS_STR_MENU:
            this->containsStringMenu.update();
            this->processContainsString();
            break;
        case State::UNIT_TYPE_MENU:
            this->typeMenu.update();
            this->processIsType();
            break;
        }

		if (this->currentState.getAppType() == AppType::HIERARCHICAL) {
		    std::cout << this->manualIt << std::endl;
	    } else if (this->currentState.getAppType() == AppType::SEQUENTIAL) {
			std::cout << this->currentSeq << std::endl;
        } 
    }
}

void App::processStartsWithString() {
    if (this->startsWithStrMenu.getSearchedString() == "~") {
        return;
    }

    std::string strLover = this->startsWithStrMenu.getSearchedString();
	Algorithms::changeCase(strLover, true);
    std::string strUpper = this->startsWithStrMenu.getSearchedString();
	Algorithms::changeCase(strUpper, false);

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

    this->proccessData(predicate);
    this->sortData();
    this->printOutput();
}

void App::processContainsString() {
    if (this->containsStringMenu.getSearchedString() == "~") {
        return;
    }

    std::string strLover = this->containsStringMenu.getSearchedString();
	Algorithms::changeCase(strLover, true);
    std::string strUpper = this->containsStringMenu.getSearchedString();
	Algorithms::changeCase(strUpper, false);

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

    this->proccessData(predicate);
    this->sortData();
    this->printOutput();
}

void App::processIsType() {
    if (this->typeMenu.getOption() == 0) {
        return;
    }

    int wantedType = this->typeMenu.getOption();

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

    this->proccessData(predicate);
    this->sortData();
    this->printOutput();
}

void App::moveManualIterator() {
    int option = this->mItMenu.getOption();
    if (option == 0) {
        return;
    }
    this->manualIt.printOptions(option);
}

void App::searchInTable() {
    if (this->tableMenu.getOption() == 0) {
        return;
    }
    UnitType type = static_cast<UnitType>(this->tableMenu.getOption());
    this->dsHandler.findInTable(
        type, this->results, this->tableMenu.getSearchedString());
}

void App::proccessData(std::function<bool (TerritorialUnit*)>& predicate) {
	if (this->currentState.getAppType() == AppType::HIERARCHICAL) {
		auto begin =
			PreOrderIterator(&this->czechia, this->manualIt.getCurrentPos());
		Algorithms::process(
            begin, this->czechia.end(), predicate, this->results);

	} else if (this->currentState.getAppType() == AppType::SEQUENTIAL) {
		this->dsHandler.filterFromSequence(
            this->currentSeq, this->results, predicate);
	}
}

void App::sortData() {
    std::cout << "\n[\033[93mORDER FILTERED DATA\033[0m]\n";
    std::cout << "  [\033[93m0\033[0m] - Alphabetically\n"
              << "  [\033[93m1\033[0m] - ConsonantCount\n";
    int number = Prompt::getInput(1);
    if (number == 0) {
		ds::adt::QuickSort<TerritorialUnit*> quick;
		quick.sort(
			this->results,
			[&](TerritorialUnit *const &a, TerritorialUnit *const &b) -> bool {
                std::string name1 = a->getName(); 
                std::string name2 = b->getName();
                size_t len = std::min(name1.length(), name2.length());

                for (size_t i = 0; i < len; i++) {
                    if (name1[i] == name2[i]) {
                        continue;
                    }

                    int weight1 = Algorithms::getWeight(name1[i]);
					int weight2 = Algorithms::getWeight(name2[i]);

                    if (i < len - 1) {
                        std::string substr1 = name1.substr(i, 2);
						std::string substr2 = name2.substr(i, 2);
            
						if (substr1 == "ch") {
							return 60 < weight2;
						}
						if (substr1 == "Ch") {
							return 18 < weight2;
						}
						if (substr2 == "ch") {
							return weight1 < 60;
						}
						if (substr2 == "Ch") {
							return weight1 < 18;
						}
                    }
					
					if (weight1 < weight2) {
						return true;
					}
					if (weight1 > weight2) {
						return false;
					}
                }
                return name1.length() < name2.length();
			});

    } else {
		ds::adt::QuickSort<TerritorialUnit*> quick;
		quick.sort(
			this->results,
			[](TerritorialUnit *const &a, TerritorialUnit *const &b) -> bool {
				return Algorithms::countConsonant(a->getName()) 
                    < Algorithms::countConsonant(b->getName());
			});
    } 
}

void App::printOutput() {
    std::cout << "\n[\033[93mOUTPUT\033[0m]\n";

    if (results.size() == 0) {
        std::cout << " \033[93m*\033[0m There is nothing with this option."
                  << std::endl;
    } else {
        std::cout << " \033[93m*\033[0m Number of results: " << results.size()
                  << std::endl
                  << std::endl;

        for (int i = 0; i < results.size(); i++) {
            std::cout << *(results.access(i)->data_) << std::endl;
        }
    }
    this->results.clear();
}
