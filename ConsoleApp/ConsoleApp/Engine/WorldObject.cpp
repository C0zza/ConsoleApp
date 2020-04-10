#include "WorldObject.h"
#include "Math/IVector2.h"

WorldObject::WorldObject()
{
	position.x = 0;
	position.y = 0;
}

WorldObject::WorldObject(IVector2 pos)
{
	position = pos;
}

Sprite* WorldObject::GetSprite()
{
	return sprite;
}
