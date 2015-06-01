#include "Gra.h"
#include "Item.h"
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
	aktualny->zloto = 10 * poziom + rzucaj(5 * poziom);

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
	aktualny->zloto = 10 * poziom + rzucaj(5 * poziom);

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
	Kwestia* kwestia = NULL;
	ItemList przedmioty;
	switch (id)
	{

#pragma region szczur_jaskiniowy
	case ListaPostaci::SzczurJaskiniowy:
		temp = createChar(id, 1, RASA_SZCZUR, KLASA_BRAK,
			L"szczur jaskiniowy",
			L"Szczur jaskiniowy s¹ nieco wiêksze od szczurów miejskich, s¹ jednak "
			L"porównywalnie obrzydliwe. Bure, mokre futerko pokrywa prawie jedno ³okciowego "
			L"gryzonia, który skrzêtnie przeszukuje otoczenie w poszukiwaniu po¿ywienia. "
			L"Odg³os ma³ych pazurków uderzaj¹cych w kamienn¹ posadzkê towarzyszy ka¿demu "
			L"ruchowi szczura.",
			L"szpera dooko³a",
			5, 6, 6, 4, 3);
		temp->equip(createItem(BronieDzikie::SzczurzeKly));
		temp->zloto = 0;
		temp->equip(createItem(PancerzeDzikie::SkoraSzczura));
		return temp;
#pragma endregion

#pragma region zakapturzona_postac
	case ListaPostaci::ZakapturzonaPostac:
		temp = createNpc(id, 50, RASA_CZLOWIEK, KLASA_BRAK, L"zakapturzona postaæ",
			L"Wpatruj¹c siê w zakapturzonego cz³owieka nie dostrzegasz w nim nic "
			L"nadzwyczajnego. Nosi on d³ugie br¹zowe szaty, które dok³adnie zakrywaj¹ "
			L"jego cia³o. Kaptur ca³kowicie zas³ania mu twarz. Nieznajomy wpatruje siê "
			L"ca³y czas w pod³ogê, nie wykonuj¹c przy tym nawet najmniejszych ruchów.",
			L"wpatruje siê w pod³ogê",
			80, 80, 80, 80, 80);
		(dynamic_cast<PostacNpc*>(temp)->trening)[SILA] = 34;
		(dynamic_cast<PostacNpc*>(temp)->trening)[ZRECZNOSC] = 34;
		(dynamic_cast<PostacNpc*>(temp)->trening)[ZWINNOSC] = 34;
		(dynamic_cast<PostacNpc*>(temp)->trening)[WYTRZYMALOSC] = 34;
		(dynamic_cast<PostacNpc*>(temp)->trening)[ZYWOTNOSC] = 34;
		dynamic_cast<PostacNpc*>(temp)->rozmowny = true;
		temp->przedmioty->dodaj(createItem(Bronie::MieczKrotkiBraz));
		temp->przedmioty->dodaj(createItem(Klucze::KluczZBrazuLvl2));

		wczytajRozmowe(temp->id, dynamic_cast<PostacNpc*>(temp));

		return temp;

#pragma endregion

#pragma region test_NPC
	case ListaPostaci::TestNPC:
		temp = createNpc(id, 50, RASA_CZLOWIEK, KLASA_BRAK, L"test NPC",
			L"To tylko testowy NPC, nie oczekuj epickich opisów. "
			L"Jedyne czego mo¿esz siê spodziewaæ to sztucznie wyd³u¿one opisy "
			L"maj¹ce na celu sprawdzenie wersalikowania opisów postaci.",
			L"stoi i zachêca do rozmowy",
			80, 80, 80, 80, 80);

		temp->zloto = 100;
		(temp->przedmioty)->dodaj(createItem(Questowe::OkraglySzafir));

		wczytajRozmowe(temp->id, dynamic_cast<PostacNpc*>(temp));

		return temp;
#pragma endregion

	case ListaPostaci::Manekin:
		return createChar(id, 1, RASA_BRAK, KLASA_MNICH,
			L"manekin",
			L"Ta postac s³u¿y do przechowywania przedmiotów gracza na czas snu.",
			L"stoi w bezruchu",
			10, 10, 10, 10, 10);

	case ListaPostaci::OgarStrazniczy:
		temp = createChar(id, 10, RASA_OGAR, KLASA_BRAK,
			L"ogar stra¿niczy",
			L"Alan napisz opis.",
			L"szpera dooko³a",
			27, 26, 22, 21, 22);
		temp->agresywny = true;
		temp->equip(createItem(BronieDzikie::KlyOgara));
		temp->equip(createItem(PancerzeDzikie::SkoraOgara));
		temp->zloto = 0;
		return temp;

#pragma region Gobliny
	case ListaPostaci::GoblinZbieracz:
		temp = createChar(id, 2, RASA_GOBLIN, KLASA_ROBOTNIK,
			L"goblin zbieracz",
			L"Goblin ten jest przedstawicielem najni¿szej kasty w spo³eczeñstwie goblinów. Jak ka¿dy goblin ma on ciemno zielon¹ skórê, pokryt¹ licznymi zmarszczkami i bruzdami. Wysoki na oko³o dwa ³okcie, ma nieproporcjonalnie d³ugie rêce i du¿¹ g³owê raz pochylon¹ postawê. Jego twarz to g³ównie para wy³upiastych oczu, du¿y spiczasty nos, oraz równie du¿e i stercz¹ce na boki uszy. Zbieracz ubrany jest w jedynie stary, lniany wór, którego równie¿ u¿ywa do przechowywania zebranych grzybów.",
			L"rozgl¹da siê dooko³a",
			7, 9, 9, 10, 7);
		temp->equip(createItem(Bronie::KamienMaly));
		//temp->equip(createItem(PancerzeDzikie::Szmaty));
		temp->zloto = rzucaj(2) + 1;
		przedmioty = createItemMany(Consumables::PsiaPurchawka, rzucaj(0, 2));
		temp->przedmioty->przenies(&przedmioty);
		return temp;

	case ListaPostaci::GoblinGwardzista:
		temp = createChar(id, 3, RASA_GOBLIN, KLASA_GWARDZISTA,
			L"goblin gwardzista",
			L"Zadaniem gobliñskich gwardzistów jest pilnowanie obozowiska, oraz alarmowanie o zbli¿aj¹cym siê zagro¿eniu. Ich ubiór stanowi najciê¿szy pancerz jaki mo¿na znaleŸæ wœród goblinów- daje to wiêksz¹ szansê na wydanie alarmuj¹cego okrzyku zanim gwardzista siê zu¿yje. Jego zbrojê stanowi¹ metalowe przedmioty zrabowane od ludzi- garnki, p³ytki, kawa³ki w³aœciwych zbroi lub kolczug, czy tarcz, powi¹zane razem linami b¹dŸ paskami. Co do reszty wygl¹du to gobliñscy gwardziœci s¹ równie paskudni co reszta przedstawicieli ich rasy.",
			L"opiera siê na w³óczni",
			12, 14, 12, 14, 12);
		temp->equip(createItem(Bronie::WloczniaMalaKrzemien));
		temp->equip(createItem(PancerzeDzikie::ZbrojaGoblinGwadzista));
		return temp;

	case ListaPostaci::GoblinBerserker:
		temp = createChar(id, 4, RASA_GOBLIN, KLASA_BERSERKER,
			L"goblin berserker",
			L"Berserkerzy nale¿¹ do najzdolniejszych wojowników wœród gobliñskiego plemienia. Za ubranie s³u¿¹ im jedynie skurzane spodnie, wytworzone rêcznie ze skóry jednej ze swoich ofiar. Ich odkryt¹ klatê ozdabiaj¹ im blizny a twarzy zazwyczaj brakuje jednego ucha, nosa, b¹dŸ oka. Pe³ni dumy berserkerzy zachowuj¹ siê pogardliwie do innych goblinów oraz ogólnie do innych stworzeñ. Maj¹ szacunek jedynie do szamana, stanowi¹c jego osobist¹ ochronê.",
			L"bacznie siê tobie przygl¹da",
			14, 16, 14, 10, 15);
		temp->equip(createItem(Bronie::ToporekBraz));
		temp->equip(createItem(PancerzeDzikie::SpodnieGoblinBerserker));
		return temp;

	case ListaPostaci::GoblinSzaman:
		temp = createNpc(id, 5, RASA_GOBLIN, KLASA_MNICH,
			L"goblin szaman",
			L"Szamani s¹ jednoczeœnie przywódcami goblinœkiego plemienia. Ich wygl¹d ma u reszty goblinów wywo³aæ strach przed mocami dysponowanymi przez szamana, nawet je¿eli takowych on nie ma. Jego cia³o jest pokryte dziwnymi tatua¿ami i malunkami z b³ota i krwi a w uszach i nosie ma mnóstwo kolczyków. Jego szata jest gruba i wykonana z lnu. Wszyto w ni¹ kawa³ki zwierzêcego futra, oraz namalowano jakimiœ barwnikami dziwne symbole. Na szyi szaman nosi naszyjnik z rzemienia, oraz zwierzêcych koœci, a na g³owie nosi koronê wykonan¹ z poro¿a jelenia. Szaman stara siê robiæ mistyczne wra¿enie, machaj¹c co chwila rêkami oraz podskakuj¹c bez powodu.",
			L"nerwowo rozgl¹da siê dooko³a",
			13, 14, 14, 18, 19);
		wczytajRozmowe(id, dynamic_cast<PostacNpc*>(temp));
		dynamic_cast<PostacNpc*>(temp)->rozmowny = true;
		temp->equip(createItem(Bronie::DragDrewniany));
		temp->equip(createItem(PancerzeDzikie::ZbrojaGoblinSzaman));
		temp->equip(createItem(PancerzeDzikie::HelmGoblinSzaman));
		temp->przedmioty->dodaj(createItem(Klucze::KluczZSrebraLvl3));
		return temp;

#pragma endregion

#pragma region Sen 1

	case ListaPostaci::Cz³owiekZTlumu:
		temp = createNpc(id, 1, RASA_CZLOWIEK, KLASA_ROBOTNIK,
			L"cz³owiek z t³umu",
			L"Cz³owiek ten jest zwrócony do ciebie ty³em i podobnie jak reszta t³umu krzyczy coœ i macha rêkami. Próbujesz siê mu przyjrzeæ jednak jedyne co zauwa¿asz, to ¿e wygl¹da on… zwyczajnie. Nie potrafisz dostrzec nic szczególnego w jego wygl¹dzie.",
			L"krzyczy i wymachuje rêkami",
			10, 10, 10, 10, 10);
		wczytajRozmowe(temp->id, dynamic_cast<PostacNpc*>(temp));
		return temp;

	case ListaPostaci::Kucharka:
		temp = createNpc(id, 1, RASA_CZLOWIEK, KLASA_ROBOTNIK,
			L"kucharka",
			L"Kucharka posiada wszelkie stereotypowe cechy wygl¹du swojej profesji. Jest gruba, stara i ubrana w bia³y fartuch. Próbujesz siê jej lepiej przyjrzeæ jednak coœ ciê rozprasza i zwracasz wzrok gdzieœ indziej. Kucharka wykonuje dalej swoj¹ pracê nie zwracaj¹c na ciebie najmniejszej uwagi.",
			L"krzêta siê po kuchni",
			10, 10, 10, 10, 10);
		wczytajRozmowe(id, dynamic_cast<PostacNpc*>(temp));
		temp->ustawRozmowny(true);
		return temp;

#pragma endregion

#pragma region Grzybnie

	case ListaPostaci::GrzybniaMala:
		temp = createChar(id, 3, RASA_GRZYBNIA, KLASA_ROBOTNIK,
			L"ma³a ¿ywa grzybnia",
			L"Opis ma³ej grzybni.",
			L"stoi bez ruchu",
			1, 1, 1, 1, 1);
		return temp;

#pragma endregion
	default:
		throw new wstring(L"BUONT! niepoprawny int dla createChar");
	}


}