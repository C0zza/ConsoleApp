#include "System.h"
#include "Object.h"
#include "Console.h"

System::System()
	: running{ true }
{
	this->console = new Console;
}

System::~System()
{
	for (int i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}
}

void System::Run()
{
	while (running)
	{
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->UpdateObject();
		}
	}
}
