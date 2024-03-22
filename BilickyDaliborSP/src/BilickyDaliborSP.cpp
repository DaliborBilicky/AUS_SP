#include <string>
#include <iostream>
#include <vector>
#include <crtdbg.h>
#include <windows.h>
#include <functional>
#include <limits>
#include "Algorithms.h"
#include "TerritorialUnit.h"
#include "Settlement.h"
#include "Soorp.h"
#include "Region.h"
#include "Menu.h"


using namespace std;

int main(int argc, char *argv[]) {
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    { 
        vector<TerritorialUnit*> results;
        vector<Settlement> settlements;
        vector<Soorp> soorps;
        vector<Region> regions;
        string path = "./res/CR_win1250.csv";
        string wantedString = "";
        string wantedStringUpper = "";
        bool run = true;
        function<bool(TerritorialUnit)> predicate;

		auto startsWithString =
            [&](TerritorialUnit unit) -> bool {
            for (int i = 0; i < wantedString.size(); i++) {
                if (wantedString[i] != unit.getName()[i] 
                    &&
                    wantedStringUpper[i] != unit.getName()[i]) {
                    return false; 
                }
            }
            return true;
		}; 

        auto containsString = [&](TerritorialUnit unit) -> bool {
            int index = 0;
            for (int i = 0; i < unit.getName().size() && index < wantedString.size(); i++) {
                if (wantedString[index] == unit.getName()[i] 
                    ||
                    wantedStringUpper[index] == unit.getName()[i]) {
                    index++;
                } else {
                    index = 0;
                }
            }
            return index == wantedString.size();
        };

        Algorithms::parseCSV(path, settlements, soorps, regions);

        while (run) {
            results.clear();
            int option = Menu::mainMenu();
            if (option == 0) {
                break;
            } else if (option == -1) {
                continue;
            }
            

            cout << "Enter string: ";
			getline(cin, wantedString); 
			Algorithms::lowerCase(wantedString);
			wantedStringUpper = wantedString;
			Algorithms::upperCase(wantedStringUpper);

			Algorithms::process(regions.begin(), regions.end(), predicate, results);
			Algorithms::process(soorps.begin(), soorps.end(), predicate, results);
			Algorithms::process(settlements.begin(), settlements.end(), predicate, results);

			for (int i = 0; i < results.size(); i++) {
				cout << *(results[i]) << endl;
			}
			cout << endl;
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
