#include "gra.h"
#include <array>

//Rasa **rasy = NULL;
array<Rasa*, ILOSC_RAS> rasy;

void Gra::wczytajRasy()
{
	rasy[RASA_BRAK] = new Rasa{ RASA_BRAK, L"brak", L"brak", L"bezkszta速ne zw這ki", 0, 0, 0, 0, 0 };
	rasy[RASA_CZLOWIEK] = new Rasa{ RASA_CZLOWIEK, L"cz這wiek", L"Tora", L"ludzkie zw這ki", 0.03f, 0.04f, 0.04f, 0, 0.04f };
	rasy[RASA_KRASNOLUD] = new Rasa{ RASA_KRASNOLUD, L"krasnolud", L"Gora", L"cia這 krasnoluda", 0.09f, -0.02f, -0.04f, 0.04f, 0.08f };
	rasy[RASA_ORK] = new Rasa{ RASA_ORK, L"ork", L"Hora", L"cielsko orka", 0.11f, -0.03f, -0.03f, 0.09f, 0.01f };
	rasy[RASA_NIZIOLEK] = new Rasa{ RASA_NIZIOLEK, L"nizio貫k", L"Nora", L"cia這 nizio趾a", -0.5f, 0.04f, 0.11f, 0.02f, 0.03f };
	rasy[RASA_ELF] = new Rasa{ RASA_ELF, L"elf", L"szcz靖ki elfa", L"Aora", -0.05f, 0.05f, 0.10f, 0.07f, -0.02f };
	rasy[RASA_POLELF] = new Rasa{ RASA_POLELF, L"p馧 elf", L"Taora", L"zw這ki p馧 elfa", -0.02f, 0.06f, 0.06f, 0.03f, 0.02f };
	rasy[RASA_MROCZNYELF] = new Rasa{ RASA_MROCZNYELF, L"Maora", L"mroczny elf", L"cia這 mrocznego elfa", -0.04f, 0.10f, 0.05f, -0.03f, 0.07f };
	rasy[RASA_LACERT] = new Rasa{ RASA_LACERT, L"lacert", L"Jora", L"cielsko lacerta", 0.07f, -0.05f, 0.07f, -0.05f, 0.11f };
	rasy[RASA_SIDAN] = new Rasa{ RASA_SIDAN, L"sidan", L"Kora", L"zw這ki sidana", -0.04f, 0.11f, 0.04f, 0.08f, -0.04f };
	rasy[RASA_GNOM] = new Rasa{ RASA_GNOM, L"gnom", L"Dora", L"szcz靖ki gnoma", 0.04f, -0.04f, 0.11f, 0.07f, -0.03f };

	rasy[RASA_SZCZUR] = new Rasa{ RASA_SZCZUR, L"szczur", L"", L"szczurze zw這ki", -0.10f, 0.02f, 0.10f, 0, -0.07f };
	rasy[RASA_GOBLIN] = new Rasa{ RASA_GOBLIN, L"goblin", L"", L"zw這ki goblina", -0.05f, 0.05f, -0.02f, 0.04f, -0.03f };
	rasy[RASA_OGAR] = new Rasa{ RASA_OGAR, L"ogar", L"", L"zw這ki ogara", 0.05f, 0.06f, 0.03f, 0.07f, 0 };
}