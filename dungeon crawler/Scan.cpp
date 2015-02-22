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
	
	playerMsg("Rozgl¹daj¹c siê dooko³a dostrzegasz:");

	playerMsg("|gTutaj:");
	playerMsg(gracz.polozenie->postacie-> wypisz(CHARLIST_WYPISZ_SCAN));

	for (int i = NORTH; i < KIERUNEK_NIEPOPRAWNY; i++)
	{
	if ((gracz.polozenie->wyjscie)[i]) 
		{
			playerMsg("|gNa |0:", celownikKierunkuSwiata((KierunekSwiata)i));
			if((gracz.polozenie->zamek)[i]>0) 
				playerMsg("\t|gdrzwi s¹ zamkniête.");
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
		return "pó³nocy";
	case SOUTH:
		return "po³udniu";
	case WEST:
		return "zachodzie";
	case EAST:
		return "wschodzie";
	case UP:
		return "górze";
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
				"U¿ycia:\n\n"
				"   scan - wyœwietla listê postaci znajduj¹cych siê w okolicy.\n\n"
				"SprawdŸ równie¿:\n"
				"   look, examine");
}