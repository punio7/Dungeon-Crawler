#include "drukuj.h"
#include <iostream>
#include <locale>
#include <windows.h>
#include "wersalikuj.h"

void drukuj(wstring wejsciowy, int delay)
{
	locale loc;
	wstring msg = wersalikuj(wejsciowy);
	for (int i = 0; i < msg.length(); i++)
	{
		wcout << msg[i];
		if (msg[i] == L'\n')
		{
			wcout.flush();
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			delay = 0;
		}
		if (!isspace(msg[i], loc)) Sleep(delay);		//delay przy spacjach powodowalby odczucie skokowego drukwoania tekstu
	}
	wcout << endl << endl;
	Sleep(delay * 10);
}