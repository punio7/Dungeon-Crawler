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
		L"Zabij wszystkie szczury w piwniczce na p�nocy.",
		L"Tajemnicza posta� wydaje si� wiedzie�, co si� dzieje. Chce jednak aby� najpierw pozby� si� szczur�w z piwniczki na p�nocy.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(2);
	temp->dodajFaze(2,
		L"Wr�� do nieznajomego po informacje.",
		L"")
		->ustawWymaganiePotwor(5)
		->ustawPrzejscia(3, 4);
	temp->dodajFaze(3,
		L"",
		L"Z rozmowy z nieznajomym nie dowiedzia�e� si� wiele.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
	temp->dodajFaze(4,
		L"",
		L"Wygarn��e� temu idiocie co o nim my�lisz.")
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
		L"Zbadaj gobliny zamieszkuj�ce podziemia",
		L"Nieznajomy powiedzia� ci, �e w�dz goblin�w ma klucz.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(2, 3, 4, 5);
	temp->dodajFaze(2,
		L"Zbadaj gobliny zamieszkuj�ce podziemia",
		L"W podziemiach spotka�e� gobliny.")
		->ustawWymaganieSpecjalny()
		->ustawPrzejscia(3, 4, 5);
	temp->dodajFaze(3,
		L"Zbadaj gobliny zamieszkuj�ce podziemia",
		L"Zabi�e� wszystkich zbieraczy.")
		->ustawWymaganiePotwor(5)
		->ustawPrzejscia(4, 5);
	temp->dodajFaze(4,
		L"",
		L"Wkurzy�e� gobliny, zapomnij o pokojowym rozwi�zaniu.")
		->ustawWymaganiePotwor(1)
		->ustawPrzejscia(-1)
		->ustawZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
	temp->dodajFaze(5,
		L"",
		L"W�dz goblin�w zechcia� z tob� rozmawia�, postanowi�e� go wys�ucha�.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(6, 4);
	temp->dodajFaze(6,
		L"Oswob�d� gobliny",
		L"W�dz goblin�w zleci� ci misj� zabicia maga")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(4, 7);
	temp->dodajFaze(7,
		L"",
		L"Uda�o ci si� oswobodzi� gobliny.")
		->ustawWymaganieRozmowa()
		->ustawPrzejscia(-1);
#pragma endregion
}