#include "utils/ds_handler.h"
#include "utils/algorithms.h"
#include <libds/heap_monitor.h>

DSHandler::DSHandler() { 
}

DSHandler::~DSHandler() {
    for (auto &item : this->settlementsTable) {
        delete item.data_;
        item.data_ = nullptr;
    }
}

void DSHandler::addRegion(Region *unit) {
	this->regions.insertLast().data_ = unit;
	this->regionsTable.insert(unit->getName(), unit);
}

void DSHandler::addSoorp(Soorp *unit) {
    this->soorps.insertLast().data_ = unit;
	this->soorpsTable.insert(unit->getName(), unit);
}

void DSHandler::addSettlement(Settlement *unit) {
	this->settlements.insertLast().data_ = unit;
	if (this->settlementsTable.contains(unit->getName())) {
		this->settlementsTable.find(
		unit->getName())->insertFirst().data_ = unit;
	} else {
		auto *synonyms = new ds::amt::SinglyLinkedSequence<Settlement *>();
		synonyms->insertFirst().data_ = unit;
		this->settlementsTable.insert(unit->getName(), synonyms);
	}
}

void DSHandler::filterFromSequence(UnitType type, IS &results, 
        std::function<bool(TerritorialUnit *)> &predicate) {
	switch (type) { 
        case UnitType::REGION:
			Algorithms::process(
                this->regions.begin(), this->regions.end(), 
                predicate, results);
            break;
        case UnitType::SOORP:
			Algorithms::process(
                this->soorps.begin(), this->soorps.end(), 
                predicate, results);
            break;
        case UnitType::SETTLEMENT:
			Algorithms::process(
                this->settlements.begin(), this->settlements.end(), 
                predicate, results);
            break;
	}
}

void DSHandler::findInTable(UnitType type, IS &results, std::string &key) {
    Region **region = nullptr;
    Soorp **soorp = nullptr;
    ds::amt::SinglyLinkedSequence<Settlement *> **settlement = nullptr;

    switch (type) {
    case UnitType::REGION:
        if (this->regionsTable.tryFind(key, region)) {
            results.insertLast().data_ = *region;
        }
        break;
    case UnitType::SOORP:
        if (this->soorpsTable.tryFind(key, soorp)) {
            results.insertLast().data_ = *soorp;
        }
        break;
    case UnitType::SETTLEMENT:
        if (this->settlementsTable.tryFind(key, settlement)) {
			for (auto item : *this->settlementsTable.find(key)) {
				results.insertLast().data_ = item;
			}
        }
        break;
    }
}



