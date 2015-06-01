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
			playerMsg(L"Popychasz lekko butelk�, nieznany ci mechanizm p�ynnie wci�ga j� w g��b stojaka. Przez chwil� s�yszysz tylko zgrzyty.\n");
			playerMsg(L"W �cianie przed tob� powstaje wg��bienie, kt�re nast�pnie powoli osuwa si� na bok, ukazuj�c ukryte przej�cie.");
		}
		else
		{
			polozenie->zamek[NORTH] = -1;
			przedmiot->dzwigniaUstawStatus(0);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PUSH, 1);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PULL, 0);
			playerMsg(L"Si�gasz g��boko w stojak i poci�gasz za butelk�, ta p�ynnie powraca do swojego poprzedniego po�o�enia w akompaniamencie zgrzyt�w.\n");
			playerMsg(L"Przy wt�rze g�o�nego szurania kamieni, ukryte przej�cie si� zamyka nie pozostawiaj�c na �cianie nawet �ladu swojego istnienia.");
		}
		return false;
		break;
#pragma endregion

#pragma region 2-6: teksty w korytarzu
	case ListaZdarzenGlobalnych::TekstWKorytarzu1:
		midiPlayer->play(MidiFiles::DREAM);
		wcout << endl;
		drukuj(L"Ciemno��. �ycie pod ziemi� przyzwyczaja do ciemno�ci, staje si� ona powietrzem, po�ywieniem i okryciem. Mo�e kiedy� brak �wiat�a kr�powa� twoje ruchy, ogranicza� wzrok, ale to by�o tak dawno �e nawet tego nie pami�tasz. Kto� m�dry kiedy� stwierdzi� i� ciemno�� nie jest przeciwno�ci� �wiat�a, a jedynie jej brakiem. Teraz jednak �wiat�o jest przeciwie�stwem ciebie, jego bezlitosne promienie wpe�zaj� ci pod g�ow� powoduj�c b�l o istnieniu kt�rego prawie zapomnia�e�. Nagle jednak w morzu blasku pojawia si� wysepka wytchnienia- cie�. Pocz�tkowo powoli opada ze sklepienia by nast�pnie z hukiem wyl�dowa� na ziemi. Cienie to demony �wiat�a- gdzie nie ma �wiat�a tam i nie ma cienia. Maj�c tylko to w g�owie odwracasz si� i zaczynasz ucieka�, byle dalej od �wiat�a i byle dalej od cienia, kt�ry ci� goni. Zaczynasz przeklina� �wiat�o kt�re rodzi takie potwory. Nie musisz si� odwraca� by wiedzie� i� cie� nadal ci� goni, ka�dy jego ruch jest prawdziw� orkiestr� ha�asu. Mimo to odwracasz si� maj�c nadziej� przyjrze� temu stworzeniu. I nagle twoja ucieczka zostaje nagle przerwana. Wrota Demona. Tylko bia�y demon ma do nich klucz i tylko bia�y demon jest wystarczaj�co wysoki by je otworzy�. To pu�apka. Opierasz si� plecami o wrota, maj�c nadziej� wypatrzy� nadej�cie nieuniknionego. Twoje kolana powoli uginaj� si� pod tob� a d�o� zaczyna szale�czo przeszukiwa� ziemi�, jednak jedyne co znajduje to niedu�y kamie�. Idealnie pasuje do twojej d�oni, jego dotyk dodaje Ci odwagi. Niemal�e jeste� pewien i� jeste� w stanie stawi� czo�a cieniowi. Wstajesz, zaczynasz ci�ko oddycha�, lecz kiedy cie� si� zbli�a jeste� ju� pozbawiony w�tpliwo�ci. Twoje gard�o mimowolnie wydaje okrzyk, kiedy �ciskaj�c kamie� w r�ce biegniesz w kierunku przeznaczenia."
			L"\n\n"
			L"Sen sko�czy� si� nagle i rzeczywisto�� zacz�a dobija� si� do twoich zmys��w. Rozmyte dochodz�ce do twoich oczu powoli staj� si� coraz wyra�niejsze. Powoli wstajesz rozmasowuj�c bol�cy kark. Pr�bujesz sobie przypomnie� w jakim miejscu si� znajdujesz, jednak twoja pami�� zieje pustkami. Nie wiesz nawet kim jeste�, ani tym bardziej co robisz w tym dziwnym miejscu.");
		midiPlayer->stop();
		return false;
		break;

	case ListaZdarzenGlobalnych::TekstWKorytarzu2:
		drukuj(L"Oddalaj�c si� od �r�d�a �wiat�a zaczynasz dostrzega� coraz mniej szczeg��w korytarza w kt�rym si� znajdujesz. Przez chwil� doznajesz lekkich zawrot�w g�owy, wi�c opierasz si� o kamienn� �cian�. Ska�a jest zimna i wilgotna. Po kr�tkiej chwili twoje oczy przystosowuj� si� do ciemno�ci, wi�c wyprostowujesz si� i powoli ruszasz dalej.");
		return false;
		break;

	case ListaZdarzenGlobalnych::TekstWKorytarzu3:
		drukuj(L"Zbli�aj�c si� zauwa�asz i� pod �cian� le�y co� intensywnie bia�ego, niewidocznego z dalszej odleg�o�ci. Podchodz�c powoli rozpoznajesz i� jest to szkielet jakiego� humanoida. Szcz�tki emanuj� biel� i raczej musz� znajdowa� si� tutaj od d�u�szego czasu. Przygl�daj�c si� im przez chwil� dostrzegasz jaki� b�ysk, mo�e warto je bli�ej zbada�?");
		return false;
		break;

	case ListaZdarzenGlobalnych::TekstWKorytarzu4:
		drukuj(L"Pog��biaj�ca si� ciemno�� w ko�cu zmusza ci� do poruszania si� po omacku. Praw� r�k� opierasz si� o �cian� i powoli poruszasz si� naprz�d. Nieoczekiwany b�l zaskakuje ci� kiedy nagle co� �apie ci� za g�ow�. Zaczynasz si� szamota� a� wyrywasz si� z u�cisku i padasz na ziemi�. Szybko obracasz i patrz�c pod �wiat�o dostrzegasz i� by�y to jedynie korzenie jakiego� drzewa, kt�re przebi�o si� przez sufit.");
		return false;
		break;

	case ListaZdarzenGlobalnych::TekstWKorytarzu5:
		drukuj(L"Powoli posuwaj�c si� naprz�d dochodzisz do ko�ca korytarza. Macaj�c r�kami �cian� przed sob� wyczuwasz drzwi. S� wykonane z drewna i mokre od wszechobecnej wilgoci. Pr�bujesz je pchn��, jednak drzwi stawiaj� zdecydowany op�r. Po omacku znajdujesz metalow� klamk�. �ciskaj�c j� mocniej masz g��bok� nadziej� i� drzwi nie oka�� si� zamkni�te na klucz.");
		return false;
		break;

