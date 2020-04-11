#pragma once
#include <vector>

class Console;
class Object;

class System
{
private:

	Console* console;
	std::vector<Object*> objects;
	
	bool running;

public:

	System();
	~System();

	void Run();

};

