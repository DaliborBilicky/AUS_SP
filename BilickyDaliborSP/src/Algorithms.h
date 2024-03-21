#pragma once
#include <vector>
#include <functional>
#include "TerritorialUnit.h"
#include "Settlement.h"
#include "Soorp.h"
#include "Region.h"

using namespace std;

class Algorithms {
  public:
    Algorithms();
    ~Algorithms();

    template <typename IteratorT, typename Predicate, typename StructT>
    static void process(IteratorT begin, IteratorT end, Predicate predicate, StructT &results);

	static void parseCSV(string &path, vector<Settlement> &settlements,
		vector<Soorp> &soorps, vector<Region> &regions);

    static string& lowerCase(string &str);
    static string& upperCase(string &str);
};

template <typename IteratorT, typename Predicate, typename StructT>
void Algorithms::process(IteratorT begin, IteratorT end, Predicate predicate, StructT &results) {
	while (begin != end) {
		if (predicate(*begin)) {
            results.emplace_back(&(*begin));
		}
        ++begin;
    }

}

