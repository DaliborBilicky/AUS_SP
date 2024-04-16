#include "app.h"
#include <crtdbg.h>
#include <windows.h>
#include <libds/amt/explicit_hierarchy.h>
#include <libds/heap_monitor.h>

int main(int argc, char *argv[]) {
    initHeapMonitor();
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
