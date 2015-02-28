#include "gra.h"
#include "PostacNpc.h"
#include "Rozmowa.h"
#include "Kwestia.h"
#include "ListaItemow.h"
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
	string temp; //do przechowywania pomocniczych tekstów

	switch (id)
	{
#pragma region zakapturzona_postac
	case 2:
		{
			postac->rozmowa->obecnaKwestia=2;

			kwestia = new Kwestia(1, 1, 
				"Witaj, czego ci trzeba?");
			kwestia->dodajOdpowiedz("Zakoñcz rozmowê.",-1);
			kwestia->dodajOdpowiedz("Zabi³em szczury w piwniczce, tak jak chcia³eœ.", 12)
				->DodajWymaganieQuestFaza(ListaQuestow::TajemniczyNieznajomy, { 2 });
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(2,2,
				"Na œrodku pomieszczenia stoi tajemnicza osoba ubrana w d³ug¹ szatê. "
				"Kaptur ca³kowicie zas³ania jej twarz. Kiedy tylko ciê zauwa¿a odzywa siê: "
				"\"Witaj "+gracz.imie+"\".");
			kwestia->dodajOdpowiedz("\"Kim jesteœ?\"",3);
			kwestia->dodajOdpowiedz("\"Sk¹d znasz moje imiê?\"",4);
			kwestia->dodajOdpowiedz("\"Gdzie ja jestem?\"",5);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(3,3,
				"\"Moje imiê jest niewa¿ne, jestem tylko s³ug¹ i spe³niam swoje obowi¹zki."
				"Jestem tu aby ciê obserwowaæ i pomagaæ ci. Chcia³bym abyœ wykona³ dla mnie "
				"pewne zadanie.\"");
			kwestia->dodajOdpowiedz("\"Sk¹d znasz moje imiê?\"",4);
			kwestia->dodajOdpowiedz("\"Gdzie ja jestem?\"",5);
			kwestia->dodajOdpowiedz("\"Jakie zadanie?\"",8);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(4,4,
				"\"Wiem o tobie znacznie wiêcej, ale nie wiêcej ni¿ jest mi to potrzebne aby móc "
				"ci s³u¿yæ pomoc¹. Chcia³bym abyœ wykona³ da mnie pewne zadanie.\"");
			kwestia->dodajOdpowiedz("\"Kim jesteœ?\"",3);
			kwestia->dodajOdpowiedz("\"Gdzie ja jestem?\"",5);
			kwestia->dodajOdpowiedz("\"Jakie zadanie?\"",8);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(5,5,
				"\"Jesteœ w podziemiach pewnej wie¿y. Jedyne wyjœcie to klapa nad nami, niestety "
				"w³aœciciel wie¿y zamkn¹³ j¹ na amen.\"");
			kwestia->dodajOdpowiedz("\"Wiêc jak siê st¹d wydostaæ?\"",6);
			kwestia->dodajOdpowiedz("\"Co to za wie¿a?\"",7);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(6,6,
				"\"Wydostanie siê st¹d nie bêdzie ³atwe, ale pomogê ci. Najpierw musisz jednak "
				"wype³niæ pewne zadanie.\"");
			kwestia->dodajOdpowiedz("\"Kim jesteœ?\"",3);
			kwestia->dodajOdpowiedz("\"Sk¹d znasz moje imiê?\"",4);
			kwestia->dodajOdpowiedz("\"Jakie zadanie?\"",8);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(7,7,
				"„Z czasem siê dowiesz.”");
			kwestia->dodajOdpowiedz("\"Kim jest w³aœciciel wierzy?\"",7);
			kwestia->dodajOdpowiedz("\"Wiêc jak siê st¹d wydostaæ?\"",6);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(8,8,
				"\"Kiedyœ by³eœ wielkim wojownikiem. Chc¹c wydostaæ siê z tego miejsca bêdziesz "
				"musia³ przypomnieæ sobie jak walczyæ. Chcê abyœ znalaz³ sobie jak¹œ broñ i "
				"zabi³ wszystkie szczury w pomieszczeniu za moimi plecami.\"");
			kwestia->dodajOdpowiedz("\"Szczury?\"",9);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(9,9,
				"\"Tak, szczury. Chcê siê upewniæ, ¿e nadal wiesz jak walczyæ, zanim staniesz "
				"przed wiêkszymi wyzwaniami.\"");
			kwestia->dodajNagrodeQuestFaza(1, 1);
			kwestia->dodajOdpowiedz("\"Dobrze, zrobiê to.\"",10);
			kwestia->dodajOdpowiedz("\"Szczury nie s¹ dla mnie wyzwaniem.\"",10);
			kwestia->dodajOdpowiedz("\"Nie mam ochoty bawiæ siê w zabijanie jakichœ szczurów.\"",11,-1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(10,1,
				"\"W takim razie idŸ i je zabij. Poczekam tutaj na ciebie.\"");
			kwestia->dodajOdpowiedz("Zakoñcz rozmowê.",-1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(11,1,
				"\"Ale i tak to zrobisz. Poczekam tutaj a¿ skoñczysz.\"");
			kwestia->dodajOdpowiedz("Zakoñcz rozmowê.",-1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(12,12,
				"\"Dobrze. Zapewne masz du¿o pytañ dotycz¹cych siebie, tego miejsca i ca³ej "
				"tej sytuacji. Niestety teraz nie mogê ci powiedzieæ du¿o wiêcej ponadto co ci ju¿ powiedzia³em.\"");
			kwestia->dodajNagrodeGraczDoswiadczenie(5);
			kwestia->dodajOdpowiedz("\"Dlaczego nie mo¿esz mi nic powiedzieæ?\"",13);
			kwestia->dodajOdpowiedz("\"Nie mo¿esz czy raczej nie chcesz?\"",14);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(13,13,
				"\"Jestem zwi¹zany przysiêg¹ wobec tych, którym s³u¿ê. Odpowiem ci na wszystkie pytania kiedy oni stwierdz¹ i¿ nadszed³ czas.\"");
			kwestia->dodajOdpowiedz("\"W takim razie pomówmy o tym jak siê st¹d wydostaæ.\"",15);
			kwestia->dodajOdpowiedz("\"Gówno mnie obchodz¹ jakieœ durne przysiêgi. Chcê wiedzieæ co siê tu u diab³a dzieje!\"",17);
			kwestia->dodajOdpowiedz("\"Komu s³u¿ysz?\"",16);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(14,14,
				"\"I to i to po czêœci. Jestem tu z obowi¹zku i nie darzê ciê zbytni¹ sympati¹. Zw³aszcza zwa¿ywszy na to kim by³eœ w przesz³oœci.\"");
			kwestia->dodajOdpowiedz("\"W takim razie pomówmy o tym jak siê st¹d wydostaæ.\"",15);
			kwestia->dodajOdpowiedz("\"A kim by³em?\"",16);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(15,15,
				"\"Dobrze. Znajdujemy siê w podziemiach wie¿y pewnego maga. Stworzy³ on rozbudowany system lochów, "
				"chroni¹cych dostêp do jego laboratorium na samym dole. Jedynie on posiada klucz otwieraj¹cy "
				"wyjœcie na powierzchniê. Je¿eli chcesz st¹d uciec, bêdziesz musia³ go zdobyæ.\"");
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(16,16,
				"\"Wszystkiego dowiesz siê w swoim czasie.\"");
			kwestia->dodajOdpowiedz("\"W takim razie pomówmy o tym jak siê st¹d wydostaæ.\"",15);
			kwestia->dodajOdpowiedz("\"Przestañ pierdoliæ i zacznij gadaæ jak cz³owiek.\"",17);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(17,17,
				"\"Jak zawsze porywczy… Poznasz odpowiedzi na swoje pytania, tylko jeszcze nie teraz. "
				"Póki co lepiej by by³o gdybyœ skupi³ siê na wydostaniu z tego miejsca.\"");
			kwestia->dodajOdpowiedz("\"W takim razie pomówmy o tym jak siê st¹d wydostaæ.\"",15);
			kwestia->dodajOdpowiedz("\"Spierdalaj.\"",18);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(18,1,
				"\"W takim razie weŸ ten klucz i sam znajdŸ sobie wyjœcie. Jeszcze siê spodkamy.\"");
			kwestia->dodajNagrodeQuestFaza(ListaQuestow::TajemniczyNieznajomy, 4);
			kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZBrazuLvl2);
			kwestia->dodajOdpowiedz("Zakoñcz rozmowê.",-1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(19,19,
				"\"Co jeszcze chcesz wiedzieæ?\"");
			kwestia->dodajOdpowiedz("\"Rozbudowany system lochów? Serio?\"",20);
			kwestia->dodajOdpowiedz("\"Czy odda on ten klucz po dobroci?\"",21);
			kwestia->dodajOdpowiedz("\"Nie mogê spróbowaæ wywa¿yæ tego wyjœcia?\"",22);
			kwestia->dodajOdpowiedz("\"Pomo¿esz mi?\"",23);
			kwestia->dodajOdpowiedz("\"Nie mam wiêcej pytañ, chcê ruszaæ w drogê.\"",24);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(20,20,
				"\"To nie ja jestem szalonym magiem. Najwidoczniej chce byæ pewny, ¿e ¿adne jego "
				"eksperymenty nie wydostan¹ siê na zewn¹trz. I wice wersa. Na twoim miejscu by³bym ostro¿ny.\"");
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(21,21,
				"\"Nie by³bym tego taki pewien, w koñcu nie bez powodu zamkn¹³ to miejsce na klucz. "
				"Pamiêtaj jednak, ¿e to cz³owiek, je¿eli znajdzie korzyœæ w oddaniu ci klucza to zrobi to. Wszystko zale¿y od ciebie.\"");
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(22,22,
				"\"Strata czasu. Tylko spójrz na nie: solidna kupa stali. Trzeba by nie byle wo³a aby choæby drgnê³o.\"");
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(23,23,
				"\"Nie mogê z tob¹ wyruszyæ i ci pomagaæ, ale niebezpiecznie jest iœæ samemu. Proszê weŸ ten miecz, z "
				"pewnoœci¹ przyda ci siê prawdziwa broñ. Poni¿ej bêdziesz móg³ polegaæ tylko na sobie i na swojej broni. "
				"Ponadto kiedy skoñczymy rozmowê chêtnie pomogê ci potrenowaæ twoje zdolnoœci bojowe. Ale sam trening to "
				"nie wszystko, prawdziwy wojownik musi ³¹czyæ trening z prawdziw¹ walk¹ je¿eli chce siê doskonaliæ.\"");
			kwestia->dodajNagrodeGraczItem(ListaItemow::Bronie::MieczKrotkiBraz);
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(24,1,
				"\"Proszê, oto klucz otwieraj¹cy przejœcie na dó³. Znajduje siê tam jaskinia w której ¿yje plemiê "
				"prymitywnych goblinów. Ich wódz posiada klucz otwieraj¹cy przejœcie w ni¿sze partie jaskini, sam "
				"zdecydujesz jak go zdobêdziesz. Kiedy ju¿ to zrobisz ruszaj w g³¹b podziemi, twój cel znajduje siê na "
				"samym dole.  Jeszcze siê spotkamy. Powodzenia.\"");
			kwestia->dodajNagrodeQuestFaza(ListaQuestow::TajemniczyNieznajomy, 3);
			kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZBrazuLvl2);
			kwestia->dodajOdpowiedz("Zakoñcz rozmowê.",-1);
			postac->dodajKwestie(kwestia);  
		}
		break;  
#pragma endregion

#pragma region testNPC
	case 3:
		{
			postac->rozmowa->obecnaKwestia=1;
			
			kwestia = new Kwestia(1, 1,
				"Witaj, czego ci trzeba?");
			kwestia->dodajOdpowiedz("Daj mi z³oto. Przy okazji jest to jakaœ niedorzecznie d³uga wypowiedŸ maj¹ca sprawdziæ jak dzia³a wersalikowanie odpowiedzi w rozmowie. ",2);
			kwestia->dodajOdpowiedz("Zabierz mi z³oto.",3)
				->DodajWymaganieZloto(100);
			kwestia->dodajOdpowiedz("Daj mi expy",4);
			kwestia->dodajOdpowiedz("Daj mi klejnot.",5);
			kwestia->dodajOdpowiedz("Zabierz mi klejnot.",6)
				->DodajWymaganieItem(Questowe::OkraglySzafir);
			kwestia->dodajOdpowiedz("W podziemiach czujê siê jak w domu!", 7)
				->DodajWymaganieRasa(RASA_GNOM | RASA_KRASNOLUD);
			kwestia->dodajOdpowiedz("Spróbuj mnie zabiæ pusta pauko!",-2);
			kwestia->dodajOdpowiedz("Zakoñcz rozmowê.",-1)
				->DodajWymaganieZdarzenieGlobalne(7);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(2, 2,
				"Dostajesz z³oto.");
			kwestia->dodajNagrodeGraczZloto(100);
			kwestia->dodajOdpowiedz("Dalej.",1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(3, 3,
				"Zabieram ci z³oto");
			kwestia->dodajOdpowiedz("Dalej.",1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(4, 4,
				"Dostajesz expy.");
			kwestia->dodajNagrodeGraczDoswiadczenie(5);
			kwestia->dodajOdpowiedz("Dalej.",1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(5, 5,
				"Dostajesz klejnot.");
			kwestia->dodajNagrodeGraczItem(ListaItemow::Questowe::OkraglySzafir);
			kwestia->dodajOdpowiedz("Dalej.",1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(6, 6,
				"Zabieram ci klejnot.");
			kwestia->dodajOdpowiedz("Dalej.",1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(7, 7,
				"No fajnie, jesteœ krasnoludem lub gnomem, gratulacje.");
			kwestia->dodajOdpowiedz("Dalej.", 1);
			postac->dodajKwestie(kwestia);
		}
		break;
#pragma endregion

#pragma region Goblin szaman
	case 8:
		temp = gracz.rasa->nazwaGoblinska;
		
		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			"„Staæ! Ty zabijaæ nie wiêcej. Torag Mora, m¹dry, jego bracia martwi. Nie wiêcej! My rozmawiaæ.”");
		kwestia->dodajOdpowiedz("„Nie obchodzi mnie co masz do powiedzenia. Broñ siê!”", -2);
		kwestia->dodajOdpowiedz("Zabij go na miejscu", 2, -10)
			->DodajWymaganieRasa(RASA_ELF | RASA_POLELF | RASA_MROCZNYELF | RASA_NIZIOLEK | RASA_SIDAN | RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz("Zabij go na miejscu", 3, -5)
			->DodajWymaganieRasa(RASA_KRASNOLUD | RASA_ORK | RASA_LACERT | RASA_GNOM);
		kwestia->dodajOdpowiedz("„Co niby taka poczwara mo¿e mieæ do powiedzenia?”", 4);
		kwestia->dodajOdpowiedz("„Mów, s³ucham Ciê.”", 4);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			"Wykorzystuj¹c element zaskoczenia podnosisz broñ i atakujesz ni¹ rozmówcê. Trafiasz go prosto w g³owê i goblin pada na ziemiê. Reszta plemienia widz¹c to, z krzykiem rzuca siê na ciebie.");
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::ZabicieSzamanaGoblinow);
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		kwestia->dodajOdpowiedz("Zakoñcz rozmowê", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(3, 3,
			"Wykorzystuj¹c element zaskoczenia podnosisz broñ i atakujesz ni¹ rozmówcê. Robisz to jednak niezdarnie i goblin wykonuje unik, po czym zaczyna uciekaæ. Drogê zastêpuje ci reszta plemienia.");
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::UcieczkaSzamanaGoblinow);
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		kwestia->dodajOdpowiedz("Zakoñcz rozmowê", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(4, 4,
			"„Goba nie twój wróg. Bia³y demon wiêziæ goba, my nie jego s³ugi. Torag rozmawiaæ " + temp + ", goba nie gin¹æ wiêcej.”");
		kwestia->dodajOdpowiedz("Dalej", 5)
			->DodajWymaganieQuestFaza(ListaQuestow::GoblinyWPodziemiach, { 3 });
		kwestia->dodajOdpowiedz("Dalej", 6)
			->DodajWymaganieQuestFaza(ListaQuestow::GoblinyWPodziemiach, { 0, 1, 2 });
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(5, 5,
			"„Twoja broñ mieæ krew goba, Torag martwiæ siê nie zgin¹æ. " + temp + " oddaæ broñ i my iœæ do chata, tam my rozmawiaæ.”");
		kwestia->dodajOdpowiedz("Oddaj mu broñ", 7);
		kwestia->dodajOdpowiedz("„Nie nabierzesz mnie na takie sztuczki! Giñ!”", -2);
		kwestia->dodajOdpowiedz("Zabij go na miejscu", 2, -10)
			->DodajWymaganieRasa(RASA_ELF | RASA_POLELF | RASA_MROCZNYELF | RASA_NIZIOLEK | RASA_SIDAN | RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz("Zabij go na miejscu", 3, -5)
			->DodajWymaganieRasa(RASA_KRASNOLUD | RASA_ORK | RASA_LACERT | RASA_GNOM);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(6, 6,
			"„Tu my nie rozmawiaæ. Du¿o uchi goba nie trzeba. My iœæ do chata, tam Torag mówiæ, " + temp + " s³uchaæ.”");
		kwestia->dodajOdpowiedz("„Sk¹d mam wiedzieæ, ¿e nie chcecie mnie otoczyæ i zabiæ?”", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(7, 9,
			"„Torag rad, " + temp + " wiedza.Rozmowa du¿o dobra.My iœæ.”");
		kwestia->dodajOdpowiedz("Zakoñcz rozmowê", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinowZOddaniemBroni);
		postac->dodajKwestie(kwestia);
		
		kwestia = new Kwestia(8, 9,
			"„" + temp + " zabiæ silne goba.My nie wiêcej tutaj, nie chcieæ gin¹æ.Bia³y demon s³uchaæ.Torag mówiæ tutaj demon zabijaæ goba.Isæ!Iœæ!”");
		kwestia->dodajOdpowiedz("„Niech bêdzie. ProwadŸ.”", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow);
		kwestia->dodajOdpowiedz("„Nie ufam Ci ropucho. ProwadŸ, ale nie wykonuj ¿adnych gwa³townych ruchów.”", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow);
		kwestia->dodajOdpowiedz("„Bardzo sprytne, jednak chyba wolê po prostu zabiæ.”", -2);
		kwestia->dodajOdpowiedz("Zabij go na miejscu”", 2);
		postac->dodajKwestie(kwestia);
		
		kwestia = new Kwestia(9, 9,
			"„My tu mówiæ bezpiecznie. Ja Torag Mora, byæ kiedyœ silny wielki wódz. Zabiæ i zjeœæ inne Goba, zbieraæ ich samice. Ale Torag zhañbiony, nie godzien swoje imiê. Nie godzien wielki wódz.”");
		kwestia->dodajOdpowiedz("Dalej", 10);
		kwestia->dodajOdpowiedz("„Streszczaj siê, twoje stêkanie dzia³a mi ju¿ na nerwy.”", 11, -2);
		postac->dodajKwestie(kwestia);
		
		kwestia = new Kwestia(10, 10,
			"„Torag zdobyæ ³atwy ³up, wpaœæ w pu³apka. Bia³y demon uwiêziæ Torag, jego braci i samice. Goba musieæ s³uchaæ demon aby mieæ co jeœæ. Goba strzec jaskinia, wtedy goba ¿yj¹. Inaczej bia³y demon ubijaæ goba.”");
		kwestia->dodajOdpowiedz("Dalej", 11);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(11, 11,
			"„Goba nie znieœæ tego wiêcej, woli raczej zgniæ. Ty " + temp + " wielki wojownik.Wzi¹æ ten klucz, one otworz¹ drzwi bia³ego demona.Ty z nim walczyæ i zabiæ - goba byæ wolne.Ty zgin¹æ, goba zgin¹æ tak¿e.”");
		kwestia->dodajOdpowiedz("„Dlaczego niby mia³bym to robiæ?”", 12);
		kwestia->dodajOdpowiedz("„Co to jest ten ca³y bia³y demon?”", 16);
		kwestia->dodajOdpowiedz("„Co bêdziecie robiæ kiedy odzyskacie wolnoœæ?”", 14);
		kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZSrebraLvl3);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(12, 12,
			"„Torag pomóc " + temp + " i daæ klucz. Teraz " + temp + " musieæ pomóc Goba.”");
		kwestia->dodajOdpowiedz("„Zatem niech tak bêdzie. Spróbujê wam pomóc.”", 13);
		kwestia->dodajOdpowiedz("„Ma³o mnie obchodz¹ wasze problemy, ale chyba i tak przyjdzie mi siê zmierzyæ z tym ca³ym bia³ym demonem.", 13);
		kwestia->dodajOdpowiedz("„Co bêdziecie robiæ kiedy odzyskacie wolnoœæ?”", 14);
		kwestia->dodajOdpowiedz("„Co to jest ten ca³y bia³y demon?”", 16);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(13, 17,
			"„|^" + temp + " ruszaæ natychmiast. Bia³y demon wielka magia, wiedzieæ du¿o. Torag zmartwiony o ¿ycie goba. Iœæ! Iœæ!”");
		kwestia->dodajOdpowiedz("Zakoñcz rozmowê.", KoniecRozmowy);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(14, 14,
			"„Torag Mora chcieæ odzyskaæ zaszczyt swojego imienia. Robiæ wielkie rzeczy aby jego bracia znowu robiæ strach. |+ " + temp + " nie rozumieæ.”");
		kwestia->dodajOdpowiedz(" „Rozumiem wiêcej ni¿ Ci siê zdaje.”", 15)
			->DodajWymaganieRasa(RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz("„W sumie i tak ma³o mnie to obchodzi.”", 13);
		kwestia->dodajOdpowiedz("„Nie wierzê w ani jedno twoje s³owo, pod³a kreaturo, a teraz giñ!”", KoniecRozmowyWalka);
		kwestia->dodajOdpowiedz("„Bardzo ciekawa historia, ale wolê nie zostawiaæ zgrai gobelinów za plecami. Da³eœ mi klucz, wiêc mo¿esz spokojnie zdychaæ.”", KoniecRozmowyWalka);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(15, 15,
			"„Co Tora mówiæ?”");
		kwestia->dodajOdpowiedz("„Ci¹gle mówisz na mnie Tora, musi to oznaczaæ „cz³owiek”. Mora brzmi jak „zag³ada”. Twoje parszywe plemiê sczeŸnie w tej jaskini, a ty zap³acisz za swoje zbrodnie!”", KoniecRozmowyWalka);
		kwestia->dodajOdpowiedz("„W sumie nie wa¿ne.”", 13);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(16, 16,
			"„Demon jest magia. Wielki, stary, z³y i straszny. Zabijaæ Goba ruchem rêki i kruszyæ g³azy s³owami.”");
		kwestia->dodajOdpowiedz("„Dlaczego mia³bym wam pomóc?”", 12);
		kwestia->dodajOdpowiedz("„Zatem niech bêdzie, spróbujê wam pomóc.”", 13);
		kwestia->dodajOdpowiedz("„Co bêdziecie robiæ kiedy odzyskacie wolnoœæ?”", 14);
		kwestia->dodajOdpowiedz("„Wkurza mnie ju¿ to twoje pieprzenie, myœlê, ¿e ciê zabijê.”", KoniecRozmowyWalka);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(17, 17,
			"„|^" + temp +" dzia³aæ, Goba nic nie mieæ mówiæ wiêcej!”");
		kwestia->dodajOdpowiedz("Zakoñcz rozmowê.", KoniecRozmowy);
		postac->dodajKwestie(kwestia);

		break;

#pragma endregion

	default:
		break;
	}
}