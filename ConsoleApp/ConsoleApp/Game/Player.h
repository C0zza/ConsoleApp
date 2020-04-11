#pragma once
#include "../Engine/WorldObject.h"

class Player : public WorldObject
{
private:

public:

	void Update();

	void Move(IVector2 movement);

};

