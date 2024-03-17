#pragma once
#include <string>
#include <iostream>

using namespace std;

class TerritorialUnit {
  private:
    string name = "";
    int code = 0;

  public:
    TerritorialUnit(); 
    TerritorialUnit(string &name, int &code); 
    ~TerritorialUnit();
    const string &getName() const;
    const int& getCode() const;
    
    friend std::ostream &operator<<(std::ostream &os,
                                    const TerritorialUnit &territorialUnit);
};
