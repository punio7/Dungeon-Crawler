#pragma once
#include <string>

using namespace std;

enum RasaNazwa
{
	RASA_BRAK = 0,

	RASA_CZLOWIEK = 1,
	RASA_KRASNOLUD = 2,
	RASA_ORK = 4,
	RASA_NIZIOLEK = 8,
	RASA_ELF = 16,
	RASA_POLELF = 32,
	RASA_MROCZNYELF = 64,
	RASA_LACERT = 128,
	RASA_SIDAN = 256,
	RASA_GNOM = 512,

	RASA_SZCZUR,
	RASA_GOBLIN,
	RASA_OGAR,
	ILOSC_RAS
};

class Rasa
{
public:
	RasaNazwa rasaEnum;
	string nazwa;
	string nazwaGoblinska;
	string nazwaZwlok;
	float si, zr, zw, wyt, zyw;
};

Rasa *getRasa(RasaNazwa nazwa);