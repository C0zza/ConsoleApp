#include "WorldObject.h"
#include "Math/IVector2.h"
#include "Sprite.h"
#include "Collider.h"

WorldObject::WorldObject()
{
	position.x = 0;
	position.y = 0;
	
	sprite = new Sprite();
	collider = new Collider(&position, &sprite->GetSprite());
}

WorldObject::WorldObject(IVector2 pos)
{
	position = pos;
	sprite = new Sprite();
	collider = new Collider(&position, &sprite->GetSprite());
}

void WorldObject::UpdateWorldObject()
{
	sprite->Draw(position);
	
	Update();
}

void WorldObject::Translate(IVector2 movement)
{
	if (!collider->CheckMovementForCollision(movement))
	{
		position += movement;
	}
}

Sprite* WorldObject::GetSprite()
{
	return sprite;
}
