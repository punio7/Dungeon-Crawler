#include "Train.h"
#include "gra.h"
#include "Lokacja.h"

Train::Train(Gra *gra) :
Komenda(gra)
{
	nazwa = L"train";
}


Train::~Train(void)
{
}

void Train::execute(ParseDTO argumenty)
{
	Postac* trener;
	Gracz &gracz = gra->gracz;

	if (gracz.pktCech <= 0)
	{
		wcout << wersalikuj(L"Wystarczy tego treningu, id� prze�wicz swoje zdolno�ci w walce.") << endl;
		return;
	}
	if (argumenty.argument2.empty())
	{
		trener = (gracz.polozenie->postacie)->znajdzTrener();
		if (!trener)
		{
			wcout << "Tutaj nie ma nikogo z kim m�g�by� potrenowa�." << endl;
			return;
		}
	}
	else
	{
		trener = (gracz.polozenie->postacie)->znajdz(argumenty.argument2, argumenty.ktory2);
		if (!trener)
		{
			wcout << "Tutaj nie ma nikogo takiego." << endl;
			return;
		}
		if (!trener->jestTrenerem())
		{
			wcout << trener->imie << " nie oferuje �adnego treningu.";
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
	playerMsg(L"Synonimy:\n"
		L"   train(tr)\n\n"
		L"U�ycia:\n\n"
		L"   train - wy�wietla dost�pne mo�liwo�ci treningu u trenera w danej lokacji.\n\n"
		L"   train <nazwa_cechy> - gracz podejmuje trening wskazanej cechy, w lokacji musi si� znajdowa� trener kt�ry prowadzi trening danej cechy.\n\n"
		L"   train <nazwa_cechy> <nazwa_postaci> - to co wy�ej tylko specyfikuje kto ma by� trenerem.\n\n"
		L"W obu przypadkach za nazw� cechy nale�y poda� jedno z: si�a(s), zr�czno��(z), zwinno��(zw), wytrzyma�o��(w), �ywotno��(�).");
}

void Train::wypiszMozliwyTrening(Postac *trener)
{
	Gracz &gracz = gra->gracz;

	playerMsg(L"|^|0 oferuje trening nast�puj�cych cech:", trener->imie);

	if (trener->trener(SILA) > 0)
	{
		if (gracz.sil_baz <= trener->trener(SILA))
			playerMsg(L"|GSi�a");
		else
			playerMsg(L"|sSi�a");
	}
	if (trener->trener(ZRECZNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZRECZNOSC))
			playerMsg(L"|GZr�czno��");
		else
			playerMsg(L"|sZr�czno��");
	}
	if (trener->trener(ZWINNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZWINNOSC))
			playerMsg(L"|GZwinno��");
		else
			playerMsg(L"|sZwinno��");
	}
	if (trener->trener(WYTRZYMALOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(WYTRZYMALOSC))
			playerMsg(L"|GWytrzyma�o��");
		else
			playerMsg(L"|sWytrzyma�o��");
	}
	if (trener->trener(ZYWOTNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZYWOTNOSC))
			playerMsg(L"|G�ywotno��");
		else
			playerMsg(L"|s�ywotno��");
	}
}

Cecha Train::znajdzCeche(wstring cecha)
{
	wstring porownawczy;

	if (cecha[0] == 's')
	{
		porownawczy = L"si�a";
		if (porownawczy.find(cecha) != -1)
			return SILA;
		else
			return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == 'z')
	{
		porownawczy = L"zr�czno��";
		if (porownawczy.find(cecha) != -1)
			return ZRECZNOSC;

		porownawczy = L"zwinno��";
		if (porownawczy.find(cecha) != -1)
			return ZWINNOSC;

		return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == 'w')
	{
		porownawczy = L"wytrzyma�o��";
		if (porownawczy.find(cecha) != -1)
			return WYTRZYMALOSC;
		else
			return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == '�')
	{
		porownawczy = L"�ywotno��";
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
			playerMsg(L"|YZwi�kszasz swoj� si��.");
			gracz.pktCech--;
			gracz.sil_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy� ci� ju� wszystkiego co wie o sile.", trener->imie);
			return;
		}
		break;

	case ZRECZNOSC:
		if (gracz.zr_baz <= trener->trener(ZRECZNOSC))
		{
			playerMsg(L"|YZwi�kszasz swoj� zr�czno��.");
			gracz.pktCech--;
			gracz.zr_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy� ci� ju� wszystkiego co wie o �ywotno�ci.", trener->imie);
			return;
		}
		break;

	case ZWINNOSC:
		if (gracz.zw_baz <= trener->trener(ZWINNOSC))
		{
			playerMsg(L"|YZwi�kszasz swoj� zwinno��.");
			gracz.pktCech--;
			gracz.zw_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy� ci� ju� wszystkiego co wie o zwinno�ci.", trener->imie);
			return;
		}
		break;

	case WYTRZYMALOSC:
		if (gracz.wyt_baz <= trener->trener(WYTRZYMALOSC))
		{
			playerMsg(L"|YZwi�kszasz swoj� wytrzyma�o��.");
			gracz.pktCech--;
			gracz.wyt_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy� ci� ju� wszystkiego co wie o wytrzyma�o�ci.", trener->imie);
			return;
		}
		break;

	case ZYWOTNOSC:
		if (gracz.zyw_baz <= trener->trener(ZYWOTNOSC))
		{
			playerMsg(L"|YZwi�kszasz swoj� �ywotno��.");
			gracz.pktCech--;
			gracz.zyw_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy� ci� ju� wszystkiego co wie o �ywotno�ci.", trener->imie);
			return;
		}
		break;
	default:
		playerMsg(L"Co chcia�by� trenowa�?");
		break;
	}

}