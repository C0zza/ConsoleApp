#pragma once
#include <vector>
#include <string>

class IVector2;
class Console;

class Sprite
{
private:
	
	Console* console;
	std::vector<char*> sprite;

public:
	
	void Draw(IVector2& position);
};

