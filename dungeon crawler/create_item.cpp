#include "gra.h"
#include <vector>
#include "zwiekszenieCechy.h"
#include "ListaItemow.h"
#include "item_types.h"
#include "randomGenerator.h"

Item* Gra::create_item(int id, ItemTyp typ, wstring nazwa, wstring opis, wstring idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc)
{
	Item *aktualny = NULL;
	switch (typ)
	{
	case ITEM_QUEST:
		aktualny = new item_quest;
		aktualny->typ = ITEM_QUEST;
		break;
	case ITEM_STATIC_QUEST:
		aktualny = new item_quest;
		aktualny->typ = ITEM_STATIC_QUEST;
		break;
	case ITEM_DZWIGNIA:
		aktualny = new item_dzwignia;
		aktualny->typ = ITEM_DZWIGNIA;
		break;
	case ITEM_CONTAINER:
		aktualny = new item_container;
		aktualny->typ = ITEM_CONTAINER;
		break;
	case ITEM_STATIC_CONTAINER:
		aktualny = new item_container;
		aktualny->typ = ITEM_STATIC_CONTAINER;
		break;
	case ITEM_1HWEAPON:
		aktualny = new item_1hbron;
		aktualny->typ = ITEM_1HWEAPON;
		break;
	case ITEM_2HWEAPON:
		aktualny = new item_1hbron;
		aktualny->typ = ITEM_2HWEAPON;
		break;
	case ITEM_TARCZA:
		aktualny = new item_1hbron;
		aktualny->typ = ITEM_TARCZA;
		break;
	case ITEM_ZBROJA:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_ZBROJA;
		break;
	case ITEM_NARAMIENNIKI:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_NARAMIENNIKI;
		break;
	case ITEM_REKAWICE:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_REKAWICE;
		break;
	case ITEM_NAGOLENNIKI:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_NAGOLENNIKI;
		break;
	case ITEM_BUTY:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_BUTY;
		break;
	case ITEM_HELM:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_HELM;
		break;

	case ITEM_WILD_1HWEAPON:
		aktualny = new item_1hbron;
		aktualny->typ = ITEM_WILD_1HWEAPON;
		break;
	case ITEM_WILD_2HWEAPON:
		aktualny = new item_1hbron;
		aktualny->typ = ITEM_WILD_2HWEAPON;
		break;
	case ITEM_WILD_TARCZA:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_WILD_TARCZA;
		break;
	case ITEM_WILD_ZBROJA:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_WILD_ZBROJA;
		break;
	case ITEM_WILD_NARAMIENNIKI:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_WILD_NARAMIENNIKI;
		break;
	case ITEM_WILD_REKAWICE:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_HELM;
		break;
	case ITEM_WILD_NAGOLENNIKI:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_WILD_NAGOLENNIKI;
		break;
	case ITEM_WILD_BUTY:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_WILD_BUTY;
		break;
	case ITEM_WILD_HELM:
		aktualny = new item_zbroja;
		aktualny->typ = ITEM_WILD_HELM;
		break;
	}

	aktualny->id = id;
	aktualny->nazwa = nazwa;
	aktualny->opis = opis;
	aktualny->idle = idle;
	aktualny->ustaw_staty(atak, obrona, dmg, ochrona, pancerz, hp, cw);
	aktualny->wartosc = wartosc;

	return aktualny;
}

Item* Gra::create_item(int id, ItemTyp typ, wstring nazwa, wstring opis, wstring idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc, int wymSila, int wymZr, int wymZw, int wymWyt, int wymZyw)
{
	Item *temp = create_item(id, typ, nazwa, opis, idle, atak, obrona, dmg, ochrona, pancerz, hp, cw, wartosc);
	temp->ustaw_wymagania(wymSila, wymZr, wymZw, wymWyt, wymZyw);
	return temp;
}

