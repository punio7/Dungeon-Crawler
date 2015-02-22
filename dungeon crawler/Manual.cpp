#include "Manual.h"
#include <math.h>
#include "gra.h"
#include "ListaKomend.h"
#include "EnumKomendy.h"

extern ListaKomend* listaKomend;

Manual::Manual(Gra *gra):
	Komenda(gra)
{
	nazwa="manual";
}


Manual::~Manual(void)
{
}

void Manual::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())
	{
		wyswietlListeKomend();
	}
	else
	{
		Ekomenda komenda = argumenty.komenda1;
		if (listaKomend->komendy[komenda] == NULL)
		{
			//TODO: tematy do manuala niezwiazane z komendami
			Komenda::manual();	//wyswietlenie wiadomosci o braku pomocy na ten temat
		}
		else
		{
			listaKomend->komendy[komenda]->manual();
		}
	}
}

void Manual::manual()
{
	playerMsg(	"Synonimy:\n"
				"   manual(m), help(he), commands(com)\n\n"
				"U¿ycia:\n\n"
				"   manual - wyœwietla listê wszystkich komend\n\n"
				"   manual <komenda> - wyœwietla pomoc dla danej komendy");
}

void Manual::wyswietlListeKomend()
{
	playerMsg("Lista dostêpnych komend. U¿yj manual <komenda> aby przeczytaæ szczegó³ow¹ pomoc.\n");
	
	Komenda **komendy = listaKomend->komendy;
	
	int startowaKomenda = COMM_NOCOMM + 1;

	int wypisaneKomendy = 0;
	for (int i = startowaKomenda; i < LICZBA_KOMEND; i++)
	{
		if (komendy[i] == NULL || komendy[i]->nazwa == "")
		{
			continue;
		}
		else
		{
			if (komendy[i]->nazwa.length() < 8)
			{
				playerMsg("|0\t\t|_", komendy[i]->nazwa);
			}
			else
			{
				playerMsg("|0\t|_", komendy[i]->nazwa);
			}
			wypisaneKomendy++;
			if (wypisaneKomendy % 5 == 0)
			{
				//playerMsg("");
			}
		}
	}


}