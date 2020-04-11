#include "WorldObject.h"
#include "Math/IVector2.h"
#include "Sprite.h"

WorldObject::WorldObject()
{
	position.x = 0;
	position.y = 0;

	sprite = new Sprite();
}

WorldObject::WorldObject(IVector2 pos)
{
	position = pos;
	sprite = new Sprite();
}

void WorldObject::UpdateWorldObject()
{
	sprite->Draw(position);
	Update();
}

Sprite* WorldObject::GetSprite()
{
	return sprite;
}
