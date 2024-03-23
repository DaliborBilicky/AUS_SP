﻿#include "algorithms.h"
#include "menu.h"
#include "units/region.h"
#include "units/settlement.h"
#include "units/soorp.h"
#include "units/territorial_unit.h"
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
        std::function<bool(TerritorialUnit)> predicate;
        std::string path = "./res/CR_win1250.csv";
        std::string wantedString = "";
        std::string wantedStringUpper = "";
        Menu menu;
        bool run = true;

        auto startsWithString = [&](TerritorialUnit unit) -> bool {
            for (int i = 0; i < wantedString.size(); i++) {
                if (wantedString[i] != unit.getName()[i] &&
                    wantedStringUpper[i] != unit.getName()[i]) {
                    return false;
                }
            }
            return true;
        };

        auto containsString = [&](TerritorialUnit unit) -> bool {
            int index = 0;
            for (int i = 0;
                 i < unit.getName().size() && index < wantedString.size();
                 i++) {
                if (wantedString[index] == unit.getName()[i] ||
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
                std::cout << std::endl << "* Try again." << std::endl;
                continue;
            default:
                break;
            }

            switch (menu.subMenu()) {
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

            std::cout << "Enter string: ";
            std::getline(std::cin, wantedString);
            Algorithms::lowerCase(wantedString);
            wantedStringUpper = wantedString;
            Algorithms::upperCase(wantedStringUpper);

            if (menu.getOption() == Options::EVERYTHING ||
                menu.getOption() == Options::REGIONS) {
                Algorithms::process(regions.begin(), regions.end(), predicate,
                                    results);
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
                std::cout << std::endl
                          << "* There is nothing with this option."
                          << std::endl;
            } else {
                std::cout << std::endl << "##### Output #####" << std::endl;
                std::cout << "Number of results: " << results.size()
                          << std::endl
                          << std::endl;
                for (int i = 0; i < results.size(); i++) {
                    std::cout << *(results[i]) << std::endl;
                }
            }
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
