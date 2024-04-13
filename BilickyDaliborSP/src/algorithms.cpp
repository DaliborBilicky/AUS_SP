#include "algorithms.h"
#include "units/units.h"
#include <fstream>
#include <libds/amt/implicit_sequence.h>
#include <locale>
#include <sstream>

void Algorithms::parseCSV(const std::string &path,
                          ds::amt::ImplicitSequence<Settlement> &settlements,
                          ds::amt::ImplicitSequence<Soorp> &soorps,
                          ds::amt::ImplicitSequence<Region> &regions) {

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
            Region region(name, code);
            regions.insertLast().data_ = region;
            sStream = std::stringstream(line);
        }

        std::getline(sStream, temp, ';');

        std::getline(sStream, temp, ';');
        code = std::atoi(temp.c_str());

        std::getline(sStream, name, ';');

        std::getline(sStream, temp, ';'); // poradove cislo
        int num = std::atoi(temp.c_str());
        if (num == 1) {
            Soorp soorp(name, code);
            soorps.insertLast().data_ = soorp;
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
        Settlement settlement(name, code, type, cadaArea, numOfRes, resU14,
                              resO65, canal, water, gas);
        settlements.insertLast().data_ = settlement;
    }
    ifs.close();
}


void Algorithms::parseCSV(const std::string &path,
    ds::amt::MultiWayExplicitHierarchy<TerritorialUnit*> &czechia) {
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
			czechia.emplaceSon(*root, regionCounter);
			czechia.accessSon(*root, regionCounter)->data_ = region;

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
            auto* region = czechia.accessSon(*root, regionCounter);
            czechia.emplaceSon(*region, soorpCounter);
            czechia.accessSon(*region, soorpCounter)->data_ = soorp;
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
        Settlement *settlement = new Settlement(
            name, code, type, cadaArea, numOfRes, 
            resU14, resO65, canal, water, gas);

		 settlementCounter++;
		 auto* region = czechia.accessSon(*root, regionCounter);
	     auto* soorp = czechia.accessSon(*region, soorpCounter);
         czechia.emplaceSon(*soorp, settlementCounter);
		 czechia.accessSon(*soorp, settlementCounter)->data_ = settlement;
    }
    ifs.close();
}


std::string &Algorithms::lowerCase(std::string &str) {
    for (char &c : str) {
        c = std::tolower(c, std::locale("Czech_Czechia.1250"));
    }
    return str;
}


std::string &Algorithms::upperCase(std::string &str) {
    for (char &c : str) {
        c = std::toupper(c, std::locale("Czech_Czechia.1250"));
    }
    return str;
}
