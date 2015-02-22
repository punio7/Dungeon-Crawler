#include "Test.h"
#include "gra.h"
#include <vector>
#include "ConsoleSize.h"

Test::Test(Gra *gra):
	Komenda(gra)
{
	nazwa="";
}


Test::~Test(void)
{
}

void Test::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;
	cout<<gracz.expDoNastPoziomu()<<endl;
	gracz.dodajEXP(10);
	cout<<gracz.expDoNastPoziomu()<<endl;
	gracz.dodajEXP(20);
	cout<<gracz.expDoNastPoziomu()<<endl;
	gracz.dodajEXP(31);
	//cout<<gracz.cechaToString(gracz.najwyzszaCecha(0))<<" "<<gracz.cechaToString(gracz.najwyzszaCecha(1))<<endl;
	//questy[1].spelnijRozmowa(1);
	//questy[1].spelnijPotwor(2);
	//questy[1].spelnijPotwor(2);
		
	/*cout<<"go lvl1"<<endl;
	midiPlayer->play(MIDI_LVL1);
	Sleep(20000);
	cout<<"go BATTLE"<<endl;
	midiPlayer->play(MIDI_BATTLE1);*/
	cout<<wersalikuj("12345678\t12345678\t12345678\t12345678\t12345678\t12345678\t12345678\n");
	cout<<wersalikuj("Jakis\ttam\ttekst\tz\tduza\tiloscia\ttabulatorow\tktore\tnajwidoczniej\tjuz\ttak\tzle\tnie\twplywaja\tna\twer\ttekstu.\n\n");

	playerMsg("Nazywam si� |b|0|W. Tak |B|0|W to w�a�nie moje imi�. A nie, mo�e to jednak |R|1|W? "
		"Nieee, chyba |G|2|W... Nie, to nie to... Wiem! |P|3|W to moje prawdziwe imi�!",
		gra->gracz.imie, "Wojtek P�dziw�r", "Skrzypek Nadachu", "Zdziocho Moczyw�s");

	playerMsg("|+Jaki� Tam Kawa�ek �liskiego Tekstu");
	playerMsg("|-Jaki� Tam Kawa�ek �liskiego Tekstu");

	playerMsg(czystyTekst("|BJaki� Tam |_POFOmatoWANY |RTEKSt."));

	int rows = 0, columns = 0;
	getWindowSize(rows, columns);
	playerMsg("Wymiary okna linie:|0 kolumny|:1.", intToStr(rows), intToStr(columns));
}

void Test::manual()
{
	Komenda::manual();	//TODO wpisac manual dla danej komendy
}