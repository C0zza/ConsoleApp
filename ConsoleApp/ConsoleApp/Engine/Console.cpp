#include "Console.h"

Console::Console()
{
	hConsoleWindow = GetConsoleWindow();
	
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);	// Initialise output and input handles
	hStdin = GetStdHandle(STD_INPUT_HANDLE);

	if (hStdin == INVALID_HANDLE_VALUE || hStdout == INVALID_HANDLE_VALUE)	// Check handles are initialised properly
	{
		MessageBox(NULL, TEXT("GetStdHandle"), TEXT("Handles failed to initialise."), MB_OK);
		return;
	}

	if (!GetConsoleScreenBufferInfo(hStdout, &screenBufferInfo))	// Initialise and validate console buffer info.
	{
		MessageBox(NULL, TEXT("GetConsoleScreenBufferInfo"), TEXT("Console buffer info failed to initialise."), MB_OK);
		return;
	}

	if (!GetConsoleCursorInfo(hStdout, &cursorInfo))
	{
		MessageBox(NULL, TEXT("GetCursorInfo"), TEXT("Cursor info failed to initialise."), MB_OK);
		return;
	}

	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hStdout, &cursorInfo);


	cursorPosition = { 0,0 };
	cursorColour = COLOUR::WHITE;

}

void Console::SetCursorPosition(int x, int y)
{
	cursorPosition = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hStdout, cursorPosition);
}

void Console::SetCursorPosition(COORD coord)
{
	cursorPosition = coord;
	SetConsoleCursorPosition(hStdout, cursorPosition);
}

void Console::SetCursorColour(COLOUR colour)
{
	SetConsoleTextAttribute(hStdout, (int)colour);
}

void Console::Print(std::string s, bool newLine)
{
	if (newLine)
	{
		std::cout << s << std::endl;
	}
	else
	{
		std::cout << s;
	}
}

void Console::Clear()
{
	DWORD dwBufferLen = screenBufferInfo.dwSize.X * screenBufferInfo.dwSize.Y;
	const COORD coordWriteStart{ 0,0 };
	DWORD dwWritten;

	const char fillChar = ' ';
	FillConsoleOutputAttribute(hStdout, screenBufferInfo.wAttributes, dwBufferLen, coordWriteStart, &dwWritten);
	FillConsoleOutputCharacter(hStdout, fillChar, dwBufferLen, coordWriteStart, &dwWritten);
	SetConsoleCursorPosition(hStdout, coordWriteStart);
}

void Console::SetWindowSize(int width, int height)
{
	GetWindowRect(hConsoleWindow, &windowDimensions);
	MoveWindow(hConsoleWindow, windowDimensions.left, windowDimensions.top, width, height, TRUE);
	SetConsoleScreenBufferSize(hStdout, COORD{ (SHORT)(width * WindowToBufferWidth) - (SHORT)1, (SHORT)(height * WindowToBufferWidth) });
}
