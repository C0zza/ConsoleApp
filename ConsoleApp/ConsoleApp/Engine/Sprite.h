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

	static void SetConsole(Console* console);
};

