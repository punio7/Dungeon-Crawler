#include "Gra.h"
#include <vector>
#include "ZwiekszenieCechy.h"
#include "ListaItemow.h"
#include "ListaZdarzenGlobalnych.h"
#include "ItemTypes.h"
#include "randomGenerator.h"

Item* Gra::createItem(int id, ItemTyp typ, wstring nazwa, wstring opis, wstring idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc)
{
	Item *aktualny = NULL;
	switch (typ)
	{
	case ITEM_QUEST:
		aktualny = new ItemQuest;
		aktualny->typ = ITEM_QUEST;
		break;
	case ITEM_STATIC_QUEST:
		aktualny = new ItemQuest;
		aktualny->typ = ITEM_STATIC_QUEST;
		break;
	case ITEM_DZWIGNIA:
		aktualny = new ItemDzwignia;
		aktualny->typ = ITEM_DZWIGNIA;
		break;
	case ITEM_CONTAINER:
		aktualny = new ItemContainer;
		aktualny->typ = ITEM_CONTAINER;
		break;
	case ITEM_STATIC_CONTAINER:
		aktualny = new ItemContainer;
		aktualny->typ = ITEM_STATIC_CONTAINER;
		break;
	case ITEM_1HWEAPON:
		aktualny = new Item1hBron;
		aktualny->typ = ITEM_1HWEAPON;
		break;
	case ITEM_2HWEAPON:
		aktualny = new Item1hBron;
		aktualny->typ = ITEM_2HWEAPON;
		break;
	case ITEM_TARCZA:
		aktualny = new Item1hBron;
		aktualny->typ = ITEM_TARCZA;
		break;
	case ITEM_ZBROJA:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_ZBROJA;
		break;
	case ITEM_NARAMIENNIKI:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_NARAMIENNIKI;
		break;
	case ITEM_REKAWICE:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_REKAWICE;
		break;
	case ITEM_NAGOLENNIKI:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_NAGOLENNIKI;
		break;
	case ITEM_BUTY:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_BUTY;
		break;
	case ITEM_HELM:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_HELM;
		break;
	case ITEM_KOSZULA:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_KOSZULA;
		break;
	case ITEM_SPODNIE:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_SPODNIE;
		break;
	case ITEM_PIERSCIEN:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_PIERSCIEN;
		break;
	case ITEM_NASZYJNIK:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_NASZYJNIK;
		break;

	case ITEM_WILD_1HWEAPON:
		aktualny = new Item1hBron;
		aktualny->typ = ITEM_WILD_1HWEAPON;
		break;
	case ITEM_WILD_2HWEAPON:
		aktualny = new Item1hBron;
		aktualny->typ = ITEM_WILD_2HWEAPON;
		break;
	case ITEM_WILD_TARCZA:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_WILD_TARCZA;
		break;
	case ITEM_WILD_ZBROJA:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_WILD_ZBROJA;
		break;
	case ITEM_WILD_NARAMIENNIKI:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_WILD_NARAMIENNIKI;
		break;
	case ITEM_WILD_REKAWICE:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_HELM;
		break;
	case ITEM_WILD_NAGOLENNIKI:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_WILD_NAGOLENNIKI;
		break;
	case ITEM_WILD_BUTY:
		aktualny = new ItemZbroja;
		aktualny->typ = ITEM_WILD_BUTY;
		break;
	case ITEM_WILD_HELM:
		aktualny = new ItemZbroja;
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

Item* Gra::createItem(int id, ItemTyp typ, wstring nazwa, wstring opis, wstring idle, int atak, int obrona, int dmg, int ochrona, int pancerz, int hp, int cw, int wartosc, int wymSila, int wymZr, int wymZw, int wymWyt, int wymZyw)
{
	Item *temp = createItem(id, typ, nazwa, opis, idle, atak, obrona, dmg, ochrona, pancerz, hp, cw, wartosc);
	temp->ustaw_wymagania(wymSila, wymZr, wymZw, wymWyt, wymZyw);
	return temp;
}

Item* Gra::createItem(int id)
{
	ItemDzwignia *temp_dzwignia = NULL;
	using namespace ListaItemow;

	switch (id)
	{

#pragma region Bronie
#pragma region Prymitywne
	case Bronie::DragDrewniany:
		return createItem(Bronie::DragDrewniany, ITEM_2HWEAPON,
			L"drewniany dr�g",
			L"Ten kawa� kija wygl�da na oderwan� i wyschni�t� ga�� jakiego� drzewa. Nie jest on ca�kiem prosty, zawiera kilka s�k�w i nieregularno�ci ale jest d�ugi na kilka �okci i mo�e ca�kiem sprawnie pos�u�y� jako improwizowana bro�.",
			L"le�y u twoich st�p",
			2, 2, 2, 0, 0, 0, 0,
			1,
			0, 0, 0, 0, 0);
		break;
	case Bronie::KamienMaly:
		return createItem(Bronie::KamienMaly, ITEM_1HWEAPON,
			L"ma�y kamie�",
			L"Jest to zwyk�y szary kawa�ek kamienia, wielko�ci oko�o pi�ci doros�ego cz�owieka. Jego masa mo�e by� niebezpieczna w bliskim kontakcie, jednak ostre kraw�dzie s� niebezpieczne dla d�oni dzier��cego.",
			L"le�y na ziemi",
			-3, -3, 1, 0, 0, 0, 0,
			0);
		break;
	case Bronie::WloczniaMalaKrzemien:
		return createItem(id, ITEM_1HWEAPON,
			L"Prymitywna w��cznia",
			L"W��cznie s� jednymi z najstarszych typ�w broni stosowanych przez rasy rozumne. Prosty pomys� zwi�kszenia zasi�gu ostrza, poprzez umieszczenie go na drewnianym kiju daje u�ytkownikowi du�� przewag� zasi�gu, sam drzewiec mo�e by� r�wnie� �atwo u�yty w parowaniu cios�w. Ostrze jest jednak ma�e i nie jest zdolne wyrz�dzi� tak du�ych szk�d jak top�r czy miecz. W tym egzemplarzu ostrze jest wykonane z ociosanego krzemienia, ca�a konstrukcja jest bardzo prymitywna i wykonana prostymi metodami.",
			L"le�y na ziemi",
			3, 3, 2, 0, 5, 0, 0,
			2);
#pragma endregion


#pragma region Br�z
	case Bronie::MieczKrotkiBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"kr�tki miecz z br�zu",
			L"Miecze s� jedn� z najpowszechniejszych broni spotykanych w krainie. S� to no�e o podw�jnym i wyd�u�onym ostrzu, oraz z kling� przystosowan� do wygodnego dzier�enia oraz walki. Kr�tkie miecze maj� d�ugo�� oko�o p�torej �okcia, podw�jne zaostrzone ostrze, jednak z powodu ma�ej wagi najlepiej nadaj� si� do wykonywania pchni�� sztychem. R�koje�� jest kr�tka, jednor�czna a jelec prosty i ma�y. Miecz ten jest szybki jednak z powody ma�ej d�ugo�ci trudniej trafi� nim przeciwnika ni� odpowiednio d�u�szymi bronami.",
			L"le�y na ziemi",
			2, 4, 2, 0, 6, 0, 0,
			36,
			9, 6, 15, 6, 0);

	case Bronie::MieczBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"miecz z br�zu",
			L"Opis miecza z br�zu.",
			L"le�y na ziemi",
			4, 4, 3, 0, 0, 0, 0,
			48,
			16, 16, 16, 0, 0);

	case Bronie::ToporekBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"toporek z br�zu",
			L"Opis toporka z br�zu.",
			L"le�y na ziemi",
			4, 1, 3, 0, 3, 0, 0,
			36,
			15, 15, 3, 3, 0);

	case Bronie::MlotBojowyBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"m�ot bojowy z br�zu",
			L"Opis m�ota bojowego z br�zu.",
			L"le�y na ziemi",
			2, 0, 3, 0, 12, 0, 0,
			36,
			18, 6, 0, 12, 0);

	case Bronie::WloczniaBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"w��cznia z br�zu",
			L"Opis w��czni z br�zu.",
			L"le�y na ziemi",
			6, 6, 4, 0, 12, 0, 0,
			36,
			6, 12, 12, 6, 0);