Item* Gra::create_item(int id)
{
	item_dzwignia *temp_dzwignia = NULL;
	using namespace ListaItemow;

	switch (id)
	{

#pragma region Bronie
	case Bronie::DragDrewniany:
		return create_item(Bronie::DragDrewniany, ITEM_2HWEAPON,
			L"drewniany dr�g",
			L"Ten kawa� kija wygl�da na oderwan� i wyschni�t� ga�� jakiego� drzewa. Nie jest on ca�kiem prosty, zawiera kilka s�k�w i nieregularno�ci ale jest d�ugi na kilka �okci i mo�e ca�kiem sprawnie pos�u�y� jako improwizowana bro�.",
			L"le�y u twoich st�p",
			2, 2, 2, 0, 0, 0, 0,
			1,
			0, 0, 0, 0, 0);
		break;

	case Bronie::MieczKrotkiBraz:
		return create_item(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"kr�tki miecz z br�zu",
			L"Miecze s� jedn� z najpowszechniejszych broni spotykanych w krainie. S� to no�e o podw�jnym i wyd�u�onym ostrzu, oraz z kling� przystosowan� do wygodnego dzier�enia oraz walki. Kr�tkie miecze maj� d�ugo�� oko�o p�torej �okcia, podw�jne zaostrzone ostrze, jednak z powodu ma�ej wagi najlepiej nadaj� si� do wykonywania pchni�� sztychem. R�koje�� jest kr�tka, jednor�czna a jelec prosty i ma�y. Miecz ten jest szybki jednak z powody ma�ej d�ugo�ci trudniej trafi� nim przeciwnika ni� odpowiednio d�u�szymi bronami.",
			L"le�y na ziemi",
			4, 4, 3, 0, 0, 0, 0,
			10,
			0, 0, 0, 0, 0);
		break;
	case Bronie::KamienMaly:
		return create_item(Bronie::KamienMaly, ITEM_1HWEAPON,
			L"ma�y kamie�",
			L"Jest to zwyk�y szary kawa�ek kamienia, wielko�ci oko�o pi�ci doros�ego cz�owieka. Jego masa mo�e by� niebezpieczna w bliskim kontakcie, jednak ostre kraw�dzie s� niebezpieczne dla d�oni dzier��cego.",
			L"le�y na ziemi",
			-3, -3, 1, 0, 0, 0, 0,
			0);
		break;
	case Bronie::ToporekMalyBraz:
		return create_item(id, ITEM_1HWEAPON,
			L"Ma�y toporek z br�zu",
			L"Topory to bro� bazuj�ca na siekierach drwal�w. Dzi�ki du�ej masie ostrza, oraz wywa�eniu skupionemu na ko�cu broni topory posiadaj� wi�ksz� si�� uderzenia ni� miecze, zdoln� do przebijania grubszych pancerzy oraz rozbijania tarcz. Brak d�ugiego ostrza, czyni jednak t� bro� ma�o u�yteczn� w parowaniu.",
			L"le�y na ziemi",
			1, 1, 3, 0, 0, 0, 0,
			2);
	case Bronie::WloczniaMalaKrzemien:
		return create_item(id, ITEM_2HWEAPON,
			L"Prymitywna w��cznia",
			L"W��cznie s� jednymi z najstarszych typ�w broni stosowanych przez rasy rozumne. Prosty pomys� zwi�kszenia zasi�gu ostrza, poprzez umieszczenie go na drewnianym kiju daje u�ytkownikowi du�� przewag� zasi�gu, sam drzewiec mo�e by� r�wnie� �atwo u�yty w parowaniu cios�w. Ostrze jest jednak ma�e i nie jest zdolne wyrz�dzi� tak du�ych szk�d jak top�r czy miecz. W tym egzemplarzu ostrze jest wykonane z ociosanego krzemienia, ca�a konstrukcja jest bardzo prymitywna i wykonana prostymi metodami.",
			L"le�y na ziemi",
			2, 2, 1, 0, 0, 0, 0,
			2);

#pragma endregion

#pragma region BronieDzikie
	case BronieDzikie::SzczurzeKly:
		return create_item(BronieDzikie::SzczurzeKly, ITEM_WILD_1HWEAPON,
			L"szczurze k�y",
			L"opis szczurzych k��w",
			L"le�� tutaj",
			3, 0, 1, 0, 0, 0, 0,
			1);
		break;

	case BronieDzikie::KlyOgara:
		return create_item(BronieDzikie::KlyOgara, ITEM_WILD_1HWEAPON,
			L"k�y ogara",
			L"opis k��w",
			L"le�� tutaj",
			10, 0, 5, 0, 0, 0, 0,
			20);
#pragma endregion

#pragma region Pancerze
#pragma region PancerzSkorzany
	case Pancerze::RekawiceSkora:
		return create_item(Pancerze::RekawiceSkora, ITEM_NARAMIENNIKI,
			L"sk�rzane naramienniki",
			L"Opis sk�rzanych naramiennik�w.",
			L"le�� tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::NaramiennikiSkora:
		return create_item(Pancerze::NaramiennikiSkora, ITEM_REKAWICE,
			L"lekkie sk�rzane r�kawiczki",
			L"Opis sk�rzanych r�kawiczek",
			L"le�� tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::NagolennikiSkora:
		return create_item(Pancerze::NagolennikiSkora, ITEM_NAGOLENNIKI,
			L"lekkie sk�rzane nagolenniki",
			L"Opis sk�rzanych nagolennik�w.",
			L"le�� tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::ButySkora:
		return create_item(Pancerze::ButySkora, ITEM_BUTY,
			L"sk�rzane trzewiki",
			L"Opis sk�rzanych but�w.",
			L"le�� tutaj",
			0, 2, 0, 35, 2, 2, 0,
			10);
		break;

	case Pancerze::ZbrojaSkora:
		return create_item(Pancerze::ZbrojaSkora, ITEM_ZBROJA,
			L"sk�rzany kaftan",
			L"Opis sk�rzanego kaftana",
			L"le�y tutaj",
			1, 1, 0, 35, 6, 2, 0,
			20);
		break;

	case Pancerze::HelmSkora:
		return create_item(Pancerze::HelmSkora, ITEM_HELM,
			L"sk�rzany kaptur",
			L"Opis sk�zanego kaptura.",
			L"le�y tutaj",
			1, 1, 0, 35, 4, 0, 0,
			10);
#pragma endregion

#pragma endregion

#pragma region PancerzeDzikie
	case PancerzeDzikie::SkoraSzczura:
		return create_item(PancerzeDzikie::SkoraSzczura, ITEM_WILD_ZBROJA,
			L"szczurza sk�ra",
			L"Opis sk�ry szczura.",
			L"le�y tutaj",
			2, 2, 0, 100, 6, 0, 0,
			2);
		break;

	case PancerzeDzikie::SkoraOgara:
		return create_item(PancerzeDzikie::SkoraOgara, ITEM_WILD_ZBROJA,
			L"sk�ra ogara",
			L"opis sk�ry ogara",
			L"le�y tutaj",
			0, 4, 0, 210, 37, 0, 0,
			5);
#pragma endregion

#pragma region Pojemniki
	case Pojemniki::TorbaPodrozna:
		return create_item(Pojemniki::TorbaPodrozna, ITEM_CONTAINER,
			L"torba podr�na",
			L"Opis torby podr�nej.",
			L"le�y tutaj",
			0, 0, 0, 0, 0, 0, 0,
			2);
		break;

	case Pojemniki::StarySzkielet:
		return create_item(Pojemniki::StarySzkielet, ITEM_STATIC_CONTAINER,
			L"stary szkielet",
			L"Nie jeste� pewien jakiej rasy by� ten nieboszczyk, ale po wielko�ci i kszta�cie czaski domy�lasz si� i� m�g� to by� cz�owiek. Czas zostawi� sw�j �lad na ko�ciach- wida� na nich ubytki i wr�by. Nie zauwa�asz �adnych szczeg��w, kt�re by wskazywa�y na to jak zmar� jego posiadacz.",
			L"le�y pod �cian�",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Pojemniki::DrewnianaSkrzynia:
		return create_item(Pojemniki::DrewnianaSkrzynia, ITEM_STATIC_CONTAINER,
			L"drewniana skrzynia",
			L"Opis drewnianej skrzyni",
			L"stoi pod �cian�",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
#pragma endregion

#pragma region Questowe
	case Questowe::OkraglySzafir:
		return create_item(Questowe::OkraglySzafir, ITEM_QUEST,
			L"okr�g�y szafir",
			L"Szafir jest kamieniem szlachetnym o barwie ciemno niebieskiej. Zazwyczaj klejnoty szlifowane s� w sze�cienne lub inne kanciaste kszta�ty, ten jednak jest uformowany w kszta�t kuli. Przygl�daj�c si� bli�ej nie zauwa�asz �adnych �lad�w szlifowania, zachwyca ci� r�wnie� niezwyk�a perfekcja kuli.",
			L"le�y tutaj",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Questowe::KawalkiPotluczonegoSzkla:
		return create_item(Questowe::KawalkiPotluczonegoSzkla, ITEM_QUEST,
			L"kawa�ki pot�uczonego szk�a",
			L"Te kawa�ki pot�uczonego szk�a formowa�y kiedy� zapewne zgrabn� butelk�. Teraz jednak do niczego ju� si� nie przydadz�.",
			L"le�� na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Questowe::StluczoneLustro:
		return create_item(Questowe::StluczoneLustro, ITEM_STATIC_QUEST,
			L"st�uczone lustro",
			L"Przed tob� stoi wykonana z br�zu zdobiona oprawa lustra. Lustro by�o wykonane ze szk�a, kt�rego kawa�ki zalegaj� woko�o na pod�odze. Oprawa jest prostok�tna o wysoko�ci ma�ego cz�owieka. Jej kraw�dzie zajmuj� wykwintne zdobienia, w�r�d kt�rych najbardziej rzuca si� w oczy symbol czaski, umieszczony na samym szczycie oprawy.",
			L"stoi w k�cie",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
	case Questowe::Mapa:
		return create_item(Questowe::Mapa, ITEM_QUEST,
			L"mapa",
			L"Mapa jest kawa�kiem wyprawianej sk�ry lub pergaminu. Powierzenie mu informacji o po�o�eniu interesuj�cych miejsc w terenie okaza�o si� lepszym pomys�em ni� powierzanie na zawodnej pami�ci. R�wnie� dla poszukiwaczy przyg�d rysowanie schemat�w przebytych miejsc okaza�o si� zbawienne w skomplikowanych labiryntach, b�d� grobowcach.",
			L"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 50);
#pragma endregion

#pragma region Klucze
	case Klucze::KluczZZelazaProsty:
		return create_item(Klucze::KluczZZelazaProsty, ITEM_QUEST,
			L"prosty klucz z �elaza",
			L"opis klucza do drewnianych skrzy�.",
			L"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
	case Klucze::KluczZBrazuLvl2:
		return create_item(Klucze::KluczZBrazuLvl2, ITEM_QUEST,
			L"zdobiony klucz z br�zu",
			L"opis klucza na poziom 2.",
			L"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
	case Klucze::KluczZSrebraLvl3:
		return create_item(Klucze::KluczZSrebraLvl3, ITEM_QUEST,
			L"zdobiony klucz ze srebra",
			L"opis klucza na poziom 3.",
			L"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
#pragma endregion

#pragma region Dzwignie
	case Dzwignie::ButelkaPoWinie:
		return create_item(Dzwignie::ButelkaPoWinie, ITEM_DZWIGNIA,
			L"butelka po winie",
			L"Tajemnicza butelka le�y samotnie na swoim miejscu w stojaku. Rozgl�daj�c si� po piwniczce nie znalaz�e� �adnej innej butelki wi�c ta jedyna skupia twoj� ciekawo��. Wykonana jest z ciemnego, grubego szk�a, korek zatykaj�cy szyjk� gdzie� znikn�� wi�c jedyn� zawarto�ci� naczynia jest powietrze. Prub�jesz wyj�� butelk� ze stojaka, jednak ta nie chce si� ruszy� ani na w�os.",
			L"le�y samotnie na stojaku",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
#pragma endregion

#pragma region Consumables
	case Consumables::MiksturaZrecznosciSlaba:
		return new miksturaStatusu(Consumables::MiksturaZrecznosciSlaba,
			L"s�absza mikstura zr�czno�ci",
			L"Jak w przypadku wszystkich magicznych mikstur, ich zapach zmusza do d�u�szego przemy�lenia z jakich ohydno�ci zosta� przygotowany dany specyfik. Nikt jednak nie chcia�by zastanawia� si� nad tym przy obiedzie. W ka�dym razie etykieta tego specyfiku sugeruje i� d�onie pij�cego stan� si� szybkie i precyzyjne niczym w�e. Uwaga! Efekty uboczne obejmuj� niekontrolowan�  zmian� koloru w�os�w.",
			L"le�y tutaj",
			15,
			new zwiekszenieCechy(L"zwi�kszona zr�czno��",
			L"Twoja zr�czno�� zosta�a zwi�kszona przez magiczn� mikstur�.",
			L"Czujesz w d�oniach dziwne mrowienie oraz ciep�o.",
			L"Tajemnicze ciep�o z d�oni odchodzi.",
			ZRECZNOSC, 15, 120));
		break;
#pragma endregion

#pragma region Magiczne
	case Magiczne::KoszulaLniana:
		return create_item(id, ITEM_KOSZULA,
			L"lniana koszula",
			L"Opis.",
			L"le�y na ziemi",
			4, 2, 0, 0, 10, 0, 0, 5);
	case Magiczne::SpodnieLniane:
		return create_item(id, ITEM_SPODNIE,
			L"lniane spodnie",
			L"Opis.",
			L"le�y na ziemi",
			2, 4, 0, 0, 10, 0, 0, 5);
#pragma endregion


	default:
		throw new wstring(L"Probowano stworzyc item o nieznanym id.");
	}

	return NULL;
}

Item* Gra::create_item(vector<int> listaMozliwych)
{
	int wybrany = rzucaj(0, listaMozliwych.size() - 1);
	return(create_item(listaMozliwych[wybrany]));
}