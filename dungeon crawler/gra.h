#pragma once
#include <array>
#include <vector>
#include <string>
#include "Gracz.h"
#include "licznikKomend.h"
#include "timer.h"

class Item;
class PostacNpc;
class Quest;
class Lokacja;
class MidiPlayer;
enum RasaNazwa;
enum KlasaNazwa;
enum ItemTyp;

;using namespace std;
extern ListaKomend *listaKomend;

enum Estan_gry
{
	STAN_GRA,
	STAN_QUIT
};

const int LICZBA_QUESTOW = 3;

class Gra
{
public:
	Gra(int argc, const char* argv[]);
	void wczytajRasy();
	void wczytajKlasy();
	void wczytaj_lokacje();
	void wczytajQuesty();
	void zakonczGre();
	//void wykonaj_komende(Ekomenda command, ParseDTO argumenty);
	void prompt();				//wypisuje na wcout prompt
	//tworzy Item o podanym id
	Item* createItem(int id);
	//Tworzy item o podanych cechach
	Item* createItem(int id, ItemTyp typ, wstring nazwa, wstring opis, wstring idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc);
	//Tworzy item o podanych cechac i wymaganiach
	Item* createItem(int id, ItemTyp typ, wstring nazwa, wstring opis, wstring idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc, int wymSila, int wymZr, int wymZw, int wymWyt, int wymZyw);
	//Tworzy jeden losowo wybrany przedmiot z podanej listy ID
	Item* createItem(vector<int> listaMozliwych);
	ItemList createItemMany(int id, int ile);

	Postac* createChar(int id);
	Postac* createChar(int id, int quest, int questFaza);
	Postac* createChar(int id, int poziom, RasaNazwa rasa, KlasaNazwa klasa, wstring imie, wstring opis, wstring idle, int sila, int zr, int zw, int wyt, int zyw);
	PostacNpc* createNpc(int id, int poziom, RasaNazwa rasa, KlasaNazwa klasa, wstring imie, wstring opis, wstring idle, int sila, int zr, int zw, int wyt, int zyw);
	void wczytajRozmowe(int id, PostacNpc* postac);

	Quest *znajdzQuest(wstring nazwa, int ktory);	//przeszukuje tylko aktywne i zakonczone questy

	bool gra_zakoncz();

	//zwraca true jezeli ma byc przerwane wykonwyanie innych zdarzen
	bool zdarzenieGlobalne(int id);
	//zdarzenia ktore zachodza w czasie pseudo-rzeczywistym np. regen
	void zdarzeniaCiagle();
	//zdarzenia zachodzace kiedy gracz wchodzi do rooma, zachodza po LOOK
	void zdarzeniaPrzySpotkaniu();	
	//zdarzenia globalne zachodzace przed LOOK, zwraca true jezeli ma byc przerwane wykonywanie innych zdarzen
	bool zdarzeniaGlobalnePrzySpotkaniu();
	//zmienia polozenia, wykonuje wszystkie elementy normalnej zmiany lokacji 
	void teleportacjaGracza(int idLokacji);

	Lokacja* getLokacja(int id);

	Gracz gracz;
	array<Quest*, LICZBA_QUESTOW> questy;

	Lokacja* listaLokacji;
	Estan_gry stan;
	string path;		//sciezka uruchomienia gry

	timer stoper;
	MidiPlayer *midiPlayer;
	licznikKomend licznikWywolanKomend;
	
};