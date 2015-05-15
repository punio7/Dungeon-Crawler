#include "wersalikuj.h"

wstring wersalikuj(wstring wejsciowy, int dlugoscWiersza)
{
	if (wejsciowy.empty()) return wejsciowy;
	int obecnyZnak = 0;
	int ostatniSpace = 0;
	int znaki = 0;
	wchar_t ch = wejsciowy[0];

	while (obecnyZnak < (int)wejsciowy.length())
	{
		ch = wejsciowy[obecnyZnak];
		if (ch == L' ' || ch == L'\t' || ch == L'\v' || ch == L'\f' || ch == L'\r') 
			ostatniSpace = obecnyZnak;
		if (znaki >= (dlugoscWiersza - 1))	//-1 poniewaz \n rownierz musi sie zmiescic w tej linii
		{
			wejsciowy[ostatniSpace] = L'\n';
			znaki = obecnyZnak - ostatniSpace;
		}
		if (ch == L'\n')
			znaki = 0;
		if (ch == L'\t') 
			znaki += znaki % 8;	//tab dodaje 0-8 znakow w linii
		else
		if (ch == L'|')		//specjalny znak formatowania, zosatnie skawoany przy wyswietlaniu wiec
		{					//ignorujemy jego i znak po nim
			obecnyZnak++;
		}
		else
			znaki++;
		obecnyZnak++;

	}

	return wejsciowy;
}