#pragma once
#include "Object.h"
#include "Math/IVector2.h"

class Sprite;
class Collider;

class WorldObject : public Object
{
protected:

	Collider* collider;
	Sprite* sprite;
	IVector2 position;

	virtual void Update() = 0;

	void Translate(IVector2 movement);

public:

	WorldObject();
	WorldObject(IVector2 pos);

	void UpdateWorldObject();

	Sprite* GetSprite();

};

