#pragma once
#include <iostream>

class TerritorialUnit {
  private:
    std::string name = "";
    int code = 0;

  public:
    TerritorialUnit();
    TerritorialUnit(std::string &name, int code);
    ~TerritorialUnit();
    const std::string &getName() const;
    const int getCode() const;

    friend std::ostream &operator<<(std::ostream &os,
                                    const TerritorialUnit &territorialUnit);
    virtual void print(std::ostream &os) const;
};
