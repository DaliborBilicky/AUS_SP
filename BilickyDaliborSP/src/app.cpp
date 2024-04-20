#include "app.h"
#include "algorithms.h"
#include "manual_iterator.h"
#include "menu/current_state.h"
#include "menu/prompt.h"
#include "menu/states.h"
#include "units/territorial_unit.h"
#include "units/units.h"
#include <functional>
#include <iostream>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/amt/implicit_sequence.h>
#include <string>

App::App()
    : typeMenu(TypeMenu(&this->currentState)),
      mItMenu(ManualIteratorMenu(&this->currentState)),
      containsStringMenu(ContainsStringMenu(&this->currentState)),
      startsWithStrMenu(StartsWithStrMenu(&this->currentState)){

    std::string name = "ÈESKÁ REPUBLIKA";
    TerritorialUnit *cr = new TerritorialUnit(name, 0);
    this->czechia.emplaceRoot().data_ = cr;
    this->manualIt = ManualIterator(&this->czechia);

    Algorithms::parseCSV("./res/CR_win1250.csv", 
        this->settlements, this->soorps, this->regions, this->czechia);
}

App::~App() {
    this->czechia.processPostOrder(
        czechia.accessRoot(),
        [&](ds::amt::MultiWayExplicitHierarchyBlock<TerritorialUnit *> *block) {
            delete block->data_;
            block->data_ = nullptr;
        });
}

void App::mainLoop() {
    LevelMenu levelMenu(&this->currentState);
    MainMenu mainMenu(&this->currentState);
    SequenceMenu seqMenu(&this->currentState);

    while (true) {
        switch (this->currentState.getState()) {
        case State::EXIT:
            return;
        case State::LEVEL_MENU:
            levelMenu.update();
            break;
        case State::MAIN_MENU:
            mainMenu.update();
            break;
        case State::MANUAL_ITERATOR_MENU:
            this->mItMenu.update();
            this->moveManualIterator();
            break;
        case State::SEQUENCE_MENU:
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
        case State::TYPE_MENU:
            this->typeMenu.update();
            this->processIsType();
            break;
        }
        
		if (this->currentState.getLevel() == Level::LEVEL_2) {
		    std::cout << this->manualIt << std::endl;
	    } else if (this->currentState.getLevel() == Level::LEVEL_1) {
			std::cout << this->currentSeq << std::endl;
        }
    }
}

void App::processStartsWithString() {
    if (this->startsWithStrMenu.getSearchedString() == "~") {
        return;
    }

    std::string strLover = Algorithms::lowerCase(
        this->startsWithStrMenu.getSearchedString());
    std::string strUpper = Algorithms::upperCase(
        this->startsWithStrMenu.getSearchedString());

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
    this->printOutput();
}

void App::processContainsString() {
    if (this->containsStringMenu.getSearchedString() == "~") {
        return;
    }

    std::string strLover = Algorithms::lowerCase(
        this->containsStringMenu.getSearchedString());
    std::string strUpper = Algorithms::upperCase(
        this->containsStringMenu.getSearchedString());

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
    this->printOutput();
}

void App::moveManualIterator() {
    if (this->mItMenu.getOption() == 0) {
        return;
    }

	int counter = 0;
    Node *node = nullptr;

	while ((node = this->czechia.accessSon(
				*this->manualIt.getCurrentPos(), counter)) != nullptr) {
		std::cout << "  [" << "\033[93m" << counter << "\033[0m"
				  << "] - " << node->data_->getName() << std::endl;
		counter++;
	}

	if (this->mItMenu.getOption() == 1) {
		this->manualIt.moveUp();
	} else if (this->mItMenu.getOption() == 2) {
		int index = Prompt::getInput(--counter);
		this->manualIt.moveDown(index);
	}
}


void App::proccessData(std::function<bool (TerritorialUnit*)>& predicate) {
	if (this->currentState.getLevel() == Level::LEVEL_2) {

		auto begin =
			PreOrderIterator(&this->czechia, this->manualIt.getCurrentPos());
		Algorithms::process(
            begin, this->czechia.end(), predicate, this->results);

	} else if (this->currentState.getLevel() == Level::LEVEL_1) {

		switch (this->currentSeq) { 
        case UnitType::REGION:
			Algorithms::process(
                this->regions.begin(), this->regions.end(), 
                predicate, this->results);
            break;
        case UnitType::SOORP:
			Algorithms::process(
                this->soorps.begin(), this->soorps.end(), 
                predicate, this->results);
            break;
        case UnitType::SETTLEMENT:
			Algorithms::process(
                this->settlements.begin(), this->settlements.end(), 
                predicate, this->results);
            break;
		}

	}
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
