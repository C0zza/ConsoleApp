#include "IVector2.h"
#include <math.h>

IVector2::IVector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

IVector2::IVector2()
	: x{ 0 }, y{ 0 }
{
}

float IVector2::Distance(IVector2 v1, IVector2 v2)
{
	return sqrt((x * x) + (y * y));
}