#pragma endregion


#pragma endregion

#pragma region BronieDzikie
	case BronieDzikie::SzczurzeKly:
		return createItem(BronieDzikie::SzczurzeKly, ITEM_WILD_1HWEAPON,
			L"szczurze k�y",
			L"opis szczurzych k��w",
			L"le�� tutaj",
			3, 0, 1, 0, 0, 0, 0,
			1);
		break;

	case BronieDzikie::KlyOgara:
		return createItem(BronieDzikie::KlyOgara, ITEM_WILD_1HWEAPON,
			L"k�y ogara",
			L"opis k��w",
			L"le�� tutaj",
			10, 0, 5, 0, 0, 0, 0,
			20);
#pragma endregion

#pragma region Pancerze
#pragma region PancerzSkorzany
	case Pancerze::RekawiceSkora:
		return createItem(Pancerze::RekawiceSkora, ITEM_NARAMIENNIKI,
			L"sk�rzane naramienniki",
			L"Opis sk�rzanych naramiennik�w.",
			L"le�� tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::NaramiennikiSkora:
		return createItem(Pancerze::NaramiennikiSkora, ITEM_REKAWICE,
			L"lekkie sk�rzane r�kawiczki",
			L"Opis sk�rzanych r�kawiczek",
			L"le�� tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::NagolennikiSkora:
		return createItem(Pancerze::NagolennikiSkora, ITEM_NAGOLENNIKI,
			L"lekkie sk�rzane nagolenniki",
			L"Opis sk�rzanych nagolennik�w.",
			L"le�� tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::ButySkora:
		return createItem(Pancerze::ButySkora, ITEM_BUTY,
			L"sk�rzane trzewiki",
			L"Opis sk�rzanych but�w.",
			L"le�� tutaj",
			0, 2, 0, 35, 2, 2, 0,
			10);
		break;

	case Pancerze::ZbrojaSkora:
		return createItem(Pancerze::ZbrojaSkora, ITEM_ZBROJA,
			L"sk�rzany kaftan",
			L"Opis sk�rzanego kaftana",
			L"le�y tutaj",
			1, 1, 0, 35, 6, 2, 0,
			20);
		break;

	case Pancerze::HelmSkora:
		return createItem(Pancerze::HelmSkora, ITEM_HELM,
			L"sk�rzany kaptur",
			L"Opis sk�zanego kaptura.",
			L"le�y tutaj",
			1, 1, 0, 35, 4, 0, 0,
			10);
#pragma endregion

#pragma endregion

#pragma region PancerzeDzikie
	case PancerzeDzikie::SkoraSzczura:
		return createItem(PancerzeDzikie::SkoraSzczura, ITEM_WILD_ZBROJA,
			L"szczurza sk�ra",
			L"Opis sk�ry szczura.",
			L"le�y tutaj",
			2, 2, 0, 100, 6, 0, 0,
			2);
		break;

	case PancerzeDzikie::SkoraOgara:
		return createItem(PancerzeDzikie::SkoraOgara, ITEM_WILD_ZBROJA,
			L"sk�ra ogara",
			L"opis sk�ry ogara",
			L"le�y tutaj",
			0, 4, 0, 210, 37, 0, 0,
			5);

#pragma region Gobli�skie
	case PancerzeDzikie::ZbrojaGoblinGwadzista:
		return createItem(id, ITEM_WILD_ZBROJA,
			L"�mieciowy pancerz",
			L"Opis �mieciowego pancerza",
			L"le�y tutaj",
			1, 1, 0, 56, 10, 0, 0,
			20);
	case PancerzeDzikie::SpodnieGoblinBerserker:
		return createItem(id, ITEM_WILD_NAGOLENNIKI,
			L"ma�e sk�rzane spodnie",
			L"Opis spodni goblina",
			L"le�y tutaj",
			2, 3, 0, 36, 6, 0, 0,
			24);
	case PancerzeDzikie::ZbrojaGoblinSzaman:
		return createItem(id, ITEM_WILD_ZBROJA,
			L"str�j gobli�skiego szamana",
			L"Opis stroju gobli�skiego szamana",
			L"le�y tutaj",
			4, 2, 0, 36, 8, 0, 0,
			32);
	case PancerzeDzikie::HelmGoblinSzaman:
		return createItem(id, ITEM_WILD_HELM,
			L"nakrycie g��wy gobli�nkiego szamana",
			L"Opis okrycia g�owy gobli�skiego szamana",
			L"le�y tutaj",
			1, 3, 0, 56, 14, 0, 0,
			28);
#pragma endregion

#pragma endregion

#pragma region Pojemniki
	case Pojemniki::TorbaPodrozna:
		return createItem(Pojemniki::TorbaPodrozna, ITEM_CONTAINER,
			L"torba podr�na",
			L"Opis torby podr�nej.",
			L"le�y tutaj",
			0, 0, 0, 0, 0, 0, 0,
			2);
		break;

	case Pojemniki::StarySzkielet:
		return createItem(Pojemniki::StarySzkielet, ITEM_STATIC_CONTAINER,
			L"stary szkielet",
			L"Nie jeste� pewien jakiej rasy by� ten nieboszczyk, ale po wielko�ci i kszta�cie czaski domy�lasz si� i� m�g� to by� cz�owiek. Czas zostawi� sw�j �lad na ko�ciach- wida� na nich ubytki i wr�by. Nie zauwa�asz �adnych szczeg��w, kt�re by wskazywa�y na to jak zmar� jego posiadacz.",
			L"le�y pod �cian�",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Pojemniki::DrewnianaSkrzynia:
		return createItem(Pojemniki::DrewnianaSkrzynia, ITEM_STATIC_CONTAINER,
			L"drewniana skrzynia",
			L"Opis drewnianej skrzyni",
			L"stoi pod �cian�",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
#pragma endregion

#pragma region Questowe
	case Questowe::OkraglySzafir:
		return createItem(Questowe::OkraglySzafir, ITEM_QUEST,
			L"okr�g�y szafir",
			L"Szafir jest kamieniem szlachetnym o barwie ciemno niebieskiej. Zazwyczaj klejnoty szlifowane s� w sze�cienne lub inne kanciaste kszta�ty, ten jednak jest uformowany w kszta�t kuli. Przygl�daj�c si� bli�ej nie zauwa�asz �adnych �lad�w szlifowania, zachwyca ci� r�wnie� niezwyk�a perfekcja kuli.",
			L"le�y tutaj",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Questowe::KawalkiPotluczonegoSzkla:
		return createItem(Questowe::KawalkiPotluczonegoSzkla, ITEM_QUEST,
			L"kawa�ki pot�uczonego szk�a",
			L"Te kawa�ki pot�uczonego szk�a formowa�y kiedy� zapewne zgrabn� butelk�. Teraz jednak do niczego ju� si� nie przydadz�.",
			L"le�� na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Questowe::StluczoneLustro:
		return createItem(Questowe::StluczoneLustro, ITEM_STATIC_QUEST,
			L"st�uczone lustro",
			L"Przed tob� stoi wykonana z br�zu zdobiona oprawa lustra. Lustro by�o wykonane ze szk�a, kt�rego kawa�ki zalegaj� woko�o na pod�odze. Oprawa jest prostok�tna o wysoko�ci ma�ego cz�owieka. Jej kraw�dzie zajmuj� wykwintne zdobienia, w�r�d kt�rych najbardziej rzuca si� w oczy symbol czaski, umieszczony na samym szczycie oprawy.",
			L"stoi w k�cie",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
	case Questowe::ZardzewialyHelm:
		return createItem(Questowe::StluczoneLustro, ITEM_QUEST,
			L"zardzewia�y he�m",
			L"He�m ten nosi wszelkie znaki staro�ci i zu�ycia: jest pordzewia�y i pogi�ty a w jego czo�owej cz�ci znajduje si� du�a dziura. Pomijaj�c fakt, �e jest ma�y i nie pasowa�by na twoj� g�ow� i tak nie zapewni�by on �adnej u�yteczno�ci.",
			L"le�y na jednej z kurhan",
			0, 0, 0, 0, 0, 0, 0, 2);
	case Questowe::Mapa:
		return createItem(Questowe::Mapa, ITEM_QUEST,
			L"mapa",
			L"Mapa jest kawa�kiem wyprawianej sk�ry lub pergaminu. Powierzenie mu informacji o po�o�eniu interesuj�cych miejsc w terenie okaza�o si� lepszym pomys�em ni� powierzanie na zawodnej pami�ci. R�wnie� dla poszukiwaczy przyg�d rysowanie schemat�w przebytych miejsc okaza�o si� zbawienne w skomplikowanych labiryntach, b�d� grobowcach.",
			L"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 50);
#pragma endregion

#pragma region Klucze
	case Klucze::KluczZZelazaProsty:
		return createItem(Klucze::KluczZZelazaProsty, ITEM_QUEST,
			L"prosty klucz z �elaza",
			L"opis klucza do drewnianych skrzy�.",
			L"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
	case Klucze::KluczZBrazuLvl2:
		return createItem(Klucze::KluczZBrazuLvl2, ITEM_QUEST,
			L"zdobiony klucz z br�zu",
			L"opis klucza na poziom 2.",
			L"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
	case Klucze::KluczZSrebraLvl3:
		return createItem(Klucze::KluczZSrebraLvl3, ITEM_QUEST,
			L"zdobiony klucz ze srebra",
			L"opis klucza na poziom 3.",
			L"le�y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
#pragma endregion

#pragma region Dzwignie
	case Dzwignie::ButelkaPoWinie:
		return createItem(Dzwignie::ButelkaPoWinie, ITEM_DZWIGNIA,
			L"butelka po winie",
			L"Tajemnicza butelka le�y samotnie na swoim miejscu w stojaku. Rozgl�daj�c si� po piwniczce nie znalaz�e� �adnej innej butelki wi�c ta jedyna skupia twoj� ciekawo��. Wykonana jest z ciemnego, grubego szk�a, korek zatykaj�cy szyjk� gdzie� znikn�� wi�c jedyn� zawarto�ci� naczynia jest powietrze. Prub�jesz wyj�� butelk� ze stojaka, jednak ta nie chce si� ruszy� ani na w�os.",
			L"le�y samotnie na stojaku",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
#pragma endregion

#pragma region Consumables
	case Consumables::PsiaPurchawka:
		return new MiksturaZdarzeniaGlobalnego(id, ITEM_JEDZENIE,
			L"psia purchawka",
			L"Opis psiej purchawki.",
			L"ro�nie na ziemi",
			2,
			ListaZdarzenGlobalnych::ZjedzeniePurchawki);

	case Consumables::MiksturaSilySlaba:
		return new MiksturaStatusu(id,
			L"s�absza mikstura si�y",
			L"Opis mikstury si�y",
			L"le�y tutaj",
			15,
			new ZwiekszenieCechy(L"zwi�kszona si�a",
			L"Twoja si�a zosta�a zwi�kszona przez magiczn� mikstur�.",
			L"Czujesz przyjemne mrowienie w bicepsach.",
			L"Tajemnicze mrowienie usta�o.",
			ZRECZNOSC, 15, 120));
		break;

	case Consumables::MiksturaZrecznosciSlaba:
		return new MiksturaStatusu(Consumables::MiksturaZrecznosciSlaba,
			L"s�absza mikstura zr�czno�ci",
			L"Jak w przypadku wszystkich magicznych mikstur, ich zapach zmusza do d�u�szego przemy�lenia z jakich ohydno�ci zosta� przygotowany dany specyfik. Nikt jednak nie chcia�by zastanawia� si� nad tym przy obiedzie. W ka�dym razie etykieta tego specyfiku sugeruje i� d�onie pij�cego stan� si� szybkie i precyzyjne niczym w�e. Uwaga! Efekty uboczne obejmuj� niekontrolowan�  zmian� koloru w�os�w.",
			L"le�y tutaj",
			15,
			new ZwiekszenieCechy(L"zwi�kszona zr�czno��",
			L"Twoja zr�czno�� zosta�a zwi�kszona przez magiczn� mikstur�.",
			L"Czujesz w d�oniach dziwne mrowienie oraz ciep�o.",
			L"Tajemnicze ciep�o z d�oni odchodzi.",
			ZRECZNOSC, 15, 120));
		break;

	case Consumables::MiksturaZwinnosciSlaba:
		return new MiksturaStatusu(id,
			L"s�absza mikstura zwinno�ci",
			L"Opis mikstury zwinno�ci",
			L"le�y tutaj",
			15,
			new ZwiekszenieCechy(L"zwi�kszona zwinno��",
			L"Twoja zwinno�� zosta�a zwi�kszona przez magiczn� mikstur�.",
			L"Czujesz niezwyk�� lekko�� w nogach.",
			L"Tajemnicze lekko�� usta�a.",
			ZRECZNOSC, 15, 120));
		break;

	case Consumables::MiksturaWytrzymalosciSlaba:
		return new MiksturaStatusu(id,
			L"s�absza mikstura wytrzyma�o�ci",
			L"Opis mikstury wytrzyma�o�ci",
			L"le�y tutaj",
			15,
			new ZwiekszenieCechy(L"zwi�kszona wytrzyma�o��",
			L"Twoja wytrzyma�o�� zosta�a zwi�kszona przez magiczn� mikstur�.",
			L"Czujesz orze�wiaj�cy ch��d w ca�ym ciele.",
			L"Tajemniczy ch��d usta�.",
			ZRECZNOSC, 15, 120));
		break;

	case Consumables::MiksturaZywotnosciSlaba:
		return new MiksturaStatusu(id,
			L"s�absza mikstura �ywotno�ci",
			L"Opis mikstury �ywotno�ci",
			L"le�y tutaj",
			15,
			new ZwiekszenieCechy(L"zwi�kszona �ywotno��",
			L"Twoja �ywotno�� zosta�a zwi�kszona przez magiczn� mikstur�.",
			L"Czujesz dziwne odr�twienie na ca�ej sk�rze.",
			L"Tajemnicze odr�twienie usta�o",
			ZRECZNOSC, 15, 120));
		break;
#pragma endregion

#pragma region Magiczne
	case Magiczne::KoszulaLniana:
		return createItem(id, ITEM_KOSZULA,
			L"lniana koszula",
			L"Opis.",
			L"le�y na ziemi",
			4, 2, 0, 0, 10, 0, 0, 5);
	case Magiczne::SpodnieLniane:
		return createItem(id, ITEM_SPODNIE,
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

Item* Gra::createItem(vector<int> listaMozliwych)
{
	int wybrany = rzucaj(0, listaMozliwych.size() - 1);
	return(createItem(listaMozliwych[wybrany]));
}

ItemList Gra::createItemMany(int id, int ile)
{
	ItemList lista;
	for (int i = 0; i < ile; i++)
	{
		lista.dodaj(createItem(id));
	}
	return lista;
}