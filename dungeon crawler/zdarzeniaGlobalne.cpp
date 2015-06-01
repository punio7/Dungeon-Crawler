#include "zdarzeniaGlobalne.h"
#include "ListaPostaci.h"
#include "ListaQuestow.h"
#include "ListaItemow.h"
#include "ListaKomend.h"
#include "ListaZdarzenGlobalnych.h"
#include "Gra.h"
#include "Item.h"
#include "Quest.h"
#include "drukuj.h"
#include "Lokacja.h"
#include "midi.h"
#include "playerMsg.h"

#include "Kill.h"
#include "Go.h"
#include "Remove.h"

Gra *instanceOfGra = NULL;

void wywolajZdarzenieGlobalne(int id)
{
	instanceOfGra->zdarzenieGlobalne(id);
}

void zamienEkwipunki(Postac* zrodlo, Postac* cel)
{
	for (int i = 0; i < SLOT_ILOSC; i++)
	{
		if (zrodlo->eq[i] != NULL)
		{
			Item* temp = zrodlo->eq[i];
			cel->equip(temp);
			zrodlo->eq[i] = NULL;
		}
	}
	zrodlo->przelicz();
}

void zamienInventory(Postac* zrodlo, Postac* cel)
{
	while (!zrodlo->przedmioty->pusta())
	{
		Item* temp = zrodlo->przedmioty->znajdz(1);
		zrodlo->przedmioty->usunPierwszy();
		cel->przedmioty->dodaj(temp);
	}
}

bool Gra::zdarzenieGlobalne(int id)
{
	Lokacja *polozenie = NULL;
	Postac *postac = NULL;
	Item *przedmiot = NULL;

	switch (id)
	{
	case 0:
		return false;


		
#pragma region 1: butelka w piwniczce
	case ListaZdarzenGlobalnych::ButelkaWPiwniczce:
		polozenie = getLokacja(9);
		przedmiot = (polozenie->przedmioty)->znajdz(ListaItemow::Dzwignie::ButelkaPoWinie, 1);
		if (przedmiot->dzwigniaStatus() == 0)
		{
			polozenie->zamek[NORTH] = 0;
			przedmiot->dzwigniaUstawStatus(1);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PUSH, 0);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PULL, 1);
			playerMsg(L"Popychasz lekko butelkê, nieznany ci mechanizm p³ynnie wci¹ga j¹ w g³¹b stojaka. Przez chwilê s³yszysz tylko zgrzyty.\n");
			playerMsg(L"W œcianie przed tob¹ powstaje wg³êbienie, które nastêpnie powoli osuwa siê na bok, ukazuj¹c ukryte przejœcie.");
		}
		else
		{
			polozenie->zamek[NORTH] = -1;
			przedmiot->dzwigniaUstawStatus(0);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PUSH, 1);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PULL, 0);
			playerMsg(L"Siêgasz g³êboko w stojak i poci¹gasz za butelkê, ta p³ynnie powraca do swojego poprzedniego po³o¿enia w akompaniamencie zgrzytów.\n");
			playerMsg(L"Przy wtórze g³oœnego szurania kamieni, ukryte przejœcie siê zamyka nie pozostawiaj¹c na œcianie nawet œladu swojego istnienia.");
		}
		return false;
		break;
#pragma endregion

