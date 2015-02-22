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
		"Zabij wszystkie szczury w piwniczce na pó³nocy.",
		"Tajemnicza postaæ wydaje siê wiedzieæ, co siê dzieje. Chce jednak abyœ najpierw pozby³ siê szczurów z piwniczki na pó³nocy.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(2);
	temp->dodajFaze(2,
		"Wróæ do nieznajomego po informacje.",
		"")
		->ustawWymaganiePotwor(5)
		->ustawPrzejscia(3,4);
	temp->dodajFaze(3,
		"",
		"Z rozmowy z nieznajomym nie dowiedzia³eœ siê wiele.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
	temp->dodajFaze(4,
		"",
		"Wygarn¹³eœ temu idiocie co o nim myœlisz.")
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
		"Zbadaj gobliny zamieszkuj¹ce podziemia",
		"Nieznajomy powiedzia³ ci, ¿e wódz goblinów ma klucz.")
		->ustawWymaganieSpecjalny()
		->ustawPrzejscia(3, 4, 5);
	temp->dodajFaze(2,
		"Zbadaj gobliny zamieszkuj¹ce podziemia",
		"W podziemiach spotka³eœ gobliny.")
		->ustawWymaganieSpecjalny()
		->ustawPrzejscia(3, 4, 5);
	temp->dodajFaze(3,
		"Zbadaj gobliny zamieszkuj¹ce podziemia",
		"Zabi³eœ wszystkich zbieraczy.")
		->ustawWymaganieSpecjalny()
		->ustawPrzejscia(4,5);
	temp->dodajFaze(4,
		"",
		"Wkurzy³eœ gobliny, zapomnij o pokojowym rozwi¹zaniu.")
		->ustawWymaganiePotwor(1)
		->ustawPrzejscia(-1);
	temp->dodajFaze(5,
		"",
		"Wódz goblinów zechia³ z tob¹ rozmawiaæ, postanowi³eœ go wys³uchaæ.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(6);
	temp->dodajFaze(6,
		"OswobódŸ gobliny",
		"Wódz goblinów zleci³ ci misjê zabicia maga")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
#pragma endregion
}