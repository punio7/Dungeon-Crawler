#include "gra.h"
#include <array>

//Rasa **rasy = NULL;
array<Rasa*, ILOSC_RAS> rasy;

void Gra::wczytajRasy()
{
	rasy[RASA_BRAK] = new Rasa{RASA_BRAK, "brak", "brak", "bezkszta速ne zw這ki", 0, 0, 0, 0, 0 };
	rasy[RASA_CZLOWIEK] = new Rasa{RASA_CZLOWIEK, "cz這wiek", "Tora", "ludzkie zw這ki", 0.03f, 0.04f, 0.04f, 0, 0.04f};
	rasy[RASA_KRASNOLUD] = new Rasa{RASA_KRASNOLUD, "krasnolud", "Gora", "cia這 krasnoluda", 0.09f, -0.02f, -0.04f, 0.04f, 0.08f};
	rasy[RASA_ORK] = new Rasa{ RASA_ORK, "ork", "Hora", "cielsko orka", 0.11f, -0.03f, -0.03f, 0.09f, 0.01f };
	rasy[RASA_NIZIOLEK] = new Rasa{RASA_NIZIOLEK, "nizio貫k", "Nora", "cia這 nizio趾a", -0.5f, 0.04f, 0.11f, 0.02f, 0.03f};
	rasy[RASA_ELF] = new Rasa{RASA_ELF, "elf", "szcz靖ki elfa", "Aora", -0.05f, 0.05f, 0.10f, 0.07f, -0.02f};
	rasy[RASA_POLELF] = new Rasa{RASA_POLELF, "p馧 elf", "Taora", "zw這ki p馧 elfa", -0.02f, 0.06f, 0.06f, 0.03f, 0.02f};
	rasy[RASA_MROCZNYELF] = new Rasa{RASA_MROCZNYELF, "Maora", "mroczny elf", "cia這 mrocznego elfa", -0.04f, 0.10f, 0.05f, -0.03f, 0.07f};
	rasy[RASA_LACERT] = new Rasa{RASA_LACERT, "lacert", "Jora", "cielsko lacerta", 0.07f, -0.05f, 0.07f, -0.05f, 0.11f};
	rasy[RASA_SIDAN] = new Rasa{RASA_SIDAN, "sidan", "Kora", "zw這ki sidana", -0.04f, 0.11f, 0.04f, 0.08f, -0.04f};
	rasy[RASA_GNOM] = new Rasa{RASA_GNOM, "gnom", "Dora", "szcz靖ki gnoma", 0.04f, -0.04f, 0.11f, 0.07f, -0.03f};

	rasy[RASA_SZCZUR] = new Rasa{RASA_SZCZUR, "szczur", "", "szczurze zw這ki", -0.10f, 0.02f, 0.10f, 0, -0.07f};
	rasy[RASA_GOBLIN] = new Rasa{RASA_GOBLIN, "goblin", "", "zw這ki goblina", -0.05f, 0.05f, -0.02f, 0.04f, -0.03f};
	rasy[RASA_OGAR] = new Rasa{RASA_OGAR, "ogar", "", "zw這ki ogara", 0.05f, 0.06f, 0.03f, 0.07f, 0};
}