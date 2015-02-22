#include "Train.h"
#include "gra.h"
#include "Lokacja.h"

Train::Train(Gra *gra):
	Komenda(gra)
{
	nazwa="train";
}


Train::~Train(void)
{
}

void Train::execute(ParseDTO argumenty)
{
	Postac* trener;
	Gracz &gracz = gra->gracz;

	if (gracz.pktCech <=0 )
	{
		cout<<wersalikuj("Wystarczy tego treningu, id� prze�wicz swoje zdolno�ci w walce.")<<endl;
		return;
	}
	if (argumenty.argument2.empty())
	{
		trener = (gracz.polozenie->postacie)->znajdzTrener();
		if (!trener)
		{
			cout<<"Tutaj nie ma nikogo z kim m�g�by� potrenowa�."<<endl;
			return;
		}
	}
	else 
	{
		trener = (gracz.polozenie->postacie)->znajdz(argumenty.argument2, argumenty.ktory2);
		if (!trener)
		{
			cout<<"Tutaj nie ma nikogo takiego."<<endl;
			return;
		}
		if (! trener->jestTrenerem() )
		{
			cout<<trener->imie<<" nie oferuje �adnego treningu.";
			return;
		}
	}

	if (argumenty.argument1.empty())
	{
		wypiszMozliwyTrening(trener);
		return;
	}

	Cecha cecha = znajdzCeche(argumenty.argument1);
	train(cecha, trener);
}

void Train::manual()
{
	playerMsg("Synonimy:\n"
				"   train(tr)\n\n"
				"U�ycia:\n\n"
				"   train - wy�wietla dost�pne mo�liwo�ci treningu u trenera w danej lokacji.\n\n"
				"   train <nazwa_cechy> - gracz podejmuje trening wskazanej cechy, w lokacji musi si� znajdowa� trener kt�ry prowadzi trening danej cechy.\n\n"
				"   train <nazwa_cechy> <nazwa_postaci> - to co wy�ej tylko specyfikuje kto ma by� trenerem.\n\n"
				"W obu przypadkach za nazw� cechy nale�y poda� jedno z: si�a(s), zr�czno��(z), zwinno��(zw), wytrzyma�o��(w), �ywotno��(�).");
}

void Train::wypiszMozliwyTrening(Postac *trener)
{
	Gracz &gracz = gra->gracz;

	playerMsg("|^|0 oferuje trening nast�puj�cych cech:", trener->imie);

	if (trener->trener(SILA) > 0)
	{
		if (gracz.sil_baz <= trener->trener(SILA))
			playerMsg("|GSi�a");
		else
			playerMsg("|sSi�a");
	}
	if (trener->trener(ZRECZNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZRECZNOSC))
			playerMsg("|GZr�czno��");
		else
			playerMsg("|sZr�czno��");
	}
	if (trener->trener(ZWINNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZWINNOSC))
			playerMsg("|GZwinno��");
		else
			playerMsg("|sZwinno��");
	}
	if (trener->trener(WYTRZYMALOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(WYTRZYMALOSC))
			playerMsg("|GWytrzyma�o��");
		else
			playerMsg("|sWytrzyma�o��");
	}
	if (trener->trener(ZYWOTNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZYWOTNOSC))
			playerMsg("|G�ywotno��");
		else
			playerMsg("|s�ywotno��");
	}
}

Cecha Train::znajdzCeche(string cecha)
{
	string porownawczy;
	
	if (cecha[0] == 's')
	{
		porownawczy="si�a";
		if (porownawczy.find(cecha) != -1)
			return SILA;
		else
			return CECHA_NIEPOPRAWNA;
	 }

	if (cecha[0] == 'z')
	{
		porownawczy="zr�czno��";
		if (porownawczy.find(cecha) != -1)
			return ZRECZNOSC;

		porownawczy="zwinno��";
		if (porownawczy.find(cecha) != -1)
			return ZWINNOSC;

		return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == 'w')
	{
		porownawczy="wytrzyma�o��";
		if (porownawczy.find(cecha) != -1)
			return WYTRZYMALOSC;
		else
			return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == '�')
	{
		porownawczy="�ywotno��";
		if (porownawczy.find(cecha) != -1)
			return ZYWOTNOSC;
		else
			return CECHA_NIEPOPRAWNA;
	}

	return CECHA_NIEPOPRAWNA;
}

void Train::train(Cecha cecha, Postac* trener)
{
	Gracz &gracz = gra->gracz;
	
	switch (cecha)
	{
	case SILA:
		if (gracz.sil_baz <= trener->trener(SILA))
		{
			playerMsg("|YZwi�kszasz swoj� si��.");
			gracz.pktCech--;
			gracz.sil_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy� ci� ju� wszystkiego co wie o sile.", trener->imie);
			return;
		}
		break;

	case ZRECZNOSC:
		if (gracz.zr_baz <= trener->trener(ZRECZNOSC) )
		{
			playerMsg("|YZwi�kszasz swoj� zr�czno��.");
			gracz.pktCech--;
			gracz.zr_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy� ci� ju� wszystkiego co wie o �ywotno�ci.", trener->imie);
			return;
		}
		break;

	case ZWINNOSC:
		if (gracz.zw_baz <= trener->trener(ZWINNOSC) )
		{
			playerMsg("|YZwi�kszasz swoj� zwinno��.");
			gracz.pktCech--;
			gracz.zw_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy� ci� ju� wszystkiego co wie o zwinno�ci.", trener->imie);
			return;
		}
		break;

	case WYTRZYMALOSC:
		if (gracz.wyt_baz <= trener->trener(WYTRZYMALOSC) )
		{
			playerMsg("|YZwi�kszasz swoj� wytrzyma�o��.");
			gracz.pktCech--;
			gracz.wyt_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy� ci� ju� wszystkiego co wie o wytrzyma�o�ci.", trener->imie);
			return;
		}
		break;

	case ZYWOTNOSC:
		if (gracz.zyw_baz <= trener->trener(ZYWOTNOSC) )
		{
			playerMsg("|YZwi�kszasz swoj� �ywotno��.");
			gracz.pktCech--;
			gracz.zyw_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy� ci� ju� wszystkiego co wie o �ywotno�ci.", trener->imie);
			return;
		}
		break;
	default:
		playerMsg("Co chcia�by� trenowa�?");
		break;
	}

}