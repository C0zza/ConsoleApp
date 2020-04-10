#include "Object.h"

Object::Object()
	:enabled{ false }
{
}

void Object::UpdateObject()
{
	if (enabled)
	{
		Update();
	}
}
