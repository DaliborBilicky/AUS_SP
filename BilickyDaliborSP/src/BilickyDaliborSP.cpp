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
        vector<TerritorialUnit*> result;
        vector<Settlement> settlements;
        vector<Soorp> soorps;
        vector<Region> regions;
        string path = "./res/CR_win1250.csv";
        string wantedString = "";
        bool run = true;

		auto containsString =
			[&](TerritorialUnit unit) -> bool {
			return unit.getLowerName().find(wantedString) != string::npos;
		};

        cout << "Starting to loead csv file." << endl;
        Algorithms::parseCSV(path, settlements, soorps, regions);

        while (run) {
            int option = -1;
            cout << "[0] End program" << endl;
            cout << "[1] Starts with string" << endl;
            cout << "[2] Contains string" << endl;
            cout << "> ";
            cin >> option; 
			switch (option) {
				case 0:
                    return 0;
                case 1:	
					cout << "Enter string: ";
					cin >> wantedString;
                    break;
                case 2:
					cout << "Enter string: ";
					cin >> wantedString;

					Algorithms::process(settlements.begin(), settlements.end(), containsString, result);
					Algorithms::process(regions.begin(), regions.end(), containsString, result);
					Algorithms::process(soorps.begin(), soorps.end(), containsString, result);

					for (int i = 0; i < result.size(); i++) {
						cout << *(result[i]) << endl;
					}
				    cout << endl;
                    break;
				default:
                    cout << "Try again." << endl;
                    break;
			}
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
