#include "color.h"
#include <Windows.h>

void color(Colors kolor)
{
	HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle, kolor);
}

void color(char c)
{
	switch (c)
	{
	case 'b':
		color(BLUE);		// |b
		break;
	case 'g':
		color(GREEN);		// |g
		break;
	case 'c':
		color(CYAN);		// |c
		break;
	case 'r':
		color(RED);			// |r
		break;
	case 'p':
		color(PURPLE);		// |p
		break;
	case 'y':
		color(YELLOW);		// |y
		break;
	case 's':
		color(GREY);		// |s
		break;
	case 'S':
		color(DGREY);		// |S
		break;
	case 'B':
		color(HBLUE);		// |B
		break;
	case 'G':
		color(HGREEN);		// |G
		break;
	case 'C':
		color(HCYAN);		// |C
		break;
	case 'R':
		color(HRED);		// |R
		break;
	case 'P':
		color(HPURPLE);		// |P
		break;
	case 'Y':
		color(HYELLOW);		// |Y
		break;
	case 'W':
		color(HWHITE);		// |W
		break;
	default:
		break;
	}
		
}
