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
			playerMsg(L"Popychasz lekko butelkê, nieznany ci mechanizm p³ynnie wci¹ga j¹ w g³¹b stojaka. Przez chwilê s³yszysz tylko zgrzyty.\n");
			playerMsg(L"W œcianie przed tob¹ powstaje wg³êbienie, które nastêpnie powoli osuwa siê na bok, ukazuj¹c ukryte przejœcie.");
		}
		else
		{
			polozenie->zamek[NORTH] = -1;
			przedmiot->dzwigniaUstawStatus(0);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PUSH,1);
			przedmiot->dzwigniaUstawZdarzenie(DZWIGNIA_PULL,0);
			playerMsg(L"Siêgasz g³êboko w stojak i poci¹gasz za butelkê, ta p³ynnie powraca do swojego poprzedniego po³o¿enia w akompaniamencie zgrzytów.\n");
			playerMsg(L"Przy wtórze g³oœnego szurania kamieni, ukryte przejœcie siê zamyka nie pozostawiaj¹c na œcianie nawet œladu swojego istnienia.");
		}
		return false;
		break;  
#pragma endregion

#pragma region 2-6: teksty w korytarzu
	case ListaZdarzenGlobalnych::TekstWKorytarzu1:
		midiPlayer->play(MidiFiles::DREAM);
		wcout<<endl;
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

#pragma region Zdarzenia z goblinami
	case ListaZdarzenGlobalnych::MorderstwoSzamanaGoblinow:

		return false;

	case ListaZdarzenGlobalnych::UcieczkaSzamanaGoblinow:
		//postac = getLokacja(45)->postacie->
		return false;

	case ListaZdarzenGlobalnych::ZagrodzenieDrogiPrzezGwardzisteGoblinow:
		drukuj(L"Jeden z goblinów zagradza ci drogê i krzyczy \"Ty nie tam! Iœæ\", po czym odpycha ciê do ty³u.");
		dynamic_cast<Go*>(listaKomend->komendy[COMM_GO])->GoKierunek(gracz.poprzedniePolozenie);
		return true;
#pragma endregion

	default:
		playerMsg(L"|RPróbowano uruchomiæ nieznane zdarzenie globalne o id |0.", intToStr(id));
		return false;

		return false;
	}
}