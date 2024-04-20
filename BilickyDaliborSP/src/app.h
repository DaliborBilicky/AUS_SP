#pragma once
#include "manual_iterator.h"
#include "menu/states.h"
#include "units/units.h"
#include <functional>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/amt/implicit_sequence.h>
#include <libds/heap_monitor.h>

using PreOrderIterator = ds::amt::MultiWayExplicitHierarchy<
    TerritorialUnit *>::PreOrderHierarchyIterator;

class App {
  private:
    ds::amt::ImplicitSequence<TerritorialUnit *> results;
    ds::amt::ImplicitSequence<Settlement *> settlements;
    ds::amt::ImplicitSequence<Soorp *> soorps;
    ds::amt::ImplicitSequence<Region *> regions;
    ds::amt::MultiWayExplicitHierarchy<TerritorialUnit *> czechia;
    CurrentState currentState;
    TypeMenu typeMenu;
    ManualIteratorMenu mItMenu;
    ContainsStringMenu containsStringMenu;
    StartsWithStrMenu startsWithStrMenu;
    ManualIterator manualIt;
    UnitType currentSeq = UnitType::REGION;

    void processStartsWithString();
    void processContainsString();
    void processIsType();
    void moveManualIterator();
    void proccessData(std::function<bool(TerritorialUnit *)> &predicate);
    void printOutput();

  public:
    App();
    ~App();

    void mainLoop();
};
