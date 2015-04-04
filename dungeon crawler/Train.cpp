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
		wcout << wersalikuj(L"Wystarczy tego treningu, idŸ przeæwicz swoje zdolnoœci w walce.") << endl;
		return;
	}
	if (argumenty.argument2.empty())
	{
		trener = (gracz.polozenie->postacie)->znajdzTrener();
		if (!trener)
		{
			wcout << "Tutaj nie ma nikogo z kim móg³byœ potrenowaæ." << endl;
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
			wcout << trener->imie << " nie oferuje ¿adnego treningu.";
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
		L"U¿ycia:\n\n"
		L"   train - wyœwietla dostêpne mo¿liwoœci treningu u trenera w danej lokacji.\n\n"
		L"   train <nazwa_cechy> - gracz podejmuje trening wskazanej cechy, w lokacji musi siê znajdowaæ trener który prowadzi trening danej cechy.\n\n"
		L"   train <nazwa_cechy> <nazwa_postaci> - to co wy¿ej tylko specyfikuje kto ma byæ trenerem.\n\n"
		L"W obu przypadkach za nazwê cechy nale¿y podaæ jedno z: si³a(s), zrêcznoœæ(z), zwinnoœæ(zw), wytrzyma³oœæ(w), ¿ywotnoœæ(¿).");
}

void Train::wypiszMozliwyTrening(Postac *trener)
{
	Gracz &gracz = gra->gracz;

	playerMsg(L"|^|0 oferuje trening nastêpuj¹cych cech:", trener->imie);

	if (trener->trener(SILA) > 0)
	{
		if (gracz.sil_baz <= trener->trener(SILA))
			playerMsg(L"|GSi³a");
		else
			playerMsg(L"|sSi³a");
	}
	if (trener->trener(ZRECZNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZRECZNOSC))
			playerMsg(L"|GZrêcznoœæ");
		else
			playerMsg(L"|sZrêcznoœæ");
	}
	if (trener->trener(ZWINNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZWINNOSC))
			playerMsg(L"|GZwinnoœæ");
		else
			playerMsg(L"|sZwinnoœæ");
	}
	if (trener->trener(WYTRZYMALOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(WYTRZYMALOSC))
			playerMsg(L"|GWytrzyma³oœæ");
		else
			playerMsg(L"|sWytrzyma³oœæ");
	}
	if (trener->trener(ZYWOTNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZYWOTNOSC))
			playerMsg(L"|G¯ywotnoœæ");
		else
			playerMsg(L"|s¯ywotnoœæ");
	}
}

Cecha Train::znajdzCeche(wstring cecha)
{
	wstring porownawczy;

	if (cecha[0] == 's')
	{
		porownawczy = L"si³a";
		if (porownawczy.find(cecha) != -1)
			return SILA;
		else
			return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == 'z')
	{
		porownawczy = L"zrêcznoœæ";
		if (porownawczy.find(cecha) != -1)
			return ZRECZNOSC;

		porownawczy = L"zwinnoœæ";
		if (porownawczy.find(cecha) != -1)
			return ZWINNOSC;

		return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == 'w')
	{
		porownawczy = L"wytrzyma³oœæ";
		if (porownawczy.find(cecha) != -1)
			return WYTRZYMALOSC;
		else
			return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == '¿')
	{
		porownawczy = L"¿ywotnoœæ";
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
			playerMsg(L"|YZwiêkszasz swoj¹ si³ê.");
			gracz.pktCech--;
			gracz.sil_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy³ ciê ju¿ wszystkiego co wie o sile.", trener->imie);
			return;
		}
		break;

	case ZRECZNOSC:
		if (gracz.zr_baz <= trener->trener(ZRECZNOSC))
		{
			playerMsg(L"|YZwiêkszasz swoj¹ zrêcznoœæ.");
			gracz.pktCech--;
			gracz.zr_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy³ ciê ju¿ wszystkiego co wie o ¿ywotnoœci.", trener->imie);
			return;
		}
		break;

	case ZWINNOSC:
		if (gracz.zw_baz <= trener->trener(ZWINNOSC))
		{
			playerMsg(L"|YZwiêkszasz swoj¹ zwinnoœæ.");
			gracz.pktCech--;
			gracz.zw_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy³ ciê ju¿ wszystkiego co wie o zwinnoœci.", trener->imie);
			return;
		}
		break;

	case WYTRZYMALOSC:
		if (gracz.wyt_baz <= trener->trener(WYTRZYMALOSC))
		{
			playerMsg(L"|YZwiêkszasz swoj¹ wytrzyma³oœæ.");
			gracz.pktCech--;
			gracz.wyt_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy³ ciê ju¿ wszystkiego co wie o wytrzyma³oœci.", trener->imie);
			return;
		}
		break;

	case ZYWOTNOSC:
		if (gracz.zyw_baz <= trener->trener(ZYWOTNOSC))
		{
			playerMsg(L"|YZwiêkszasz swoj¹ ¿ywotnoœæ.");
			gracz.pktCech--;
			gracz.zyw_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg(L"|^|0 nauczy³ ciê ju¿ wszystkiego co wie o ¿ywotnoœci.", trener->imie);
			return;
		}
		break;
	default:
		playerMsg(L"Co chcia³byœ trenowaæ?");
		break;
	}

}