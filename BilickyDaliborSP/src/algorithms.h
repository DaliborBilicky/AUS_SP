#pragma once
#include "units/territorial_unit.h"
#include "units/units.h"
#include <functional>
#include <libds/amt/implicit_sequence.h>

class Algorithms {
  public:
    template <typename IteratorT, typename PredicateParam, typename StructT>
    static void process(IteratorT begin, IteratorT end,
                        std::function<bool(PredicateParam)> predicate,
                        StructT &results);

    static void parseCSV(std::string &path,
                         ds::amt::ImplicitSequence<Settlement> &settlements,
                         ds::amt::ImplicitSequence<Soorp> &soorps,
                         ds::amt::ImplicitSequence<Region> &regions);

    static std::string &lowerCase(std::string &str);
    static std::string &upperCase(std::string &str);
};

template <typename IteratorT, typename PredicateParam, typename StructT>
void Algorithms::process(IteratorT begin, IteratorT end,
                         std::function<bool(PredicateParam)> predicate,
                         StructT &results) {
    while (begin != end) {
        if (predicate(&(*begin))) {
            // results.emplace_back(&(*begin));
            results.insertLast().data_ = &(*begin);
        }
        ++begin;
    }
}
