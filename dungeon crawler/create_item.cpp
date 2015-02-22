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
			"drewniany dr�g",
			"Opis drewnianego dr�ga.",
			"le�y u twoich st�p",
			2,2,1,0,0,0,0,
			1, 
			0,0,0,0,0);
		break;

	case Bronie::MieczKrotkiBraz:
		return create_item(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			"kr�tki miecz z br�zu",
			"Opis kr�tkiego miecza.",
			"le�y u twoich st�p",
			4,4,3,0,0,0,0,
			10, 
			0,0,0,0,0);
		break;
	case Bronie::KamienMaly:
		return create_item(Bronie::KamienMaly, ITEM_1HWEAPON,
			"ma�y kamie�",
			"Opis kamionka.",
			"le�y na ziemi",
			-3,-3,1,0,0,0,0,
			0);
		break;  
#pragma endregion

#pragma region BronieDzikie
	case BronieDzikie::SzczurzeKly:
		return create_item(BronieDzikie::SzczurzeKly, ITEM_WILD_1HWEAPON,
			"szczurze k�y",
			"opis szczurzych k��w",
			"le�� tutaj",
			3,0,1,0,0,0,0,
			1);
		break;

	case BronieDzikie::KlyOgara:
		return create_item(BronieDzikie::KlyOgara, ITEM_WILD_1HWEAPON,
			"k�y ogara",
			"opis k��w",
			"le�� tutaj",
			10,0,5,0,0,0,0,
			20);  
#pragma endregion

#pragma region Pancerze
#pragma region PancerzSkorzany
	case Pancerze::RekawiceSkora:
		return create_item(Pancerze::RekawiceSkora, ITEM_NARAMIENNIKI,
			"sk�rzane naramienniki",
			"Opis sk�rzanych naramiennik�w.",
			"le�� tutaj",
			2,2,0,35,4,2,0,
			10);
		break;

	case Pancerze::NaramiennikiSkora:
		return create_item(Pancerze::NaramiennikiSkora, ITEM_REKAWICE,
			"lekkie sk�rzane r�kawiczki",
			"Opis sk�rzanych r�kawiczek",
			"le�� tutaj",
			2,2,0,35,4,2,0,
			10);
		break;

	case Pancerze::NagolennikiSkora:
		return create_item(Pancerze::NagolennikiSkora, ITEM_NAGOLENNIKI,
			"lekkie sk�rzane nagolenniki",
			"Opis sk�rzanych nagolennik�w.",
			"le�� tutaj",
			2,2,0,35,4,2,0,
			10);
		break;

	case Pancerze::ButySkora:
		return create_item(Pancerze::ButySkora, ITEM_BUTY,
			"sk�rzane trzewiki",
			"Opis sk�rzanych but�w.",
			"le�� tutaj",
			0,2,0,35,2,2,0,
			10);
		break;

	case Pancerze::ZbrojaSkora:
		return create_item(Pancerze::ZbrojaSkora, ITEM_ZBROJA,
			"sk�rzany kaftan",
			"Opis sk�rzanego kaftana",
			"le�y tutaj",
			1,1,0,35,6,2,0,
			20);
		break;    
		
	case Pancerze::HelmSkora:
		return create_item(Pancerze::HelmSkora, ITEM_HELM,
			"sk�rzany kaptur",
			"Opis sk�zanego kaptura.",
			"le�y tutaj",
			1,1,0,35,4,0,0,
			10);
#pragma endregion

#pragma endregion

#pragma region PancerzeDzikie
	case PancerzeDzikie::SkoraSzczura:
		return create_item(PancerzeDzikie::SkoraSzczura, ITEM_WILD_ZBROJA,
			"szczurza sk�ra",
			"Opis sk�ry szczura.",
			"le�y tutaj",
			2,2,0,100,6,0,0,
			2);
		break;

	case PancerzeDzikie::SkoraOgara:
		return create_item(PancerzeDzikie::SkoraOgara, ITEM_WILD_ZBROJA,
			"sk�ra ogara",
			"opis sk�ry ogara",
			"le�y tutaj",
			0,4,0,210,37,0,0,
			5);  
#pragma endregion

