#pragma once

enum Predicates {
	NOTHING,
	STARTS_WITH_STRING,
	CONTAINS_STRING
};

enum Options {
	NONE,
	EXIT,
	EVERYTHING,
	REGIONS,
	SOORPS,
	SETTLEMENTS,
	WRONG_INPUT
};

class Menu {
  private:
    Options option = Options::NONE; 
  public:
    Menu();
    ~Menu();
    void mainMenu();
    Predicates subMenu();
    int getOption();
};
