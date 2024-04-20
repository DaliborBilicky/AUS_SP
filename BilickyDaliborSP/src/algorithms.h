#pragma once
#include "units/territorial_unit.h"
#include "units/units.h"
#include <functional>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/amt/implicit_sequence.h>
#include <libds/heap_monitor.h>
#include <string>

class Algorithms {
  public:
    template <typename IteratorT, typename PredicateParam, typename StructT>
    static void process(IteratorT begin, IteratorT end,
                        std::function<bool(PredicateParam)> predicate,
                        StructT &results);

    static void parseCSV(
			 const std::string &path,
             ds::amt::ImplicitSequence<Settlement *> &settlements,
             ds::amt::ImplicitSequence<Soorp *> &soorps,
             ds::amt::ImplicitSequence<Region *> &regions,
             ds::amt::MultiWayExplicitHierarchy<TerritorialUnit *> &czechia);

    static std::string &lowerCase(std::string &str);
    static std::string &upperCase(std::string &str);
};

template <typename IteratorT, typename PredicateParam, typename StructT>
void Algorithms::process(IteratorT begin, IteratorT end,
                         std::function<bool(PredicateParam)> predicate,
                         StructT &results) {
    while (begin != end) {
        if (predicate(*begin)) {
            // results.emplace_back(&(*begin)); -> vector
            results.insertLast().data_ = *begin;
        }
        ++begin;
    }
}
