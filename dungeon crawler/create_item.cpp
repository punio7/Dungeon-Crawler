#include "gra.h"
#include "zwiekszenieCechy.h"
#include "ListaItemow.h"
#include "item_types.h"

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
		return create_item(Bronie::DragDrewniany, ITEM_1HWEAPON,
			L"drewniany dr¹g",
			L"Opis drewnianego drêga.",
			L"le¿y u twoich stóp",
			2, 2, 1, 0, 0, 0, 0,
			1,
			0, 0, 0, 0, 0);
		break;

	case Bronie::MieczKrotkiBraz:
		return create_item(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"krótki miecz z br¹zu",
			L"Opis krótkiego miecza.",
			L"le¿y u twoich stóp",
			4, 4, 3, 0, 0, 0, 0,
			10,
			0, 0, 0, 0, 0);
		break;
	case Bronie::KamienMaly:
		return create_item(Bronie::KamienMaly, ITEM_1HWEAPON,
			L"ma³y kamieñ",
			L"Opis kamionka.",
			L"le¿y na ziemi",
			-3, -3, 1, 0, 0, 0, 0,
			0);
		break;
#pragma endregion

#pragma region BronieDzikie
	case BronieDzikie::SzczurzeKly:
		return create_item(BronieDzikie::SzczurzeKly, ITEM_WILD_1HWEAPON,
			L"szczurze k³y",
			L"opis szczurzych k³ów",
			L"le¿¹ tutaj",
			3, 0, 1, 0, 0, 0, 0,
			1);
		break;

	case BronieDzikie::KlyOgara:
		return create_item(BronieDzikie::KlyOgara, ITEM_WILD_1HWEAPON,
			L"k³y ogara",
			L"opis k³ów",
			L"le¿¹ tutaj",
			10, 0, 5, 0, 0, 0, 0,
			20);
#pragma endregion

