#include <sstream>
#include "Quest.h"
#include "playerMsg.h"
#include "zdarzeniaGlobalne.h"
#include "Color.h"
#include "wersalikuj.h"


QuestFaza::QuestFaza(void)
{
	id = 0;
	wymRozmowa = false;
	wymSpecjalny = false;
	wymPotwor = 0;
	a = -1; b = -1; c = -1; d = -1;
	zdarzenieGlobalne = 0;
}

QuestFaza* QuestFaza::ustawWymaganieRozmowa()
{
	wymRozmowa = true;
	return this;
}

QuestFaza* QuestFaza::ustawWymaganieSpecjalny()
{
	wymSpecjalny = true;
	return this;
}

QuestFaza* QuestFaza::ustawWymaganiePotwor(int ilosc)
{
	wymPotwor = ilosc;
	return this;
}

QuestFaza* QuestFaza::ustawPrzejscia(int a, int b, int c, int d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	return this;
}

QuestFaza* QuestFaza::ustawZdarzenieGlobalne(int numer)
{
	this->zdarzenieGlobalne = numer;
	return this;
}

void QuestFaza::spelnijWymaganieRozmowa()
{
	wymRozmowa = false;
}

void QuestFaza::spelnijWymaganieSpecjalny()
{
	wymSpecjalny = false;
}

void QuestFaza::spelnijWymaganiePotwor()
{
	wymPotwor--;
}

bool QuestFaza::czyJestPoczatkowa()
{
	return id == 0;
}

bool QuestFaza::czyJestKoncowa()
{
	return a == -1;
}


QuestFaza* Quest::znajdzFaze(int id)
{
	if (id < 0) return NULL;
	if (id > listaFaz.size()) return NULL;
	else return listaFaz[id];
}

bool QuestFaza::sprawdzWymagania()
{
	return (!wymSpecjalny && !wymRozmowa && (wymPotwor <= 0));
}



Quest::Quest(void)
{
	faza = NULL;
}

void Quest::inicjujFazy(int iloscFaz)
{
	this->listaFaz.resize(iloscFaz, NULL);
}

Quest::~Quest(void)
{
}


QuestFaza* Quest::dodajFaze(int id, wstring cel, wstring notatki)
{
	QuestFaza *temp = new QuestFaza;
	temp->id = id;
	temp->cel = cel;
	temp->notatki = notatki;

	if (id == 0)	//faze o id 0 standardowo ustawiamy jako aktualna
	{
		faza = temp;
	}
	listaFaz[id] = temp;
	return temp;
}

bool Quest::aktywny()
{
	if (!faza) return false;
	if (faza->id == 0) return false;
	if (nazwa.empty()) return false;
	if (faza->a == -1) return false;

	return true;
}

bool Quest::zakonczony()
{
	if (nazwa.empty()) return false;
	if (!faza) return true;
	if (faza->a == -1) return true;
	else return false;
}

int Quest::obecnaFaza()
{
	if (!faza) return -1;
	return faza->id;
}

wstring Quest::notatki()
{
	QuestFaza *aktualna = listaFaz[0];
	wstringstream temp;
	temp << aktualna->notatki;
	bool pierwszaNotatka = true; //pierwsza notatka nie ma /n na poczatku
	for (int i = 0; i < (int)przebieg.size(); i++)
	{
		switch (przebieg.at(i))
		{
		case 'a':
			aktualna = znajdzFaze(aktualna->a);
			break;
		case 'b':
			aktualna = znajdzFaze(aktualna->b);
			break;
		case 'c':
			aktualna = znajdzFaze(aktualna->c);
			break;
		case 'd':
			aktualna = znajdzFaze(aktualna->d);
			break;
		default:
			playerMsg(L"B��d czytania przebiegu questa.");
			return temp.str();
		}
		if (!aktualna)
		{
			playerMsg(L"Nie znaleziono fazy podczas wy�wietlania notatek.");
			return temp.str();
		}
		if (!(aktualna->notatki).empty())
		{
			if (pierwszaNotatka) pierwszaNotatka = false;
			else temp << endl << endl;
			temp << aktualna->notatki;
		}
	}

	return temp.str();
}

bool Quest::sprawdzWymagania()
{
	if (!faza) return false;		//jezeli quest sie skonczyl
	char opcja = '0';				//a, b, c, d - mozliwe sciezki rozwoju questa
	if (faza->a != -1 && znajdzFaze(faza->a)->sprawdzWymagania()) opcja = 'a';
	else if (faza->b != -1 && znajdzFaze(faza->b)->sprawdzWymagania()) opcja = 'b';
	else if (faza->c != -1 && znajdzFaze(faza->c)->sprawdzWymagania()) opcja = 'c';
	else if (faza->d != -1 && znajdzFaze(faza->d)->sprawdzWymagania()) opcja = 'd';

	if (opcja != '0')
	{
		przebieg += opcja;			//dodajemy do przebiegu questa obecna sciezke
		QuestFaza* temp = NULL;
		switch (opcja)
		{
		case 'a':
			temp = znajdzFaze(faza->a);
			break;
		case 'b':
			temp = znajdzFaze(faza->b);
			break;
		case 'c':
			temp = znajdzFaze(faza->c);
			break;
		case 'd':
			temp = znajdzFaze(faza->d);
			break;
		}
		if (!nazwa.empty())	//jezeli zadanie nie jest ukryte to wysietlimy powiadomienie dla gracza
		{
			if (faza->czyJestPoczatkowa())
			{
				playerMsg(L"|YNowe zadanie: |0", nazwa);
			}
			else if (temp->czyJestKoncowa())
			{
				playerMsg(L"|YZadanie zako�czone: |0", nazwa);
			}
			else
			{
				playerMsg(L"|YUaktualniono dziennik: |0", nazwa);
			}
		}
		faza = temp;
		if (faza != NULL)
		{
			wywolajZdarzenieGlobalne(faza->zdarzenieGlobalne);
		}
		sprawdzWymagania();
		return true;
	}
	else if (faza->czyJestKoncowa())		//jezeli opcja a==-1 oznacza to faze koncowa questa
	{
		return true;
	}

	return false;
}

void Quest::spelnijRozmowa(int faza)
{
	QuestFaza *aktualny = znajdzFaze(faza);
	if (!aktualny) return;

	aktualny->spelnijWymaganieRozmowa();
	sprawdzWymagania();
}

void Quest::spelnijSpecjalny(int faza)
{
	QuestFaza *aktualny = znajdzFaze(faza);
	if (!aktualny) return;

	aktualny->spelnijWymaganieSpecjalny();
	sprawdzWymagania();
}

void Quest::spelnijPotwor(int faza)
{
	QuestFaza *aktualny = znajdzFaze(faza);
	if (!aktualny) return;

	aktualny->spelnijWymaganiePotwor();
	sprawdzWymagania();
}
