#pragma once
#include <string>
#include <math.h>

using namespace std;

enum KlasaNazwa{
	KLASA_BRAK,
	KLASA_BARBARZYNCA,
	KLASA_LOWCA,
	KLASA_RYCERZ,
	KLASA_NAJEMNIK,
	KLASA_SZERMIERZ,
	KLASA_GWARDZISTA,
	KLASA_BERSERKER,
	KLASA_PALADYN,
	KLASA_STRAZNIK,
	KLASA_MNICH,

	KLASA_ROBOTNIK,
	KLASA_ZBROJNY,
	ILOSC_KLAS
};

class Klasa
{
public:
	Klasa(string nazwa, float si, float zr, float zw, float wyt, float zyw);
	~Klasa(void);
	float getSi(int lvl);
	float getZr(int lvl);
	float getZw(int lvl);
	float getWyt(int lvl);
	float getZyw(int lvl);

	string nazwa;
	float si, zr, zw, wyt, zyw;
};

Klasa *getKlasa(KlasaNazwa nazwa);