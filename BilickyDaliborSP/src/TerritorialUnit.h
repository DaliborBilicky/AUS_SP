#pragma once
#include <string>
#include <iostream>

using namespace std;

class TerritorialUnit {
  private:
    string name = "";
    string code = "";

  public:
    TerritorialUnit(); 
    TerritorialUnit(string &name, string &code); 
    ~TerritorialUnit();
    const string& getName() const;
    const string& getCode() const;
    
    friend std::ostream &operator<<(std::ostream &os,
                                    const TerritorialUnit &territorialUnit);
};
