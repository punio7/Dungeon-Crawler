#include "gra.h"
#include "PostacNpc.h"
#include "Rozmowa.h"
#include "Kwestia.h"
#include "ListaItemow.h"
#include "ListaPostaci.h"
#include "ListaQuestow.h"
#include "ListaZdarzenGlobalnych.h"

using namespace ListaItemow;

enum RozmowaSpecjanleWartosci
{
	KoniecRozmowyWalka = -2,
	KoniecRozmowy = -1
};

void Gra::wczytajRozmowe(int id, PostacNpc* postac)
{
	Kwestia* kwestia = NULL;
	postac->rozmowa = new Rozmowa();
	wstring temp; //do przechowywania pomocniczych tekstów

	switch (id)
	{
#pragma region zakapturzona_postac
	case ListaPostaci::ZakapturzonaPostac:
		postac->rozmowa->obecnaKwestia = 2;

		kwestia = new Kwestia(1, 1,
			L"Witaj, czego ci trzeba?");
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê.", -1);
		kwestia->dodajOdpowiedz(L"Zabi³em szczury w piwniczce, tak jak chcia³eœ.", 12)
			->DodajWymaganieQuestFaza(ListaQuestow::TajemniczyNieznajomy, { 2 });
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			L"Na œrodku pomieszczenia stoi tajemnicza osoba ubrana w d³ug¹ szatê. "
			L"Kaptur ca³kowicie zas³ania jej twarz. Kiedy tylko ciê zauwa¿a odzywa siê: "
			L"\"Witaj " + gracz.imie + L"\".");
		kwestia->dodajOdpowiedz(L"\"Kim jesteœ?\"", 3);
		kwestia->dodajOdpowiedz(L"\"Sk¹d znasz moje imiê?\"", 4);
		kwestia->dodajOdpowiedz(L"\"Gdzie ja jestem?\"", 5);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(3, 3,
			L"\"Moje imiê jest niewa¿ne, jestem tylko s³ug¹ i spe³niam swoje obowi¹zki."
			L"Jestem tu aby ciê obserwowaæ i pomagaæ ci. Chcia³bym abyœ wykona³ dla mnie "
			L"pewne zadanie.\"");
		kwestia->dodajOdpowiedz(L"\"Sk¹d znasz moje imiê?\"", 4);
		kwestia->dodajOdpowiedz(L"\"Gdzie ja jestem?\"", 5);
		kwestia->dodajOdpowiedz(L"\"Jakie zadanie?\"", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(4, 4,
			L"\"Wiem o tobie znacznie wiêcej, ale nie wiêcej ni¿ jest mi to potrzebne aby móc "
			L"ci s³u¿yæ pomoc¹. Chcia³bym abyœ wykona³ da mnie pewne zadanie.\"");
		kwestia->dodajOdpowiedz(L"\"Kim jesteœ?\"", 3);
		kwestia->dodajOdpowiedz(L"\"Gdzie ja jestem?\"", 5);
		kwestia->dodajOdpowiedz(L"\"Jakie zadanie?\"", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(5, 5,
			L"\"Jesteœ w podziemiach pewnej wie¿y. Jedyne wyjœcie to klapa nad nami, niestety "
			L"w³aœciciel wie¿y zamkn¹³ j¹ na amen.\"");
		kwestia->dodajOdpowiedz(L"\"Wiêc jak siê st¹d wydostaæ?\"", 6);
		kwestia->dodajOdpowiedz(L"\"Co to za wie¿a?\"", 7);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(6, 6,
			L"\"Wydostanie siê st¹d nie bêdzie ³atwe, ale pomogê ci. Najpierw musisz jednak "
			L"wype³niæ pewne zadanie.\"");
		kwestia->dodajOdpowiedz(L"\"Kim jesteœ?\"", 3);
		kwestia->dodajOdpowiedz(L"\"Sk¹d znasz moje imiê?\"", 4);
		kwestia->dodajOdpowiedz(L"\"Jakie zadanie?\"", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(7, 7,
			L"„Z czasem siê dowiesz.”");
		kwestia->dodajOdpowiedz(L"\"Kim jest w³aœciciel wierzy?\"", 7);
		kwestia->dodajOdpowiedz(L"\"Wiêc jak siê st¹d wydostaæ?\"", 6);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(8, 8,
			L"\"Kiedyœ by³eœ wielkim wojownikiem. Chc¹c wydostaæ siê z tego miejsca bêdziesz "
			L"musia³ przypomnieæ sobie jak walczyæ. Chcê abyœ znalaz³ sobie jak¹œ broñ i "
			L"zabi³ wszystkie szczury w pomieszczeniu za moimi plecami.\"");
		kwestia->dodajOdpowiedz(L"\"Szczury?\"", 9);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(9, 9,
			L"\"Tak, szczury. Chcê siê upewniæ, ¿e nadal wiesz jak walczyæ, zanim staniesz "
			L"przed wiêkszymi wyzwaniami.\"");
		kwestia->dodajNagrodeQuestFaza(1, 1);
		kwestia->dodajOdpowiedz(L"\"Dobrze, zrobiê to.\"", 10);
		kwestia->dodajOdpowiedz(L"\"Szczury nie s¹ dla mnie wyzwaniem.\"", 10);
		kwestia->dodajOdpowiedz(L"\"Nie mam ochoty bawiæ siê w zabijanie jakichœ szczurów.\"", 11, -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(10, 1,
			L"\"W takim razie idŸ i je zabij. Poczekam tutaj na ciebie.\"");
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê.", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(11, 1,
			L"\"Ale i tak to zrobisz. Poczekam tutaj a¿ skoñczysz.\"");
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê.", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(12, 12,
			L"\"Dobrze. Zapewne masz du¿o pytañ dotycz¹cych siebie, tego miejsca i ca³ej "
			L"tej sytuacji. Niestety teraz nie mogê ci powiedzieæ du¿o wiêcej ponadto co ci ju¿ powiedzia³em.\"");
		kwestia->dodajNagrodeGraczDoswiadczenie(5);
		kwestia->dodajOdpowiedz(L"\"Dlaczego nie mo¿esz mi nic powiedzieæ?\"", 13);
		kwestia->dodajOdpowiedz(L"\"Nie mo¿esz czy raczej nie chcesz?\"", 14);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(13, 13,
			L"\"Jestem zwi¹zany przysiêg¹ wobec tych, którym s³u¿ê. Odpowiem ci na wszystkie pytania kiedy oni stwierdz¹ i¿ nadszed³ czas.\"");
		kwestia->dodajOdpowiedz(L"\"W takim razie pomówmy o tym jak siê st¹d wydostaæ.\"", 15);
		kwestia->dodajOdpowiedz(L"\"Gówno mnie obchodz¹ jakieœ durne przysiêgi. Chcê wiedzieæ co siê tu u diab³a dzieje!\"", 17);
		kwestia->dodajOdpowiedz(L"\"Komu s³u¿ysz?\"", 16);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(14, 14,
			L"\"I to i to po czêœci. Jestem tu z obowi¹zku i nie darzê ciê zbytni¹ sympati¹. Zw³aszcza zwa¿ywszy na to kim by³eœ w przesz³oœci.\"");
		kwestia->dodajOdpowiedz(L"\"W takim razie pomówmy o tym jak siê st¹d wydostaæ.\"", 15);
		kwestia->dodajOdpowiedz(L"\"A kim by³em?\"", 16);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(15, 15,
			L"\"Dobrze. Znajdujemy siê w podziemiach wie¿y pewnego maga. Stworzy³ on rozbudowany system lochów, L"
			L"chroni¹cych dostêp do jego laboratorium na samym dole. Jedynie on posiada klucz otwieraj¹cy "
			L"wyjœcie na powierzchniê. Je¿eli chcesz st¹d uciec, bêdziesz musia³ go zdobyæ.\"");
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(16, 16,
			L"\"Wszystkiego dowiesz siê w swoim czasie.\"");
		kwestia->dodajOdpowiedz(L"\"W takim razie pomówmy o tym jak siê st¹d wydostaæ.\"", 15);
		kwestia->dodajOdpowiedz(L"\"Przestañ pierdoliæ i zacznij gadaæ jak cz³owiek.\"", 17);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(17, 17,
			L"\"Jak zawsze porywczy… Poznasz odpowiedzi na swoje pytania, tylko jeszcze nie teraz. "
			L"Póki co lepiej by by³o gdybyœ skupi³ siê na wydostaniu z tego miejsca.\"");
		kwestia->dodajOdpowiedz(L"\"W takim razie pomówmy o tym jak siê st¹d wydostaæ.\"", 15);
		kwestia->dodajOdpowiedz(L"\"Spierdalaj.\"", 18);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(18, 1,
			L"\"W takim razie weŸ ten klucz i sam znajdŸ sobie wyjœcie. Jeszcze siê spodkamy.\"");
		kwestia->dodajNagrodeQuestFaza(ListaQuestow::TajemniczyNieznajomy, 4);
		kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZBrazuLvl2);
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê.", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(19, 19,
			L"\"Co jeszcze chcesz wiedzieæ?\"");
		kwestia->dodajOdpowiedz(L"\"Rozbudowany system lochów? Serio?\"", 20);
		kwestia->dodajOdpowiedz(L"\"Czy odda on ten klucz po dobroci?\"", 21);
		kwestia->dodajOdpowiedz(L"\"Nie mogê spróbowaæ wywa¿yæ tego wyjœcia?\"", 22);
		kwestia->dodajOdpowiedz(L"\"Pomo¿esz mi?\"", 23);
		kwestia->dodajOdpowiedz(L"\"Nie mam wiêcej pytañ, chcê ruszaæ w drogê.\"", 24);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(20, 20,
			L"\"To nie ja jestem szalonym magiem. Najwidoczniej chce byæ pewny, ¿e ¿adne jego "
			L"eksperymenty nie wydostan¹ siê na zewn¹trz. I wice wersa. Na twoim miejscu by³bym ostro¿ny.\"");
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(21, 21,
			L"\"Nie by³bym tego taki pewien, w koñcu nie bez powodu zamkn¹³ to miejsce na klucz. "
			L"Pamiêtaj jednak, ¿e to cz³owiek, je¿eli znajdzie korzyœæ w oddaniu ci klucza to zrobi to. Wszystko zale¿y od ciebie.\"");
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(22, 22,
			L"\"Strata czasu. Tylko spójrz na nie: solidna kupa stali. Trzeba by nie byle wo³a aby choæby drgnê³o.\"");
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(23, 23,
			L"\"Nie mogê z tob¹ wyruszyæ i ci pomagaæ, ale niebezpiecznie jest iœæ samemu. Proszê weŸ ten miecz, z "
			L"pewnoœci¹ przyda ci siê prawdziwa broñ. Poni¿ej bêdziesz móg³ polegaæ tylko na sobie i na swojej broni. "
			L"Ponadto kiedy skoñczymy rozmowê chêtnie pomogê ci potrenowaæ twoje zdolnoœci bojowe. Ale sam trening to "
			L"nie wszystko, prawdziwy wojownik musi ³¹czyæ trening z prawdziw¹ walk¹ je¿eli chce siê doskonaliæ.\"");
		kwestia->dodajNagrodeGraczItem(ListaItemow::Bronie::MieczKrotkiBraz);
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(24, 1,
			L"\"Proszê, oto klucz otwieraj¹cy przejœcie na dó³. Znajduje siê tam jaskinia w której ¿yje plemiê "
			L"prymitywnych goblinów. Ich wódz posiada klucz otwieraj¹cy przejœcie w ni¿sze partie jaskini, sam "
			L"zdecydujesz jak go zdobêdziesz. Kiedy ju¿ to zrobisz ruszaj w g³¹b podziemi, twój cel znajduje siê na "
			L"samym dole.  Jeszcze siê spotkamy. Powodzenia.\"");
		kwestia->dodajNagrodeQuestFaza(ListaQuestow::TajemniczyNieznajomy, 3);
		kwestia->dodajNagrodeQuestFaza(ListaQuestow::GoblinyWPodziemiach, 2);
		kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZBrazuLvl2);
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê.", -1);
		postac->dodajKwestie(kwestia);
		break;
