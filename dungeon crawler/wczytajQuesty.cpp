#include "Gra.h"
#include "Quest.h"
#include "ListaQuestow.h"
#include "ListaZdarzenGlobalnych.h"

void Gra::wczytajQuesty()
{
	for (size_t i = 0; i < questy.max_size(); i++)
	{
		questy[i] = NULL;
	}

	Quest* temp = NULL;

	///////////////// 1 ///////////////
#pragma region 1 - Tajemniczy nieznajomy
	temp = questy[ListaQuestow::TajemniczyNieznajomy] = new Quest();
	temp->inicjujFazy(5);
	temp->nazwa = L"tajemniczy nieznajmy";

	temp->dodajFaze(0, L"", L"")
		->ustawPrzejscia(1);
	temp->dodajFaze(1,
		L"Zabij wszystkie szczury w piwniczce na pó³nocy.",
		L"Tajemnicza postaæ wydaje siê wiedzieæ, co siê dzieje. Chce jednak abyœ najpierw pozby³ siê szczurów z piwniczki na pó³nocy.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(2);
	temp->dodajFaze(2,
		L"Wróæ do nieznajomego po informacje.",
		L"")
		->ustawWymaganiePotwor(5)
		->ustawPrzejscia(3, 4);
	temp->dodajFaze(3,
		L"",
		L"Z rozmowy z nieznajomym nie dowiedzia³eœ siê wiele.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
	temp->dodajFaze(4,
		L"",
		L"Wygarn¹³eœ temu idiocie co o nim myœlisz.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
#pragma endregion


#pragma region 2 - Gobliny
	temp = questy[ListaQuestow::GoblinyWPodziemiach] = new Quest();
	temp->inicjujFazy(8);
	temp->nazwa = L"gobliny w podziemiach";

	temp->dodajFaze(0, L"", L"")
		->ustawPrzejscia(1, 2);
	temp->dodajFaze(1,
		L"Zbadaj gobliny zamieszkuj¹ce podziemia",
		L"Nieznajomy powiedzia³ ci, ¿e wódz goblinów ma klucz.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(2, 3, 4, 5);
	temp->dodajFaze(2,
		L"Zbadaj gobliny zamieszkuj¹ce podziemia",
		L"W podziemiach spotka³eœ gobliny.")
		->ustawWymaganieSpecjalny()
		->ustawPrzejscia(3, 4, 5);
	temp->dodajFaze(3,
		L"Zbadaj gobliny zamieszkuj¹ce podziemia",
		L"Zabi³eœ wszystkich zbieraczy.")
		->ustawWymaganiePotwor(5)
		->ustawPrzejscia(4, 5);
	temp->dodajFaze(4,
		L"",
		L"Wkurzy³eœ gobliny, zapomnij o pokojowym rozwi¹zaniu.")
		->ustawWymaganiePotwor(1)
		->ustawPrzejscia(-1)
		->ustawZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
	temp->dodajFaze(5,
		L"",
		L"Wódz goblinów zechcia³ z tob¹ rozmawiaæ, postanowi³eœ go wys³uchaæ.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(6, 4);
	temp->dodajFaze(6,
		L"OswobódŸ gobliny",
		L"Wódz goblinów zleci³ ci misjê zabicia maga")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(4, 7);
	temp->dodajFaze(7,
		L"",
		L"Uda³o ci siê oswobodziæ gobliny.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
#pragma endregion
}