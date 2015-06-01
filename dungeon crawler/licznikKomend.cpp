#include <iostream>
#include "CommandTree.h"
#include "licznikKomend.h"

licznikKomend::licznikKomend()
{
	for (int i = 0; i < LICZBA_KOMEND; i++)
	{
		iloscWywolan[i] = 0;
	}
}

void licznikKomend::zwieksz(Ekomenda komenda)
{
	iloscWywolan[komenda]++;
}

int licznikKomend::sprawdz(Ekomenda komenda)
{
	return iloscWywolan[komenda];
}

void licznikKomend::wypiszLicznik()
{
	for (int i = 0; i < LICZBA_KOMEND; i++)
	{
		wcout << iloscWywolan[i] << ' ';
	}
}