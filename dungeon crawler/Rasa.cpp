#include "Rasa.h"
#include <array>

extern array<Rasa*, ILOSC_RAS> rasy;

Rasa *getRasa(RasaNazwa nazwa)
{
	if (nazwa < 0) return rasy[RASA_BRAK];
	if (nazwa >= ILOSC_RAS) return rasy[RASA_BRAK];
	return rasy[nazwa];
}