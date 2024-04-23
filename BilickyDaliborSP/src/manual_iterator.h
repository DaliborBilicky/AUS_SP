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

    void moveUp();
    void moveDown(int index);

  public:
    ManualIterator();
    ManualIterator(Hierarchy *hierachy);
    ~ManualIterator();

    Node *getCurrentPos();
    void printOptions(int option);
    friend std::ostream &operator<<(std::ostream &os,
                                    const ManualIterator &mIt);
};
