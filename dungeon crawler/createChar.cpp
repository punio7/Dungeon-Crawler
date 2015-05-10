#include "gra.h"
#include "item.h"
#include "errors.h"
#include "ListaItemow.h"
#include "ListaPostaci.h"
#include "PostacNpc.h"
#include "Rozmowa.h"
#include "Kwestia.h"
#include "randomGenerator.h"

using namespace ListaPostaci;

Postac* Gra::createChar(int id, int poziom, RasaNazwa rasa, KlasaNazwa klasa, wstring imie, wstring opis, wstring idle, int sila, int zr, int zw, int wyt, int zyw)
{
	Postac *aktualny = new Postac;

	aktualny->id = id;
	aktualny->poziom = poziom;
	aktualny->dawaneDoswiadczenie = poziom;
	aktualny->rasa = getRasa(rasa);
	aktualny->klasa = getKlasa(klasa);
	aktualny->imie = imie;
	aktualny->opis = opis;
	aktualny->idle = idle;
	aktualny->ustawStatyBazowe(sila, zr, zw, wyt, zyw);
	aktualny->przelicz();
	aktualny->currentHP = aktualny->zdr_calk;

	return aktualny;
}

PostacNpc* Gra::createNpc(int id, int poziom, RasaNazwa rasa, KlasaNazwa klasa, wstring imie, wstring opis, wstring idle, int sila, int zr, int zw, int wyt, int zyw)
{
	PostacNpc *aktualny = new PostacNpc;

	aktualny->id = id;
	aktualny->poziom = poziom;
	aktualny->poziom = poziom;
	aktualny->rasa = getRasa(rasa);
	aktualny->klasa = getKlasa(klasa);
	aktualny->imie = imie;
	aktualny->opis = opis;
	aktualny->idle = idle;
	aktualny->ustawStatyBazowe(sila, zr, zw, wyt, zyw);
	aktualny->przelicz();
	aktualny->currentHP = aktualny->zdr_calk;

	return aktualny;
}

Postac* Gra::createChar(int id, int quest, int questFaza)
{
	Postac *temp = createChar(id);
	temp->quest = quest;
	temp->questFaza = questFaza;
	return temp;
}

using namespace ListaItemow;

