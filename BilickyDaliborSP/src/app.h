#pragma once
#include "utils/manual_iterator.h"
#include "menu/states.h"
#include "units/units.h"
#include "utils/ds_handler.h"
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
    ds::amt::MultiWayExplicitHierarchy<TerritorialUnit *> czechia;
    CurrentState currentState;
    TypeMenu typeMenu;
    TableMenu tableMenu;
    ManualIteratorMenu mItMenu;
    ContainsStringMenu containsStringMenu;
    StartsWithStrMenu startsWithStrMenu;
    ManualIterator manualIt;
    DSHandler dsHandler;
    UnitType currentSeq = UnitType::REGION;

    void processStartsWithString();
    void processContainsString();
    void processIsType();
    void moveManualIterator();
    void searchInTable();
    void printOutput();
    void sortData();
    void proccessData(std::function<bool(TerritorialUnit *)> &predicate);

  public:
    App();
    ~App();

    void mainLoop();
};
