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
		cout<<wersalikuj("Wystarczy tego treningu, idŸ przeæwicz swoje zdolnoœci w walce.")<<endl;
		return;
	}
	if (argumenty.argument2.empty())
	{
		trener = (gracz.polozenie->postacie)->znajdzTrener();
		if (!trener)
		{
			cout<<"Tutaj nie ma nikogo z kim móg³byœ potrenowaæ."<<endl;
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
			cout<<trener->imie<<" nie oferuje ¿adnego treningu.";
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
				"U¿ycia:\n\n"
				"   train - wyœwietla dostêpne mo¿liwoœci treningu u trenera w danej lokacji.\n\n"
				"   train <nazwa_cechy> - gracz podejmuje trening wskazanej cechy, w lokacji musi siê znajdowaæ trener który prowadzi trening danej cechy.\n\n"
				"   train <nazwa_cechy> <nazwa_postaci> - to co wy¿ej tylko specyfikuje kto ma byæ trenerem.\n\n"
				"W obu przypadkach za nazwê cechy nale¿y podaæ jedno z: si³a(s), zrêcznoœæ(z), zwinnoœæ(zw), wytrzyma³oœæ(w), ¿ywotnoœæ(¿).");
}

void Train::wypiszMozliwyTrening(Postac *trener)
{
	Gracz &gracz = gra->gracz;

	playerMsg("|^|0 oferuje trening nastêpuj¹cych cech:", trener->imie);

	if (trener->trener(SILA) > 0)
	{
		if (gracz.sil_baz <= trener->trener(SILA))
			playerMsg("|GSi³a");
		else
			playerMsg("|sSi³a");
	}
	if (trener->trener(ZRECZNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZRECZNOSC))
			playerMsg("|GZrêcznoœæ");
		else
			playerMsg("|sZrêcznoœæ");
	}
	if (trener->trener(ZWINNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZWINNOSC))
			playerMsg("|GZwinnoœæ");
		else
			playerMsg("|sZwinnoœæ");
	}
	if (trener->trener(WYTRZYMALOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(WYTRZYMALOSC))
			playerMsg("|GWytrzyma³oœæ");
		else
			playerMsg("|sWytrzyma³oœæ");
	}
	if (trener->trener(ZYWOTNOSC) > 0)
	{
		if (gracz.sil_baz <= trener->trener(ZYWOTNOSC))
			playerMsg("|G¯ywotnoœæ");
		else
			playerMsg("|s¯ywotnoœæ");
	}
}

Cecha Train::znajdzCeche(string cecha)
{
	string porownawczy;
	
	if (cecha[0] == 's')
	{
		porownawczy="si³a";
		if (porownawczy.find(cecha) != -1)
			return SILA;
		else
			return CECHA_NIEPOPRAWNA;
	 }

	if (cecha[0] == 'z')
	{
		porownawczy="zrêcznoœæ";
		if (porownawczy.find(cecha) != -1)
			return ZRECZNOSC;

		porownawczy="zwinnoœæ";
		if (porownawczy.find(cecha) != -1)
			return ZWINNOSC;

		return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == 'w')
	{
		porownawczy="wytrzyma³oœæ";
		if (porownawczy.find(cecha) != -1)
			return WYTRZYMALOSC;
		else
			return CECHA_NIEPOPRAWNA;
	}

	if (cecha[0] == '¿')
	{
		porownawczy="¿ywotnoœæ";
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
			playerMsg("|YZwiêkszasz swoj¹ si³ê.");
			gracz.pktCech--;
			gracz.sil_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy³ ciê ju¿ wszystkiego co wie o sile.", trener->imie);
			return;
		}
		break;

	case ZRECZNOSC:
		if (gracz.zr_baz <= trener->trener(ZRECZNOSC) )
		{
			playerMsg("|YZwiêkszasz swoj¹ zrêcznoœæ.");
			gracz.pktCech--;
			gracz.zr_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy³ ciê ju¿ wszystkiego co wie o ¿ywotnoœci.", trener->imie);
			return;
		}
		break;

	case ZWINNOSC:
		if (gracz.zw_baz <= trener->trener(ZWINNOSC) )
		{
			playerMsg("|YZwiêkszasz swoj¹ zwinnoœæ.");
			gracz.pktCech--;
			gracz.zw_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy³ ciê ju¿ wszystkiego co wie o zwinnoœci.", trener->imie);
			return;
		}
		break;

	case WYTRZYMALOSC:
		if (gracz.wyt_baz <= trener->trener(WYTRZYMALOSC) )
		{
			playerMsg("|YZwiêkszasz swoj¹ wytrzyma³oœæ.");
			gracz.pktCech--;
			gracz.wyt_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy³ ciê ju¿ wszystkiego co wie o wytrzyma³oœci.", trener->imie);
			return;
		}
		break;

	case ZYWOTNOSC:
		if (gracz.zyw_baz <= trener->trener(ZYWOTNOSC) )
		{
			playerMsg("|YZwiêkszasz swoj¹ ¿ywotnoœæ.");
			gracz.pktCech--;
			gracz.zyw_baz++;
			gracz.przelicz();
			return;
		}
		else
		{
			playerMsg("|^|0 nauczy³ ciê ju¿ wszystkiego co wie o ¿ywotnoœci.", trener->imie);
			return;
		}
		break;
	default:
		playerMsg("Co chcia³byœ trenowaæ?");
		break;
	}

}