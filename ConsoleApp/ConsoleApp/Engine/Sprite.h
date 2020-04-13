#pragma once
#include <vector>
#include <string>

class IVector2;
class Console;

class Sprite
{
private:
	
	static Console* console;
	std::vector<std::string> sprite;
	
public:
	
	Sprite();

	void Draw(IVector2& position);

	void SetSprite(std::vector<std::string> sprite);
	std::vector<std::string> GetSprite();

	static void SetConsole(Console* console);
};

