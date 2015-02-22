#include "gra.h"
#include "zwiekszenieCechy.h"
#include "ListaItemow.h"
#include "item_types.h"

Item* Gra::create_item(int id, ItemTyp typ, string nazwa, string opis, string idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc)
{
	Item *aktualny=NULL;
	switch (typ)
	{
	case ITEM_QUEST:
		aktualny=new item_quest;
		aktualny->typ=ITEM_QUEST;
		break;
	case ITEM_STATIC_QUEST:
		aktualny=new item_quest;
		aktualny->typ=ITEM_STATIC_QUEST;
		break;
	case ITEM_DZWIGNIA:
		aktualny=new item_dzwignia;
		aktualny->typ=ITEM_DZWIGNIA;
		break;
	case ITEM_CONTAINER:
		aktualny=new item_container;
		aktualny->typ=ITEM_CONTAINER;
		break;
	case ITEM_STATIC_CONTAINER:
		aktualny=new item_container;
		aktualny->typ=ITEM_STATIC_CONTAINER;
		break;
	case ITEM_1HWEAPON:
		aktualny=new item_1hbron;
		aktualny->typ=ITEM_1HWEAPON;
		break;
	case ITEM_2HWEAPON:
		aktualny=new item_1hbron;
		aktualny->typ=ITEM_2HWEAPON;
		break;
	case ITEM_TARCZA:
		aktualny=new item_1hbron;
		aktualny->typ=ITEM_TARCZA;
		break;
	case ITEM_ZBROJA:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_ZBROJA;
		break;
	case ITEM_NARAMIENNIKI:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_NARAMIENNIKI;
		break;
	case ITEM_REKAWICE:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_REKAWICE;
		break;
	case ITEM_NAGOLENNIKI:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_NAGOLENNIKI;
		break;
	case ITEM_BUTY:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_BUTY;
		break;
	case ITEM_HELM:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_HELM;
		break;

	case ITEM_WILD_1HWEAPON:
		aktualny=new item_1hbron;
		aktualny->typ=ITEM_WILD_1HWEAPON;
		break;
	case ITEM_WILD_2HWEAPON:
		aktualny=new item_1hbron;
		aktualny->typ=ITEM_WILD_2HWEAPON;
		break;
	case ITEM_WILD_TARCZA:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_WILD_TARCZA;
		break;
	case ITEM_WILD_ZBROJA:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_WILD_ZBROJA;
		break;
	case ITEM_WILD_NARAMIENNIKI:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_WILD_NARAMIENNIKI;
		break;
	case ITEM_WILD_REKAWICE:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_HELM;
		break;
	case ITEM_WILD_NAGOLENNIKI:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_WILD_NAGOLENNIKI;
		break;
	case ITEM_WILD_BUTY:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_WILD_BUTY;
		break;
	case ITEM_WILD_HELM:
		aktualny=new item_zbroja;
		aktualny->typ=ITEM_WILD_HELM;
		break;
	}

	aktualny->id=id;
	aktualny->nazwa=nazwa;
	aktualny->opis=opis;
	aktualny->idle=idle;
	aktualny->ustaw_staty(atak, obrona, dmg, ochrona, pancerz, hp, cw);
	aktualny->wartosc=wartosc;
	
	return aktualny;
}

Item* Gra::create_item(int id, ItemTyp typ, string nazwa, string opis, string idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc, int wymSila, int wymZr, int wymZw, int wymWyt, int wymZyw)
{
	Item *temp= create_item(id, typ, nazwa, opis, idle, atak, obrona, dmg, ochrona, pancerz, hp, cw, wartosc);
	temp->ustaw_wymagania(wymSila, wymZr, wymZw, wymWyt, wymZyw);
	return temp;
}

