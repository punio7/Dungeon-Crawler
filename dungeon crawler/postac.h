#pragma once
#include <string>
#include <list>
#include <array>
#include "ItemSlot.h"
#include "Rasa.h"
#include "Klasa.h"

class Item;
class ItemList;
class Staty;
class StatusList;
class Rozmowa;
class Kwestia;

using namespace std;

enum Cecha {
	SILA,
	ZRECZNOSC,
	ZWINNOSC,
	WYTRZYMALOSC,
	ZYWOTNOSC,
	CECHA_NIEPOPRAWNA
};

class Postac
{
public:
	Postac();
	~Postac();
	void przelicz();					//przelicza cala postac
	void wypisz_staty();
	void przelicz_eq();						//przelicza premie z eq
	void equip(Item* przedmiot);			//zak³ada postaci podany przedmiot UWAGA, NIE ZDEJMUJE PRZEDMIOTOW, UPEWNIC SIE ZE NIE MA NIC NA DANYM MIEJSCU ALBO BEDZIE WYCIEK PAMIECI						
	void dodajPrzedmiot(Item* przedmiot);	//dodaje podany przedmiot do inwentarza postaci
	void usunPrzedmiot(Item* przedmiot);	//usuwa dany przedmiot z listy inwentarza ale nie kasuje jego obiektu
	Item* znajdzPrzedmiot(int id);			//znajduje w inwentarzu postaci przedmiot o danym id, jezeli nie ma to NULL
	void dodajZloto(int ile);
	void usunZloto(int ile);
	void deequipALL();						//przenosi wszystkie przedmioty z eq do inv i przelicza
	void ustawStatyBazowe(int sil, int zr, int zw, int wyt, int zyw);
	void dodaj_staty(Staty staty);			//dodaje statystyki przedmiotu, automatycznie zmniejsza je ejzeli wymagania przemdiotu nie sa spelnione
	void odejmij_staty(Staty staty);		//nic nie robi
	Cecha najwyzszaCecha(int n);			//zwraca n-ta najwyzsza ceche calkowita 0-najwyzsza, 1- druga najwyzsza
	wstring cechaTowstring(Cecha cecha);		//zwraca wstring z danej cechy
	ItemSlot znajdzEQ(wstring cel, int ktory);	//znajduje item w eq postaci i zwraca jego slot
	virtual Rozmowa* wskRozmowa();
	virtual Kwestia* wskObecnaKwestia();
	void aktywujStatusyPasywne();			//dodaje premie pasywne statusow do statystyk postaci
	void aktywujStatusyWalka(Postac &wrog);	//wywolywane w kazdej turze walki, np. zwieksza lczniki tur statusow
	void usunNieatywneStatusy();			//usuwa statusy ktore sie skonczyly
	void usunStatusyBitewne();				//uzywane po walce usuwa statusy bitewne

	virtual bool chceRozmawiac();		//true jezeli z postacia mozna prowadzic dialog, false jezeli nie
	virtual bool jestRozmowny();		//rozmowna postac wymusza rozmowe przy pierwszym spotkaniu
	virtual bool jestTrenerem();		//true je¿eli mo¿e trenowaæ gracza
	virtual bool jestKupcem();			//true, je¿eli postaæ ma coœ na sprzedaz
	virtual bool jestGraczem();

	virtual wstring list();				//wypisuje wszystkie przedmioty na sprzedaz
	virtual void setSklep(Item *sklep);	//ustawia magazyn sklepowy
	virtual void sklepSprzedaj(Item *Item, int cena);	//usuwa item ze sklepu i dodaje zloto
	virtual void sklepKup(Item *Item, int cena);		//dodaje item do sklepu i odejmuje zloto
	virtual Item* sklepZnajdz(wstring cel, int ktory);	//znajduje w sklepie item

	virtual int trener(Cecha atrybut);
	virtual void ustawRozmowny(bool cel);	//dziala tylko dla klasy PostacNpc
	wstring poziomZdrowia(int tryb=0);				//zwraca poziom zdrowia postaci, tryb 0-kó³ka 1-opis
	wstring wypiszEQ();	//wypisuje na wcout zawartoœæ eq

	int id;
	wstring imie;
	wstring opis;
	wstring idle;
	bool agresywny;					//gdy true, postac atakuje gracza przy spotkaniu
	int quest, questFaza;			//zabicie tej postaci jest wymogiem podanego questu i podanej fazy
	int poziom;
	int dawaneDoswiadczenie;		//standardowo = poziom, moze sie zmieniac w wyniku zdarzen
	int currentHP, currentPanc;
	float otrzymywaneObrazenia;			//wyrazona w procentach, standardowo 1.00, zmieniane przez upadki, profity i mikstury
	bool maksymalneObrazenia;		//dopóki true, postaæ zawsze zadaje maksymalne obra¿enia
	int sil_baz, zr_baz, zw_baz, wyt_baz, zyw_baz;			//bazowa czyli 10 + to co rozda³ gracz
	int sil_bon, zr_bon, zw_bon, wyt_bon, zyw_bon;			//bonusy ze statusow i profitow
	int sil_calk, zr_calk, zw_calk, wyt_calk, zyw_calk;		//calkowita cecha z uwzg. bonosow rasowych i klasowych
	int at_cecha, obr_cecha, zdr_cecha, panc_cecha, zm_cecha, dmg;				//baza z cechy
	int at_poz, obr_poz, zdr_poz, zm_poz;										//premie za poziom
	int at_eq, obr_eq, zdr_eq, panc_eq, ochr_eq, zm_eq, dmg_eq;					//atrybutu z noszonego ekwipunku
	int at_bon, obr_bon, zdr_bon, panc_bon, ochr_bon, zm_bon, dmg_bon;			//bonusy z profitow i statusow
	int at_mod, obr_mod, zdr_mod, panc_mod, ochr_mod, zm_mod, dmg_mod;			//% wartosc o ile zostanie zwiekszony calkowity atrybut (cecha+poz+eq+bon)
	int at_calk, obr_calk, zdr_calk, panc_calk, ochr_calk, zm_calk, dmg_calk;	//calkowita suma uwzgledniajaca wszystko powyzsze
	Rasa *rasa;
	Klasa *klasa;

	array<Item*, SLOT_ILOSC> eq;
	ItemList *przedmioty;
	int zloto;
	StatusList *statusy;
};

enum CharListWypiszTryb
{
	CHARLIST_WYPISZ_LOOK,
	CHARLIST_WYPISZ_SCAN
};

class CharList : public list<Postac*>
{
public:
	CharList();
	~CharList();

	wstring wypisz(CharListWypiszTryb tryb=CHARLIST_WYPISZ_LOOK);

	void dodaj(Postac* postac);
	void usun(Postac* postac);
	Postac* znajdz(wstring szukany, int ktory=1);
	Postac* znajdz(int id, int ktory);
	Postac* znajdzAgresywny(int ktory=1);		//zwraca wskaŸnik na pierwsza agresywna postac na liscie
	Postac* znajdzRozmowny(int ktory=1);		//zwraca wskaŸnik na pierwsza rozmowna postac na liscie
	Postac* znajdzTrener(int ktory=1);			//zwraca wskaŸnik na pierwszego trenera na liscie
	Postac* znajdzKupiec(int ktory=1);			//zwraca wskaŸnik na pierwszego kupca na liœcie
	bool pusta();
};