#include "Sprite.h"
#include "Math/IVector2.h"
#include "Console.h"

void Sprite::Draw(IVector2& position)
{
	for (int i = 0; i < sprite.size(); i++)
	{
		console->SetCursorPosition(COORD{ (SHORT)position.x, (SHORT)(position.y + i) });
		console->Print(sprite[i]);
	}
}
