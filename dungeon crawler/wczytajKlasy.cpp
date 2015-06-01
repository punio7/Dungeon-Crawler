#include "Gra.h"

Klasa **klasy = NULL;

void Gra::wczytajKlasy()
{
	klasy = new Klasa*[ILOSC_KLAS];
	klasy[RASA_BRAK] = new Klasa(L"bezklasowy", 0,0,0,0,0);

	klasy[KLASA_BARBARZYNCA] = new Klasa(L"barbarzyñca", 0.02f, 0, 0, 0, 0.02f);
	klasy[KLASA_LOWCA] = new Klasa(L"³owca", 0, 0.02f, 0, 0, 0.02f);
	klasy[KLASA_RYCERZ] = new Klasa(L"rycerz", 0.02f, 0, 0, 0.02f, 0);
	klasy[KLASA_NAJEMNIK] = new Klasa(L"najemnik", 0.02f, 0, 0.02f, 0, 0);
	klasy[KLASA_SZERMIERZ] = new Klasa(L"szermierz", 0, 0.02f, 0.02f, 0, 0);
	klasy[KLASA_GWARDZISTA] = new Klasa(L"gwardzista", 0, 0.02f, 0, 0.02f, 0);
	klasy[KLASA_BERSERKER] = new Klasa(L"berserker", 0.02f, 0.02f, 0, 0, 0);
	klasy[KLASA_PALADYN] = new Klasa(L"paladyn", 0, 0, 0.02f, 0, 0.02f);
	klasy[KLASA_STRAZNIK] = new Klasa(L"stra¿nik", 0, 0, 0.02f, 0.02f, 0);
	klasy[KLASA_MNICH] = new Klasa(L"mnich", 0, 0, 0, 0.02f, 0.02f);

	klasy[KLASA_ROBOTNIK] = new Klasa(L"robotnik", 0, 0, 0, 0.01f, 0);
	klasy[KLASA_ZBROJNY] = new Klasa(L"zbrojny", 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);
}
