#include "gracz.h"
#include "Lokacja.h"
#include "item_types.h"
#include "color.h"
#include "wersalikuj.h"
#include "ListaKomend.h"

using namespace std;

Gracz::Gracz():
	Postac()
{
	exp =0;
	pktCech =0;
	charakter =0;
	polozenie = NULL;
	poprzedniePolozenie = KIERUNEK_NIEPOPRAWNY;
}

void Gracz::tworzenie_postaci()
{
	color(HWHITE);
	cout<<"Podaj swoje imie:"<<endl;
	cin>>imie;
	cin.ignore(999,'\n');
	int wybor=-1;
	
	///////////////////// RASA //////////////////////////
	
	while (wybor)
	{
		cout<<"Wybierz swoja rase:"<<endl;
		cout<<"  1-Czlowiek"<<endl;
		cout<<"  2-Krasnolud"<<endl;
		cout<<"  3-Ork"<<endl;
		cout<<"  4-Nizio³ek"<<endl;
		cout<<"  5-Elf"<<endl;
		cout<<"  6-Pol Elf"<<endl;
		cout<<"  7-Mroczny elf"<<endl;
		cout<<"  8-Lacert"<<endl;
		cout<<"  9-Sidan"<<endl;
		cout<<"  10-Gnom"<<endl;
		cin>>wybor;
		cin.clear();
		cin.ignore(999,'\n');
		switch(wybor)
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
			cout<<"Buont!"<<endl;
			wybor = -1;
		}
	}
	
	///////////////////////// KLASA /////////////////////
	
	wybor=-1;
	while (wybor)
	{
		cout<<"Wybierz swoja klase:"<<endl;
		cout<<"  1-Barbarzyñca"<<endl;
		cout<<"  2-£owca"<<endl;
		cout<<"  3-Rycerz"<<endl;
		cout<<"  4-Najemnik"<<endl;
		cout<<"  5-Szermierz"<<endl;
		cout<<"  6-Gwardzista"<<endl;
		cout<<"  7-Berserker"<<endl;
		cout<<"  8-Paladyn"<<endl;
		cout<<"  9-Stra¿nik"<<endl;
		cout<<"  10-Mnich"<<endl;

		cin>>wybor;
		cin.clear();
		cin.ignore(999,'\n');
		switch(wybor)
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
			cout<<"Buont!"<<endl;
			wybor = -1;
		}
	}

	sil_baz=10, zr_baz=10, zw_baz=10, wyt_baz=10, zyw_baz=10;

	poziom = 1;
	exp=0;
	pktCech = 0;
	przelicz();

	currentHP=1;
	poprzedniePolozenie = KIERUNEK_NIEPOPRAWNY;
}

void Gracz::ulecz(int ile)
{
	if (currentHP+ile>zdr_calk) currentHP = zdr_calk;	//je¿eli gracz mialby byc wyleczony ponad max HP
	else currentHP += ile;								//normalne leczenoe
}

void Gracz::dodajEXP(int ile)
{
	exp+=ile;
	if (exp >= expDoNastPoziomu() ) awansOPoziom();
}

void Gracz::awansOPoziom()
{
	color(HYELLOW);
	cout<<"Awansowa³eœ o poziom!"<<endl;
	color(HWHITE);

	exp-=expDoNastPoziomu();
	poziom++;
	pktCech += 7;
	przelicz();
}

int Gracz::expDoNastPoziomu()
{
	return (int)floor( poziom*10*pow(1.02,poziom) );
}


bool Gracz::jestGraczem()
{
	return true;
}

bool Gracz::jestUzbrojony()
{
	if (Item* przedmiot=eq[SLOT_PREKA])
	{
		if (przedmiot->typ == ITEM_1HWEAPON) return true;
		if (przedmiot->typ == ITEM_2HWEAPON) return true;
	}
	if (Item* przedmiot=eq[SLOT_LREKA])
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
		cout<<"Twoja si³a jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem."<<endl;
	}
	if (zr_calk < staty.zr)
	{
		cout<<"Twoja zrêcznoœæ jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem."<<endl;
	}
	if (zw_calk < staty.zw)
	{
		cout<<"Twoja zwinnoœæ jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem."<<endl;
	}
	if (wyt_calk < staty.wyt)
	{
		cout<<"Twoja wytrzyma³oœæ jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem."<<endl;
	}
	if (zyw_calk < staty.zyw)
	{
		cout<<"Twoja ¿ywotnoœæ jest za ma³a aby sprawnie pos³ugiwaæ siê tym przedmiotem."<<endl;
	}
}

void Gracz::hold(string cel, int ktory)
{
	if (cel.empty())
	{
		cout<<"Czego chcesz dobyæ?"<<endl;
	}

	Item* przedmiot = przedmioty->znajdz(cel,ktory);

	if (przedmiot==NULL)
	{
		cout<<"Nie masz przy sobie czegoœ takiego jak "<<cel<<'.'<<endl;
		return;
	}

	if(!(przedmiot->jestBronia() || przedmiot->jestTarcza()))
	{
		cout<<przedmiot->nazwa<<" nie jest broni¹ ani tarcz¹."<<endl;
		return;
	}

	if (eq[SLOT_LREKA])		//jezeli jest w tym slocie juz jakis przedmiot
	{					//to go zdejmujemy
		przedmioty->dodaj(eq[SLOT_LREKA]);
		cout<<"Odk³adasz "<<eq[SLOT_LREKA]->nazwa<<'.'<<endl;
	}
	przedmioty->usun(przedmiot);
	eq[SLOT_LREKA]=przedmiot;
	cout<<"Chwytasz w lew¹ rêkê "<<przedmiot->nazwa<<'.'<<endl;
	przelicz();
	sprawdzWymagania(przedmiot);
}


