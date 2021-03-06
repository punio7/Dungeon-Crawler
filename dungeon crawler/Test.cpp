#include <iostream>
#include <vector>
#include "Test.h"
#include "Gra.h"
#include "ConsoleSize.h"
#include "wersalikuj.h"

Test::Test(Gra *gra):
	Komenda(gra)
{
	nazwa = L"";
}


Test::~Test(void)
{
}

void Test::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;
	wcout<<gracz.expDoNastPoziomu()<<endl;
	gracz.dodajEXP(10);
	wcout<<gracz.expDoNastPoziomu()<<endl;
	gracz.dodajEXP(20);
	wcout<<gracz.expDoNastPoziomu()<<endl;
	gracz.dodajEXP(31);

	//test segv
	//Gracz* cos = 0;
	//cos->imie = L"";
		
	/*wcout<<"go lvl1"<<endl;
	midiPlayer->play(MIDI_LVL1);
	Sleep(20000);
	wcout<<"go BATTLE"<<endl;
	midiPlayer->play(MIDI_BATTLE1);*/
	wcout << wersalikuj(L"12345678901234567890123456789012345678901234567890123456789012345678901234567890\n");
	wcout << wersalikuj(L"12345678\t12345678\t12345678\t12345678\t12345678\t12345678\t12345678\n");
	wcout<<wersalikuj(L"Jakis\ttam\ttekst\tz\tduza\tiloscia\ttabulatorow\tktore\tnajwidoczniej\tjuz\ttak\tzle\tnie\twplywaja\tna\twer\ttekstu.\n\n");

	playerMsg(L"Nazywam si� |b|0|W. Tak |B|0|W to w�a�nie moje imi�. A nie, mo�e to jednak |R|1|W? "
	 L"Nieee, chyba |G|2|W... Nie, to nie to... Wiem! |P|3|W to moje prawdziwe imi�!",
		gra->gracz.imie, L"Wojtek P�dziw�r", L"Skrzypek Nadachu", L"Zdziocho Moczyw�s");

	playerMsg(L"|+Jaki� Tam Kawa�ek �liskiego Tekstu");
	playerMsg(L"|-Jaki� Tam Kawa�ek �liskiego Tekstu");

	playerMsg(czystyTekst(L"|BJaki� Tam |_POFOmatoWANY |RTEKSt."));

	int rows = 0, columns = 0;
	getWindowSize(rows, columns);
	playerMsg(L"Wymiary okna linie:|0 kolumny|:1.", intToStr(rows), intToStr(columns));
}

void Test::manual()
{
	Komenda::manual();	//TODO wpisac manual dla danej komendy
}