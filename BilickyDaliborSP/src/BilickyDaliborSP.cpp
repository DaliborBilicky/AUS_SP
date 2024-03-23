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
        function<bool(TerritorialUnit)> predicate;
        string path = "./res/CR_win1250.csv";
        string wantedString = "";
        string wantedStringUpper = "";
        Menu menu;
        bool run = true;

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
            menu.mainMenu();

            switch (menu.getOption()) {
				case Options::EXIT:
                    run = false;
                    continue;
				case Options::WRONG_INPUT:
					std::cout << "Try again." << std::endl;
					continue;
				default:
                    break;
            }
            
            switch(menu.subMenu()) {
                default:
                case Predicates::NOTHING: 
                    continue;
                case Predicates::CONTAINS_STRING:
                    predicate = containsString;
                    break;
                case Predicates::STARTS_WITH_STRING:
                    predicate = startsWithString;
                    break;
            }

            cout << "Enter string: ";
			getline(cin, wantedString); 
			Algorithms::lowerCase(wantedString);
			wantedStringUpper = wantedString;
			Algorithms::upperCase(wantedStringUpper);

            if (menu.getOption() == Options::EVERYTHING ||
                            menu.getOption() == Options::REGIONS) {
				Algorithms::process(regions.begin(), regions.end(), predicate, results);
            }

            if (menu.getOption() == Options::EVERYTHING ||
                menu.getOption() == Options::SOORPS) {
                Algorithms::process(soorps.begin(), soorps.end(), predicate,
                                    results);
            }

            if (menu.getOption() == Options::EVERYTHING ||
                menu.getOption() == Options::SETTLEMENTS) {
                Algorithms::process(settlements.begin(), settlements.end(),
                                    predicate, results);
            }

            if (results.size() == 0) {
                cout << endl << "* There is nothing with this option." << endl;
            } else {
                cout << endl << "##### Output #####" << endl;
				for (int i = 0; i < results.size(); i++) {
					cout << *(results[i]) << endl;
				}
			}
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
