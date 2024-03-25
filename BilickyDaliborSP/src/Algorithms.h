#pragma once
#include "units/region.h"
#include "units/settlement.h"
#include "units/soorp.h"
#include "units/territorial_unit.h"
#include <functional>
#include <vector>

class Algorithms {
  public:
    template <typename IteratorT, typename PredicateT, typename StructT>
    static void process(IteratorT begin, IteratorT end,
                        std::function<bool(PredicateT)> predicate,
                        StructT &results);

    static void parseCSV(std::string &path,
                         std::vector<Settlement> &settlements,
                         std::vector<Soorp> &soorps,
                         std::vector<Region> &regions);

    static std::string &lowerCase(std::string &str);
    static std::string &upperCase(std::string &str);
};

template <typename IteratorT, typename PredicateT, typename StructT>
void Algorithms::process(IteratorT begin, IteratorT end,
                         std::function<bool(PredicateT)> predicate,
                         StructT &results) {
    while (begin != end) {
        if (predicate(*begin)) {
            results.emplace_back(&(*begin));
        }
        ++begin;
    }
}
