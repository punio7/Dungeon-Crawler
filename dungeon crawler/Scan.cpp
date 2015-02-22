#include "Scan.h"
#include "gra.h"
#include "Lokacja.h"

Scan::Scan(Gra *gra):
	Komenda(gra)
{
	nazwa="scan";
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
	
	playerMsg("Rozgl�daj�c si� dooko�a dostrzegasz:");

	playerMsg("|gTutaj:");
	playerMsg(gracz.polozenie->postacie-> wypisz(CHARLIST_WYPISZ_SCAN));

	for (int i = NORTH; i < KIERUNEK_NIEPOPRAWNY; i++)
	{
	if ((gracz.polozenie->wyjscie)[i]) 
		{
			playerMsg("|gNa |0:", celownikKierunkuSwiata((KierunekSwiata)i));
			if((gracz.polozenie->zamek)[i]>0) 
				playerMsg("\t|gdrzwi s� zamkni�te.");
			else 
				playerMsg(( ( (gracz.polozenie->wyjscie)[i] )->postacie ) -> wypisz(CHARLIST_WYPISZ_SCAN));
		}
	}
}

string Scan::celownikKierunkuSwiata(KierunekSwiata kierunek)
{
	switch (kierunek)
	{
	case NORTH:
		return "p�nocy";
	case SOUTH:
		return "po�udniu";
	case WEST:
		return "zachodzie";
	case EAST:
		return "wschodzie";
	case UP:
		return "g�rze";
	case DOWN:
		return "dole";
		break;
	default:
		return "";
	}
}

void Scan::manual()
{
	playerMsg("Synonimy:\n"
				"   scan(sc)\n\n"
				"U�ycia:\n\n"
				"   scan - wy�wietla list� postaci znajduj�cych si� w okolicy.\n\n"
				"Sprawd� r�wnie�:\n"
				"   look, examine");
}