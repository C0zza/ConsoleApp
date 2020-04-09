
#include "Engine/Console.h"
#include "Engine/Math/IVector2.h"
#include <iostream>

int main()
{
    IVector2 testVector(5, 5);
    IVector2 testVector2(10, 10);

    testVector += testVector2;

    std::cout << testVector.x << ", " << testVector.y;

    return 0;
}
