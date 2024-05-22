#include "app.h"
#include "units/units.h"
#include <libds/amt/explicit_hierarchy.h>
#include <libds/heap_monitor.h>
#include <windows.h>


int main(int argc, char *argv[]) {
    initHeapMonitor();
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);

    std::cout << "\033[31m    ___   __  _______    _____ ____\n"
              << "\033[93m   /   | / / / / ___/   / ___// __ |\n"
              << "\033[92m  / /| |/ / / /|__ |    |__ |/ /_/ /\n"
              << "\033[96m / ___ / /_/ /___/ /   ___/ / ____/\n"
              << "\033[94m/_/  |_|____//____/   /____/_/\n"
              << "\033[95m************************************\033[0m\n";
    App app;
    app.mainLoop();

    return 0;
}
