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
    virtual void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os,
                                    const TerritorialUnit &territorialUnit);
    friend bool operator==(const TerritorialUnit &me, const TerritorialUnit &other);
};
