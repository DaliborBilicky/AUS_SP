#pragma once
#include "manual_iterator.h"
#include "menu/states.h"
#include "units/units.h"
#include <functional>
#include <libds/adt/table.h>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/amt/implicit_sequence.h>
#include <libds/heap_monitor.h>

using PreOrderIterator = ds::amt::MultiWayExplicitHierarchy<
    TerritorialUnit *>::PreOrderHierarchyIterator;

class App {
  private:
    ds::amt::ImplicitSequence<TerritorialUnit *> results;
    ds::adt::SortedSequenceTable<std::string,
				ds::amt::SinglyLinkedSequence<Settlement *> *> settlements;
    ds::adt::SortedSequenceTable<std::string, Soorp *> soorps;
    ds::adt::SortedSequenceTable<std::string, Region *> regions;
    ds::amt::MultiWayExplicitHierarchy<TerritorialUnit *> czechia;
    CurrentState currentState;
    TypeMenu typeMenu;
    TableMenu tableMenu;
    ManualIteratorMenu mItMenu;
    ContainsStringMenu containsStringMenu;
    StartsWithStrMenu startsWithStrMenu;
    ManualIterator manualIt;

    void processStartsWithString();
    void processContainsString();
    void processIsType();
    void moveManualIterator();
    void searchInTable();
    void printOutput();

  public:
    App();
    ~App();

    void mainLoop();
};
