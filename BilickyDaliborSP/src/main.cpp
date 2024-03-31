#include "algorithms.h"
#include "units/units.h"
#include "units/territorial_unit.h"
#include "menu/prompt.h"
#include "menu/current_state.h"
#include "menu/states.h"
#include <chrono>
#include <crtdbg.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

int main(int argc, char *argv[]) {
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    {
        std::vector<TerritorialUnit *> results;
        std::vector<Settlement> settlements;
        std::vector<Soorp> soorps;
        std::vector<Region> regions;
        std::string path = "./res/CR_win1250.csv";
        bool run = true;
        CurrentState currentState;
        MainMenu mainMenu(currentState);
        TypeMenu isTypeMenu(currentState);
        std::string wantedString = "";
        std::string wantedStringUpper = "";

        auto predicate1 = [&](TerritorialUnit unit) -> bool {
            for (int i = 0; i < wantedString.size(); i++) {
                if (wantedString[i] != unit.getName()[i] &&
                    wantedStringUpper[i] != unit.getName()[i]) {
                    return false;
                }
            }
            return true;
        };

        auto predicate2 = [&](TerritorialUnit unit) -> bool {
            int option = 0;
            switch (option) {
				default:
                case 0:
                    return false;
                case 1:
                    return unit.getUnitType() == TerrUnitType::REGION;
                case 2:
                    return unit.getUnitType() == TerrUnitType::SOORP;
                case 3:
                    return unit.getUnitType() == TerrUnitType::SETTLEMENT;
            }
        };

        auto predicate3 = [&](TerritorialUnit unit) -> bool {
            int index = 0;
            int i = 0;
            while (i < unit.getName().size() && index < wantedString.size()) {
                if (wantedString[index] == unit.getName()[i] ||
                    wantedStringUpper[index] == unit.getName()[i]) {
                    index++;
                } else {
                    index = 0;
                }
                i++;
            }
            return index == wantedString.size();
        };

        auto start = std::chrono::high_resolution_clock::now();
        Algorithms::parseCSV(path, settlements, soorps, regions);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        std::cout << "* Parsing CSV took: " << duration.count() * 1000 << "ms"
                  << std::endl;

		results.clear();

		start = std::chrono::high_resolution_clock::now();

		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		if (results.size() == 0) {
			std::cout << std::endl
					  << "* There is nothing with this option."
					  << std::endl;
		} else {
			std::cout << std::endl
					  << "##### Output #####" << std::endl
					  << "* Searching in data took: "
					  << duration.count() * 1000 << "ms" << std::endl
					  << "* Number of results: " << results.size()
					  << std::endl
					  << std::endl;

			for (int i = 0; i < results.size(); i++) {
				std::cout << *(results[i]) << std::endl;
			}
		}

		while (run) {
			switch (currentState.getState()) {
			case State::EXIT:
                run = false;
				break;
			case State::MAIN_MENU:
				mainMenu.show();
				break;
			case State::TYPE_MENU:
				isTypeMenu.show();
				break;
			case State::STARTS_WITH_STR_MENU:
				break;
			case State::CONTAINS_STR_MENU:
				break;
			default:
				break;
			}
		}
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
