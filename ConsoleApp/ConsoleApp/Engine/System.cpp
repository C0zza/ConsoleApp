#include "System.h"
#include "Object.h"
#include "Console.h"
#include "Sprite.h"
#include "../Game/Player.h"
#include "../Game/TestObject.h"

System::System()
	: running{ true }
{
	this->console = new Console;
	objects.push_back(new Player());
	objects.push_back(new TestObject(IVector2(20, 20)));
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

		Sleep(1000 / 30);

		console->Clear();
	}
}