Postac* Gra::createChar(int id)
{
	Postac* temp = NULL;
	PostacNpc* tempNpc = NULL;
	Kwestia* kwestia = NULL;
	switch (id)
	{

#pragma region szczur_jaskiniowy
	case ListaPostaci::SzczurJaskiniowy:
		temp = createChar(id, 1, RASA_SZCZUR, KLASA_BRAK,
			L"szczur jaskiniowy",
			L"Szczur jaskiniowy s� nieco wi�ksze od szczur�w miejskich, s� jednak "
			L"por�wnywalnie obrzydliwe. Bure, mokre futerko pokrywa prawie jedno �okciowego "
			L"gryzonia, kt�ry skrz�tnie przeszukuje otoczenie w poszukiwaniu po�ywienia. "
			L"Odg�os ma�ych pazurk�w uderzaj�cych w kamienn� posadzk� towarzyszy ka�demu "
			L"ruchowi szczura.",
			L"szpera dooko�a",
			5, 6, 6, 4, 3);
		temp->equip(create_item(BronieDzikie::SzczurzeKly));
		temp->zloto = rzucaj(2);
		temp->equip(create_item(PancerzeDzikie::SkoraSzczura));
		return temp;
#pragma endregion

#pragma region zakapturzona_postac
	case ListaPostaci::ZakapturzonaPostac:
		tempNpc = createNpc(id, 50, RASA_CZLOWIEK, KLASA_BRAK, L"zakapturzona posta�",
			L"Wpatruj�c si� w zakapturzonego cz�owieka nie dostrzegasz w nim nic "
			L"nadzwyczajnego. Nosi on d�ugie br�zowe szaty, kt�re dok�adnie zakrywaj� "
			L"jego cia�o. Kaptur ca�kowicie zas�ania mu twarz. Nieznajomy wpatruje si� "
			L"ca�y czas w pod�og�, nie wykonuj�c przy tym nawet najmniejszych ruch�w.",
			L"wpatruje si� w pod�og�",
			80, 80, 80, 80, 80);
		(tempNpc->trening)[SILA] = 34;
		(tempNpc->trening)[ZRECZNOSC] = 34;
		(tempNpc->trening)[ZWINNOSC] = 34;
		(tempNpc->trening)[WYTRZYMALOSC] = 34;
		(tempNpc->trening)[ZYWOTNOSC] = 34;
		tempNpc->rozmowny = true;
		tempNpc->przedmioty->dodaj(create_item(Bronie::MieczKrotkiBraz));
		tempNpc->przedmioty->dodaj(create_item(Klucze::KluczZBrazuLvl2));

		wczytajRozmowe(tempNpc->id, tempNpc);

		return tempNpc;

#pragma endregion

#pragma region test_NPC
	case ListaPostaci::TestNPC:
		tempNpc = createNpc(id, 50, RASA_CZLOWIEK, KLASA_BRAK, L"test NPC",
			L"To tylko testowy NPC, nie oczekuj epickich opis�w. "
			L"Jedyne czego mo�esz si� spodziewa� to sztucznie wyd�u�one opisy "
			L"maj�ce na celu sprawdzenie wersalikowania opis�w postaci.",
			L"stoi i zach�ca do rozmowy",
			80, 80, 80, 80, 80);

		tempNpc->zloto = 100;
		(tempNpc->przedmioty)->dodaj(create_item(Questowe::OkraglySzafir));

		wczytajRozmowe(tempNpc->id, tempNpc);

		return tempNpc;
#pragma endregion


	case ListaPostaci::OgarStrazniczy:
		temp = createChar(id, 10, RASA_OGAR, KLASA_BRAK,
			L"ogar stra�niczy",															 //poza lini� konsoli
			L"Alan napisz opis.",
			L"szpera dooko�a",
			27, 26, 22, 21, 22);
		temp->agresywny = true;
		temp->equip(create_item(BronieDzikie::KlyOgara));
		temp->equip(create_item(PancerzeDzikie::SkoraOgara));
		temp->zloto = rzucaj(10) + 3;
		return temp;

#pragma region Gobliny
	case ListaPostaci::GoblinZbieracz:
		temp = createChar(id, 2, RASA_GOBLIN, KLASA_ROBOTNIK,
			L"goblin zbieracz",
			L"Goblin ten jest przedstawicielem najni�szej kasty w spo�ecze�stwie goblin�w. Jak ka�dy goblin ma on ciemno zielon� sk�r�, pokryt� licznymi zmarszczkami i bruzdami. Wysoki na oko�o dwa �okcie, ma nieproporcjonalnie d�ugie r�ce i du�� g�ow� raz pochylon� postaw�. Jego twarz to g��wnie para wy�upiastych oczu, du�y spiczasty nos, oraz r�wnie du�e i stercz�ce na boki uszy. Zbieracz ubrany jest w jedynie stary, lniany w�r, kt�rego r�wnie� u�ywa do przechowywania zebranych grzyb�w.",
			L"rozgl�da si� dooko�a",
			7, 9, 9, 10, 7);
		temp->equip(create_item(Bronie::KamienMaly));
		temp->zloto = rzucaj(2) + 1;
		return temp;

	case ListaPostaci::GoblinGwardzista:
		temp = createChar(id, 3, RASA_GOBLIN, KLASA_GWARDZISTA,
			L"goblin gwardzista",
			L"Zadaniem gobli�skich gwardzist�w jest pilnowanie obozowiska, oraz alarmowanie o zbli�aj�cym si� zagro�eniu. Ich ubi�r stanowi najci�szy pancerz jaki mo�na znale�� w�r�d goblin�w- daje to wi�ksz� szans� na wydanie alarmuj�cego okrzyku zanim gwardzista si� zu�yje. Jego zbroj� stanowi� metalowe przedmioty zrabowane od ludzi- garnki, p�ytki, kawa�ki w�a�ciwych zbroi lub kolczug, czy tarcz, powi�zane razem linami b�d� paskami. Co do reszty wygl�du to gobli�scy gwardzi�ci s� r�wnie paskudni co reszta przedstawicieli ich rasy.",
			L"opiera si� na w��czni",
			12, 14, 12, 14, 12);
		return temp;

	case ListaPostaci::GoblinBerserker:
		temp = createChar(id, 4, RASA_GOBLIN, KLASA_BERSERKER,
			L"goblin berserker",
			L"Berserkerzy nale�� do najzdolniejszych wojownik�w w�r�d gobli�skiego plemienia. Za ubranie s�u�� im jedynie skurzane spodnie, wytworzone r�cznie ze sk�ry jednej ze swoich ofiar. Ich odkryt� klat� ozdabiaj� im blizny a twarzy zazwyczaj brakuje jednego ucha, nosa, b�d� oka. Pe�ni dumy berserkerzy zachowuj� si� pogardliwie do innych goblin�w oraz og�lnie do innych stworze�. Maj� szacunek jedynie do szamana, stanowi�c jego osobist� ochron�.",
			L"bacznie si� tobie przygl�da",
			14, 16, 14, 10, 15);
		return temp;

	case ListaPostaci::GoblinSzaman:
		tempNpc = createNpc(id, 5, RASA_GOBLIN, KLASA_MNICH,
			L"goblin szaman",
			L"Szamani s� jednocze�nie przyw�dcami goblin�kiego plemienia. Ich wygl�d ma u reszty goblin�w wywo�a� strach przed mocami dysponowanymi przez szamana, nawet je�eli takowych on nie ma. Jego cia�o jest pokryte dziwnymi tatua�ami i malunkami z b�ota i krwi a w uszach i nosie ma mn�stwo kolczyk�w. Jego szata jest gruba i wykonana z lnu. Wszyto w ni� kawa�ki zwierz�cego futra, oraz namalowano jakimi� barwnikami dziwne symbole. Na szyi szaman nosi naszyjnik z rzemienia, oraz zwierz�cych ko�ci, a na g�owie nosi koron� wykonan� z poro�a jelenia. Szaman stara si� robi� mistyczne wra�enie, machaj�c co chwila r�kami oraz podskakuj�c bez powodu.",
			L"nerwowo rozgl�da si� dooko�a",
			13, 14, 14, 18, 19);
		wczytajRozmowe(tempNpc->id, tempNpc);
		return tempNpc;

#pragma endregion

#pragma region Grzybnie

	case ListaPostaci::GrzybniaMala:
		temp = createChar(id, 3, RASA_GRZYBNIA, KLASA_ROBOTNIK,
			L"ma�a �ywa grzybnia",
			L"Opis ma�ej grzybni.",
			L"stoi bez ruchu",
			1, 1, 1, 1, 1);
		return temp;

#pragma endregion
	default:
		throw new wstring(L"BUONT! niepoprawny int dla createChar");
	}


}