#pragma once
#include <string>
#include <vector>

class Gra;

using namespace std;

class QuestFaza
{
public:
	QuestFaza(void);
	bool sprawdzWymagania();
	QuestFaza* ustawWymaganieRozmowa();
	QuestFaza* ustawWymaganieSpecjalny();
	QuestFaza* ustawWymaganiePotwor(int ilosc);
	QuestFaza* ustawPrzejscia(int a, int b = -1, int c = -1, int d = -1);
	QuestFaza* ustawZdarzenieGlobalne(int numer);
	void spelnijWymaganieRozmowa();
	void spelnijWymaganieSpecjalny();
	void spelnijWymaganiePotwor();
	//zwraca true jezeli faza jest faza startowa questa
	bool czyJestPoczatkowa();
	//zwraca true jezeli faza jest faza koncowa questa
	bool czyJestKoncowa();


	int id;				//id==0 -faza poczatkowa, quest nie zosta³ jeszcze zaczety
	wstring cel;			//cel questa jaki widzi gracz w dzienniku
						//cel ma dotyczyc wymagan nastepnej fazy, niezaleznie od tego jakie sa jej rozgalezienia
	wstring notatki;		//notatki, które zostan¹ dodane do dziennika po przejœciu do tej fazy
	int zdarzenieGlobalne;	//numer zdarzenia globalnego uruchomianego, po przejsciu do tej fazy

						//wymogi jakie musza byc spelnione aby przejsc do tej fazy
	bool wymRozmowa;	//wymog spelniony gdy true, spelniany przez rozmowy
	bool wymSpecjalny;	//wymog spelniony gdy true, spelniany przez zdarzenia globalne
	int wymPotwor;		//wymog spelniony gdy rowny 0, spelniany przez zabijanie mobow
	int a, b, c, d;		//numer nastepnej fazy z kazdej opcji, faza=-1 -koniec questa
						//priorytety faz a>b>c>d tzn. jezeli dwie opcje zostana spelnione to i tak uruchomi sie tylko opcja o najwyzszym priorytecie
						//opcje nalezy zapelniac od gory, bo jezeli a==-1 to quest jest uznawany za skonczony
};

class Quest
{
public:
	Quest(void);
	~Quest(void);
	void inicjujFazy(int iloscFaz);		//tworzy liste faz
	QuestFaza *dodajFaze(int id, wstring cel, wstring notatki);
	QuestFaza* znajdzFaze(int id);		//zwraca wsk na waze o danym id

	wstring nazwa;		//nazwa questa, jezeli brak to quest jest ukryty (nie widac go w dzienniku)
	wstring przebieg;	//ciag typu "abcdaaabc" jest to zapis sciezek jakie zostaly wybrane
	QuestFaza *faza;	//obecna faza questa, NULL- quest ukonczony
	vector<QuestFaza*> listaFaz;	//lista wszystkich faz numerycznie

	bool aktywny();				//czy quest ma sie znalezc w dzienniku?
	bool zakonczony();			//czy quest ma widniec jako zakonczony?
	int obecnaFaza();			//zwraca id obecnej fazy, 0-quest nie zaczety, -1= quest skonczony
	wstring notatki();
	bool sprawdzWymagania();		//sprawdza wymagania przejscia do nast fazy i zmienia ja jezeli spelnione i zwraca true
	void spelnijRozmowa(int faza);		//spelnia wymaganie danej fazy oraz sprawdzWymagania()
	void spelnijSpecjalny(int faza);
	void spelnijPotwor(int faza);		//zmniejsza counter potworów danej fazy i sprawdzWymagania()
};

