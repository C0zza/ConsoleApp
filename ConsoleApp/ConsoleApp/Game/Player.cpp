#include "Player.h"
#include "../Engine/Input.h"

void Player::Update()
{
	if (Input::IsKeyDown(KEY_D))
	{
		Move(IVector2(1, 0));
	}
	if (Input::IsKeyDown(KEY_A))
	{
		Move(IVector2(-1, 0));
	}
	if (Input::IsKeyDown(KEY_W))
	{
		Move(IVector2(0, -1));
	}
	if (Input::IsKeyDown(KEY_S))
	{
		Move(IVector2(0, 1));
	}
}

void Player::Move(IVector2 movement)
{
	position += movement;
}
