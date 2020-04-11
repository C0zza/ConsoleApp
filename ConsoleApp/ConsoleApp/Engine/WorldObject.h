#pragma once
#include "Object.h"
#include "Math/IVector2.h"

class Sprite;

class WorldObject : public Object
{
protected:

	Sprite* sprite;
	IVector2 position;

	virtual void Update() = 0;

public:

	WorldObject();
	WorldObject(IVector2 pos);

	void UpdateWorldObject();

	Sprite* GetSprite();

};

