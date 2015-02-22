#include "Take.h"
#include "gra.h"
#include "item.h"
#include "Lokacja.h"

Take::Take(Gra *gra):
	Komenda(gra)
{
	nazwa="take";
}


Take::~Take(void)
{
}

void Take::execute(ParseDTO argumenty)
{
	Gracz &gracz = gra->gracz;

	if (argumenty.argument1.empty()) 
		playerMsg("Wzi¹æ co?");
	else 
	{
		if (argumenty.argument2.empty()) 
		{
			if (argumenty.argument1=="all")
			{
				TakeAllOtoczenie();
			}
			else
			{
				TakePrzedmiotOtoczenie(argumenty.argument1, argumenty.ktory1);
			}
		}
		else
		{
			if (argumenty.argument1=="all")
			{
				TakeAllPojemnik(argumenty.argument2, argumenty.ktory2);
			}
			else
			{
				TakePrzedmiotPojemnik(argumenty.argument1, argumenty.ktory1, argumenty.argument2, argumenty.ktory2);
			}
		}
	}
}

void Take::manual()
{
	playerMsg("Synonimy:\n"
				"   take(t), get(g)\n\n"
				"U¿ycia:\n\n"
				"   take <nazwa_przedmiotu> - gracz bierze wskazany przedmiot z lokacji i umieszca go w inwentarzu.\n\n"
				"   take <nazwa_przedmiotu> <nazwa_pojemnika> - gracz wyjmuje wskazany przedmiot z wskazanego pojemnika i umeiszcza go w inwentarzu.\n\n"
				"W obu przypadkach u¿yj 'all' zamiast nazwy_przedmiotu aby zastosowaæ do wszystkich przedmiotów w lokacji/pojemniku.\n\n"
				"SprawdŸ równie¿:\n"
				"   inventory, drop, put");
}

void Take::TakePrzedmiotOtoczenie(string cel, int ktory)
{
	ItemList *lista = gra->gracz.polozenie->przedmioty;
	Item *przedmiot = lista->znajdz(cel, ktory);
	if (przedmiot == NULL)
	{
		playerMsg("Tutaj nie ma czegoœ takiego jak |0.", cel);
		return;
	}

	if (!przedmiot->daSieWziac())
	{
		playerMsg("Nie mo¿esz tego podnieœæ.");
		return;
	}

	TakePrzedmiot(przedmiot, lista);
	playerMsg("Podnosisz |0.",przedmiot->nazwa);

}

void Take::TakePrzedmiotPojemnik(string cel1, int ktory1, string cel2, int ktory2)
{
	Item *pojemnik = gra->gracz.polozenie->przedmioty->znajdz(cel2, ktory2);
	if (pojemnik == NULL)
		pojemnik = gra->gracz.przedmioty->znajdz(cel2, ktory2);

	if (pojemnik == NULL)
	{
		playerMsg("Tutaj nie ma czegoœ takiego jak |0.", cel2);
		return;
	}

	if (!pojemnik->jestPojemnikiem())
	{
		playerMsg("|^|0 nie jest pojemnikiem.", pojemnik->nazwa);
		return;
	}

	if (pojemnik->numerZamka())
	{
		playerMsg("Pojemnik jest zamkniêty.");
		return;
	}

	ItemList *lista = pojemnik->getItemList();

	Item *przedmiot = lista->znajdz(cel1, ktory1);
	if (przedmiot == NULL)
	{
		playerMsg("|^|0 nie zawiera w sobie czegoœ takiego jak |1.", pojemnik->nazwa, cel1);
		return;
	}

	if (!przedmiot->daSieWziac())
	{
		playerMsg("Nie mo¿esz tego podnieœæ.");
		return;
	}

	TakePrzedmiot(przedmiot, lista);
	playerMsg("Wyjmujesz |0 z |1.", przedmiot->nazwa, pojemnik->nazwa);
	
}

void Take::TakePrzedmiot(Item *przedmiot, ItemList *lista)
{
	lista->usun(przedmiot);
	gra->gracz.przedmioty->dodaj(przedmiot);
}

void Take::TakeAllPojemnik(string cel, int ktory)
{
	Item *pojemnik = gra->gracz.polozenie->przedmioty->znajdz(cel, ktory);
	if (pojemnik == NULL)
		pojemnik = gra->gracz.przedmioty->znajdz(cel, ktory);

	if (pojemnik == NULL)
	{
		playerMsg("Tutaj nie ma czegoœ takiego jak |0.");
		return;
	}

		if (!pojemnik->jestPojemnikiem())
	{
		playerMsg("Hahaha, bardzo zabawne.");
		return;
	}

	if (pojemnik->numerZamka())
	{
		playerMsg("Pojemnik jest zamkniêty.");
		return;
	}

	ItemList *lista = pojemnik->getItemList();
	Gracz &gracz = gra->gracz;
	if (lista->pusta())
	{
		playerMsg("|^|0 nie zawiera w sobie niczego godnego uwagi.", pojemnik->nazwa);
		return;
	}
	int i=1;
	for (Item* aktualny = lista->znajdz(i); aktualny != NULL; aktualny=lista->znajdz(i))
	{
		if (aktualny->daSieWziac())
		{
			playerMsg("Wyjmujesz |0 z |1.", aktualny->nazwa, pojemnik->nazwa);
			TakePrzedmiot(aktualny, lista);
		}
		else
		{
			playerMsg("Nie mo¿esz tego wyj¹æ.");	//jezeli przedmiotu nie da sie podniesc
			i++;									//to opuszczamy go i patrzymy na nastepny
		}
	}
	zabierzZloto(pojemnik);
}

void Take::TakeAllOtoczenie()
{
	Gracz &gracz = gra->gracz;
	ItemList *lista = gracz.polozenie->przedmioty;
	if (lista->pusta())
	{
		playerMsg("Nic tu nie ma.");
		return;
	}
	int i=1;
	for (Item* aktualny = lista->znajdz(i); aktualny != NULL; aktualny = lista->znajdz(i))
	{
		if (aktualny->daSieWziac())
		{
			playerMsg("Podnosisz |0.", aktualny->nazwa);
			TakePrzedmiot(aktualny, lista);
		}
		else
		{
			playerMsg("Nie mo¿esz tego podnieœæ.");	//jezeli przedmiotu nie da sie podniesc
			i++;									//to opuszczamy go i patrzymy na nastepny
		}
	}
}

void Take::zabierzZloto(Item* cel)
{
	if (cel->zloto())	//je¿eli przedmiot zawiera z³oto
	{
		playerMsg("Przeszukuj¹c |0 znalaz³eœ |Y|1 szt. z³ota|W.", cel->nazwa, intToStr(cel->zloto()));
		gra->gracz.dodajZloto(cel->zloto());			//dodajemy zloto graczowi
		cel->usunZloto(cel->zloto());	//i usuwamy je z pojemnika
	}
}