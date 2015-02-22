#pragma once
#include <array>
#include <string>
#include "gracz.h"
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

const int LICZBA_QUESTOW = 50;

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
	void prompt();				//wypisuje na cout prompt
	Item* create_item(int id);	//tworzy Item o podanym id
	Item* create_item(int id, ItemTyp typ, string nazwa, string opis, string idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc);
	Item* create_item(int id, ItemTyp typ, string nazwa, string opis, string idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc, int wymSila, int wymZr, int wymZw, int wymWyt, int wymZyw);
	//tworzy item o podanej w argumentach specyfikacji, u¿ywany w funkcji wy¿ej

	Postac* createChar(int id);
	Postac* createChar(int id, int quest, int questFaza);
	Postac* createChar(int id, int poziom, RasaNazwa rasa, KlasaNazwa klasa, string imie, string opis, string idle, int sila, int zr, int zw, int wyt, int zyw);
	PostacNpc* createNpc(int id, int poziom, RasaNazwa rasa, KlasaNazwa klasa, string imie, string opis, string idle, int sila, int zr, int zw, int wyt, int zyw);
	void wczytajRozmowe(int id, PostacNpc* postac);

	Quest *znajdzQuest(string nazwa, int ktory);	//przeszukuje tylko aktywne i zakonczone questy

	bool gra_zakoncz();

	//zwraca true jezeli ma byc przerwane wykonwyanie innych zdarzen
	bool zdarzenieGlobalne(int id);
	//zdarzenia ktore zachodza w czasie pseudo-rzeczywistym np. regen
	void zdarzeniaCiagle();
	//zdarzenia zachodzace kiedy gracz wchodzi do rooma, zachodza po LOOK
	void zdarzeniaPrzySpotkaniu();	
	//zdarzenia globalne zachodzace przed LOOK, zwraca true jezeli ma byc przerwane wykonywanie innych zdarzen
	bool zdarzeniaGlobalnePrzySpotkaniu();

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