#include "app.h"
#include <crtdbg.h>
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
