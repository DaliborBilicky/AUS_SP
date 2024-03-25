#include "algorithms.h"
#include "units/region.h"
#include "units/settlement.h"
#include "units/soorp.h"
#include <fstream>
#include <locale>
#include <sstream>
#include <vector>

void Algorithms::parseCSV(std::string &path,
                          std::vector<Settlement> &settlements,
                          std::vector<Soorp> &soorps,
                          std::vector<Region> &regions) {

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
            regions.push_back(Region(name, code));
            sStream = std::stringstream(line);
        }

        std::getline(sStream, temp, ';');

        std::getline(sStream, temp, ';');
        code = std::atoi(temp.c_str());

        std::getline(sStream, name, ';');

        std::getline(sStream, temp, ';'); // poradove cislo
        int num = std::atoi(temp.c_str());
        if (num == 1 || temp == "x") {
            soorps.push_back(Soorp(name, code));
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

        settlements.push_back(Settlement(name, code, type, cadaArea, numOfRes,
                                         resU14, resO65, canal, water, gas));
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
