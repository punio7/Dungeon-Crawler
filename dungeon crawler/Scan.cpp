#include "Scan.h"
#include "Gra.h"
#include "Lokacja.h"

Scan::Scan(Gra *gra):
	Komenda(gra)
{
	nazwa = L"scan";
}


Scan::~Scan(void)
{
}

void Scan::execute(ParseDTO argumenty)
{
	scan();	
}

void Scan::scan()
{
	Gracz &gracz = gra->gracz;
	
	playerMsg(L"Rozgl�daj�c si� dooko�a dostrzegasz:");

	playerMsg(L"|gTutaj:");
	playerMsg(gracz.polozenie->postacie-> wypisz(CHARLIST_WYPISZ_SCAN));

	for (int i = NORTH; i < KIERUNEK_NIEPOPRAWNY; i++)
	{
	if ((gracz.polozenie->wyjscie)[i]) 
		{
			playerMsg(L"|gNa |0:", celownikKierunkuSwiata((KierunekSwiata)i));
			if((gracz.polozenie->zamek)[i]>0) 
				playerMsg(L"\t|gdrzwi s� zamkni�te.");
			else 
				playerMsg(( ( (gracz.polozenie->wyjscie)[i] )->postacie ) -> wypisz(CHARLIST_WYPISZ_SCAN));
		}
	}
}

wstring Scan::celownikKierunkuSwiata(KierunekSwiata kierunek)
{
	switch (kierunek)
	{
	case NORTH:
		return L"p�nocy";
	case SOUTH:
		return L"po�udniu";
	case WEST:
		return L"zachodzie";
	case EAST:
		return L"wschodzie";
	case UP:
		return L"g�rze";
	case DOWN:
		return L"dole";
		break;
	default:
		return L"";
	}
}

void Scan::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   scan(sc)\n\n"
			 L"U�ycia:\n\n"
			 L"   scan - wy�wietla list� postaci znajduj�cych si� w okolicy.\n\n"
			 L"Sprawd� r�wnie�:\n"
			 L"   look, examine");
}