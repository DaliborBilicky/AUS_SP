#pragma once
#include "units/territorial_unit.h"
#include <iostream>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/heap_monitor.h>

using Node = ds::amt::MultiWayExplicitHierarchyBlock<TerritorialUnit *>;
using Hierarchy = ds::amt::MultiWayExplicitHierarchy<TerritorialUnit *>;

class ManualIterator {
  private:
    Node *currentPos = nullptr;
    Hierarchy *hierarchy = nullptr;
    int level = 0;

  public:
    ManualIterator();
    ManualIterator(Hierarchy *hierachy);
    ~ManualIterator();

    void moveUp();
    void moveDown(int index);
    Node *getCurrentPos();
    void printOptions();
    friend std::ostream &operator<<(std::ostream &os,
                                    const ManualIterator &mIt);
};
