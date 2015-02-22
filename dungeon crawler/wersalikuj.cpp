#include "wersalikuj.h"

string wersalikuj(string wejsciowy, int dlugoscWiersza)
{
	if (wejsciowy.empty()) return wejsciowy;
	int obecnyZnak=0;
	int ostatniSpace=0;
	int znaki=0;
	char ch = wejsciowy[0];

	while (obecnyZnak < (int)wejsciowy.length())
	{
		ch = wejsciowy[obecnyZnak];
		if ( ch==' ' || ch=='\t' || ch=='\v' || ch=='\f' || ch=='\r' ) ostatniSpace = obecnyZnak;
		if (znaki >= (dlugoscWiersza-1))	//-1 poniewaz \n rownierz musi sie zmiescic w tej linii
		{
			wejsciowy[ostatniSpace] = '\n';
			znaki = obecnyZnak-ostatniSpace;
		}
		if ( ch=='\n' ) znaki=0;
		if ( ch=='\t' ) znaki += znaki%8;	//tab dodaje 0-8 znakow w linii
		else
			if ( ch == '|')		//specjalny znak formatowania, zosatnie skawoany przy wyswietlaniu wiec
			{					//ignorujemy jego i znak po nim
				obecnyZnak++;
			}
			else
				znaki++;
		obecnyZnak++;
		
	}

	return wejsciowy;
}