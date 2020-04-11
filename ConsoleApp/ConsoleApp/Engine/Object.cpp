#include "Object.h"

Object::Object()
	:enabled{ true }, destroyed{ false }
{
}

void Object::UpdateObject()
{
	if (enabled)
	{
		UpdateWorldObject();
	}
}

void Object::DestroyObject()
{
	destroyed = true;
}

bool Object::GetDestroyed()
{
	return destroyed;
}