#pragma region Pancerze
#pragma region PancerzSkorzany
	case Pancerze::RekawiceSkora:
		return create_item(Pancerze::RekawiceSkora, ITEM_NARAMIENNIKI,
			L"skórzane naramienniki",
			L"Opis skórzanych naramienników.",
			L"le¿¹ tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::NaramiennikiSkora:
		return create_item(Pancerze::NaramiennikiSkora, ITEM_REKAWICE,
			L"lekkie skórzane rêkawiczki",
			L"Opis skórzanych rêkawiczek",
			L"le¿¹ tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::NagolennikiSkora:
		return create_item(Pancerze::NagolennikiSkora, ITEM_NAGOLENNIKI,
			L"lekkie skórzane nagolenniki",
			L"Opis skórzanych nagolenników.",
			L"le¿¹ tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::ButySkora:
		return create_item(Pancerze::ButySkora, ITEM_BUTY,
			L"skórzane trzewiki",
			L"Opis skórzanych butów.",
			L"le¿¹ tutaj",
			0, 2, 0, 35, 2, 2, 0,
			10);
		break;

	case Pancerze::ZbrojaSkora:
		return create_item(Pancerze::ZbrojaSkora, ITEM_ZBROJA,
			L"skórzany kaftan",
			L"Opis skórzanego kaftana",
			L"le¿y tutaj",
			1, 1, 0, 35, 6, 2, 0,
			20);
		break;

	case Pancerze::HelmSkora:
		return create_item(Pancerze::HelmSkora, ITEM_HELM,
			L"skórzany kaptur",
			L"Opis skózanego kaptura.",
			L"le¿y tutaj",
			1, 1, 0, 35, 4, 0, 0,
			10);
#pragma endregion

#pragma endregion

#pragma region PancerzeDzikie
	case PancerzeDzikie::SkoraSzczura:
		return create_item(PancerzeDzikie::SkoraSzczura, ITEM_WILD_ZBROJA,
			L"szczurza skóra",
			L"Opis skóry szczura.",
			L"le¿y tutaj",
			2, 2, 0, 100, 6, 0, 0,
			2);
		break;

	case PancerzeDzikie::SkoraOgara:
		return create_item(PancerzeDzikie::SkoraOgara, ITEM_WILD_ZBROJA,
			L"skóra ogara",
			L"opis skóry ogara",
			L"le¿y tutaj",
			0, 4, 0, 210, 37, 0, 0,
			5);
#pragma endregion

#pragma region Pojemniki
	case Pojemniki::TorbaPodrozna:
		return create_item(Pojemniki::TorbaPodrozna, ITEM_CONTAINER,
			L"torba podró¿na",
			L"Opis torby podró¿nej.",
			L"le¿y tutaj",
			0, 0, 0, 0, 0, 0, 0,
			2);
		break;

	case Pojemniki::StarySzkielet:
		return create_item(Pojemniki::StarySzkielet, ITEM_STATIC_CONTAINER,
			L"stary szkielet",
			L"Nie jesteœ pewien jakiej rasy by³ ten nieboszczyk, ale po wielkoœci i "
			L"kszta³cie czaski domyœlasz siê i¿ móg³ to byæ cz³owiek. Czas zostawi³ swój "
			L"œlad na koœciach- widaæ na nich ubytki i wrêby. Nie zauwa¿asz ¿adnych "
			L"szczegó³ów, które by wskazywa³y na to jak zmar³ jego posiadacz.",
			L"le¿y pod œcian¹",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Pojemniki::DrewnianaSkrzynia:
		return create_item(Pojemniki::DrewnianaSkrzynia, ITEM_STATIC_CONTAINER,
			L"drewniana skrzynia",
			L"Opis drewnianej skrzyni",
			L"stoi pod œcian¹",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
#pragma endregion

#pragma region Questowe
	case Questowe::OkraglySzafir:
		return create_item(Questowe::OkraglySzafir, ITEM_QUEST,
			L"okr¹g³y szafir",
			L"Opis okr¹g³ego szafitu.",
			L"le¿y tutaj",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Questowe::KawalkiPotluczonegoSzkla:
		return create_item(Questowe::KawalkiPotluczonegoSzkla, ITEM_QUEST,
			L"kawa³ki pot³uczonego szk³a",
			L"Te kawa³ki pot³uczonego szk³a formowa³y kiedyœ zapewne zgrabn¹ butelkê. Teraz jednak do niczego ju¿ siê nie przydadz¹.",
			L"le¿¹ na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Questowe::StluczoneLustro:
		return create_item(Questowe::StluczoneLustro, ITEM_STATIC_QUEST,
			L"st³uczone lustro",
			L"Opis st³uczonego lustra.",
			L"stoi w k¹cie",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
	case Questowe::Mapa:
		return create_item(Questowe::Mapa, ITEM_QUEST,
			L"mapa",
			L"Jest to kawa³ek czystego pergaminu, na którym mo¿esz rysowaæ mapê odwiedzonych miejsc.",
			L"le¿y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 50);
#pragma endregion

#pragma region Klucze
	case Klucze::KluczZBrazuLvl2:
		return create_item(Klucze::KluczZBrazuLvl2, ITEM_QUEST,
			L"zdobiony klucz z br¹zu",
			L"opis klucza na poziom 2.",
			L"le¿y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
#pragma endregion

#pragma region Dzwignie
	case Dzwignie::ButelkaPoWinie:
		return create_item(Dzwignie::ButelkaPoWinie, ITEM_DZWIGNIA,
			L"butelka po winie",
			L"Tajemnicza butelka le¿y samotnie na swoim miejscu w stojaku. Rozgl¹daj¹c siê po piwniczce nie znalaz³eœ ¿adnej innej butelki wiêc ta jedyna skupia twoj¹ ciekawoœæ. Wykonana jest z ciemnego, grubego szk³a, korek zatykaj¹cy szyjkê gdzieœ znikn¹³ wiêc jedyn¹ zawartoœci¹ naczynia jest powietrze. Prubujesz wyj¹æ butelke ze stojaka, jednak ta nie chce siê ruszyæ ani na w³os.",
			L"le¿y samotnie na stojaku",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
#pragma endregion

#pragma region Consumables
	case Consumables::MiksturaZrecznosciSlaba:
		return new miksturaStatusu(Consumables::MiksturaZrecznosciSlaba,
			L"s³absza mikstura zrêcznoœci",
			L"Jak w przypadku wszystkich magicznych mikstur, ich zapach zmusza do d³u¿szego przemyœlenia z jakich ochydnoœci zosta³ przygotowany dany specyfik. Nikt jednak nie chcia³by zastanawiaæ siê nad tym przy obiedzie. W ka¿dym razie etykieta tego specyfiku sugeruje i¿ d³onie pij¹cego stan¹ siê szybkie i precyzyjne niczym wê¿e. Uwaga! Efekty uboczne obejmuj¹ niekontrolwoan¹ zmianê koloru w³osów.",
			L"le¿y tutaj",
			15,
			new zwiekszenieCechy(L"zwiêkszona zrêcznoœæ",
			L"Twoja zrêcznoœæ zosta³a zwiêkszona przez magiczn¹ miksturê.",
			L"Czujesz w d³oniach dziwne mrowienie oraz ciep³o.",
			L"Tajemnicze ciep³o z d³oni odchodzi.",
			ZRECZNOSC, 15, 120));
		break;
#pragma endregion

#pragma region Magiczne
		//////////////// magiczne ////////////  
#pragma endregion


	default:
		throw new wstring(L"Probowano stworzyc item o nieznanym id.");
	}

	return NULL;
}