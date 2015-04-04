#include "Test.h"
#include "gra.h"
#include <vector>
#include "ConsoleSize.h"

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
	//wcout<<gracz.cechaTowstring(gracz.najwyzszaCecha(0))<<" "<<gracz.cechaTowstring(gracz.najwyzszaCecha(1))<<endl;
	//questy[1].spelnijRozmowa(1);
	//questy[1].spelnijPotwor(2);
	//questy[1].spelnijPotwor(2);
		
	/*wcout<<"go lvl1"<<endl;
	midiPlayer->play(MIDI_LVL1);
	Sleep(20000);
	wcout<<"go BATTLE"<<endl;
	midiPlayer->play(MIDI_BATTLE1);*/
	wcout<<wersalikuj(L"12345678\t12345678\t12345678\t12345678\t12345678\t12345678\t12345678\n");
	wcout<<wersalikuj(L"Jakis\ttam\ttekst\tz\tduza\tiloscia\ttabulatorow\tktore\tnajwidoczniej\tjuz\ttak\tzle\tnie\twplywaja\tna\twer\ttekstu.\n\n");

	playerMsg(L"Nazywam siê |b|0|W. Tak |B|0|W to w³aœnie moje imiê. A nie, mo¿e to jednak |R|1|W? "
	 L"Nieee, chyba |G|2|W... Nie, to nie to... Wiem! |P|3|W to moje prawdziwe imiê!",
		gra->gracz.imie, L"Wojtek Pêdziwór", L"Skrzypek Nadachu", L"Zdziocho Moczyw¹s");

	playerMsg(L"|+Jakiœ Tam Kawa³ek Œliskiego Tekstu");
	playerMsg(L"|-Jakiœ Tam Kawa³ek Œliskiego Tekstu");

	playerMsg(czystyTekst(L"|BJakiœ Tam |_POFOmatoWANY |RTEKSt."));

	int rows = 0, columns = 0;
	getWindowSize(rows, columns);
	playerMsg(L"Wymiary okna linie:|0 kolumny|:1.", intToStr(rows), intToStr(columns));
}

void Test::manual()
{
	Komenda::manual();	//TODO wpisac manual dla danej komendy
}