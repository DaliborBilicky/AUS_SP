#include "app.h"
#include <crtdbg.h>
#include <windows.h>
#include <libds/amt/explicit_hierarchy.h>

int main(int argc, char *argv[]) {
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    {

         //ds::amt::MultiWayExplicitHierarchy<TerritorialUnit> czechia;

         //TerritorialUnit mesto(str, 0);
         //czechia.emplaceSon(*root, 0);
         //czechia.accessSon(*root, 0)->data_ = mesto;
         //czechia.emplaceSon(*root, 1);
         //czechia.accessSon(*root, 1)->data_ = mesto;
         //czechia.emplaceSon(*root, 2);
         //czechia.accessSon(*root, 2)->data_ = mesto;
         //auto* mestoBlock = czechia.accessSon(*root, 0);

         //std::cout << czechia.degree(*mestoBlock) << std::endl;
         //std::cout << czechia.accessSon(*root, 0)->parent_->data_ << std::endl;
         //std::cout << czechia.accessSon(*root, 0)->data_ << std::endl;
         //std::cout << czechia.accessSon(*root, 1)->data_ << std::endl;
         //std::cout << czechia.accessSon(*root, 2)->data_ << std::endl;

        App app;
        app.start();
        app.mainLoop();
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