#pragma region 2-6: teksty w korytarzu
	case ListaZdarzenGlobalnych::TekstWKorytarzu1:
		midiPlayer->play(MidiFiles::DREAM);
		wcout << endl;
		drukuj(L"Ciemnoœæ. ¯ycie pod ziemi¹ przyzwyczaja do ciemnoœci, staje siê ona powietrzem, po¿ywieniem i okryciem. Mo¿e kiedyœ brak œwiat³a krêpowa³ twoje ruchy, ogranicza³ wzrok, ale to by³o tak dawno ¿e nawet tego nie pamiêtasz. Ktoœ m¹dry kiedyœ stwierdzi³ i¿ ciemnoœæ nie jest przeciwnoœci¹ œwiat³a, a jedynie jej brakiem. Teraz jednak œwiat³o jest przeciwieñstwem ciebie, jego bezlitosne promienie wpe³zaj¹ ci pod g³owê powoduj¹c ból o istnieniu którego prawie zapomnia³eœ. Nagle jednak w morzu blasku pojawia siê wysepka wytchnienia- cieñ. Pocz¹tkowo powoli opada ze sklepienia by nastêpnie z hukiem wyl¹dowaæ na ziemi. Cienie to demony œwiat³a- gdzie nie ma œwiat³a tam i nie ma cienia. Maj¹c tylko to w g³owie odwracasz siê i zaczynasz uciekaæ, byle dalej od œwiat³a i byle dalej od cienia, który ciê goni. Zaczynasz przeklinaæ œwiat³o które rodzi takie potwory. Nie musisz siê odwracaæ by wiedzieæ i¿ cieñ nadal ciê goni, ka¿dy jego ruch jest prawdziw¹ orkiestr¹ ha³asu. Mimo to odwracasz siê maj¹c nadziejê przyjrzeæ temu stworzeniu. I nagle twoja ucieczka zostaje nagle przerwana. Wrota Demona. Tylko bia³y demon ma do nich klucz i tylko bia³y demon jest wystarczaj¹co wysoki by je otworzyæ. To pu³apka. Opierasz siê plecami o wrota, maj¹c nadziejê wypatrzyæ nadejœcie nieuniknionego. Twoje kolana powoli uginaj¹ siê pod tob¹ a d³oñ zaczyna szaleñczo przeszukiwaæ ziemiê, jednak jedyne co znajduje to niedu¿y kamieñ. Idealnie pasuje do twojej d³oni, jego dotyk dodaje Ci odwagi. Niemal¿e jesteœ pewien i¿ jesteœ w stanie stawiæ czo³a cieniowi. Wstajesz, zaczynasz ciê¿ko oddychaæ, lecz kiedy cieñ siê zbli¿a jesteœ ju¿ pozbawiony w¹tpliwoœci. Twoje gard³o mimowolnie wydaje okrzyk, kiedy œciskaj¹c kamieñ w rêce biegniesz w kierunku przeznaczenia."
			L"\n\n"
			L"Sen skoñczy³ siê nagle i rzeczywistoœæ zaczê³a dobijaæ siê do twoich zmys³ów. Rozmyte dochodz¹ce do twoich oczu powoli staj¹ siê coraz wyraŸniejsze. Powoli wstajesz rozmasowuj¹c bol¹cy kark. Próbujesz sobie przypomnieæ w jakim miejscu siê znajdujesz, jednak twoja pamiêæ zieje pustkami. Nie wiesz nawet kim jesteœ, ani tym bardziej co robisz w tym dziwnym miejscu.");
		midiPlayer->stop();
		return false;
		break;

	case ListaZdarzenGlobalnych::TekstWKorytarzu2:
		drukuj(L"Oddalaj¹c siê od Ÿród³a œwiat³a zaczynasz dostrzegaæ coraz mniej szczegó³ów korytarza w którym siê znajdujesz. Przez chwilê doznajesz lekkich zawrotów g³owy, wiêc opierasz siê o kamienn¹ œcianê. Ska³a jest zimna i wilgotna. Po krótkiej chwili twoje oczy przystosowuj¹ siê do ciemnoœci, wiêc wyprostowujesz siê i powoli ruszasz dalej.");
		return false;
		break;

	case ListaZdarzenGlobalnych::TekstWKorytarzu3:
		drukuj(L"Zbli¿aj¹c siê zauwa¿asz i¿ pod œcian¹ le¿y coœ intensywnie bia³ego, niewidocznego z dalszej odleg³oœci. Podchodz¹c powoli rozpoznajesz i¿ jest to szkielet jakiegoœ humanoida. Szcz¹tki emanuj¹ biel¹ i raczej musz¹ znajdowaæ siê tutaj od d³u¿szego czasu. Przygl¹daj¹c siê im przez chwilê dostrzegasz jakiœ b³ysk, mo¿e warto je bli¿ej zbadaæ?");
		return false;
		break;

	case ListaZdarzenGlobalnych::TekstWKorytarzu4:
		drukuj(L"Pog³êbiaj¹ca siê ciemnoœæ w koñcu zmusza ciê do poruszania siê po omacku. Praw¹ rêk¹ opierasz siê o œcianê i powoli poruszasz siê naprzód. Nieoczekiwany ból zaskakuje ciê kiedy nagle coœ ³apie ciê za g³owê. Zaczynasz siê szamotaæ a¿ wyrywasz siê z uœcisku i padasz na ziemiê. Szybko obracasz i patrz¹c pod œwiat³o dostrzegasz i¿ by³y to jedynie korzenie jakiegoœ drzewa, które przebi³o siê przez sufit.");
		return false;
		break;

	case ListaZdarzenGlobalnych::TekstWKorytarzu5:
		drukuj(L"Powoli posuwaj¹c siê naprzód dochodzisz do koñca korytarza. Macaj¹c rêkami œcianê przed sob¹ wyczuwasz drzwi. S¹ wykonane z drewna i mokre od wszechobecnej wilgoci. Próbujesz je pchn¹æ, jednak drzwi stawiaj¹ zdecydowany opór. Po omacku znajdujesz metalow¹ klamkê. Œciskaj¹c j¹ mocniej masz g³êbok¹ nadziejê i¿ drzwi nie oka¿¹ siê zamkniête na klucz.");
		return false;
		break;

