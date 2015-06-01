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
			L"drewniany dr¹g",
			L"Ten kawa³ kija wygl¹da na oderwan¹ i wyschniêt¹ ga³êŸ jakiegoœ drzewa. Nie jest on ca³kiem prosty, zawiera kilka sêków i nieregularnoœci ale jest d³ugi na kilka ³okci i mo¿e ca³kiem sprawnie pos³u¿yæ jako improwizowana broñ.",
			L"le¿y u twoich stóp",
			2, 2, 2, 0, 0, 0, 0,
			1,
			0, 0, 0, 0, 0);
		break;
	case Bronie::KamienMaly:
		return createItem(Bronie::KamienMaly, ITEM_1HWEAPON,
			L"ma³y kamieñ",
			L"Jest to zwyk³y szary kawa³ek kamienia, wielkoœci oko³o piêœci doros³ego cz³owieka. Jego masa mo¿e byæ niebezpieczna w bliskim kontakcie, jednak ostre krawêdzie s¹ niebezpieczne dla d³oni dzier¿¹cego.",
			L"le¿y na ziemi",
			-3, -3, 1, 0, 0, 0, 0,
			0);
		break;
	case Bronie::WloczniaMalaKrzemien:
		return createItem(id, ITEM_1HWEAPON,
			L"Prymitywna w³ócznia",
			L"W³ócznie s¹ jednymi z najstarszych typów broni stosowanych przez rasy rozumne. Prosty pomys³ zwiêkszenia zasiêgu ostrza, poprzez umieszczenie go na drewnianym kiju daje u¿ytkownikowi du¿¹ przewagê zasiêgu, sam drzewiec mo¿e byæ równie¿ ³atwo u¿yty w parowaniu ciosów. Ostrze jest jednak ma³e i nie jest zdolne wyrz¹dziæ tak du¿ych szkód jak topór czy miecz. W tym egzemplarzu ostrze jest wykonane z ociosanego krzemienia, ca³a konstrukcja jest bardzo prymitywna i wykonana prostymi metodami.",
			L"le¿y na ziemi",
			3, 3, 2, 0, 5, 0, 0,
			2);
#pragma endregion


#pragma region Br¹z
	case Bronie::MieczKrotkiBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"krótki miecz z br¹zu",
			L"Miecze s¹ jedn¹ z najpowszechniejszych broni spotykanych w krainie. S¹ to no¿e o podwójnym i wyd³u¿onym ostrzu, oraz z kling¹ przystosowan¹ do wygodnego dzier¿enia oraz walki. Krótkie miecze maj¹ d³ugoœæ oko³o pó³torej ³okcia, podwójne zaostrzone ostrze, jednak z powodu ma³ej wagi najlepiej nadaj¹ siê do wykonywania pchniêæ sztychem. Rêkojeœæ jest krótka, jednorêczna a jelec prosty i ma³y. Miecz ten jest szybki jednak z powody ma³ej d³ugoœci trudniej trafiæ nim przeciwnika ni¿ odpowiednio d³u¿szymi bronami.",
			L"le¿y na ziemi",
			2, 4, 2, 0, 6, 0, 0,
			36,
			9, 6, 15, 6, 0);

	case Bronie::MieczBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"miecz z br¹zu",
			L"Opis miecza z br¹zu.",
			L"le¿y na ziemi",
			4, 4, 3, 0, 0, 0, 0,
			48,
			16, 16, 16, 0, 0);

	case Bronie::ToporekBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"toporek z br¹zu",
			L"Opis toporka z br¹zu.",
			L"le¿y na ziemi",
			4, 1, 3, 0, 3, 0, 0,
			36,
			15, 15, 3, 3, 0);

	case Bronie::MlotBojowyBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"m³ot bojowy z br¹zu",
			L"Opis m³ota bojowego z br¹zu.",
			L"le¿y na ziemi",
			2, 0, 3, 0, 12, 0, 0,
			36,
			18, 6, 0, 12, 0);

	case Bronie::WloczniaBraz:
		return createItem(Bronie::MieczKrotkiBraz, ITEM_1HWEAPON,
			L"w³ócznia z br¹zu",
			L"Opis w³óczni z br¹zu.",
			L"le¿y na ziemi",
			6, 6, 4, 0, 12, 0, 0,
			36,
			6, 12, 12, 6, 0);