#pragma endregion

#pragma region testNPC
	case ListaPostaci::TestNPC:
		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			L"Witaj, czego ci trzeba?");
		kwestia->dodajOdpowiedz(L"Daj mi z³oto. Przy okazji jest to jakaœ niedorzecznie d³uga wypowiedŸ maj¹ca sprawdziæ jak dzia³a wersalikowanie odpowiedzi w rozmowie. ", 2);
		kwestia->dodajOdpowiedz(L"Zabierz mi z³oto.", 3)
			->DodajWymaganieZloto(100);
		kwestia->dodajOdpowiedz(L"Daj mi expy", 4);
		kwestia->dodajOdpowiedz(L"Daj mi klejnot.", 5);
		kwestia->dodajOdpowiedz(L"Zabierz mi klejnot.", 6)
			->DodajWymaganieItem(Questowe::OkraglySzafir);
		kwestia->dodajOdpowiedz(L"W podziemiach czujê siê jak w domu!", 7)
			->DodajWymaganieRasa(RASA_GNOM | RASA_KRASNOLUD);
		kwestia->dodajOdpowiedz(L"Spróbuj mnie zabiæ pusta pauko!", -2);
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê.", -1)
			->DodajWymaganieZdarzenieGlobalne(7);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			L"Dostajesz z³oto.");
		kwestia->dodajNagrodeGraczZloto(100);
		kwestia->dodajOdpowiedz(L"Dalej.", 1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(3, 3,
			L"Zabieram ci z³oto");
		kwestia->dodajOdpowiedz(L"Dalej.", 1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(4, 4,
			L"Dostajesz expy.");
		kwestia->dodajNagrodeGraczDoswiadczenie(5);
		kwestia->dodajOdpowiedz(L"Dalej.", 1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(5, 5,
			L"Dostajesz klejnot.");
		kwestia->dodajNagrodeGraczItem(ListaItemow::Questowe::OkraglySzafir);
		kwestia->dodajOdpowiedz(L"Dalej.", 1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(6, 6,
			L"Zabieram ci klejnot.");
		kwestia->dodajOdpowiedz(L"Dalej.", 1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(7, 7,
			L"No fajnie, jesteœ krasnoludem lub gnomem, gratulacje.");
		kwestia->dodajOdpowiedz(L"Dalej.", 1);
		postac->dodajKwestie(kwestia);
		break;
#pragma endregion

#pragma region Goblin szaman
	case ListaPostaci::GoblinSzaman:
		temp = gracz.rasa->nazwaGoblinska;

		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			L"„Staæ! Ty zabijaæ nie wiêcej. Torag Mora, m¹dry, jego bracia martwi. Nie wiêcej! My rozmawiaæ.”");
		kwestia->dodajOdpowiedz(L"„Nie obchodzi mnie co masz do powiedzenia. Broñ siê!”", -2);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu", 2, -10)
			->DodajWymaganieRasa(RASA_ELF | RASA_POLELF | RASA_MROCZNYELF | RASA_NIZIOLEK | RASA_SIDAN | RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu", 3, -5)
			->DodajWymaganieRasa(RASA_KRASNOLUD | RASA_ORK | RASA_LACERT | RASA_GNOM);
		kwestia->dodajOdpowiedz(L"„Co niby taka poczwara mo¿e mieæ do powiedzenia?”", 4);
		kwestia->dodajOdpowiedz(L"„Mów, s³ucham Ciê.”", 4);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			L"Wykorzystuj¹c element zaskoczenia podnosisz broñ i atakujesz ni¹ rozmówcê. Trafiasz go prosto w g³owê i goblin pada na ziemiê. Reszta plemienia widz¹c to, z krzykiem rzuca siê na ciebie.");
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::MorderstwoSzamanaGoblinow);
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(3, 3,
			L"Wykorzystuj¹c element zaskoczenia podnosisz broñ i atakujesz ni¹ rozmówcê. Robisz to jednak niezdarnie i goblin wykonuje unik, po czym zaczyna uciekaæ. Drogê zastêpuje ci reszta plemienia.");
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::UcieczkaSzamanaGoblinow);
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(4, 4,
			L"„Goba nie twój wróg. Bia³y demon wiêziæ goba, my nie jego s³ugi. Torag rozmawiaæ " + temp + L", goba nie gin¹æ wiêcej.”");
		kwestia->dodajOdpowiedz(L"Dalej", 5)
			->DodajWymaganieQuestFaza(ListaQuestow::GoblinyWPodziemiach, { 3 });
		kwestia->dodajOdpowiedz(L"Dalej", 6)
			->DodajWymaganieQuestFaza(ListaQuestow::GoblinyWPodziemiach, { 0, 1, 2 });
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(5, 5,
			L"„Twoja broñ mieæ krew goba, Torag martwiæ siê nie zgin¹æ. " + temp + L" oddaæ broñ i my iœæ do chata, tam my rozmawiaæ.”");
		kwestia->dodajOdpowiedz(L"Oddaj mu broñ", 7);
		kwestia->dodajOdpowiedz(L"„Nie nabierzesz mnie na takie sztuczki! Giñ!”", -2);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu", 2, -10)
			->DodajWymaganieRasa(RASA_ELF | RASA_POLELF | RASA_MROCZNYELF | RASA_NIZIOLEK | RASA_SIDAN | RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu", 3, -5)
			->DodajWymaganieRasa(RASA_KRASNOLUD | RASA_ORK | RASA_LACERT | RASA_GNOM);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(6, 6,
			L"„Tu my nie rozmawiaæ. Du¿o uchi goba nie trzeba. My iœæ do chata, tam Torag mówiæ, L" + temp + L" s³uchaæ.”");
		kwestia->dodajOdpowiedz(L"„Sk¹d mam wiedzieæ, ¿e nie chcecie mnie otoczyæ i zabiæ?”", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(7, 9,
			L"„Torag rad, L" + temp + L" wiedza.Rozmowa du¿o dobra.My iœæ.”");
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinowZOddaniemBroni);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(8, 9,
			L"„" + temp + L" zabiæ silne goba.My nie wiêcej tutaj, nie chcieæ gin¹æ.Bia³y demon s³uchaæ.Torag mówiæ tutaj demon zabijaæ goba.Isæ!Iœæ!”");
		kwestia->dodajOdpowiedz(L"„Niech bêdzie. ProwadŸ.”", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow);
		kwestia->dodajOdpowiedz(L"„Nie ufam Ci ropucho. ProwadŸ, ale nie wykonuj ¿adnych gwa³townych ruchów.”", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow);
		kwestia->dodajOdpowiedz(L"„Bardzo sprytne, jednak chyba wolê po prostu zabiæ.”", -2);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu”", 2);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(9, 9,
			L"„My tu mówiæ bezpiecznie. Ja Torag Mora, byæ kiedyœ silny wielki wódz. Zabiæ i zjeœæ inne Goba, zbieraæ ich samice. Ale Torag zhañbiony, nie godzien swoje imiê. Nie godzien wielki wódz.”");
		kwestia->dodajOdpowiedz(L"Dalej", 10);
		kwestia->dodajOdpowiedz(L"„Streszczaj siê, twoje stêkanie dzia³a mi ju¿ na nerwy.”", 11, -2);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(10, 10,
			L"„Torag zdobyæ ³atwy ³up, wpaœæ w pu³apka. Bia³y demon uwiêziæ Torag, jego braci i samice. Goba musieæ s³uchaæ demon aby mieæ co jeœæ. Goba strzec jaskinia, wtedy goba ¿yj¹. Inaczej bia³y demon ubijaæ goba.”");
		kwestia->dodajOdpowiedz(L"Dalej", 11);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(11, 11,
			L"„Goba nie znieœæ tego wiêcej, woli raczej zgniæ. Ty " + temp + L" wielki wojownik.Wzi¹æ ten klucz, one otworz¹ drzwi bia³ego demona.Ty z nim walczyæ i zabiæ - goba byæ wolne.Ty zgin¹æ, goba zgin¹æ tak¿e.”");
		kwestia->dodajOdpowiedz(L"„Dlaczego niby mia³bym to robiæ?”", 12);
		kwestia->dodajOdpowiedz(L"„Co to jest ten ca³y bia³y demon?”", 16);
		kwestia->dodajOdpowiedz(L"„Co bêdziecie robiæ kiedy odzyskacie wolnoœæ?”", 14);
		kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZSrebraLvl3);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(12, 12,
			L"„Torag pomóc " + temp + L" i daæ klucz. Teraz " + temp + L" musieæ pomóc Goba.”");
		kwestia->dodajOdpowiedz(L"„Zatem niech tak bêdzie. Spróbujê wam pomóc.”", 13);
		kwestia->dodajOdpowiedz(L"„Ma³o mnie obchodz¹ wasze problemy, ale chyba i tak przyjdzie mi siê zmierzyæ z tym ca³ym bia³ym demonem.", 13);
		kwestia->dodajOdpowiedz(L"„Co bêdziecie robiæ kiedy odzyskacie wolnoœæ?”", 14);
		kwestia->dodajOdpowiedz(L"„Co to jest ten ca³y bia³y demon?”", 16);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(13, 17,
			L"„|^" + temp + L" ruszaæ natychmiast. Bia³y demon wielka magia, wiedzieæ du¿o. Torag zmartwiony o ¿ycie goba. Iœæ! Iœæ!”");
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê.", KoniecRozmowy);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(14, 14,
			L"„Torag Mora chcieæ odzyskaæ zaszczyt swojego imienia. Robiæ wielkie rzeczy aby jego bracia znowu robiæ strach. |+ L" + temp + L" nie rozumieæ.”");
		kwestia->dodajOdpowiedz(L" „Rozumiem wiêcej ni¿ Ci siê zdaje.”", 15)
			->DodajWymaganieRasa(RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz(L"„W sumie i tak ma³o mnie to obchodzi.”", 13);
		kwestia->dodajOdpowiedz(L"„Nie wierzê w ani jedno twoje s³owo, pod³a kreaturo, a teraz giñ!”", KoniecRozmowyWalka);
		kwestia->dodajOdpowiedz(L"„Bardzo ciekawa historia, ale wolê nie zostawiaæ zgrai gobelinów za plecami. Da³eœ mi klucz, wiêc mo¿esz spokojnie zdychaæ.”", KoniecRozmowyWalka);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(15, 15,
			L"„Co Tora mówiæ?”");
		kwestia->dodajOdpowiedz(L"„Ci¹gle mówisz na mnie Tora, musi to oznaczaæ „cz³owiek”. Mora brzmi jak „zag³ada”. Twoje parszywe plemiê sczeŸnie w tej jaskini, a ty zap³acisz za swoje zbrodnie!”", KoniecRozmowyWalka);
		kwestia->dodajOdpowiedz(L"„W sumie nie wa¿ne.”", 13);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(16, 16,
			L"„Demon jest magia. Wielki, stary, z³y i straszny. Zabijaæ Goba ruchem rêki i kruszyæ g³azy s³owami.”");
		kwestia->dodajOdpowiedz(L"„Dlaczego mia³bym wam pomóc?”", 12);
		kwestia->dodajOdpowiedz(L"„Zatem niech bêdzie, spróbujê wam pomóc.”", 13);
		kwestia->dodajOdpowiedz(L"„Co bêdziecie robiæ kiedy odzyskacie wolnoœæ?”", 14);
		kwestia->dodajOdpowiedz(L"„Wkurza mnie ju¿ to twoje pieprzenie, myœlê, ¿e ciê zabijê.”", KoniecRozmowyWalka);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(17, 17,
			L"„|^" + temp + L" dzia³aæ, Goba nic nie mieæ mówiæ wiêcej!”");
		kwestia->dodajOdpowiedz(L"Zakoñcz rozmowê.", KoniecRozmowy);
		postac->dodajKwestie(kwestia);

		break;

#pragma endregion

#pragma region Cz³owiek z t³umu
	case ListaPostaci::Cz³owiekZTlumu:
		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			L"Klepiesz pierwszego lepszego cz³owieka z brzegu, chc¹c zadaæ mu kilka pytañ. Cz³owiek odwraca siê do ciebie i niezbyt mi³ym tonem oznajmia: „Czego?”");
		kwestia->dodajOdpowiedz(L"„Gdzie ja jestem?”", 2);
		kwestia->dodajOdpowiedz(L"„Co tu siê dzieje?”", 2);
		kwestia->dodajOdpowiedz(L"„Kogo wieszaj¹?”", 2);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			L"„Nie zadawaj g³upich pytañ tylko patrz. Patrz. Patrz...”");
		kwestia->dodajOdpowiedz(L"Patrz...", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::Sen1Wstawka2);
		postac->dodajKwestie(kwestia);
		break;
#pragma endregion

#pragma region Kucharka
	case ListaPostaci::Kucharka:
		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			L"Stara Kucharka patrzy na ciebie z nieukrywanym wyrzutem. „Patrz co¿eœ zrobi³a, mówi³am uwa¿aj! Teraz ca³e miêso pójdzie najwy¿ej na mielone!”");
		kwestia->dodajOdpowiedz(L"„Przepraszam ciociu.”", 2);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, -1,
			L"„Pan ma goœcia, lepiej idŸ spytaj siê czy czegoœ potrzebuj¹. Tylko migiem! Potrzebujem jeszcze twojej pomocy przy obiedzie.”");
		kwestia->dodajOdpowiedz(L"„Ju¿, ju¿ ciociu.”", -1);
		postac->dodajKwestie(kwestia);
		break;
#pragma endregion
	default:
		break;
	}
}