#include "Unlock.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Unlock::Unlock(Gra *gra):
	Komenda(gra)
{
	nazwa="unlock";
}


Unlock::~Unlock(void)
{
}

void Unlock::execute(ParseDTO argumenty)
{
	if (argumenty.kierunek1 != KIERUNEK_NIEPOPRAWNY)
	{
		if (!(gra->gracz.polozenie->zamek[argumenty.kierunek1]>1))
		{
			playerMsg("Tam nie ma nic do odkluczenia.");
			return;
		}
		
		unlockDoor(argumenty.kierunek1);
	}
	else
	{
		if (argumenty.argument1.empty())
		{
			playerMsg("Co chcia�by� odkluczy�?");
			return;
		}
		
		Item *chest = gra->gracz.polozenie->przedmioty->znajdz(argumenty.argument1, argumenty.ktory1);

		if (!chest)
		{
			playerMsg("Tutaj nie ma nic takiego.");
			return;
		}

		if (!chest->jestPojemnikiem() || !chest->numerZamka())
		{
			playerMsg("|^|0 nie ma �adnego zamka.", chest->nazwa);
			return;
		}

		unlockChest(chest);
	}
}

void Unlock::manual()
{
	playerMsg("Synonimy:\n"
				"   unlock(un)\n\n"
				"U�ycia:\n\n"
				"   unlock <kierunek> - gracz spr�buje odkluczy� drzwi/klap� we wskazanym kierunku. Musisz posiada� w inwentarzu klucz pasuj�cy do zamka.\n\n"
				"   unlock <nazwa_pojemnika> - gracz spr�buje odkluczy� wskazan� skrzyni�, sejf, szaf�, kolzetk�, szkatu�k� b�d� inny pojemnik. Oczywi�cie musisz posiada� klucz.\n\n"
				"Sprawd� r�wnie�:\n"
				"   open, examine");
}

void Unlock::unlockDoor(KierunekSwiata kierunek)
{
	Gracz &gracz = gra->gracz;

	Item *klucz = gracz.przedmioty->znajdz(gracz.polozenie->zamek[kierunek], 1);

	if (!klucz)
	{
		playerMsg("�aden z twoich kluczy nie pasuje do zamka.");
		return;
	}

	playerMsg("Odkluczasz |0 przy pomocy |1.", (kierunek==UP||kierunek==DOWN)?"klap�":"przej�cie", klucz->nazwa);
	gracz.polozenie->zamek[kierunek]=1;
	gracz.polozenie->wyjscie[kierunek]->zamek[kierunekPrzeciwny(kierunek)]=1; //z drugiej strony rowniez zdejmujemy zamek
}

void Unlock::unlockChest(Item *chest)
{
	Gracz &gracz = gra->gracz;

	Item *klucz = gracz.przedmioty->znajdz(chest->numerZamka(), 1);

	if (!klucz)
	{
		playerMsg("�aden z twoich kluczy nie pasuje do zamka.");
		return;
	}

	playerMsg("Odkluczasz |0 przy pomocy |1.", chest->nazwa, klucz->nazwa);
	chest->ustawZamek(0);
}