#pragma endregion

#pragma region 7: TEST NPC koniec rozmowy
	case ListaZdarzenGlobalnych::TestNpcKoniecRozmowy:
		drukuj(L"Z oddali s�yszysz g�os:\nTo jeszcze nie koniec!");
		return false;
		break;
#pragma endregion
#pragma region Zdarzenia poziom 2

	case ListaZdarzenGlobalnych::ZejscieDoJaskini:
		drukuj(L"Ciemno��. Patrz�c w g��b otworu dostrzegasz jedynie czer�. Powoli ustawiasz si� ty�em do klapy, po czym zaczynasz ostro�nie schodzi� po drabinie w d�. Zej�cie jest d�ugie a drewno drabiny ugina si� pod tob� przy ka�dym ruchu. Pocz�tkowo nie mo�esz dostrzec niczego w panuj�cej dooko�a ciemno�ci, ale twoje oczy powoli si� do niej przyzwyczajaj�. Kiedy ju� jeste� blisko ziemi zeskakujesz i starasz si� rozejrze� dooko�a siebie. Wtedy zauwa�asz naprzeciw siebie drobny cie�, skulony pod �cian�. Kiedy wykonujesz krok w jego kierunku, cie� nagle wstaje i zaczyna ucieka� na po�udnie. Dosy� szybko tracisz go z oczu i pozostajesz sam w ciemno�ci.");
		questy[ListaQuestow::GoblinyWPodziemiach]->spelnijSpecjalny(2);
		return false;

	case ListaZdarzenGlobalnych::DogonienieGoblinaWJaskini:
		drukuj(L"W ko�cu doganiasz uciekiniera. Du�e drewniane drzwi blokuj� przej�cie dalej, natomiast tajemniczy cie� okazuje si� by� zaledwie goblinem. Szybkim spojrzeniem zauwa�asz i� trzyma co� w r�ce, nim jednak zd��asz cokolwiek zrobi� rzuca si� on na ciebie, g�o�no krzycz�c.");
		return false;

	case ListaZdarzenGlobalnych::PrzejsciePrzezDrzwiDemona:
		drukuj(L"Przechodz�c przez drzwi zauwa�asz nag�� zmian� w jaskini. �ciany przesta�y by� pustymi ska�ami a zape�ni�y si� r�norakiej ma�ci grzybami i mchami. Wszelakie wg��bienia w skale zarastaj� ma�e grzyby o w�skich trzonach, na �cianach wisi co� podobnego do huby, natomiast na pod�odze rosn� nieznane ci odmiany o du�ych i kolorowych kapeluszach. Powietrze jest g�ste i duszne, ledwo zdatne do oddychania, zdaje si� i� wisz� w nim jakie� drobiny. Przygl�daj�c si� tym wszystkim dziwom powolnym krokiem ruszasz do przodu. Pr�bujesz oceni� zapach panuj�cy dooko�a, co� jakby w zamkni�tym pomieszczeniu zacz�to obiera� grzyby, ale du�o bardziej st�ch�y i niepokoj�cy. Nagle czujesz i� zdepta�e� co� nog�, zanim zd��y�by� spojrze� na d� s�yszysz �wist i powietrze dooko�a zacz�o g�stnie� od czego� bia�ego. Zarodniki dostaj� ci si� do nosa i gard�a przez co nie mo�esz z�apa� oddechu. �apiesz si� za klatk� i zaczynasz dysze� jak szalony, upadasz na kolana i nieoczekiwanie wszystko znika.");
		teleportacjaGracza(60);
		return true;

	case ListaZdarzenGlobalnych::ZjedzeniePurchawki:
		playerMsg(L"Prze�ykasz k�s grzyba, po czym zaczynasz si� g�o�no krztusi�. Zaczynasz plu� na pod�og�, dop�ki nie udaje ci si� wyplu� wszystkiego co pozosta�o ci jeszcze w ustach. W �yciu nie jad�e� czego� tak obrzydliwego!");
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
		drukuj(L"Jeden z goblin�w zagradza ci drog� i krzyczy \"Ty nie tam! I��\", po czym odpycha ci� do ty�u.");
		dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(gracz.poprzedniePolozenie);
		return true;
