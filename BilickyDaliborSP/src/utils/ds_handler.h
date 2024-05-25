#pragma once
#include "units/units.h"
#include <libds/adt/table.h>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/amt/implicit_sequence.h>
#include <functional>
#include <libds/heap_monitor.h>
#include <string>

using IS = ds::amt::ImplicitSequence<TerritorialUnit *>;

class DSHandler {
  private:
    ds::adt::Treap<std::string,
				ds::amt::SinglyLinkedSequence<Settlement *> *> settlementsTable;
    ds::adt::Treap<std::string, Soorp *> soorpsTable;
    ds::adt::Treap<std::string, Region *> regionsTable;
    ds::amt::ImplicitSequence<Settlement *> settlements; 
    ds::amt::ImplicitSequence<Soorp *> soorps; 
    ds::amt::ImplicitSequence<Region *> regions; 

  public:
    DSHandler();
    ~DSHandler();

    void addRegion(Region* unit);
    void addSoorp(Soorp* unit);
    void addSettlement(Settlement* unit);
    void filterFromSequence(UnitType type, IS &results,
                             std::function<bool(TerritorialUnit *)>& predicate);
    void findInTable(UnitType type, IS &results, std::string &key);
};