#pragma endregion


#pragma endregion

#pragma region BronieDzikie
	case BronieDzikie::SzczurzeKly:
		return createItem(BronieDzikie::SzczurzeKly, ITEM_WILD_1HWEAPON,
			L"szczurze k³y",
			L"opis szczurzych k³ów",
			L"le¿¹ tutaj",
			3, 0, 1, 0, 0, 0, 0,
			1);
		break;

	case BronieDzikie::KlyOgara:
		return createItem(BronieDzikie::KlyOgara, ITEM_WILD_1HWEAPON,
			L"k³y ogara",
			L"opis k³ów",
			L"le¿¹ tutaj",
			10, 0, 5, 0, 0, 0, 0,
			20);
#pragma endregion

#pragma region Pancerze
#pragma region PancerzSkorzany
	case Pancerze::RekawiceSkora:
		return createItem(Pancerze::RekawiceSkora, ITEM_NARAMIENNIKI,
			L"skórzane naramienniki",
			L"Opis skórzanych naramienników.",
			L"le¿¹ tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::NaramiennikiSkora:
		return createItem(Pancerze::NaramiennikiSkora, ITEM_REKAWICE,
			L"lekkie skórzane rêkawiczki",
			L"Opis skórzanych rêkawiczek",
			L"le¿¹ tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::NagolennikiSkora:
		return createItem(Pancerze::NagolennikiSkora, ITEM_NAGOLENNIKI,
			L"lekkie skórzane nagolenniki",
			L"Opis skórzanych nagolenników.",
			L"le¿¹ tutaj",
			2, 2, 0, 35, 4, 2, 0,
			10);
		break;

	case Pancerze::ButySkora:
		return createItem(Pancerze::ButySkora, ITEM_BUTY,
			L"skórzane trzewiki",
			L"Opis skórzanych butów.",
			L"le¿¹ tutaj",
			0, 2, 0, 35, 2, 2, 0,
			10);
		break;

	case Pancerze::ZbrojaSkora:
		return createItem(Pancerze::ZbrojaSkora, ITEM_ZBROJA,
			L"skórzany kaftan",
			L"Opis skórzanego kaftana",
			L"le¿y tutaj",
			1, 1, 0, 35, 6, 2, 0,
			20);
		break;

	case Pancerze::HelmSkora:
		return createItem(Pancerze::HelmSkora, ITEM_HELM,
			L"skórzany kaptur",
			L"Opis skózanego kaptura.",
			L"le¿y tutaj",
			1, 1, 0, 35, 4, 0, 0,
			10);
#pragma endregion

#pragma endregion

#pragma region PancerzeDzikie
	case PancerzeDzikie::SkoraSzczura:
		return createItem(PancerzeDzikie::SkoraSzczura, ITEM_WILD_ZBROJA,
			L"szczurza skóra",
			L"Opis skóry szczura.",
			L"le¿y tutaj",
			2, 2, 0, 100, 6, 0, 0,
			2);
		break;

	case PancerzeDzikie::SkoraOgara:
		return createItem(PancerzeDzikie::SkoraOgara, ITEM_WILD_ZBROJA,
			L"skóra ogara",
			L"opis skóry ogara",
			L"le¿y tutaj",
			0, 4, 0, 210, 37, 0, 0,
			5);

#pragma region Gobliñskie
	case PancerzeDzikie::ZbrojaGoblinGwadzista:
		return createItem(id, ITEM_WILD_ZBROJA,
			L"œmieciowy pancerz",
			L"Opis œmieciowego pancerza",
			L"le¿y tutaj",
			1, 1, 0, 56, 10, 0, 0,
			20);
	case PancerzeDzikie::SpodnieGoblinBerserker:
		return createItem(id, ITEM_WILD_NAGOLENNIKI,
			L"ma³e skórzane spodnie",
			L"Opis spodni goblina",
			L"le¿y tutaj",
			2, 3, 0, 36, 6, 0, 0,
			24);
	case PancerzeDzikie::ZbrojaGoblinSzaman:
		return createItem(id, ITEM_WILD_ZBROJA,
			L"strój gobliñskiego szamana",
			L"Opis stroju gobliñskiego szamana",
			L"le¿y tutaj",
			4, 2, 0, 36, 8, 0, 0,
			32);
	case PancerzeDzikie::HelmGoblinSzaman:
		return createItem(id, ITEM_WILD_HELM,
			L"nakrycie g³ówy gobliœnkiego szamana",
			L"Opis okrycia g³owy gobliñskiego szamana",
			L"le¿y tutaj",
			1, 3, 0, 56, 14, 0, 0,
			28);
#pragma endregion

#pragma endregion

#pragma region Pojemniki
	case Pojemniki::TorbaPodrozna:
		return createItem(Pojemniki::TorbaPodrozna, ITEM_CONTAINER,
			L"torba podró¿na",
			L"Opis torby podró¿nej.",
			L"le¿y tutaj",
			0, 0, 0, 0, 0, 0, 0,
			2);
		break;

	case Pojemniki::StarySzkielet:
		return createItem(Pojemniki::StarySzkielet, ITEM_STATIC_CONTAINER,
			L"stary szkielet",
			L"Nie jesteœ pewien jakiej rasy by³ ten nieboszczyk, ale po wielkoœci i kszta³cie czaski domyœlasz siê i¿ móg³ to byæ cz³owiek. Czas zostawi³ swój œlad na koœciach- widaæ na nich ubytki i wrêby. Nie zauwa¿asz ¿adnych szczegó³ów, które by wskazywa³y na to jak zmar³ jego posiadacz.",
			L"le¿y pod œcian¹",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Pojemniki::DrewnianaSkrzynia:
		return createItem(Pojemniki::DrewnianaSkrzynia, ITEM_STATIC_CONTAINER,
			L"drewniana skrzynia",
			L"Opis drewnianej skrzyni",
			L"stoi pod œcian¹",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
#pragma endregion

#pragma region Questowe
	case Questowe::OkraglySzafir:
		return createItem(Questowe::OkraglySzafir, ITEM_QUEST,
			L"okr¹g³y szafir",
			L"Szafir jest kamieniem szlachetnym o barwie ciemno niebieskiej. Zazwyczaj klejnoty szlifowane s¹ w szeœcienne lub inne kanciaste kszta³ty, ten jednak jest uformowany w kszta³t kuli. Przygl¹daj¹c siê bli¿ej nie zauwa¿asz ¿adnych œladów szlifowania, zachwyca ciê równie¿ niezwyk³a perfekcja kuli.",
			L"le¿y tutaj",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Questowe::KawalkiPotluczonegoSzkla:
		return createItem(Questowe::KawalkiPotluczonegoSzkla, ITEM_QUEST,
			L"kawa³ki pot³uczonego szk³a",
			L"Te kawa³ki pot³uczonego szk³a formowa³y kiedyœ zapewne zgrabn¹ butelkê. Teraz jednak do niczego ju¿ siê nie przydadz¹.",
			L"le¿¹ na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;

	case Questowe::StluczoneLustro:
		return createItem(Questowe::StluczoneLustro, ITEM_STATIC_QUEST,
			L"st³uczone lustro",
			L"Przed tob¹ stoi wykonana z br¹zu zdobiona oprawa lustra. Lustro by³o wykonane ze szk³a, którego kawa³ki zalegaj¹ woko³o na pod³odze. Oprawa jest prostok¹tna o wysokoœci ma³ego cz³owieka. Jej krawêdzie zajmuj¹ wykwintne zdobienia, wœród których najbardziej rzuca siê w oczy symbol czaski, umieszczony na samym szczycie oprawy.",
			L"stoi w k¹cie",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
	case Questowe::ZardzewialyHelm:
		return createItem(Questowe::StluczoneLustro, ITEM_QUEST,
			L"zardzewia³y he³m",
			L"He³m ten nosi wszelkie znaki staroœci i zu¿ycia: jest pordzewia³y i pogiêty a w jego czo³owej czêœci znajduje siê du¿a dziura. Pomijaj¹c fakt, ¿e jest ma³y i nie pasowa³by na twoj¹ g³owê i tak nie zapewni³by on ¿adnej u¿ytecznoœci.",
			L"le¿y na jednej z kurhan",
			0, 0, 0, 0, 0, 0, 0, 2);
	case Questowe::Mapa:
		return createItem(Questowe::Mapa, ITEM_QUEST,
			L"mapa",
			L"Mapa jest kawa³kiem wyprawianej skóry lub pergaminu. Powierzenie mu informacji o po³o¿eniu interesuj¹cych miejsc w terenie okaza³o siê lepszym pomys³em ni¿ powierzanie na zawodnej pamiêci. Równie¿ dla poszukiwaczy przygód rysowanie schematów przebytych miejsc okaza³o siê zbawienne w skomplikowanych labiryntach, b¹dŸ grobowcach.",
			L"le¿y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 50);
#pragma endregion

#pragma region Klucze
	case Klucze::KluczZZelazaProsty:
		return createItem(Klucze::KluczZZelazaProsty, ITEM_QUEST,
			L"prosty klucz z ¿elaza",
			L"opis klucza do drewnianych skrzyñ.",
			L"le¿y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
	case Klucze::KluczZBrazuLvl2:
		return createItem(Klucze::KluczZBrazuLvl2, ITEM_QUEST,
			L"zdobiony klucz z br¹zu",
			L"opis klucza na poziom 2.",
			L"le¿y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
	case Klucze::KluczZSrebraLvl3:
		return createItem(Klucze::KluczZSrebraLvl3, ITEM_QUEST,
			L"zdobiony klucz ze srebra",
			L"opis klucza na poziom 3.",
			L"le¿y na ziemi",
			0, 0, 0, 0, 0, 0, 0, 0);
#pragma endregion

#pragma region Dzwignie
	case Dzwignie::ButelkaPoWinie:
		return createItem(Dzwignie::ButelkaPoWinie, ITEM_DZWIGNIA,
			L"butelka po winie",
			L"Tajemnicza butelka le¿y samotnie na swoim miejscu w stojaku. Rozgl¹daj¹c siê po piwniczce nie znalaz³eœ ¿adnej innej butelki wiêc ta jedyna skupia twoj¹ ciekawoœæ. Wykonana jest z ciemnego, grubego szk³a, korek zatykaj¹cy szyjkê gdzieœ znikn¹³ wiêc jedyn¹ zawartoœci¹ naczynia jest powietrze. Prubójesz wyj¹æ butelkê ze stojaka, jednak ta nie chce siê ruszyæ ani na w³os.",
			L"le¿y samotnie na stojaku",
			0, 0, 0, 0, 0, 0, 0, 0);
		break;
#pragma endregion

#pragma region Consumables
	case Consumables::PsiaPurchawka:
		return new MiksturaZdarzeniaGlobalnego(id, ITEM_JEDZENIE,
			L"psia purchawka",
			L"Opis psiej purchawki.",
			L"roœnie na ziemi",
			2,
			ListaZdarzenGlobalnych::ZjedzeniePurchawki);

	case Consumables::MiksturaSilySlaba:
		return new MiksturaStatusu(id,
			L"s³absza mikstura si³y",
			L"Opis mikstury si³y",
			L"le¿y tutaj",
			15,
			new ZwiekszenieCechy(L"zwiêkszona si³a",
			L"Twoja si³a zosta³a zwiêkszona przez magiczn¹ miksturê.",
			L"Czujesz przyjemne mrowienie w bicepsach.",
			L"Tajemnicze mrowienie usta³o.",
			ZRECZNOSC, 15, 120));
		break;

	case Consumables::MiksturaZrecznosciSlaba:
		return new MiksturaStatusu(Consumables::MiksturaZrecznosciSlaba,
			L"s³absza mikstura zrêcznoœci",
			L"Jak w przypadku wszystkich magicznych mikstur, ich zapach zmusza do d³u¿szego przemyœlenia z jakich ohydnoœci zosta³ przygotowany dany specyfik. Nikt jednak nie chcia³by zastanawiaæ siê nad tym przy obiedzie. W ka¿dym razie etykieta tego specyfiku sugeruje i¿ d³onie pij¹cego stan¹ siê szybkie i precyzyjne niczym wê¿e. Uwaga! Efekty uboczne obejmuj¹ niekontrolowan¹  zmianê koloru w³osów.",
			L"le¿y tutaj",
			15,
			new ZwiekszenieCechy(L"zwiêkszona zrêcznoœæ",
			L"Twoja zrêcznoœæ zosta³a zwiêkszona przez magiczn¹ miksturê.",
			L"Czujesz w d³oniach dziwne mrowienie oraz ciep³o.",
			L"Tajemnicze ciep³o z d³oni odchodzi.",
			ZRECZNOSC, 15, 120));
		break;

	case Consumables::MiksturaZwinnosciSlaba:
		return new MiksturaStatusu(id,
			L"s³absza mikstura zwinnoœci",
			L"Opis mikstury zwinnoœci",
			L"le¿y tutaj",
			15,
			new ZwiekszenieCechy(L"zwiêkszona zwinnoœæ",
			L"Twoja zwinnoœæ zosta³a zwiêkszona przez magiczn¹ miksturê.",
			L"Czujesz niezwyk³¹ lekkoœæ w nogach.",
			L"Tajemnicze lekkoœæ usta³a.",
			ZRECZNOSC, 15, 120));
		break;

	case Consumables::MiksturaWytrzymalosciSlaba:
		return new MiksturaStatusu(id,
			L"s³absza mikstura wytrzyma³oœci",
			L"Opis mikstury wytrzyma³oœci",
			L"le¿y tutaj",
			15,
			new ZwiekszenieCechy(L"zwiêkszona wytrzyma³oœæ",
			L"Twoja wytrzyma³oœæ zosta³a zwiêkszona przez magiczn¹ miksturê.",
			L"Czujesz orzeŸwiaj¹cy ch³ód w ca³ym ciele.",
			L"Tajemniczy ch³ód usta³.",
			ZRECZNOSC, 15, 120));
		break;

	case Consumables::MiksturaZywotnosciSlaba:
		return new MiksturaStatusu(id,
			L"s³absza mikstura ¿ywotnoœci",
			L"Opis mikstury ¿ywotnoœci",
			L"le¿y tutaj",
			15,
			new ZwiekszenieCechy(L"zwiêkszona ¿ywotnoœæ",
			L"Twoja ¿ywotnoœæ zosta³a zwiêkszona przez magiczn¹ miksturê.",
			L"Czujesz dziwne odrêtwienie na ca³ej skórze.",
			L"Tajemnicze odrêtwienie usta³o",
			ZRECZNOSC, 15, 120));
		break;
#pragma endregion

#pragma region Magiczne
	case Magiczne::KoszulaLniana:
		return createItem(id, ITEM_KOSZULA,
			L"lniana koszula",
			L"Opis.",
			L"le¿y na ziemi",
			4, 2, 0, 0, 10, 0, 0, 5);
	case Magiczne::SpodnieLniane:
		return createItem(id, ITEM_SPODNIE,
			L"lniane spodnie",
			L"Opis.",
			L"le¿y na ziemi",
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