#include "gra.h"

Klasa **klasy = NULL;

void Gra::wczytajKlasy()
{
	klasy = new Klasa*[ILOSC_KLAS];
	klasy[RASA_BRAK] = new Klasa("bezklasowy", 0,0,0,0,0);

	klasy[KLASA_BARBARZYNCA] = new Klasa("barbarzyñca", 0.02f, 0, 0, 0, 0.02f);
	klasy[KLASA_LOWCA] = new Klasa("³owca", 0, 0.02f, 0, 0, 0.02f);
	klasy[KLASA_RYCERZ] = new Klasa("rycerz", 0.02f, 0, 0, 0.02f, 0);
	klasy[KLASA_NAJEMNIK] = new Klasa("najemnik", 0.02f, 0, 0.02f, 0, 0);
	klasy[KLASA_SZERMIERZ] = new Klasa("szermierz", 0, 0.02f, 0.02f, 0, 0);
	klasy[KLASA_GWARDZISTA] = new Klasa("gwardzista", 0, 0.02f, 0, 0.02f, 0);
	klasy[KLASA_BERSERKER] = new Klasa("berserker", 0.02f, 0.02f, 0, 0, 0);
	klasy[KLASA_PALADYN] = new Klasa("paladyn", 0, 0, 0.02f, 0, 0.02f);
	klasy[KLASA_STRAZNIK] = new Klasa("stra¿nik", 0, 0, 0.02f, 0.02f, 0);
	klasy[KLASA_MNICH] = new Klasa("mnich", 0, 0, 0, 0.02f, 0.02f);

	klasy[KLASA_ROBOTNIK] = new Klasa("robotnik", 0, 0, 0, 0.01f, 0);
	klasy[KLASA_ZBROJNY] = new Klasa("zbrojny", 0.01f, 0.01f, 0.01f, 0.01f, 0.01f);
}
