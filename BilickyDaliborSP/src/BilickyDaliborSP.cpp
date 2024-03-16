#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <crtdbg.h>
#include <windows.h>


using namespace std;

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    { 
        ifstream ifs;
        ifs.open("./res/CR.csv");
        ofstream ofs;
        ofs.open("./res/out.txt");
        string line = "";

        int c = 0;
        while (getline(ifs, line)) {
            stringstream sStream(line);
            string kod;

            getline(sStream, kod, ';'); 
            ofs << kod << endl;
            cout << kod << endl; 
            getline(sStream, kod, ';'); 
            ofs << kod << endl;
            cout << kod << endl; 
            getline(sStream, kod, ';'); 
            ofs << kod << endl;
            cout << kod << endl; 

            if (c == 10) {
                break;
            }
            c++;
            line = "";
        }
        
        ofs.close();
        ifs.close();
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
