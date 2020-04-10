
#include"Engine/System.h"

int main()
{
    System* system = new System;

    system->Run();

    delete system;
    system = nullptr;

    return 0;
}
