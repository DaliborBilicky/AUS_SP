#pragma once
#include <iostream>
#include <libds/heap_monitor.h>

class TerritorialUnit {
  private:
    std::string name = "";
    int code = 0;

  public:
    TerritorialUnit();
    TerritorialUnit(std::string &name, int code);
    virtual ~TerritorialUnit();
    const std::string &getName() const;
    const int getCode() const;
    virtual void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os,
                                    const TerritorialUnit &territorialUnit);
    friend bool operator==(const TerritorialUnit &me, const TerritorialUnit &other);
};
