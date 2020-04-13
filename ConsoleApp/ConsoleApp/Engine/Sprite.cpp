#include "Sprite.h"
#include "Math/IVector2.h"
#include "Console.h"

Console* Sprite::console;

Sprite::Sprite()
{
	sprite.push_back("O");
}

void Sprite::Draw(IVector2& position)
{
	for (int i = 0; i < sprite.size(); i++)
	{
		console->SetCursorPosition(COORD{ (SHORT)position.x, (SHORT)(position.y + i) });
		console->Print(sprite[i]);
	}
}

void Sprite::SetSprite(std::vector<std::string> sprite)
{
	this->sprite = sprite;
}

std::vector<std::string> Sprite::GetSprite()
{
	return sprite;
}

void Sprite::SetConsole(Console* theConsole)
{
	console = theConsole;
}
