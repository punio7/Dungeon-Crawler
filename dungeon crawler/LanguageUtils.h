#pragma once

namespace RodzajRzeczownika
{
	enum RodzajRzeczownikaEnum
	{
		MESKI,
		ZENSKI,
		NIJAKI,
		MESKOOSOBOWY,
		NIEMESKOOSOBOWY
	};
}

namespace PrzypadekRzeczownika
{
	enum PrzypadekRzeczownikaEnum
	{
		MIANOWNIK,		//kto, co
		DOPELNIACZ,		//kogo, czego
		CELOWNIK,		//komu, czemu
		BIERNIK,		//kogo, czego
		NARZEDNIK,		//z kim, z czym
		MIEJSCOWNIK,	//o kim, o czym
		LICZBA_PRZYPADKOW
		//WOLACZ			//o! niepotrzebny, jest taki sam jak miejscownik
	};
}