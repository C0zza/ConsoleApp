#pragma once
#include <Windows.h>
#include <iostream>
#include "Colours.h"

class Console
{
private:

	HWND hConsoleWindow;
	RECT windowDimensions;

	HANDLE hStdout, hStdin;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

	CONSOLE_CURSOR_INFO cursorInfo;
	COORD cursorPosition;
	COLOUR cursorColour;

	const double WindowToBufferWidth = 0.12395833333333333333333333333333;

public:

	Console();

	void SetCursorPosition(int x, int y);
	void SetCursorPosition(COORD coord);
	void SetCursorColour(COLOUR colour);

	void Print(std::string s, bool newLine = false);

	void Clear();
	void SetWindowSize(int width, int height);
};