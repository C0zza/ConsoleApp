#include "Input.h"
#include <Windows.h>

bool Input::IsKeyDown(unsigned char keycode)
{
	if (GetAsyncKeyState(keycode) & 0x8000)
	{
		return true;
	}
	else
	{
		return false;
	}
}
