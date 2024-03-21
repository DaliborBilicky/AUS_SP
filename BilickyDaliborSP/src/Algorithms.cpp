#include <fstream>
#include <vector>
#include <sstream>
#include <functional>
#include <locale>
#include "Algorithms.h"
#include "TerritorialUnit.h"
#include "Settlement.h"
#include "Soorp.h"
#include "Region.h"


using namespace std;

Algorithms::Algorithms() {}

Algorithms::~Algorithms() {}

void Algorithms::parseCSV(string& path, vector<Settlement>& settlements, 
			  vector<Soorp>& soorps, vector<Region>& regions) {

	ifstream ifs;
	string line = "";

	ifs.open(path);
	ifs.ignore(1);
	while (getline(ifs, line)) {
		stringstream sStream(line);
		string temp;
		string name;
		string type;
		int code = 0;

		if (line.substr(0, 2) == ";;") {
			std::getline(sStream, temp, ';');
			std::getline(sStream, temp, ';');

			getline(sStream, name, ';');

			getline(ifs, line);
			sStream = stringstream(line);

			getline(sStream, temp, ';');
			code = atoi(temp.substr(2).c_str());
			regions.push_back(Region(name, code));
			sStream = stringstream(line);
		}

		getline(sStream, temp, ';');

		getline(sStream, temp, ';');
		code = atoi(temp.c_str());

		getline(sStream, name, ';');

		getline(sStream, temp, ';'); //poradove cislo 
		int num = atoi(temp.c_str());
		if (num == 1) {
			soorps.push_back(Soorp(name, code));
		}

		getline(sStream, name, ';');

		getline(sStream, temp, ';');
		code = atoi(temp.c_str());

		getline(sStream, type, ';');

		getline(sStream, temp, ';');
		getline(sStream, temp, ';');
		
		getline(sStream, temp, ';');
		temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
		int cadaArea = atoi(temp.c_str());

		getline(sStream, temp, ';');
		temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
		int numOfRes = atoi(temp.c_str());
		
		getline(sStream, temp, ';');
		temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
		int resU14 = atoi(temp.c_str());

		getline(sStream, temp, ';');
		temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
		int resO65 = atoi(temp.c_str());

		getline(sStream, temp, ';');
		char canal = temp[0];

		getline(sStream, temp, ';');
		char water = temp[0];

		getline(sStream, temp, ';');
		char gas = temp[0];

		settlements.push_back(Settlement(name, code, type, cadaArea,
										 numOfRes, resU14, resO65, canal,
										 water, gas));
	}
	ifs.close();
}

string& Algorithms::lowerCase(string &str) {
	for (char &c : str) {
		c = tolower(c, locale("Czech_Czechia.1250"));
	}
    return str;
}

string& Algorithms::upperCase(string &str) {
	for (char &c : str) {
		c = toupper(c, locale("Czech_Czechia.1250"));
	}
    return str;
}
