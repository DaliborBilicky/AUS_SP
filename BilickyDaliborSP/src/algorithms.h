#pragma once
#include "units/units.h"
#include "units/territorial_unit.h"
#include <functional>
#include <vector>

class Algorithms {
  public:
    template <typename IteratorT, typename PredicateParam, typename StructT>
    static void process(IteratorT begin, IteratorT end,
                        std::function<bool(PredicateParam)> predicate,
                        StructT &results);

    static void parseCSV(std::string &path,
                         std::vector<Settlement> &settlements,
                         std::vector<Soorp> &soorps,
                         std::vector<Region> &regions);

    static std::string &lowerCase(std::string &str);
    static std::string &upperCase(std::string &str);
};

template <typename IteratorT, typename PredicateParam, typename StructT>
void Algorithms::process(IteratorT begin, IteratorT end,
                         std::function<bool(PredicateParam)> predicate,
                         StructT &results) {
    while (begin != end) {
        if (predicate(*begin)) {
            results.emplace_back(&(*begin));
        }
        ++begin;
    }
}
