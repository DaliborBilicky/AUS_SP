#pragma once
#include <vector>
#include "TerritorialUnit.h"
#include "Settlement.h"
#include "Soorp.h"
#include "Region.h"

class Algorithms {
  public:
    Algorithms();
    ~Algorithms();
	static void parseCSV(string &path, vector<Settlement> &settlements,
		vector<Soorp> &soorps, vector<Region> &regions);
};