Item* Gra::create_item(int id)
{
	item_dzwignia *temp_dzwignia=NULL;
	using namespace ListaItemow;

	switch (id)
	{

#pragma region Bronie
	case Bronie::DragDrewniany:
		return create_item(Bronie::DragDrewniany, ITEM_1HWEAPON,
			"drewniany dr¹g",
			"Opis drewnianego drêga.",
			"le¿y u twoich stóp",
			2,2,1,0,0,0,0,
			1, 
			0,0,0,0,0);
		break;

	case Bronie::MieczKrotkiBraz:
		return create_item(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			"krótki miecz z br¹zu",
			"Opis krótkiego miecza.",
			"le¿y u twoich stóp",
			4,4,3,0,0,0,0,
			10, 
			0,0,0,0,0);
		break;
	case Bronie::KamienMaly:
		return create_item(Bronie::KamienMaly, ITEM_1HWEAPON,
			"ma³y kamieñ",
			"Opis kamionka.",
			"le¿y na ziemi",
			-3,-3,1,0,0,0,0,
			0);
		break;  
#pragma endregion

#pragma region BronieDzikie
	case BronieDzikie::SzczurzeKly:
		return create_item(BronieDzikie::SzczurzeKly, ITEM_WILD_1HWEAPON,
			"szczurze k³y",
			"opis szczurzych k³ów",
			"le¿¹ tutaj",
			3,0,1,0,0,0,0,
			1);
		break;

	case BronieDzikie::KlyOgara:
		return create_item(BronieDzikie::KlyOgara, ITEM_WILD_1HWEAPON,
			"k³y ogara",
			"opis k³ów",
			"le¿¹ tutaj",
			10,0,5,0,0,0,0,
			20);  
#pragma endregion

#pragma region Pancerze
#pragma region PancerzSkorzany
	case Pancerze::RekawiceSkora:
		return create_item(Pancerze::RekawiceSkora, ITEM_NARAMIENNIKI,
			"skórzane naramienniki",
			"Opis skórzanych naramienników.",
			"le¿¹ tutaj",
			2,2,0,35,4,2,0,
			10);
		break;

	case Pancerze::NaramiennikiSkora:
		return create_item(Pancerze::NaramiennikiSkora, ITEM_REKAWICE,
			"lekkie skórzane rêkawiczki",
			"Opis skórzanych rêkawiczek",
			"le¿¹ tutaj",
			2,2,0,35,4,2,0,
			10);
		break;

	case Pancerze::NagolennikiSkora:
		return create_item(Pancerze::NagolennikiSkora, ITEM_NAGOLENNIKI,
			"lekkie skórzane nagolenniki",
			"Opis skórzanych nagolenników.",
			"le¿¹ tutaj",
			2,2,0,35,4,2,0,
			10);
		break;

	case Pancerze::ButySkora:
		return create_item(Pancerze::ButySkora, ITEM_BUTY,
			"skórzane trzewiki",
			"Opis skórzanych butów.",
			"le¿¹ tutaj",
			0,2,0,35,2,2,0,
			10);
		break;

	case Pancerze::ZbrojaSkora:
		return create_item(Pancerze::ZbrojaSkora, ITEM_ZBROJA,
			"skórzany kaftan",
			"Opis skórzanego kaftana",
			"le¿y tutaj",
			1,1,0,35,6,2,0,
			20);
		break;    
		
	case Pancerze::HelmSkora:
		return create_item(Pancerze::HelmSkora, ITEM_HELM,
			"skórzany kaptur",
			"Opis skózanego kaptura.",
			"le¿y tutaj",
			1,1,0,35,4,0,0,
			10);
#pragma endregion

#pragma endregion

#pragma region PancerzeDzikie
	case PancerzeDzikie::SkoraSzczura:
		return create_item(PancerzeDzikie::SkoraSzczura, ITEM_WILD_ZBROJA,
			"szczurza skóra",
			"Opis skóry szczura.",
			"le¿y tutaj",
			2,2,0,100,6,0,0,
			2);
		break;

	case PancerzeDzikie::SkoraOgara:
		return create_item(PancerzeDzikie::SkoraOgara, ITEM_WILD_ZBROJA,
			"skóra ogara",
			"opis skóry ogara",
			"le¿y tutaj",
			0,4,0,210,37,0,0,
			5);  
#pragma endregion

#pragma region Pojemniki
	case Pojemniki::TorbaPodrozna:
		return create_item(Pojemniki::TorbaPodrozna, ITEM_CONTAINER,
			"torba podró¿na",
			"Opis torby podró¿nej.",
			"le¿y tutaj",
			0,0,0,0,0,0,0,
			2);
		break;

	case Pojemniki::StarySzkielet:
		return create_item(Pojemniki::StarySzkielet, ITEM_STATIC_CONTAINER,
			"stary szkielet",
			"Nie jesteœ pewien jakiej rasy by³ ten nieboszczyk, ale po wielkoœci i "
			"kszta³cie czaski domyœlasz siê i¿ móg³ to byæ cz³owiek. Czas zostawi³ swój "
			"œlad na koœciach- widaæ na nich ubytki i wrêby. Nie zauwa¿asz ¿adnych "
			"szczegó³ów, które by wskazywa³y na to jak zmar³ jego posiadacz.",
			"le¿y pod œcian¹",
			0,0,0,0,0,0,0,0);
		break;

	case Pojemniki::DrewnianaSkrzynia:
		return create_item(Pojemniki::DrewnianaSkrzynia, ITEM_STATIC_CONTAINER,
			"drewniana skrzynia",
			"Opis drewnianej skrzyni",
			"stoi pod œcian¹",
			0,0,0,0,0,0,0,0);
		break;  
#pragma endregion

#pragma region Questowe
	case Questowe::OkraglySzafir:
		return create_item(Questowe::OkraglySzafir, ITEM_QUEST,
			"okr¹g³y szafir",
			"Opis okr¹g³ego szafitu.",
			"le¿y tutaj",
			0,0,0,0,0,0,0,0);
		break;

	case Questowe::KawalkiPotluczonegoSzkla:
		return create_item(Questowe::KawalkiPotluczonegoSzkla, ITEM_QUEST,
			"kawa³ki pot³uczonego szk³a",
			"Te kawa³ki pot³uczonego szk³a formowa³y kiedyœ zapewne zgrabn¹ butelkê. Teraz jednak do niczego ju¿ siê nie przydadz¹.",
			"le¿¹ na ziemi",
			0,0,0,0,0,0,0,0);
		break;  

	case Questowe::StluczoneLustro:
		return create_item(Questowe::StluczoneLustro, ITEM_STATIC_QUEST,
			"st³uczone lustro",
			"Opis st³uczonego lustra.",
			"stoi w k¹cie",
			0,0,0,0,0,0,0,0);
		break;
	case Questowe::Mapa:
		return create_item(Questowe::Mapa, ITEM_QUEST,
			"mapa",
			"Jest to kawa³ek czystego pergaminu, na którym mo¿esz rysowaæ mapê odwiedzonych miejsc.",
			"le¿y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 50);
#pragma endregion

#pragma region Klucze
	case Klucze::KluczZBrazuLvl2:
		return create_item(Klucze::KluczZBrazuLvl2, ITEM_QUEST,
			"zdobiony klucz z br¹zu",
			"opis klucza na poziom 2.",
			"le¿y na ziemi",
			0,0,0,0,0,0,0,0);  
#pragma endregion

#pragma region Dzwignie
	case Dzwignie::ButelkaPoWinie:
		return create_item(Dzwignie::ButelkaPoWinie, ITEM_DZWIGNIA,
			"butelka po winie",
			"Tajemnicza butelka le¿y samotnie na swoim miejscu w stojaku. Rozgl¹daj¹c siê po piwniczce nie znalaz³eœ ¿adnej innej butelki wiêc ta jedyna skupia twoj¹ ciekawoœæ. Wykonana jest z ciemnego, grubego szk³a, korek zatykaj¹cy szyjkê gdzieœ znikn¹³ wiêc jedyn¹ zawartoœci¹ naczynia jest powietrze. Prubujesz wyj¹æ butelke ze stojaka, jednak ta nie chce siê ruszyæ ani na w³os.",
			"le¿y samotnie na stojaku",
			0,0,0,0,0,0,0,0);
		break;  
#pragma endregion

#pragma region Consumables
	case Consumables::MiksturaZrecznosciSlaba :
		return new miksturaStatusu(Consumables::MiksturaZrecznosciSlaba,
			"s³absza mikstura zrêcznoœci",
			"Jak w przypadku wszystkich magicznych mikstur, ich zapach zmusza do d³u¿szego przemyœlenia z jakich ochydnoœci zosta³ przygotowany dany specyfik. Nikt jednak nie chcia³by zastanawiaæ siê nad tym przy obiedzie. W ka¿dym razie etykieta tego specyfiku sugeruje i¿ d³onie pij¹cego stan¹ siê szybkie i precyzyjne niczym wê¿e. Uwaga! Efekty uboczne obejmuj¹ niekontrolwoan¹ zmianê koloru w³osów.",
			"le¿y tutaj",
			15, 
			new zwiekszenieCechy("zwiêkszona zrêcznoœæ", 
			"Twoja zrêcznoœæ zosta³a zwiêkszona przez magiczn¹ miksturê.",
			"Czujesz w d³oniach dziwne mrowienie oraz ciep³o.",
			"Tajemnicze ciep³o z d³oni odchodzi.",
			ZRECZNOSC, 15, 120) );
		break;  
#pragma endregion

#pragma region Magiczne
		//////////////// magiczne ////////////  
#pragma endregion


	default:
		throw new string("Probowano stworzyc item o nieznanym id.");
	}

	return NULL;
}