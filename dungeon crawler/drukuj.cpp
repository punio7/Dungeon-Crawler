#include "drukuj.h"
#include <iostream>
#include <locale>
#include <windows.h>
#include "wersalikuj.h"

void drukuj(string wejsciowy, int delay)
{
	locale loc;
	string msg = wersalikuj(wejsciowy);
	for (int i=0;i < msg.length(); i++)
	{
		cout<<msg[i];
		if (GetAsyncKeyState(VK_ESCAPE))
		{
              delay=0;
		}
		if (!isspace(msg[i],loc)) Sleep(delay);		//delay przy spacjach powodowalby odczucie skokowego drukwoania tekstu
	}
	Sleep(delay*10);
}