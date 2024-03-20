#include <string>
#include <iostream>
#include <vector>
#include <crtdbg.h>
#include <windows.h>
#include <functional>
#include "Algorithms.h"
#include "TerritorialUnit.h"
#include "Settlement.h"
#include "Soorp.h"
#include "Region.h"


using namespace std;

int main(int argc, char *argv[]) {
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    { 
        vector<TerritorialUnit> result;
        vector<Settlement> settlements;
        vector<Soorp> soorps;
        vector<Region> regions;
        string path = "./res/CR_win1250.csv";
        string hladany = "";

        Algorithms::parseCSV(path, settlements, soorps, regions);



        cout << "Zadaj string: ";
        cin >> hladany;

        auto containsString =
            [&](TerritorialUnit unit) -> bool {
            return unit.getName().find(hladany) != string::npos;
        };

        Algorithms::process(settlements.begin(), settlements.end(), containsString, result);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (result[i].getName().find(hladany) != string::npos){
                cout << " *" << endl;
            } else {
                cout << endl;
            }
        }

    }
    _CrtDumpMemoryLeaks();
    return 0;
}