#pragma region Pojemniki
	case Pojemniki::TorbaPodrozna:
		return create_item(Pojemniki::TorbaPodrozna, ITEM_CONTAINER,
			"torba podr�na",
			"Opis torby podr�nej.",
			"le�y tutaj",
			0,0,0,0,0,0,0,
			2);
		break;

	case Pojemniki::StarySzkielet:
		return create_item(Pojemniki::StarySzkielet, ITEM_STATIC_CONTAINER,
			"stary szkielet",
			"Nie jeste� pewien jakiej rasy by� ten nieboszczyk, ale po wielko�ci i "
			"kszta�cie czaski domy�lasz si� i� m�g� to by� cz�owiek. Czas zostawi� sw�j "
			"�lad na ko�ciach- wida� na nich ubytki i wr�by. Nie zauwa�asz �adnych "
			"szczeg��w, kt�re by wskazywa�y na to jak zmar� jego posiadacz.",
			"le�y pod �cian�",
			0,0,0,0,0,0,0,0);
		break;

	case Pojemniki::DrewnianaSkrzynia:
		return create_item(Pojemniki::DrewnianaSkrzynia, ITEM_STATIC_CONTAINER,
			"drewniana skrzynia",
			"Opis drewnianej skrzyni",
			"stoi pod �cian�",
			0,0,0,0,0,0,0,0);
		break;  
#pragma endregion

#pragma region Questowe
	case Questowe::OkraglySzafir:
		return create_item(Questowe::OkraglySzafir, ITEM_QUEST,
			"okr�g�y szafir",
			"Opis okr�g�ego szafitu.",
			"le�y tutaj",
			0,0,0,0,0,0,0,0);
		break;

	case Questowe::KawalkiPotluczonegoSzkla:
		return create_item(Questowe::KawalkiPotluczonegoSzkla, ITEM_QUEST,
			"kawa�ki pot�uczonego szk�a",
			"Te kawa�ki pot�uczonego szk�a formowa�y kiedy� zapewne zgrabn� butelk�. Teraz jednak do niczego ju� si� nie przydadz�.",
			"le�� na ziemi",
			0,0,0,0,0,0,0,0);
		break;  

	case Questowe::StluczoneLustro:
		return create_item(Questowe::StluczoneLustro, ITEM_STATIC_QUEST,
			"st�uczone lustro",
			"Opis st�uczonego lustra.",
			"stoi w k�cie",
			0,0,0,0,0,0,0,0);
		break;
	case Questowe::Mapa:
		return create_item(Questowe::Mapa, ITEM_QUEST,
			"mapa",
			"Jest to kawa�ek czystego pergaminu, na kt�rym mo�esz rysowa� map� odwiedzonych miejsc.",
			"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 50);
#pragma endregion

#pragma region Klucze
	case Klucze::KluczZBrazuLvl2:
		return create_item(Klucze::KluczZBrazuLvl2, ITEM_QUEST,
			"zdobiony klucz z br�zu",
			"opis klucza na poziom 2.",
			"le�y na ziemi",
			0,0,0,0,0,0,0,0);  
#pragma endregion

#pragma region Dzwignie
	case Dzwignie::ButelkaPoWinie:
		return create_item(Dzwignie::ButelkaPoWinie, ITEM_DZWIGNIA,
			"butelka po winie",
			"Tajemnicza butelka le�y samotnie na swoim miejscu w stojaku. Rozgl�daj�c si� po piwniczce nie znalaz�e� �adnej innej butelki wi�c ta jedyna skupia twoj� ciekawo��. Wykonana jest z ciemnego, grubego szk�a, korek zatykaj�cy szyjk� gdzie� znikn�� wi�c jedyn� zawarto�ci� naczynia jest powietrze. Prubujesz wyj�� butelke ze stojaka, jednak ta nie chce si� ruszy� ani na w�os.",
			"le�y samotnie na stojaku",
			0,0,0,0,0,0,0,0);
		break;  
#pragma endregion

#pragma region Consumables
	case Consumables::MiksturaZrecznosciSlaba :
		return new miksturaStatusu(Consumables::MiksturaZrecznosciSlaba,
			"s�absza mikstura zr�czno�ci",
			"Jak w przypadku wszystkich magicznych mikstur, ich zapach zmusza do d�u�szego przemy�lenia z jakich ochydno�ci zosta� przygotowany dany specyfik. Nikt jednak nie chcia�by zastanawia� si� nad tym przy obiedzie. W ka�dym razie etykieta tego specyfiku sugeruje i� d�onie pij�cego stan� si� szybkie i precyzyjne niczym w�e. Uwaga! Efekty uboczne obejmuj� niekontrolwoan� zmian� koloru w�os�w.",
			"le�y tutaj",
			15, 
			new zwiekszenieCechy("zwi�kszona zr�czno��", 
			"Twoja zr�czno�� zosta�a zwi�kszona przez magiczn� mikstur�.",
			"Czujesz w d�oniach dziwne mrowienie oraz ciep�o.",
			"Tajemnicze ciep�o z d�oni odchodzi.",
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