#pragma once
#include "units/territorial_unit.h"
#include "units/units.h"
#include <functional>
#include <libds/adt/table.h>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/amt/implicit_sequence.h>
#include <libds/amt/explicit_sequence.h>
#include <libds/heap_monitor.h>
#include <string>

class Algorithms {
  public:
    template <typename IteratorT, typename PredicateParam, typename StructT>
    static void process(IteratorT begin, IteratorT end,
                        std::function<bool(PredicateParam)> predicate,
                        StructT &results);

    static void
    parseCSV(const std::string &path,
             ds::adt::Table<std::string,
					ds::amt::SinglyLinkedSequence<Settlement *> *> &settlements,
             ds::adt::Table<std::string, Soorp *> &soorps,
             ds::adt::Table<std::string, Region *> &region,
             ds::amt::MultiWayExplicitHierarchy<TerritorialUnit *> &czechia);

    static void changeCase(std::string &str, bool toLower);
    static int countConsonant(const std::string& name);
    static int getWeight(char c);
};

template <typename IteratorT, typename PredicateParam, typename StructT>
void Algorithms::process(IteratorT begin, IteratorT end,
                         std::function<bool(PredicateParam)> predicate,
                         StructT &results) {
    while (begin != end) {
        if (predicate(*begin)) {
            results.insertLast().data_ = *begin;
        }
        ++begin;
    }
}