#pragma endregion

#pragma region 7: TEST NPC koniec rozmowy
	case ListaZdarzenGlobalnych::TestNpcKoniecRozmowy:
		drukuj(L"Z oddali s³yszysz g³os:\nTo jeszcze nie koniec!");
		return false;
		break;
#pragma endregion
#pragma region Zdarzenia poziom 2

	case ListaZdarzenGlobalnych::ZejscieDoJaskini:
		drukuj(L"Ciemnoœæ. Patrz¹c w g³¹b otworu dostrzegasz jedynie czerñ. Powoli ustawiasz siê ty³em do klapy, po czym zaczynasz ostro¿nie schodziæ po drabinie w dó³. Zejœcie jest d³ugie a drewno drabiny ugina siê pod tob¹ przy ka¿dym ruchu. Pocz¹tkowo nie mo¿esz dostrzec niczego w panuj¹cej dooko³a ciemnoœci, ale twoje oczy powoli siê do niej przyzwyczajaj¹. Kiedy ju¿ jesteœ blisko ziemi zeskakujesz i starasz siê rozejrzeæ dooko³a siebie. Wtedy zauwa¿asz naprzeciw siebie drobny cieñ, skulony pod œcian¹. Kiedy wykonujesz krok w jego kierunku, cieñ nagle wstaje i zaczyna uciekaæ na po³udnie. Dosyæ szybko tracisz go z oczu i pozostajesz sam w ciemnoœci.");
		questy[ListaQuestow::GoblinyWPodziemiach]->spelnijSpecjalny(2);
		return false;

	case ListaZdarzenGlobalnych::DogonienieGoblinaWJaskini:
		drukuj(L"W koñcu doganiasz uciekiniera. Du¿e drewniane drzwi blokuj¹ przejœcie dalej, natomiast tajemniczy cieñ okazuje siê byæ zaledwie goblinem. Szybkim spojrzeniem zauwa¿asz i¿ trzyma coœ w rêce, nim jednak zd¹¿asz cokolwiek zrobiæ rzuca siê on na ciebie, g³oœno krzycz¹c.");
		return false;

	case ListaZdarzenGlobalnych::PrzejsciePrzezDrzwiDemona:
		drukuj(L"Przechodz¹c przez drzwi zauwa¿asz nag³¹ zmianê w jaskini. Œciany przesta³y byæ pustymi ska³ami a zape³ni³y siê ró¿norakiej maœci grzybami i mchami. Wszelakie wg³êbienia w skale zarastaj¹ ma³e grzyby o w¹skich trzonach, na œcianach wisi coœ podobnego do huby, natomiast na pod³odze rosn¹ nieznane ci odmiany o du¿ych i kolorowych kapeluszach. Powietrze jest gêste i duszne, ledwo zdatne do oddychania, zdaje siê i¿ wisz¹ w nim jakieœ drobiny. Przygl¹daj¹c siê tym wszystkim dziwom powolnym krokiem ruszasz do przodu. Próbujesz oceniæ zapach panuj¹cy dooko³a, coœ jakby w zamkniêtym pomieszczeniu zaczêto obieraæ grzyby, ale du¿o bardziej stêch³y i niepokoj¹cy. Nagle czujesz i¿ zdepta³eœ coœ nog¹, zanim zd¹¿y³byœ spojrzeæ na dó³ s³yszysz œwist i powietrze dooko³a zaczê³o gêstnieæ od czegoœ bia³ego. Zarodniki dostaj¹ ci siê do nosa i gard³a przez co nie mo¿esz z³apaæ oddechu. £apiesz siê za klatkê i zaczynasz dyszeæ jak szalony, upadasz na kolana i nieoczekiwanie wszystko znika.");
		teleportacjaGracza(60);
		return true;

	case ListaZdarzenGlobalnych::ZjedzeniePurchawki:
		playerMsg(L"Prze³ykasz kês grzyba, po czym zaczynasz siê g³oœno krztusiæ. Zaczynasz pluæ na pod³ogê, dopóki nie udaje ci siê wypluæ wszystkiego co pozosta³o ci jeszcze w ustach. W ¿yciu nie jad³eœ czegoœ tak obrzydliwego!");
		return false;
