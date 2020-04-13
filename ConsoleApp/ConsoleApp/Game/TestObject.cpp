#include "TestObject.h"
#include "../Engine/Sprite.h"
#include "../Engine/Collider.h"

TestObject::TestObject(IVector2 v)
{
	position = v;

	const char* s1[4];
	s1[0] = "####";
	s1[1] = "####";
	s1[2] = "####";
	s1[3] = "####";

	sprite->SetSprite(s1);
	collider->UpdateDimensions(&sprite->GetSprite());
}

void TestObject::Update()
{
}