#pragma endregion

#pragma region Sen 1 Wstawki

	case ListaZdarzenGlobalnych::Sen1Wstawka1:
		midiPlayer->play(MidiFiles::DREAM);
		postac = getLokacja(59)->postacie->znajdz(ListaPostaci::Manekin, 1);
		zamienEkwipunki(&gracz, postac);
		zamienInventory(&gracz, postac);
		drukuj(L"Czujesz zaduch i �cisk. Z daleka dobiegaj� do ciebie odg�osy t�umu, przyt�umione i g�uche. Powoli staj� si� coraz g�o�niejsze, jakby� wynurza� si� z wody. Scena widziana z oddali, szybko zbli�a si� do ciebie, nim zd��ysz zauwa�y� sam znajdujesz si� w jej �rodku.");
		return false;

	case ListaZdarzenGlobalnych::Sen1Wstawka2:
		drukuj(L"Wyt�aj�c wzrok dostrzegasz na horyzoncie szubienic�. Pr�bujesz przyjrze� si� co na niej si� dzieje jednak w jednej chwili szubienica oraz ca�y t�um znika.");
		teleportacjaGracza(61);
		return false;

	case ListaZdarzenGlobalnych::Sen1Wstawka3:
		drukuj(L"Z za zamkni�tych drzwi gabinetu dochodz� ci� krzyki. Cicho podchodzisz i zaczynasz pods�uchiwa�.\n"
			L"- Jakim prawem masz czelno�� proponowa� mi co� takiego?\n"
			L"- Poniewa� s� rzeczy gorsze ni� �mier�. Mam przyjaci� kt�rzy pomog� to zrealizowa�...\n"
			L"- Wyno� si� z mojego domu, albo zawi�niesz razem z nim! Won!\n"
			L"- Gdyby waszmo��  zmieni� zdanie, przyjd� jeszcze w przeddzie� egzekucji. Prosz� o wybaczenie za zak��cenie spokoju.\n"
			L"Szybko odskakujesz od drzwi chwil� zanim si� otwieraj�, go�� widz�c ciebie pochyla g�ow�. Wykorzystujesz chwil� aby mu si� przyjrze�. Ubrany jest w d�ugie, szarobure szaty, z kapturem, za to jego twarz... Bia�a sk�ra, bia�e w�osy, bia�a broda, oraz to spojrzenie... Udaj�ce �yczliwo��, ale w rzeczywisto�ci kamienne i bez uczu�.\n"
			L"- Panienka wybaczy, w�a�nie wychodz�.\n");
		drukuj(L"Powoli budzi ci� pulsuj�cy b�l g�owy w miejscu, w kt�rym uderzy�e� si� o ziemi� upadaj�c. Twoj� twarz muska delikatny podmuch wiatru, kt�ry musia� rozwia� zarodniki, ratuj�c ci tym samym �ycie. Oddychasz swobodnie i g��boko, czuj�c niezwyk�� rado�� z ka�dego wdechu i wydechu. St�kaj�c podpierasz si� d�oni� o pod�og� i powoli wstajesz. Na chwil� robi ci si� ciemno przed oczyma, wi�c opierasz si� o �cian� jaskini, nudno�� jednak szybko mija. Wyprostowujesz si�, w pe�ni got�w do dalszej podr�y.");
		postac = getLokacja(59)->postacie->znajdz(ListaPostaci::Manekin, 1);
		zamienEkwipunki(postac, &gracz);
		zamienInventory(postac, &gracz);
		teleportacjaGracza(55);
		midiPlayer->play(MidiFiles::LVL2);
		return true;

#pragma endregion
	default:
		playerMsg(L"|RPr�bowano uruchomi� nieznane zdarzenie globalne o id |0.", intToStr(id));
		return false;

		return false;
	}
}

void Gra::teleportacjaGracza(int idLokacji)
{
	dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->ZmianaPolozenia(getLokacja(idLokacji));
}