#pragma endregion

#pragma region Zdarzenia z goblinami
	case ListaZdarzenGlobalnych::MorderstwoSzamanaGoblinow:
		polozenie = getLokacja(45);
		postac = polozenie->postacie->znajdz(ListaPostaci::GoblinSzaman, 1);
		gracz.dodajEXP(postac->dawaneDoswiadczenie);
		dynamic_cast<Kill*>(listaKomend->komendy[COMM_KILL])->zabijPostac(postac, polozenie);
		return false;

	case ListaZdarzenGlobalnych::UcieczkaSzamanaGoblinow:
		polozenie = getLokacja(45);
		postac = polozenie->postacie->znajdz(ListaPostaci::GoblinSzaman, 1);
		polozenie->postacie->usun(postac);
		polozenie = getLokacja(51);
		polozenie->postacie->dodaj(postac);
		zdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		return false;

	case ListaZdarzenGlobalnych::AgresjaGoblinow:
		for (int i = 42; i < 55; i++)
		{
			for (Postac* postac : *(getLokacja(i)->postacie))
			{
				if (postac->rasa == getRasa(RasaNazwa::RASA_GOBLIN))
				{
					postac->agresywny = true;
				}
			}
		}
		getLokacja(48)->zdGlob = 0;
		getLokacja(53)->zdGlob = 0;
		return false;

	case ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow:
		polozenie = getLokacja(45);
		postac = polozenie->postacie->znajdz(ListaPostaci::GoblinSzaman, 1);
		polozenie->postacie->usun(postac);
		polozenie = getLokacja(51);
		polozenie->postacie->dodaj(postac);
		teleportacjaGracza(51);
		return false;

	case ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinowZOddaniemBroni:
		polozenie = getLokacja(45);
		postac = polozenie->postacie->znajdz(ListaPostaci::GoblinSzaman, 1);
		polozenie->postacie->usun(postac);
		polozenie = getLokacja(51);
		polozenie->postacie->dodaj(postac);
		dynamic_cast<Remove*>(listaKomend->komendy[COMM_REMOVE])->remove(SLOT_LREKA);
		dynamic_cast<Remove*>(listaKomend->komendy[COMM_REMOVE])->remove(SLOT_PREKA);
		teleportacjaGracza(51);
		return false;

	case ListaZdarzenGlobalnych::ZagrodzenieDrogiPrzezGwardzisteGoblinow:
		drukuj(L"Jeden z goblinów zagradza ci drogê i krzyczy \"Ty nie tam! Iœæ\", po czym odpycha ciê do ty³u.");
		dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(gracz.poprzedniePolozenie);
		return true;
