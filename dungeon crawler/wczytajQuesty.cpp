#include "gra.h"
#include "Quest.h"
#include "ListaQuestow.h"

void Gra::wczytajQuesty()
{
	for (int i = 0; i < questy.max_size(); i++)
	{
		questy[i] = NULL;
	}
	
	Quest* temp = NULL;

	///////////////// 1 ///////////////
#pragma region 1 - Tajemniczy nieznajomy
	temp = questy[ListaQuestow::TajemniczyNieznajomy] = new Quest();
	temp->inicjujFazy(5);
	temp->nazwa = "tajemniczy nieznajmy";

	temp->dodajFaze(0,"","")
		->ustawPrzejscia(1);
	temp->dodajFaze(1,
		"Zabij wszystkie szczury w piwniczce na p�nocy.",
		"Tajemnicza posta� wydaje si� wiedzie�, co si� dzieje. Chce jednak aby� najpierw pozby� si� szczur�w z piwniczki na p�nocy.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(2);
	temp->dodajFaze(2,
		"Wr�� do nieznajomego po informacje.",
		"")
		->ustawWymaganiePotwor(5)
		->ustawPrzejscia(3,4);
	temp->dodajFaze(3,
		"",
		"Z rozmowy z nieznajomym nie dowiedzia�e� si� wiele.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
	temp->dodajFaze(4,
		"",
		"Wygarn��e� temu idiocie co o nim my�lisz.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
#pragma endregion


#pragma region 2 - Gobliny
	temp = questy[ListaQuestow::GoblinyWPodziemiach] = new Quest();
	temp->inicjujFazy(7);
	temp->nazwa = "gobliny w podziemiach";

	temp->dodajFaze(0,"","")
		->ustawPrzejscia(1);
	temp->dodajFaze(1,
		"Zbadaj gobliny zamieszkuj�ce podziemia",
		"Nieznajomy powiedzia� ci, �e w�dz goblin�w ma klucz.")
		->ustawWymaganieSpecjalny()
		->ustawPrzejscia(3, 4, 5);
	temp->dodajFaze(2,
		"Zbadaj gobliny zamieszkuj�ce podziemia",
		"W podziemiach spotka�e� gobliny.")
		->ustawWymaganieSpecjalny()
		->ustawPrzejscia(3, 4, 5);
	temp->dodajFaze(3,
		"Zbadaj gobliny zamieszkuj�ce podziemia",
		"Zabi�e� wszystkich zbieraczy.")
		->ustawWymaganieSpecjalny()
		->ustawPrzejscia(4,5);
	temp->dodajFaze(4,
		"",
		"Wkurzy�e� gobliny, zapomnij o pokojowym rozwi�zaniu.")
		->ustawWymaganiePotwor(1)
		->ustawPrzejscia(-1);
	temp->dodajFaze(5,
		"",
		"W�dz goblin�w zechia� z tob� rozmawia�, postanowi�e� go wys�ucha�.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(6);
	temp->dodajFaze(6,
		"Oswob�d� gobliny",
		"W�dz goblin�w zleci� ci misj� zabicia maga")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
#pragma endregion
}