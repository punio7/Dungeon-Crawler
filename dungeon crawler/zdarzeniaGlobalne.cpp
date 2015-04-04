#include "zdarzeniaGlobalne.h"
#include "ListaZdarzenGlobalnych.h"
#include "gra.h"
#include "item.h"
#include "drukuj.h"
#include "Lokacja.h"
#include "midi.h"
#include "playerMsg.h"

#include "Go.h"

void wywolajZdarzenieGlobalne(int id)
{
	instanceOfGra->zdarzenieGlobalne(id);
}

bool Gra::zdarzenieGlobalne(int id)
{
	Lokacja *polozenie=NULL;
	Postac *postac=NULL;
	Item *przedmiot=NULL;

	switch (id)
	{
	case 0:
		return false;
	

	//1-otwiera ukryte przejscie po nacisnieciu butelki w piwniczce
#pragma region 1: butelka w piwniczce
	case ListaZdarzenGlobalnych::ButelkaWPiwniczce:			
		polozenie=getLokacja(9);
		przedmiot=(polozenie->przedmioty)->znajdz(,1);
		if (przedmiot->dzwigniaStatus() == 0)
		{
			polozenie->zamek[NORTH] = 0;
			przedmiot->dzwigniaUstawStatus(1);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PUSH,0);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PULL,1);
			playerMsg(L"Popychasz lekko butelk�, nieznany ci mechanizm p�ynnie wci�ga j� w g��b stojaka. Przez chwil� s�yszysz tylko zgrzyty.\n");
			playerMsg(L"W �cianie przed tob� powstaje wg��bienie, kt�re nast�pnie powoli osuwa si� na bok, ukazuj�c ukryte przej�cie.");
		}
		else
		{
			polozenie->zamek[NORTH] = -1;
			przedmiot->dzwigniaUstawStatus(0);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PUSH,1);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PULL,0);
			playerMsg(L"Si�gasz g��boko w stojak i poci�gasz za butelk�, ta p�ynnie powraca do swojego poprzedniego po�o�enia w akompaniamencie zgrzyt�w.\n");
			playerMsg(L"Przy wt�rze g�o�nego szurania kamieni, ukryte przej�cie si� zamyka nie pozostawiaj�c na �cianie nawet �ladu swojego istnienia.");
		}
		return false;
		break;  
#pragma endregion

#pragma region 2-6: teksty w korytarzu
	case ListaZdarzenGlobalnych::TekstWKorytarzu1:
		midiPlayer->play(MidiFiles::DREAM);
		wcout<<endl;
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

#pragma region Zdarzenia z goblinami
	case ListaZdarzenGlobalnych::MorderstwoSzamanaGoblinow:

		return false;

	case ListaZdarzenGlobalnych::UcieczkaSzamanaGoblinow:
		//postac = getLokacja(45)->postacie->
		return false;

	case ListaZdarzenGlobalnych::ZagrodzenieDrogiPrzezGwardzisteGoblinow:
		drukuj(L"Jeden z goblin�w zagradza ci drog� i krzyczy \"Ty nie tam! I��\", po czym odpycha ci� do ty�u.");
		dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(gracz.poprzedniePolozenie);
		return true;
#pragma endregion

	default:
		playerMsg(L"|RPr�bowano uruchomi� nieznane zdarzenie globalne o id |0.", intToStr(id));
		return false;

		return false;
	}
}