#pragma endregion

#pragma region Sen 1 Wstawki

	case ListaZdarzenGlobalnych::Sen1Wstawka1:
		midiPlayer->play(MidiFiles::DREAM);
		postac = getLokacja(59)->postacie->znajdz(ListaPostaci::Manekin, 1);
		zamienEkwipunki(&gracz, postac);
		zamienInventory(&gracz, postac);
		drukuj(L"Czujesz zaduch i œcisk. Z daleka dobiegaj¹ do ciebie odg³osy t³umu, przyt³umione i g³uche. Powoli staj¹ siê coraz g³oœniejsze, jakbyœ wynurza³ siê z wody. Scena widziana z oddali, szybko zbli¿a siê do ciebie, nim zd¹¿ysz zauwa¿yæ sam znajdujesz siê w jej œrodku.");
		return false;

	case ListaZdarzenGlobalnych::Sen1Wstawka2:
		drukuj(L"Wytê¿aj¹c wzrok dostrzegasz na horyzoncie szubienicê. Próbujesz przyjrzeæ siê co na niej siê dzieje jednak w jednej chwili szubienica oraz ca³y t³um znika.");
		teleportacjaGracza(61);
		return false;

	case ListaZdarzenGlobalnych::Sen1Wstawka3:
		drukuj(L"Z za zamkniêtych drzwi gabinetu dochodz¹ ciê krzyki. Cicho podchodzisz i zaczynasz pods³uchiwaæ.\n"
			L"- Jakim prawem masz czelnoœæ proponowaæ mi coœ takiego?\n"
			L"- Poniewa¿ s¹ rzeczy gorsze ni¿ œmieræ. Mam przyjació³ którzy pomog¹ to zrealizowaæ...\n"
			L"- Wynoœ siê z mojego domu, albo zawiœniesz razem z nim! Won!\n"
			L"- Gdyby waszmoœæ  zmieni³ zdanie, przyjdê jeszcze w przeddzieñ egzekucji. Proszê o wybaczenie za zak³ócenie spokoju.\n"
			L"Szybko odskakujesz od drzwi chwilê zanim siê otwieraj¹, goœæ widz¹c ciebie pochyla g³owê. Wykorzystujesz chwilê aby mu siê przyjrzeæ. Ubrany jest w d³ugie, szarobure szaty, z kapturem, za to jego twarz... Bia³a skóra, bia³e w³osy, bia³a broda, oraz to spojrzenie... Udaj¹ce ¿yczliwoœæ, ale w rzeczywistoœci kamienne i bez uczuæ.\n"
			L"- Panienka wybaczy, w³aœnie wychodzê.\n");
		drukuj(L"Powoli budzi ciê pulsuj¹cy ból g³owy w miejscu, w którym uderzy³eœ siê o ziemiê upadaj¹c. Twoj¹ twarz muska delikatny podmuch wiatru, który musia³ rozwiaæ zarodniki, ratuj¹c ci tym samym ¿ycie. Oddychasz swobodnie i g³êboko, czuj¹c niezwyk³¹ radoœæ z ka¿dego wdechu i wydechu. Stêkaj¹c podpierasz siê d³oni¹ o pod³ogê i powoli wstajesz. Na chwilê robi ci siê ciemno przed oczyma, wiêc opierasz siê o œcianê jaskini, nudnoœæ jednak szybko mija. Wyprostowujesz siê, w pe³ni gotów do dalszej podró¿y.");
		postac = getLokacja(59)->postacie->znajdz(ListaPostaci::Manekin, 1);
		zamienEkwipunki(postac, &gracz);
		zamienInventory(postac, &gracz);
		teleportacjaGracza(55);
		midiPlayer->play(MidiFiles::LVL2);
		return true;

#pragma endregion
	default:
		playerMsg(L"|RPróbowano uruchomiæ nieznane zdarzenie globalne o id |0.", intToStr(id));
		return false;

		return false;
	}
}

void Gra::teleportacjaGracza(int idLokacji)
{
	dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->ZmianaPolozenia(getLokacja(idLokacji));
}