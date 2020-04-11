#include "System.h"
#include "Object.h"
#include "Console.h"
#include "Sprite.h"
#include "../Game/Player.h"

System::System()
	: running{ true }
{
	this->console = new Console;
	objects.push_back(new Player());
	Sprite::SetConsole(console);
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
			if (!objects[i]->GetDestroyed())
			{
				objects[i]->UpdateObject();
			}
			else
			{
				objects.erase(objects.begin() + i + 1);
			}
		}

		Sleep(1000 / 60);

		console->Clear();
	}
}
