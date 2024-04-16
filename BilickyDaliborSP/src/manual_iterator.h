#pragma once
#include "units/territorial_unit.h"
#include <libds/heap_monitor.h>
#include <libds/amt/explicit_hierarchy.h>

using Node = ds::amt::MultiWayExplicitHierarchyBlock<TerritorialUnit*>; 
using Hierarchy = ds::amt::MultiWayExplicitHierarchy<TerritorialUnit*>;

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
    Node* getCurrentPos(); 
    friend std::ostream &operator<<(std::ostream &os,
                                    const ManualIterator &mIt);

};
