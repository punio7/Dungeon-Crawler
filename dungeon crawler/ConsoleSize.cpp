#include <windows.h>

void getWindowSize(int& lines, int& columns)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
	{
		lines = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}
	else lines = columns = 0;
}

void setWindowSize(int lines, int columns)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
	{
		// Make sure the new size isn't too big
		if (lines > csbi.dwSize.Y) lines = csbi.dwSize.Y;
		if (columns > csbi.dwSize.X) columns = csbi.dwSize.X;

		// Adjust window origin if necessary
		if ((csbi.srWindow.Top + lines) > csbi.dwSize.Y) csbi.srWindow.Top = csbi.dwSize.Y - lines - 1;
		if ((csbi.srWindow.Left + columns) > csbi.dwSize.Y) csbi.srWindow.Left = csbi.dwSize.X - columns - 1;

		// Calculate new size
		csbi.srWindow.Bottom = csbi.srWindow.Top + lines - 1;
		csbi.srWindow.Right = csbi.srWindow.Left + columns - 1;

		SetConsoleWindowInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			true,
			&csbi.srWindow
			);
	}
}