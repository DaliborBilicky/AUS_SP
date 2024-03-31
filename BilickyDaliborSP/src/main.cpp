#include "algorithms.h"
#include "units/units.h"
#include "units/territorial_unit.h"
#include "menu/prompt.h"
#include "menu/current_state.h"
#include "menu/states.h"
#include "app.h"
#include <chrono>
#include <crtdbg.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

int main(int argc, char *argv[]) {
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    {
        App app;
        app.start();
        app.mainLoop();
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
