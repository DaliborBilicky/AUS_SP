#include "algorithms.h"
#include "units/units.h"
#include <fstream>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/amt/implicit_sequence.h>
#include <libds/heap_monitor.h>
#include <locale>
#include <sstream>
#include <string>

void Algorithms::parseCSV(const std::string &path, DSHandler& dsHandler,
    ds::amt::MultiWayExplicitHierarchy<TerritorialUnit *> &czechia) {

    auto *root = czechia.accessRoot();
    int regionCounter = -1;
    int soorpCounter = -1;
    int settlementCounter = 0;

    std::ifstream ifs;
    std::string line = "";

    ifs.open(path);
    ifs.ignore(1);
    while (std::getline(ifs, line)) {
        std::stringstream sStream(line);
        std::string temp;
        std::string name;
        std::string type;
        int code = 0;

        if (line.substr(0, 2) == ";;") {
            std::getline(sStream, temp, ';');
            std::getline(sStream, temp, ';');

            std::getline(sStream, name, ';');

            std::getline(ifs, line);
            sStream = std::stringstream(line);

            std::getline(sStream, temp, ';');
            code = std::atoi(temp.substr(2).c_str());
            Region *region = new Region(name, code);

            soorpCounter = -1;
            regionCounter++;
            czechia.emplaceSon(*root, regionCounter).data_ = region;

            dsHandler.addRegion(region);

            sStream = std::stringstream(line);
        }

        std::getline(sStream, temp, ';');

        std::getline(sStream, temp, ';');
        code = std::atoi(temp.c_str());

        std::getline(sStream, name, ';');

        std::getline(sStream, temp, ';'); // poradove cislo
        int num = std::atoi(temp.c_str());
        if (num == 1) {
            Soorp *soorp = new Soorp(name, code);

            settlementCounter = -1;
            soorpCounter++;
            auto *region = czechia.accessSon(*root, regionCounter);
            czechia.emplaceSon(*region, soorpCounter).data_ = soorp;

            dsHandler.addSoorp(soorp);
        }

        std::getline(sStream, name, ';');

        std::getline(sStream, temp, ';');
        code = std::atoi(temp.c_str());

        std::getline(sStream, type, ';');

        std::getline(sStream, temp, ';');
        std::getline(sStream, temp, ';');

        std::getline(sStream, temp, ';');
        temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
        int cadaArea = std::atoi(temp.c_str());

        std::getline(sStream, temp, ';');
        temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
        int numOfRes = std::atoi(temp.c_str());

        std::getline(sStream, temp, ';');
        temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
        int resU14 = std::atoi(temp.c_str());

        std::getline(sStream, temp, ';');
        temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
        int resO65 = std::atoi(temp.c_str());

        std::getline(sStream, temp, ';');
        char canal = temp[0];

        std::getline(sStream, temp, ';');
        char water = temp[0];

        std::getline(sStream, temp, ';');
        char gas = temp[0];
        Settlement *settlement =
            new Settlement(name, code, type, cadaArea, numOfRes, resU14, resO65,
                           canal, water, gas);

        settlementCounter++;
        auto *region = czechia.accessSon(*root, regionCounter);
        auto *soorp = czechia.accessSon(*region, soorpCounter);
        czechia.emplaceSon(*soorp, settlementCounter).data_ = settlement;

        dsHandler.addSettlement(settlement);
    }
    ifs.close();
}


void Algorithms::changeCase(std::string &str, bool toLower) {
    for (char &c : str) {
		if (toLower) {
			c = std::tolower(c, std::locale("Czech_Czechia.1250"));
		} else {
            c = std::toupper(c, std::locale("Czech_Czechia.1250"));
		}
    }
}

int Algorithms::countConsonant(const std::string& name) {
    std::string lower = "bcËdÔfghjklmnÚpr¯sötùvzû";
    std::string upper = "BC»DœFGHJKLMN“PRÿSäTçVZé";
    int number = 0;

    for (int i = 0; i < name.length(); i++) {
        for (int j = 0; j < lower.length(); j++) {
            if (name[i] == lower[j] || name[i] == upper[j]) {
                number++;
            }
        }
        if (i < name.size() - 1 && name.substr(i, 2) == "ch" ||
            name.substr(i, 2) == "Ch") {
            number -= 2;
            number++;
        }
    }
    return number;
}

int Algorithms::getWeight(char c) { 
    // _ pozicia Ch index 18 a ch index 60
	std::string alphabet = 
        " ()-.A¡BC»DœE…ÃFGH_IÕJKLMN“O”PQRÿSäTçU⁄ŸVWXY›Zé"
	    "a·bcËdÔeÈÏfgh_iÌjklmnÚoÛpqr¯sötùu˙˘vwxy˝zû";
	for (int i = 0; i < alphabet.length(); i++) {
		if (c == alphabet[i]) {
			return i;
		}
	}
    return -1; 
}
