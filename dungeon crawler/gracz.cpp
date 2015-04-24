#include "gracz.h"
#include "Walka.h"
#include "Lokacja.h"
#include "item_types.h"
#include "color.h"
#include "wersalikuj.h"
#include "ListaKomend.h"

using namespace std;

Gracz::Gracz() :
Postac()
{
	exp = 0;
	pktCech = 0;
	charakter = 0;
	polozenie = NULL;
	poprzedniePolozenie = KIERUNEK_NIEPOPRAWNY;
}

void Gracz::tworzenie_postaci()
{
	color(HWHITE);
	wcout << L"Podaj swoje imię:" << endl;
	//wcin.read(imie, L'\n');
	wcin >> imie;
	wcin.ignore(999, L'\n');
	wcin.sync();
	int wybor = -1;

	///////////////////// RASA //////////////////////////

	while (wybor)
	{
		wcout << L"Wybierz swoją rasę:" << endl;
		wcout << "  1-Czlowiek" << endl;
		wcout << "  2-Krasnolud" << endl;
		wcout << "  3-Ork" << endl;
		wcout << "  4-Niziołek" << endl;
		wcout << "  5-Elf" << endl;
		wcout << "  6-Pol Elf" << endl;
		wcout << "  7-Mroczny elf" << endl;
		wcout << "  8-Lacert" << endl;
		wcout << "  9-Sidan" << endl;
		wcout << "  10-Gnom" << endl;
		//wstring sWybor;
		wcin >> wybor;
		//wybor = stoi(sWybor);
		wcin.clear();
		wcin.ignore(999, L'\n');
		wcin.sync();
		switch (wybor)
		{
		case 1:
			rasa = getRasa(RASA_CZLOWIEK);
			wybor = 0;
			break;
		case 2:
			rasa = getRasa(RASA_KRASNOLUD);
			wybor = 0;
			break;
		case 3:
			rasa = getRasa(RASA_ORK);
			wybor = 0;
			break;
		case 4:
			rasa = getRasa(RASA_NIZIOLEK);
			wybor = 0;
			break;
		case 5:
			rasa = getRasa(RASA_ELF);
			wybor = 0;
			break;
		case 6:
			rasa = getRasa(RASA_POLELF);
			wybor = 0;
			break;
		case 7:
			rasa = getRasa(RASA_MROCZNYELF);
			wybor = 0;
			break;
		case 8:
			rasa = getRasa(RASA_LACERT);
			wybor = 0;
			break;
		case 9:
			rasa = getRasa(RASA_SIDAN);
			wybor = 0;
			break;
		case 10:
			rasa = getRasa(RASA_GNOM);
			wybor = 0;
			break;
		default:
			wcout << "Buont!" << endl;
			wybor = -1;
		}
	}

	///////////////////////// KLASA /////////////////////

	wybor = -1;
	while (wybor)
	{
		wcout << L"Wybierz swoja klasę:" << endl;
		wcout << L"  1-Barbarzyńca" << endl;
		wcout << L"  2-Łowca" << endl;
		wcout << L"  3-Rycerz" << endl;
		wcout << L"  4-Najemnik" << endl;
		wcout << L"  5-Szermierz" << endl;
		wcout << L"  6-Gwardzista" << endl;
		wcout << L"  7-Berserker" << endl;
		wcout << L"  8-Paladyn" << endl;
		wcout << L"  9-Strażnik" << endl;
		wcout << L"  10-Mnich" << endl;

		wcin >> wybor;
		wcin.clear();
		wcin.ignore(999, L'\n');
		wcin.sync();
		switch (wybor)
		{
		case 1:
			klasa = getKlasa(KLASA_BARBARZYNCA);
			wybor = 0;
			break;
		case 2:
			klasa = getKlasa(KLASA_LOWCA);
			wybor = 0;
			break;
		case 3:
			klasa = getKlasa(KLASA_RYCERZ);
			wybor = 0;
			break;
		case 4:
			klasa = getKlasa(KLASA_NAJEMNIK);
			wybor = 0;
			break;
		case 5:
			klasa = getKlasa(KLASA_SZERMIERZ);
			wybor = 0;
			break;
		case 6:
			klasa = getKlasa(KLASA_GWARDZISTA);
			wybor = 0;
			break;
		case 7:
			klasa = getKlasa(KLASA_BERSERKER);
			wybor = 0;
			break;
		case 8:
			klasa = getKlasa(KLASA_PALADYN);
			wybor = 0;
			break;
		case 9:
			klasa = getKlasa(KLASA_STRAZNIK);
			wybor = 0;
			break;
		case 10:
			klasa = getKlasa(KLASA_MNICH);
			wybor = 0;
			break;

		default:
			wcout << "Buont!" << endl;
			wybor = -1;
		}
	}

	sil_baz = 10, zr_baz = 10, zw_baz = 10, wyt_baz = 10, zyw_baz = 10;

	poziom = 1;
	exp = 0;
	pktCech = 0;
	przelicz();

	currentHP = 1;
	poprzedniePolozenie = KIERUNEK_NIEPOPRAWNY;
}

void Gracz::ulecz(int ile)
{
	if (currentHP + ile > zdr_calk) currentHP = zdr_calk;	//jeżeli gracz mialby byc wyleczony ponad max HP
	else currentHP += ile;								//normalne leczenoe
}

void Gracz::dodajEXP(int ile)
{
	if (DEBUG_WALKA)
		playerMsg(L"|YZdobywasz |0 pkt. doświadczenia.", intToStr(ile));
	exp += ile;
	if (exp >= expDoNastPoziomu())
		awansOPoziom();
}

void Gracz::awansOPoziom()
{
	color(HYELLOW);
	playerMsg(L"Awansowałeś o poziom!");
	color(HWHITE);

	exp -= expDoNastPoziomu();
	poziom++;
	pktCech += 7;
	przelicz();
}

int Gracz::expDoNastPoziomu()
{
	return (int)floor(poziom * 10 * pow(1.02, poziom));
}


bool Gracz::jestGraczem()
{
	return true;
}

bool Gracz::jestUzbrojony()
{
	if (Item* przedmiot = eq[SLOT_PREKA])
	{
		if (przedmiot->typ == ITEM_1HWEAPON) return true;
		if (przedmiot->typ == ITEM_2HWEAPON) return true;
	}
	if (Item* przedmiot = eq[SLOT_LREKA])
	{
		if (przedmiot->typ == ITEM_1HWEAPON) return true;
		if (przedmiot->typ == ITEM_2HWEAPON) return true;
	}
	return false;
}

void Gracz::sprawdzWymagania(Item *Item)
{
	Staty staty = Item->czytaj_staty();
	if (sil_calk < staty.sil)
	{
		wcout << "Twoja siła jest za mała aby sprawnie posługiwać się tym przedmiotem." << endl;
	}
	if (zr_calk < staty.zr)
	{
		wcout << "Twoja zręczność jest za mała aby sprawnie posługiwać się tym przedmiotem." << endl;
	}
	if (zw_calk < staty.zw)
	{
		wcout << "Twoja zwinność jest za mała aby sprawnie posługiwać się tym przedmiotem." << endl;
	}
	if (wyt_calk < staty.wyt)
	{
		wcout << "Twoja wytrzymałość jest za mała aby sprawnie posługiwać się tym przedmiotem." << endl;
	}
	if (zyw_calk < staty.zyw)
	{
		wcout << "Twoja żywotność jest za mała aby sprawnie posługiwać się tym przedmiotem." << endl;
	}
}


