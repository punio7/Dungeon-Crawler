﻿#include "Gra.h"
#include "Item.h"
#include "ListaItemow.h"
#include "ListaPostaci.h"
#include "ListaQuestow.h"
#include "ListaZdarzenGlobalnych.h"
#include "Lokacja.h"
#include "randomGenerator.h"
#include "midi.h"

Lokacja* Gra::getLokacja(int id)
{
	return listaLokacji + id;
}

using namespace ListaItemow;

void Gra::wczytaj_lokacje()
{
	{
		listaLokacji = new Lokacja[100];
	}
	
	Lokacja* aktualny;
	Item *temp;
	Postac *postac;
#pragma region Poziom1

	//////////////////	0	//////////////////
	aktualny=getLokacja(0);
	aktualny->nazwa = L"Początek korytarza";
	aktualny->jednorazoweZdGlob=2;
	aktualny->opis=
	 L"Rozglądając się dookoła dostrzegasz głównie ciemność. Wąski słup światła wpadający z dziury w suficie jest jedynym źródłem światła. Miejsce to wygląda na jakiś stary, podziemny tunel. Przejście za twoimi plecami zostało zasypane gruzem, kamieniami i ziemią, którą teraz porastają chwasty i trawa. Patrząc wprost widzisz morze kamienia ginące w mroku poza światłem. Interesująca wydaje się jedynie dziura w podłodze, umieszczona bezpośrednia pod tą w suficie. Słup światła nurkuje do niej ginąc gdzieś dużo, dużo niżej.";
	(aktualny->wyjscie)[NORTH]=getLokacja(1);

	aktualny->przedmioty->dodaj(createItem(Bronie::DragDrewniany));

	//////////////////	1	//////////////////
	aktualny=getLokacja(1);
	aktualny->nazwa = L"Podziemny korytarz";
	aktualny->backgroundMusic=MidiFiles::LVL1;
	aktualny->jednorazoweZdGlob=3;
	aktualny->opis= 
	 L"Korytarz wyłożony jest starymi kamiennymi płytami. Takie same płytki na ścianach, podłodze, suficie, od tego kamienia zaczyna kręcić ci się w głowie. Niektóre z nich powypadały ze swoich miejsc, tworzą teraz warstwę gruzu na podłodze. Większość z tych, które pozostały jest porośnięta mchem. Sztucznie uformowany kamień powoli poddaje się otaczającej go naturze.";
	(aktualny->wyjscie)[NORTH]=getLokacja(2);
	(aktualny->wyjscie)[SOUTH]=getLokacja(0);
	postac = createChar(ListaPostaci::SzczurJaskiniowy);
	aktualny->postacie->dodaj(postac);

	//////////////////	2	//////////////////
	aktualny=getLokacja(2);
	aktualny->nazwa = L"Podziemny korytarz";
	aktualny->jednorazoweZdGlob=4;
	aktualny->opis=
	 L"Im dalej od źródła światła tym bardziej korytarz pogłębia się ciemności i dostrzegasz coraz mniej. Cienie robią się nadzwyczaj długie, niknące w ciemności znajdującej się przed tobą. Refleksje światła na nieporośniętych mchem płytkach stają się coraz słabsze, natomiast podłoga wydaje się być pokryta dywanem mroku.";
	(aktualny->wyjscie)[NORTH]=getLokacja(3);
	(aktualny->wyjscie)[SOUTH]=getLokacja(1);

	temp = createItem(Pojemniki::StarySzkielet);
	temp->dodajZloto(rzucaj(16));
	temp->lista_dodaj( createItem(Questowe::OkraglySzafir) );
	(aktualny->przedmioty)->dodaj(temp);

	//////////////////	3	//////////////////
	aktualny=getLokacja(3);
	aktualny->nazwa = L"Podziemny korytarz";
	aktualny->jednorazoweZdGlob=5;
	aktualny->opis=
	 L"Patrząc pod światło możesz podziwiać dzieło zniszczenia dokonane przez naturę. Grube korzenie strąciły kamienną kostkę z sufitu i wpełzły do korytarza. Część z nich wbiła się w ścianę, reszta natomiast smętnie wisi w powietrzu. Na podłodze leża potłuczone kawałki kamiennych płytek, które spadając z sufitu roztrzaskały się i porozlatywały na wszystkie strony. Zgromadzona na nich wilgoć odbija drobiny światła dobiegające z oddali, reszta natomiast ginie we wszechogarniającej ciemności.";
	(aktualny->wyjscie)[NORTH]=getLokacja(4);
	(aktualny->wyjscie)[SOUTH]=getLokacja(2);

	temp = createItem(Pojemniki::DrewnianaSkrzynia);
	temp->ustawZamek(Klucze::KluczZZelazaProsty);
	temp->dodajZloto(rzucaj(5, 15));
	temp->lista_dodaj(createItem(Questowe::Mapa));
	temp->lista_dodaj(createItem(Consumables::MiksturaZywotnosciSlaba));
	temp->lista_dodaj(createItem(Pancerze::ZbrojaSkora));
	temp->lista_dodaj(createItem({ Pancerze::NagolennikiSkora, Pancerze::NaramiennikiSkora, Pancerze::ButySkora, Pancerze::RekawiceSkora }));
	(aktualny->przedmioty)->dodaj(temp);


	//////////////////	4	//////////////////
	aktualny=getLokacja(4);
	aktualny->nazwa = L"Koniec korytarza";
	aktualny->jednorazoweZdGlob=6;
	aktualny->opis=
	 L"Koniec korytarza jest kompletnie ciemny. Macając rękami na oślep określasz iż drzwi są przeciętnej wysokości, wykonane z drewna. Klamka jest umieszczona mniej więcej w połowie wysokości drzwi ma zakrzywiony kształt z gałką na końcu. Dotykając jej czujesz wygrawerowane na jej powierzchni zdobienia. Z powodu ciemności nie możesz określić z jakiego metalu jest wykonana.";
	(aktualny->wyjscie)[NORTH]=getLokacja(5);
	(aktualny->zamek)[NORTH]=1;
	(aktualny->wyjscie)[SOUTH]=getLokacja(3);

	postac = createChar(ListaPostaci::TestNPC);
	postac->zloto = 100;
	postac->setSklep(getLokacja(3)->przedmioty->znajdz(Pojemniki::DrewnianaSkrzynia, 1));
	(aktualny->postacie)->dodaj(postac);



	//////////////////	5	//////////////////
	aktualny=getLokacja(5);
	aktualny->nazwa = L"Wejście do piwniczki";
	aktualny->backgroundMusic=MidiFiles::LVL1;
	aktualny->opis=
	 L"To niewielkie pomieszczenie wygląda na piwniczkę. Drewniana drabina zamocowana "
	 L"do wschodniej ściany prowadzi do zamkniętej klapy w suficie. Przy przeciwległej "
	 L"ścianie znajduje się podobna klapa prowadząca na dół. Ściany i podłogi "
	 L"pomieszczenia są wykonane z kamiennych cegieł, jednak te są czyste, L"
	 L"nieporośnięte mchami. W północnej ścianie znajdują się drzwi prowadzące do "
	 L"dalszych piwniczek. Koło drzwi zamontowana w ścianie jest pochodnia rzucające "
	 L"jasne światło na całe pomieszczenie.";
	(aktualny->wyjscie)[NORTH]=getLokacja(6);
	(aktualny->zamek)[NORTH]=1;
	(aktualny->wyjscie)[SOUTH]=getLokacja(4);
	(aktualny->zamek)[SOUTH]=1;
	(aktualny->wyjscie)[UP]=getLokacja(17);
	(aktualny->zamek)[UP]=2;
	(aktualny->wyjscie)[DOWN]=getLokacja(20);
	(aktualny->zamek)[DOWN]=Klucze::KluczZBrazuLvl2;

	postac = createChar(ListaPostaci::ZakapturzonaPostac);
	(aktualny->postacie)->dodaj(postac);

	//////////////////	6	//////////////////
	aktualny=getLokacja(6);
	aktualny->nazwa = L"Wyjście z piwniczki";
	//aktualny->backgroundMusic=MIDI_BATTLE1;
	aktualny->opis=
	 L"Ściany i podłogi piwniczki podobnie jak cała piwnica są wymurowane staranną "
	 L"kamienną kostką. Wnętrza nie oświetla żadna pochodnia a blask bijący od wejście "
	 L"oświetla niewielką część pomieszczenia.  Widać iż służyło ono do składowania "
	 L"trunków- całą piwniczkę zajmuje 5 długich, ciągnących się aż po zasięg światła, L"
	 L"stojaków do przechowywania wina. W zasięgu wzroku nie dostrzegasz jednak "
	 L"żadnej butelki. Ciche szuranie i piski rozchodzą się po pomieszczeniu.";
	(aktualny->wyjscie)[NORTH]=getLokacja(10);
	(aktualny->wyjscie)[SOUTH]=getLokacja(5);
	(aktualny->zamek)[SOUTH]=1;
	(aktualny->wyjscie)[EAST]=getLokacja(12);
	(aktualny->wyjscie)[WEST]=getLokacja(7);

	(aktualny->postacie)->dodaj(createChar(ListaPostaci::SzczurJaskiniowy, ListaQuestow::TajemniczyNieznajomy, 2));

	//////////////////	7	//////////////////
	aktualny=getLokacja(7);
	aktualny->nazwa = L"Początek alejki stojaków";
	aktualny->opis=
	 L"Przed tobą ciągną się dwa długie stojaki na wino. Są one wykonane z "
	 L"podniszczałego już drewna i sięgają od podłogi do sufitu. Stojak po twojej "
	 L"lewej przylega do ściany natomiast ten po prawej stoi niczym ściana działowa. "
	 L"Deski stojaków krzyżują się ze sobą tworząc kratę w której przechowuje się "
	 L"trunki. Niestety żadnego nie dostrzegasz. Pomiędzy stojakami jest alejka "
	 L"wystarczająco szeroka aby jedna osoba mogła swobodnie spacerować pomiędzy nimi. "
	 L"Ciche szuranie i piski rozchodzą się po pomieszczeniu.";
	(aktualny->wyjscie)[NORTH]=getLokacja(8);
	(aktualny->wyjscie)[EAST]=getLokacja(6);

	//////////////////	8	//////////////////
	aktualny=getLokacja(8);
	aktualny->nazwa = L"Alejka pomiędzy stojakami";
	aktualny->opis=
	 L"Po swojej lewej i prawej masz dwa drewniane stojaki na wino. Są one wykonane z "
	 L"podniszczałego już drewna i sięgają od podłogi do sufitu. Deski stojaków "
	 L"krzyżują się ze sobą tworząc kratę w której przechowuje się trunki. Niestety "
	 L"żadnego w pobliżu nie dostrzegasz. Pomiędzy stojakami jest alejka wystarczająco "
	 L"szeroka aby jedna osoba mogła swobodnie spacerować pomiędzy nimi. Alejka "
	 L"ciągnie się prosto i ginie w mrokach. Ciche szuranie i piski rozchodzą się po "
	 L"pomieszczeniu.";
	(aktualny->wyjscie)[NORTH]=getLokacja(9);
	(aktualny->wyjscie)[SOUTH]=getLokacja(7);

	(aktualny->przedmioty)->dodaj(createItem(Questowe::KawalkiPotluczonegoSzkla));

	//////////////////	9	//////////////////
	aktualny=getLokacja(9);
	aktualny->nazwa = L"Koniec alejki";
	aktualny->opis=
	 L"Dotarłeś do końca alejki. Stojak po twojej prawej kończy się pozostawiając "
	 L"przejście do równoległych alejek. Na wprost ciebie kamienna ściana znaczy "
	 L"kraniec piwniczki. Ciche szuranie i piski rozchodzą się po pomieszczeniu.";
	(aktualny->wyjscie)[NORTH]=getLokacja(15);
	(aktualny->zamek)[NORTH]=-1;
	(aktualny->wyjscie)[SOUTH]=getLokacja(8);
	(aktualny->wyjscie)[EAST]=getLokacja(11);

	(aktualny->postacie)->dodaj(createChar(ListaPostaci::SzczurJaskiniowy, ListaQuestow::TajemniczyNieznajomy, 2));
	temp=createItem(Dzwignie::ButelkaPoWinie);
	temp->dzwigniaUstawZdarzenie(DZWIGNIA_PUSH, 1);
	(aktualny->przedmioty)->dodaj(temp);

	//////////////////	10	//////////////////
	aktualny=getLokacja(10);
	aktualny->nazwa = L"Alejka pomiędzy stojakami";
	aktualny->opis=
	 L"Po swojej lewej i prawej masz dwa drewniane stojaki na wino. Są one wykonane z "
	 L"podniszczałego już drewna i sięgają od podłogi do sufitu. Deski stojaków "
	 L"krzyżują się ze sobą tworząc kratę w której przechowuje się trunki. Niestety "
	 L"żadnego w pobliżu nie dostrzegasz. Pomiędzy stojakami jest alejka wystarczająco "
	 L"szeroka aby jedna osoba mogła swobodnie spacerować pomiędzy nimi. Alejka "
	 L"ciągnie się prosto i ginie w mrokach. Ciche szuranie i piski rozchodzą się po "
	 L"pomieszczeniu.";
	(aktualny->wyjscie)[NORTH]=getLokacja(11);
	(aktualny->wyjscie)[SOUTH]=getLokacja(6);	

	(aktualny->postacie)->dodaj(createChar(ListaPostaci::SzczurJaskiniowy, ListaQuestow::TajemniczyNieznajomy, 2));
	(aktualny->przedmioty)->dodaj(createItem(Questowe::KawalkiPotluczonegoSzkla));

	//////////////////	11	//////////////////
	aktualny=getLokacja(11);
	aktualny->nazwa = L"Koniec alejki";
	aktualny->opis=
	 L"Dotarłeś do końca alejki. Stojaki po twoich obu stronach kończą się "
	 L"pozostawiając przejście do równoległych alejek. Na wprost ciebie kamienna "
	 L"ściana znaczy kraniec piwniczki. Ciche szuranie i piski rozchodzą się po "
	 L"pomieszczeniu.";
	(aktualny->wyjscie)[SOUTH]=getLokacja(10);
	(aktualny->wyjscie)[EAST]=getLokacja(14);
	(aktualny->wyjscie)[WEST]=getLokacja(9);	

	(aktualny->postacie)->dodaj(createChar(ListaPostaci::SzczurJaskiniowy, ListaQuestow::TajemniczyNieznajomy, 2));

	//////////////////	12	//////////////////
	aktualny=getLokacja(12);
	aktualny->nazwa = L"Początek alejki stojaków";
	aktualny->opis=
	 L"Przed tobą ciągną się dwa długie stojaki na wino. Są one wykonane z "
	 L"podniszczałego już drewna i sięgają od podłogi do sufitu. Stojak po twojej "
	 L"prawej przylega do ściany natomiast ten po lewej stoi niczym ściana działowa. "
	 L"Deski stojaków krzyżują się ze sobą tworząc kratę w której przechowuje się "
	 L"trunki. Niestety żadnego nie dostrzegasz. Pomiędzy stojakami jest alejka "
	 L"wystarczająco szeroka aby jedna osoba mogła swobodnie spacerować pomiędzy nimi. "
	 L"Ciche szuranie i piski rozchodzą się po pomieszczeniu.";
	(aktualny->wyjscie)[NORTH]=getLokacja(13);
	(aktualny->wyjscie)[WEST]=getLokacja(6);	

	(aktualny->przedmioty)->dodaj(createItem(Questowe::KawalkiPotluczonegoSzkla));

	//////////////////	13	//////////////////
	aktualny=getLokacja(13);
	aktualny->nazwa = L"Alejka pomiędzy stojakami";
	aktualny->opis=
	 L"Po swojej lewej i prawej masz dwa drewniane stojaki na wino. Są one wykonane z "
	 L"podniszczałego już drewna i sięgają od podłogi do sufitu. Deski stojaków "
	 L"krzyżują się ze sobą tworząc kratę w której przechowuje się trunki. Niestety "
	 L"żadnego w pobliżu nie dostrzegasz. Pomiędzy stojakami jest alejka wystarczająco "
	 L"szeroka aby jedna osoba mogła swobodnie spacerować pomiędzy nimi. Alejka "
	 L"ciągnie się prosto i ginie w mrokach. Ciche szuranie i piski rozchodzą się po "
	 L"pomieszczeniu.";
	(aktualny->wyjscie)[NORTH]=getLokacja(14);
	(aktualny->wyjscie)[SOUTH]=getLokacja(12);		

	postac = createChar(ListaPostaci::SzczurJaskiniowy, ListaQuestow::TajemniczyNieznajomy, 2);
	postac->dodajPrzedmiot(createItem(Klucze::KluczZZelazaProsty));
	aktualny->postacie->dodaj(postac);
	aktualny->przedmioty->dodaj(createItem(Questowe::KawalkiPotluczonegoSzkla));

	//////////////////	14	//////////////////
	aktualny=getLokacja(14);
	aktualny->nazwa = L"Koniec alejki";
	aktualny->opis=
	 L"Dotarłeś do końca alejki. Stojak po twojej lewej kończy się pozostawiając "
	 L"przejście do równoległych alejek. Na wprost ciebie kamienna ściana znaczy "
	 L"kraniec piwniczki. Ciche szuranie i piski rozchodzą się po pomieszczeniu.";
	(aktualny->wyjscie)[SOUTH]=getLokacja(13);
	(aktualny->wyjscie)[WEST]=getLokacja(11);		

	//////////////////	15	//////////////////
	aktualny=getLokacja(15);
	aktualny->nazwa = L"Ukryte przejście";
	aktualny->opis=
	 L"Ukryte przejście było najwidoczniej od początku zaplanowane- jego ściany są "
	 L"pokryte tą samą staranną kamienną kostką, jedynie bardziej zarośniętą mchem i "
	 L"porostami. Przejście jest wąskie ale wystarczająco wysokie aby można było "
	 L"przejść bez schylania się. Jednak pierwsze co rzuca ci się w oczy to mnogość "
	 L"ludzkich szczątek leżących na podłodze oraz złowieszczy smród śmierci.";
	(aktualny->wyjscie)[NORTH]=getLokacja(16);
	(aktualny->wyjscie)[SOUTH]=getLokacja(9);	


	//////////////////	16	//////////////////
	aktualny=getLokacja(16);
	aktualny->nazwa = L"Legowisko ogara";
	aktualny->opis=
	 L"Jakiś opis";
	(aktualny->wyjscie)[SOUTH]=getLokacja(15);

	(aktualny->postacie)->dodaj(createChar(ListaPostaci::OgarStrazniczy));

	//////////////////	17	//////////////////

	//todo Lokacja powyzej

	//////////////////	18	//////////////////


	//////////////////	19	//////////////////


#pragma endregion
#pragma region Poziom2

	//////////////////	20	//////////////////
	aktualny=getLokacja(20);
	aktualny->nazwa = L"Wyjście z jaskiń";
	aktualny->opis=
	 L"Znajdujesz się w wysokim podziemnym korytarzu, będącym częścią jakiejś jaskini. Podłoże jest nierówne, usłane kamieniami, a z niknącego w mroku sufitu zwisają pojedyncze stalagmity. Pieczara wyglądną na niemal nietkniętą przez człowieka, gdzieniegdzie pod ścianami poustawiano zagradzające przejście kamienie, ale to jedyne oznaki ingerencji w naturalny chaos. Korytarz w tym miejscu bierze ostry zakręt na wschód, jednak panująca ciemność nie pozwala ci dostrzec gdzie biegnie dalej. W zagłębieniu zakrętu stoi oparta o ścianę drabina, oświetlona przez światło dobywające się z góry.";
	aktualny->wyjscie[SOUTH]=getLokacja(21);
	aktualny->wyjscie[EAST] = getLokacja(22);
	aktualny->wyjscie[UP] = getLokacja(5);
	(aktualny->zamek)[UP]=Klucze::KluczZBrazuLvl2;
	aktualny->jednorazoweZdGlob = ListaZdarzenGlobalnych::ZejscieDoJaskini;

	//////////////////	21	//////////////////
	aktualny=getLokacja(21);
	aktualny->nazwa = L"Drzwi w jaskini";
	aktualny->backgroundMusic = MidiFiles::LVL2;
	aktualny->opis =
	 L"W tym miejscu korytarz szybko się zwęża i kurczy, a jedyne przejście prowadzi przez mocarne drewniane drzwi. Portal drzwi zakreśla idealnie owalny kształt i jest starannie wykonany z kamiennych cegiełek. Same drzwi wyglądają raczej prosto ale wytrzymale, ich powierzchnię zajmują wypukłe kwadraty, ale poza nimi nie ma żadnych zdobień. Drzewo nie wygląda staro i jest zapewne w świetnej kondycji. Z prawej strony drzwi znajduje się mosiężny uchwyt do ich otwierania, a poniżej niego duża dziura na klucz. Dookoła drzwi zauważasz mnóstwo grzybów, zajmujących wszystkie wgłębienia w ścianie i podłodze.";
	aktualny->wyjscie[NORTH]=getLokacja(20);
	aktualny->wyjscie[SOUTH]=getLokacja(55);
	aktualny->zamek[SOUTH]= Klucze::KluczZSrebraLvl3;
	aktualny->jednorazoweZdGlob = ListaZdarzenGlobalnych::DogonienieGoblinaWJaskini;
	postac = createChar(ListaPostaci::GoblinZbieracz, ListaQuestow::GoblinyWPodziemiach, 3);
	postac->agresywny = true;
	aktualny->postacie->dodaj(postac);

	//////////////////	22	//////////////////
	aktualny=getLokacja(22);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Dwie duże skały niemal blokują przejście w tym miejscu, znajduje się jednak pomiędzy nimi wąskie przejście. Lekki wiatr przepływający przez jaskinie kumuluje się w tym miejscu, gwiżdżąc leciutko. Spoglądając przez zwężenie zauważasz iż korytarz znowu skręca, tym razem na północ.";
	aktualny->wyjscie[WEST]=getLokacja(20);
	aktualny->wyjscie[NORTH]=getLokacja(23);

	//////////////////	23	//////////////////
	aktualny=getLokacja(23);
	aktualny->nazwa = L"Rozwidlenie korytarza";
	aktualny->opis=
	 L"Główny korytarz jaskini ciągnie się dalej na północ, jednak na zachodniej ścianie znajduje się dużej wielkości dziura prowadząca do jakiejś odnogi. Ponieważ nie czujesz żadnego wiatru dochodzącego z tamtego kierunku, wnioskujesz iż musi być ona ślepym zaułkiem.";
	aktualny->wyjscie[SOUTH]=getLokacja(22);
	aktualny->wyjscie[EAST]=getLokacja(24);
	aktualny->wyjscie[NORTH]=getLokacja(27);

	//////////////////	24	//////////////////
	aktualny=getLokacja(24);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Odnoga okazuje się być dużą dziurą utworzoną przy pęknięciu skały. Olbrzymią szczelinę w skale przywalił ogromny głaz, służący teraz za sufit. W efekcie powstała wąska ale całkiem wysoka dziura w skale. Jej ściany są proste i niemalże gładkie, miejscami znajdują się tylko bruzdy po przedwiecznym pęknięciu. Dno szczeliny zajęły drobne kamienie i ziemia, tworząc całkiem solidne, choć nierówne podłoże.";
	aktualny->wyjscie[WEST]=getLokacja(23);
	aktualny->wyjscie[EAST]=getLokacja(25);

	//////////////////	25	//////////////////
	aktualny=getLokacja(25);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Idąc wzdłuż szczeliny zauważasz iż staje się ona coraz szersza, podłoże schodzi lekko w dół i staje się coraz bardziej wilgotne. W pewnym momencie pęknięcie zmienia kierunek, przez co szelina skręca na południe.";
	aktualny->wyjscie[WEST]=getLokacja(24);
	aktualny->wyjscie[SOUTH]=getLokacja(26);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinZbieracz, ListaQuestow::GoblinyWPodziemiach, 3));

	//////////////////	26	//////////////////
	aktualny=getLokacja(26);
	aktualny->nazwa = L"Wilgotny zakątek";
	aktualny->opis=
	 L"W tym miejscu widać koniec głazu będącego sufitem szczeliny- większe i mniejsze skały zasypały jej dalszą część a wraz z czasem uformowały niemalże litą ścianę. Utworzone w ten sposób pomieszczenie ma całkiem duże rozmiary, choć podłoga jest nierówna a w jej najgłębszym miejscu stoi spora kałuża wody. Wokół niej rośnie sporo mchu, a na nim nieznane ci gatunki grzybów.";
	aktualny->wyjscie[NORTH]=getLokacja(25);
	aktualny->przedmioty->dodaj(createItem(Consumables::PsiaPurchawka));

	//////////////////	27	//////////////////
	aktualny=getLokacja(27);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Leżący na podłożu głaz utworzył w tym miejscu wysoki stopień. Wspinając się na niego dostrzegasz iż niewiele dalej korytarz skręca na zachód po czym ginie w mroku.";
	aktualny->wyjscie[SOUTH]=getLokacja(23);
	aktualny->wyjscie[WEST]=getLokacja(28);

	//////////////////	28	//////////////////
	aktualny=getLokacja(28);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Korytarz w jaskini jest całkiem szeroki i wysoki, umożliwiając ci swobodne chodzenie. Ściany jaskini są chropowate, pełne drobnych pęknięć i bruzd. Drobne kamienie wyścielają nierówną podłogę korytarza. Powietrze jest czyste, chłodne i wilgotne. Dominującą ciszę zakłóca tylko głos wiatru przelatującego przez korytarz oraz okresowe kapanie wody gdzieś z oddali.";
	aktualny->wyjscie[EAST]=getLokacja(27);
	aktualny->wyjscie[WEST]=getLokacja(29);

	//////////////////	29	//////////////////
	aktualny=getLokacja(29);
	aktualny->nazwa = L"Rozwidlenie korytarza";
	aktualny->opis=
	 L"W tym miejscu korytarz skręca w prawo, a w raz z nim strumień świeżego powietrza. Po lewej zauważasz jednak niedużą dziurę prowadzącą ku ciemności.";
	aktualny->wyjscie[EAST]=getLokacja(28);
	aktualny->wyjscie[SOUTH]=getLokacja(30);
	aktualny->wyjscie[NORTH]=getLokacja(31);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinZbieracz, ListaQuestow::GoblinyWPodziemiach, 3));

	//////////////////	30	//////////////////
	aktualny=getLokacja(30);
	aktualny->nazwa = L"Wilgotny zakątek";
	aktualny->opis=
	 L"Pomieszczenie to wygląda nienaturalnie w porównaniu z całą resztą jaskini. Ściany są idealnie gładkie, proste i pozbawione nierówności. Tworzą one rodzaj pokoju wyrzeźbionego w skale, jednak nie znasz narzędzi które mogły by zrobić tak dokładnie. Podłoga jest mokra i pokryta gęstym mchem oraz grzybami. Ze sklepienia ciągle kapie woda, przez co czuć wyjątkową wilgoć.";
	aktualny->wyjscie[NORTH]=getLokacja(29);
	aktualny->przedmioty->dodaj(createItem(Consumables::PsiaPurchawka));

	//////////////////	31	//////////////////
	aktualny=getLokacja(31);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Korytarz w jaskini jest całkiem szeroki i wysoki, umożliwiając ci swobodne chodzenie. Ściany jaskini są chropowate, pełne drobnych pęknięć i bruzd. Drobne kamienie wyścielają nierówną podłogę korytarza. Powietrze jest czyste, chłodne i wilgotne. Dominującą ciszę zakłóca tylko głos wiatru przelatującego przez korytarz oraz okresowe kapanie wody gdzieś z oddali.";
	aktualny->wyjscie[SOUTH]=getLokacja(29);
	aktualny->wyjscie[NORTH]=getLokacja(32);

	//////////////////	32	//////////////////
	aktualny=getLokacja(32);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Korytarz w jaskini jest całkiem szeroki i wysoki, umożliwiając ci swobodne chodzenie. Ściany jaskini są chropowate, pełne drobnych pęknięć i bruzd. Drobne kamienie wyścielają nierówną podłogę korytarza. Powietrze jest czyste, chłodne i wilgotne. Dominującą ciszę zakłóca tylko głos wiatru przelatującego przez korytarz oraz okresowe kapanie wody gdzieś z oddali.";
	aktualny->wyjscie[NORTH]=getLokacja(33);
	aktualny->wyjscie[SOUTH]=getLokacja(31);

	//////////////////	33	//////////////////
	aktualny=getLokacja(33);
	aktualny->nazwa = L"Wejście na cmentarz";
	aktualny->opis=
	 L"Korytarz brnie nadal na przód, jednak po lewej stronie zauważasz sporej wielkości dziurę. Przyglądając się niej widzisz iż prowadzi ona do całkiem sporego pomieszczenia, znajdującego się tuż obok głównego korytarza.";
	aktualny->wyjscie[SOUTH]=getLokacja(32);
	aktualny->wyjscie[WEST]=getLokacja(34);
	aktualny->wyjscie[NORTH]=getLokacja(38);

	//////////////////	34	//////////////////
	aktualny=getLokacja(34);
	aktualny->nazwa = L"Cmentarz w jaskini";
	aktualny->opis=
	 L"Pomieszczenie za dziurą okazało się być o wiele większe niż przewidywałeś. Jego sklepienie jest wysokie na dobre kilkanaście łokci, a objętościowo pomieściłby dobre kilkadziesiąt ludzi. Wydaje się, że pełni ono rolę pewnego rodzaju cmentarza- w całym pomieszczeniu znajduje się kilkanaście małych, usypanych z kamieni kurhanów. Ułożone są równo, jednak wykonano byle jak. Nic w pokoju nie wskazuje co jest pochowane w kurhanach.";
	aktualny->wyjscie[EAST]=getLokacja(33);
	aktualny->wyjscie[WEST]=getLokacja(35);
	aktualny->wyjscie[SOUTH]=getLokacja(37);

	//////////////////	35	//////////////////
	aktualny=getLokacja(35);
	aktualny->nazwa = L"Cmentarz w jaskini";
	aktualny->opis=
	 L"Pomieszczenie za dziurą okazało się być o wiele większe niż przewidywałeś. Jego sklepienie jest wysokie na dobre kilkanaście łokci, a objętościowo pomieściłby dobre kilkadziesiąt ludzi. Wydaje się, że pełni ono rolę pewnego rodzaju cmentarza- w całym pomieszczeniu znajduje się kilkanaście małych, usypanych z kamieni kurhanów. Ułożone są równo, jednak wykonano byle jak. Nic w pokoju nie wskazuje co jest pochowane w kurhanach.";
	aktualny->wyjscie[EAST]=getLokacja(34);
	aktualny->wyjscie[SOUTH]=getLokacja(36);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinZbieracz, ListaQuestow::GoblinyWPodziemiach, 3));

	//////////////////	36	//////////////////
	aktualny=getLokacja(36);
	aktualny->nazwa = L"Cmentarz w jaskini";
	aktualny->opis=
	 L"Pomieszczenie za dziurą okazało się być o wiele większe niż przewidywałeś. Jego sklepienie jest wysokie na dobre kilkanaście łokci, a objętościowo pomieściłby dobre kilkadziesiąt ludzi. Wydaje się, że pełni ono rolę pewnego rodzaju cmentarza- w całym pomieszczeniu znajduje się kilkanaście małych, usypanych z kamieni kurhanów. Ułożone są równo, jednak wykonano byle jak. Nic w pokoju nie wskazuje co jest pochowane w kurhanach.";
	aktualny->wyjscie[NORTH]=getLokacja(35);
	aktualny->wyjscie[EAST]=getLokacja(37);
	aktualny->przedmioty->dodaj(createItem(Questowe::ZardzewialyHelm));

	//////////////////	37	//////////////////
	aktualny=getLokacja(37);
	aktualny->nazwa = L"Cmentarz w jaskini";
	aktualny->opis=
	 L"Pomieszczenie za dziurą okazało się być o wiele większe niż przewidywałeś. Jego sklepienie jest wysokie na dobre kilkanaście łokci, a objętościowo pomieściłby dobre kilkadziesiąt ludzi. Wydaje się, że pełni ono rolę pewnego rodzaju cmentarza- w całym pomieszczeniu znajduje się kilkanaście małych, usypanych z kamieni kurhanów. Ułożone są równo, jednak wykonano byle jak. Nic w pokoju nie wskazuje co jest pochowane w kurhanach.";
	aktualny->wyjscie[WEST]=getLokacja(36);
	aktualny->wyjscie[NORTH]=getLokacja(34);
	aktualny->przedmioty->dodaj(createItem({ Bronie::MieczKrotkiBraz, Bronie::MieczBraz, Bronie::ToporekBraz, Bronie::MlotBojowyBraz }));

	//////////////////	38	//////////////////
	aktualny=getLokacja(38);
	aktualny->nazwa = L"Rozwidlenie korytarza";
	aktualny->opis=
	 L"W tym miejscu korytarz ponownie się rozwidla, jego główna część wiedzie dalej na przód, wraz ze strumieniem czystego powietrza. Odnoga znajdująca się po prawej jest niemal tak duża jak główny korytarz i dochodzą z niej bliżej nie określone dźwięki.";
	aktualny->wyjscie[SOUTH]=getLokacja(33);
	aktualny->wyjscie[NORTH]=getLokacja(39);
	aktualny->wyjscie[EAST]=getLokacja(41);

	//////////////////	39	//////////////////
	aktualny=getLokacja(39);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Korytarz w jaskini jest całkiem szeroki i wysoki, umożliwiając ci swobodne chodzenie. Ściany jaskini są chropowate, pełne drobnych pęknięć i bruzd. Drobne kamienie wyścielają nierówną podłogę korytarza. Powietrze jest czyste, chłodne i wilgotne. Dominującą ciszę zakłóca tylko głos wiatru przelatującego przez korytarz oraz okresowe kapanie wody gdzieś z oddali.";
	aktualny->wyjscie[SOUTH]=getLokacja(38);
	aktualny->wyjscie[NORTH]=getLokacja(40);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinZbieracz, ListaQuestow::GoblinyWPodziemiach, 3));

	//////////////////	40	//////////////////
	aktualny=getLokacja(40);
	aktualny->nazwa = L"Gruzowisko";
	aktualny->opis=
	 L"Korytarz nagle kończy się zawaliskiem kamieni i skał. Dwa największe głazy przysypane masą mniejszych, tworzą ścianę nie do pokonania. Przyglądając się ścianom jaskini zauważasz dookoła liczne pęknięcia i szpary, zupełnie jakby sklepienie zawaliło się w tym miejscu. Nic nie wskazuje co było przyczyną zawalenia.";
	aktualny->wyjscie[SOUTH]=getLokacja(39);

	//////////////////	41	//////////////////
	aktualny=getLokacja(41);
	aktualny->nazwa = L"Korytarz w jaskini";
	aktualny->opis=
	 L"Ta odnoga jest tylko trochę mniejsza od głównego korytarza, jego wygląd jest jednak bardzo podobny. Ściany są chropowate i nierówne, podobnie jak podłoga, na której jednak zalega cienka warstwa ziemi i drobnych kamieni. Bez strumienia wiatru powietrze wydaje się duszne, oraz cieplejsze. Patrząc na przód widzisz iż korytarz jest kręty i często zmienia swój kierunek. Wydaje ci się, że dostrzegłeś błysk światła oraz jakieś odgłosy, dobywające się gdzieś zza zakrętu.";
	aktualny->wyjscie[WEST]=getLokacja(38);
	aktualny->wyjscie[EAST]=getLokacja(42);

	//////////////////	42	//////////////////
	aktualny=getLokacja(42);
	aktualny->nazwa = L"Stróżówka goblinów";
	aktualny->opis=
	 L"Ten kawałek korytarza został zajęty przez gobliny- małe i zajadłe jaskiniowe stworzenia. Wykorzystały one kręty korytarz do zorganizowania zasadzki na wszelkich zbliżających się intruzów Rozglądając się dookoła zauważasz dużo śladów ich dłuższej obecności- dogasające ognisko, pojemniki z wodą, oraz kupy szmat, które mogły służyć za posłanie.";
	aktualny->wyjscie[WEST]=getLokacja(41);
	aktualny->wyjscie[SOUTH]=getLokacja(43);
	postac = createChar(ListaPostaci::GoblinGwardzista);
	postac->agresywny = true;
	aktualny->postacie->dodaj(postac);

	//////////////////	43	//////////////////
	aktualny=getLokacja(43);
	aktualny->nazwa = L"Stróżówka goblinów";
	aktualny->opis=
	 L"Room 43.";
	aktualny->wyjscie[NORTH]=getLokacja(42);
	aktualny->wyjscie[EAST]=getLokacja(44);
	postac = createChar(ListaPostaci::GoblinGwardzista);
	postac->agresywny = true;
	aktualny->postacie->dodaj(postac);

	//////////////////	44	//////////////////
	aktualny=getLokacja(44);
	aktualny->nazwa = L"Stróżówka goblinów";
	aktualny->opis=
	 L"Room 44.";
	aktualny->wyjscie[WEST]=getLokacja(43);
	aktualny->wyjscie[SOUTH]=getLokacja(45);
	postac = createChar(ListaPostaci::GoblinGwardzista);
	postac->agresywny = true;
	aktualny->postacie->dodaj(postac);

	//////////////////	45	//////////////////
	aktualny=getLokacja(45);
	aktualny->nazwa = L"Wejście do jaskiń goblinów";
	aktualny->opis=
	 L"Room 45.";
	aktualny->wyjscie[NORTH]=getLokacja(44);
	aktualny->wyjscie[EAST]=getLokacja(46);

	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinSzaman, ListaQuestow::GoblinyWPodziemiach, 4));
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinBerserker, ListaQuestow::GoblinyWPodziemiach, 4));

	//////////////////	46	//////////////////
	aktualny=getLokacja(46);
	aktualny->nazwa = L"Jaskinia goblinów";
	aktualny->opis=
	 L"Room 46.";
	aktualny->wyjscie[WEST]=getLokacja(45);
	aktualny->wyjscie[EAST]=getLokacja(47);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinGwardzista, ListaQuestow::GoblinyWPodziemiach, 4));

	//////////////////	47	//////////////////
	aktualny=getLokacja(47);
	aktualny->nazwa = L"Jaskinia goblinów";
	aktualny->opis=
	 L"Room 47.";
	aktualny->wyjscie[WEST]=getLokacja(46);
	aktualny->wyjscie[SOUTH]=getLokacja(48);
	aktualny->wyjscie[EAST]=getLokacja(50);
	aktualny->wyjscie[NORTH]=getLokacja(52);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinBerserker, ListaQuestow::GoblinyWPodziemiach, 4));

	//////////////////	48	//////////////////
	aktualny=getLokacja(48);
	aktualny->nazwa = L"Wejście do skarbca goblinów";
	aktualny->opis=
	 L"Room 48.";
	aktualny->wyjscie[NORTH]=getLokacja(47);
	aktualny->wyjscie[SOUTH]=getLokacja(49);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinGwardzista, ListaQuestow::GoblinyWPodziemiach, 4));
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinGwardzista, ListaQuestow::GoblinyWPodziemiach, 4));

	//////////////////	49	//////////////////
	aktualny=getLokacja(49);
	aktualny->nazwa = L"Skarbiec goblinów";
	aktualny->opis=
	 L"Room 49.";
	aktualny->wyjscie[NORTH]=getLokacja(48);
	aktualny->zdGlob = ListaZdarzenGlobalnych::ZagrodzenieDrogiPrzezGwardzisteGoblinow;

	//////////////////	50	//////////////////
	aktualny=getLokacja(50);
	aktualny->nazwa = L"Wejście do namiotu szamana";
	aktualny->opis=
	 L"Room 50.";
	aktualny->wyjscie[WEST]=getLokacja(47);
	aktualny->wyjscie[EAST]=getLokacja(51);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinBerserker, ListaQuestow::GoblinyWPodziemiach, 4));

	//////////////////	51	//////////////////
	aktualny=getLokacja(51);
	aktualny->nazwa = L"Namiot szamana goblinów";
	aktualny->opis=
	 L"Room 51.";
	aktualny->wyjscie[WEST]=getLokacja(50);

	//////////////////	52	//////////////////
	aktualny=getLokacja(52);
	aktualny->nazwa = L"Jaskinia goblinów";
	aktualny->opis=
	 L"Room 52.";
	aktualny->wyjscie[SOUTH]=getLokacja(47);
	aktualny->wyjscie[EAST]=getLokacja(53);

	//////////////////	53	//////////////////
	aktualny=getLokacja(53);
	aktualny->nazwa = L"Wejście do pomieszczenia ze strumykiem";
	aktualny->opis=
	 L"Room 54.";
	aktualny->wyjscie[WEST]=getLokacja(52);
	aktualny->wyjscie[EAST]=getLokacja(54);
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinGwardzista, ListaQuestow::GoblinyWPodziemiach, 4));
	aktualny->postacie->dodaj(createChar(ListaPostaci::GoblinGwardzista, ListaQuestow::GoblinyWPodziemiach, 4));

	//////////////////	54	//////////////////
	aktualny=getLokacja(54);
	aktualny->nazwa = L"Pomieszczenie ze strumykiem";
	aktualny->opis=
	 L"Room 54.";
	aktualny->wyjscie[WEST]=getLokacja(53);
	aktualny->zdGlob = ListaZdarzenGlobalnych::ZagrodzenieDrogiPrzezGwardzisteGoblinow;

	//////////////////	55	//////////////////
	aktualny=getLokacja(55);
	aktualny->nazwa = L"Zamknięta część jaskini";
	aktualny->opis=
	 L"Room 55.";
	aktualny->wyjscie[NORTH]=getLokacja(21);
	aktualny->zamek[NORTH]=Klucze::KluczZSrebraLvl3;
	aktualny->wyjscie[SOUTH]=getLokacja(56);
	aktualny->jednorazoweZdGlob = ListaZdarzenGlobalnych::PrzejsciePrzezDrzwiDemona;

	//////////////////	56	//////////////////
	aktualny=getLokacja(56);
	aktualny->nazwa = L"Room 56";
	aktualny->opis=
	 L"Room 56.";
	aktualny->wyjscie[NORTH]=getLokacja(55);
	aktualny->wyjscie[EAST]=getLokacja(57);

	//////////////////	57	//////////////////
	aktualny=getLokacja(57);
	aktualny->nazwa = L"Room 57";
	aktualny->opis=
	 L"Room 57.";
	aktualny->wyjscie[WEST]=getLokacja(56);
	aktualny->wyjscie[NORTH]=getLokacja(58);

	//////////////////	58	//////////////////
	aktualny=getLokacja(58);
	aktualny->nazwa = L"Room 58";
	aktualny->opis=
	 L"Room 58.";
	aktualny->wyjscie[DOWN]=getLokacja(65);

#pragma endregion

#pragma region Sen 1
	//////////////////	59	//////////////////
		
	aktualny = getLokacja(59);
	aktualny->nazwa = L"Śniąca skrytka";
	aktualny->opis = L"Gracz nigdy nie odwiedzi tej lokacji, jest ona tylko po to, by przechować jego przedmioty na czas snu.";
	aktualny->postacie->dodaj(createChar(ListaPostaci::Manekin));

	//////////////////	60	//////////////////
	aktualny = getLokacja(60);
	aktualny->nazwa = L"Tłum ludzi";
	aktualny->opis =
		L"Tłum napiera na ciebie ze wszystkich stron. Nieprzebrane morze głów wydaje się ciągnąć aż po horyzont. Ludzie wiercą się, wymachują rękami i coś krzyczą, jednak nie możesz zrozumieć co. Nawet gdybyś chciał nie możesz się poruszyć, tłum ci na to nie pozwala.";
	aktualny->jednorazoweZdGlob = ListaZdarzenGlobalnych::Sen1Wstawka1;
	aktualny->postacie->dodaj(createChar(ListaPostaci::CzłowiekZTlumu));

	//////////////////	61	//////////////////
	aktualny = getLokacja(61);
	aktualny->nazwa = L"Kuchnia";
	aktualny->opis =
		L"Znajdujesz się w kuchni, rozglądając się dostrzegasz mnóstwo  kuchennego sprzętu: kocioł, garnki, miski, noże. Przyglądając się im nie możesz jednak dostrzec żadnych szczegółów ich budowy, ani tym  bardziej umieścić w konkretnym miejscu przestrzeni. Wszystko zdaje się pływać wokół ciebie i jednocześnie być dokładnie na swoim miejscu.";
	aktualny->wyjscie[DOWN] = getLokacja(62);
	aktualny->wyjscie[UP] = getLokacja(62);
	aktualny->wyjscie[NORTH] = getLokacja(62);
	aktualny->wyjscie[EAST] = getLokacja(62);
	aktualny->wyjscie[WEST] = getLokacja(62);
	aktualny->wyjscie[SOUTH] = getLokacja(62);
	aktualny->postacie->dodaj(createChar(ListaPostaci::Kucharka));

	//////////////////	62	//////////////////
	aktualny = getLokacja(62);
	aktualny->nazwa = L"Korytarz na parterze";
	aktualny->opis =
		L"Znajdujesz się w głównym korytarzu domu. Podłoga, ściany i sufit pokryte są jakimś drogim, ciemnym drewnem, nie potrafisz ustalić jaki to gatunek. Na wprost znajduje się wyjście na ganek, z lewej duże wejście do Sali jadalnej, z prawej drzwi do pokoiku gościnnego.  Obok drzwi do kuchni znajdują się duże drewniane schody na piętro. Drewniana podłoga skrzypi przy każdym twoim kroku.";
	aktualny->wyjscie[DOWN] = getLokacja(63);
	aktualny->wyjscie[UP] = getLokacja(63);
	aktualny->wyjscie[NORTH] = getLokacja(63);
	aktualny->wyjscie[EAST] = getLokacja(63);
	aktualny->wyjscie[WEST] = getLokacja(63);
	aktualny->wyjscie[SOUTH] = getLokacja(63);

	//////////////////	63	//////////////////
	aktualny = getLokacja(63);
	aktualny->nazwa = L"Korytarz na piętrze";
	aktualny->opis =
		L"Powoli wchodzisz po schodach opierając rękę na drewnianej poręczy. Na piętrze również znajduje się korytarz, tutaj jednak tylko podłoga jest wykonana z drewna. Zdobione panele i obicia idealnie komponują się z ciemnymi, drewnianymi drzwiami. Prowadzą one do sypialni domowników i gości, gabinet znajduje się na samym końcu korytarza.";
	aktualny->wyjscie[DOWN] = getLokacja(64);
	aktualny->wyjscie[UP] = getLokacja(64);
	aktualny->wyjscie[NORTH] = getLokacja(64);
	aktualny->wyjscie[EAST] = getLokacja(64);
	aktualny->wyjscie[WEST] = getLokacja(64);
	aktualny->wyjscie[SOUTH] = getLokacja(64);

	//////////////////	64	//////////////////
	aktualny = getLokacja(64);
	aktualny->nazwa = L"Wejście do gabinetu";
	aktualny->opis = L"";
	aktualny->jednorazoweZdGlob = ListaZdarzenGlobalnych::Sen1Wstawka3;
#pragma endregion

		
	//////////////////	65	//////////////////
		
		
	//////////////////	66	//////////////////
		
		
	//////////////////	67	//////////////////
		
		
	//////////////////	68	//////////////////
		
		
	//////////////////	69	//////////////////
		
		
	//////////////////	70	//////////////////
		
		
	//////////////////	71	//////////////////
		
		
	//////////////////	72	//////////////////
		
		
	//////////////////	73	//////////////////
		
		
	//////////////////	74	//////////////////
		
		
	//////////////////	75	//////////////////
		
		
	//////////////////	76	//////////////////
		
		
	//////////////////	77	//////////////////
		
		
	//////////////////	78	//////////////////
		
		
	//////////////////	79	//////////////////
		
		
	//////////////////	80	//////////////////
		
		
	//////////////////	81	//////////////////
		
		
	//////////////////	82	//////////////////
		
		
	//////////////////	83	//////////////////
		
		
	//////////////////	84	//////////////////
		
		
	//////////////////	85	//////////////////
		
		
	//////////////////	86	//////////////////
		
		
	//////////////////	87	//////////////////
		
		
	//////////////////	88	//////////////////
		
		
	//////////////////	89	//////////////////
		
		
	//////////////////	90	//////////////////
		
		
	//////////////////	91	//////////////////
		
		
	//////////////////	92	//////////////////
		
		
	//////////////////	93	//////////////////
		
		
	//////////////////	94	//////////////////
		
		
	//////////////////	95	//////////////////
		
		
	//////////////////	96	//////////////////
		
		
	//////////////////	97	//////////////////
		
		
	//////////////////	98	//////////////////
		
		
	//////////////////	99	//////////////////
		
		
	//////////////////	100	//////////////////
		
		
	//////////////////	101	//////////////////
		
		
	//////////////////	102	//////////////////
		
		
	//////////////////	103	//////////////////
		
		
	//////////////////	104	//////////////////
		
		
	//////////////////	105	//////////////////
		
		
	//////////////////	106	//////////////////
		
		
	//////////////////	107	//////////////////
		
		
	//////////////////	108	//////////////////
		
		
	//////////////////	109	//////////////////
		
		
	//////////////////	110	//////////////////
		
		
	//////////////////	111	//////////////////
		
		
	//////////////////	112	//////////////////
		
		
	//////////////////	113	//////////////////
		
		
	//////////////////	114	//////////////////
		
		
	//////////////////	115	//////////////////
		
		
	//////////////////	116	//////////////////
		
		
	//////////////////	117	//////////////////
		
		
	//////////////////	118	//////////////////
		
		
	//////////////////	119	//////////////////
		
		
	//////////////////	120	//////////////////
		
		
	//////////////////	121	//////////////////
		
		
	//////////////////	122	//////////////////
		
		
	//////////////////	123	//////////////////
		
		
	//////////////////	124	//////////////////
		
		
	//////////////////	125	//////////////////
		
		
	//////////////////	126	//////////////////
		
		
	//////////////////	127	//////////////////
		
		
	//////////////////	128	//////////////////
		
		
	//////////////////	129	//////////////////
		
		
	//////////////////	130	//////////////////
		
		
	//////////////////	131	//////////////////
		
		
	//////////////////	132	//////////////////
		
		
	//////////////////	133	//////////////////
		
		
	//////////////////	134	//////////////////
		
		
	//////////////////	135	//////////////////
		
		
	//////////////////	136	//////////////////
		
		
	//////////////////	137	//////////////////
		
		
	//////////////////	138	//////////////////
		
		
	//////////////////	139	//////////////////
		
		
	//////////////////	140	//////////////////
		
		
	//////////////////	141	//////////////////
		
		
	//////////////////	142	//////////////////
		
		
	//////////////////	143	//////////////////
		
		
	//////////////////	144	//////////////////
		
		
	//////////////////	145	//////////////////
		
		
	//////////////////	146	//////////////////
		
		
	//////////////////	147	//////////////////
		
		
	//////////////////	148	//////////////////
		
		
	//////////////////	149	//////////////////
		
		
	//////////////////	150	//////////////////
		
		
	//////////////////	151	//////////////////
		
		
	//////////////////	152	//////////////////
		
		
	//////////////////	153	//////////////////
		
		
	//////////////////	154	//////////////////
		
		
	//////////////////	155	//////////////////
		
		
	//////////////////	156	//////////////////
		
		
	//////////////////	157	//////////////////
		
		
	//////////////////	158	//////////////////
		
		
	//////////////////	159	//////////////////
		
		
	//////////////////	160	//////////////////
		
		
	//////////////////	161	//////////////////
		
		
	//////////////////	162	//////////////////
		
		
	//////////////////	163	//////////////////
		
		
	//////////////////	164	//////////////////
		
		
	//////////////////	165	//////////////////
		
		
	//////////////////	166	//////////////////
		
		
	//////////////////	167	//////////////////
		
		
	//////////////////	168	//////////////////
		
		
	//////////////////	169	//////////////////
		
		
	//////////////////	170	//////////////////
		
		
	//////////////////	171	//////////////////
		
		
	//////////////////	172	//////////////////
		
		
	//////////////////	173	//////////////////
		
		
	//////////////////	174	//////////////////
		
		
	//////////////////	175	//////////////////
		
		
	//////////////////	176	//////////////////
		
		
	//////////////////	177	//////////////////
		
		
	//////////////////	178	//////////////////
		
		
	//////////////////	179	//////////////////
		
		
	//////////////////	180	//////////////////
		
		
	//////////////////	181	//////////////////
		
		
	//////////////////	182	//////////////////
		
		
	//////////////////	183	//////////////////
		
		
	//////////////////	184	//////////////////
		
		
	//////////////////	185	//////////////////
		
		
	//////////////////	186	//////////////////
		
		
	//////////////////	187	//////////////////
		
		
	//////////////////	188	//////////////////
		
		
	//////////////////	189	//////////////////
		
		
	//////////////////	190	//////////////////
		
		
	//////////////////	191	//////////////////
		
		
	//////////////////	192	//////////////////
		
		
	//////////////////	193	//////////////////
		
		
	//////////////////	194	//////////////////
		
		
	//////////////////	195	//////////////////
		
		
	//////////////////	196	//////////////////
		
		
	//////////////////	197	//////////////////
		
		
	//////////////////	198	//////////////////
		
		
	//////////////////	199	//////////////////
		
		
	//////////////////	200	//////////////////
		
		
	//////////////////	201	//////////////////
		
		
	//////////////////	202	//////////////////
		
		
	//////////////////	203	//////////////////
		
		
	//////////////////	204	//////////////////
		
		
	//////////////////	205	//////////////////
		
		
	//////////////////	206	//////////////////
		
		
	//////////////////	207	//////////////////
		
		
	//////////////////	208	//////////////////
		
		
	//////////////////	209	//////////////////
		
		
	//////////////////	210	//////////////////
		
		
	//////////////////	211	//////////////////
		
		
	//////////////////	212	//////////////////
		
		
	//////////////////	213	//////////////////
		
		
	//////////////////	214	//////////////////
		
		
	//////////////////	215	//////////////////
		
		
	//////////////////	216	//////////////////
		
		
	//////////////////	217	//////////////////
		
		
	//////////////////	218	//////////////////
		
		
	//////////////////	219	//////////////////
		
		
	//////////////////	220	//////////////////
		
		
	//////////////////	221	//////////////////
		
		
	//////////////////	222	//////////////////
		
		
	//////////////////	223	//////////////////
		
		
	//////////////////	224	//////////////////
		
		
	//////////////////	225	//////////////////
		
		
	//////////////////	226	//////////////////
		
		
	//////////////////	227	//////////////////
		
		
	//////////////////	228	//////////////////
		
		
	//////////////////	229	//////////////////
		
		
	//////////////////	230	//////////////////
		
		
	//////////////////	231	//////////////////
		
		
	//////////////////	232	//////////////////
		
		
	//////////////////	233	//////////////////
		
		
	//////////////////	234	//////////////////
		
		
	//////////////////	235	//////////////////
		
		
	//////////////////	236	//////////////////
		
		
	//////////////////	237	//////////////////
		
		
	//////////////////	238	//////////////////
		
		
	//////////////////	239	//////////////////
		
		
	//////////////////	240	//////////////////
		
		
	//////////////////	241	//////////////////
		
		
	//////////////////	242	//////////////////
		
		
	//////////////////	243	//////////////////
		
		
	//////////////////	244	//////////////////
		
		
	//////////////////	245	//////////////////
		
		
	//////////////////	246	//////////////////
		
		
	//////////////////	247	//////////////////
		
		
	//////////////////	248	//////////////////
		
		
	//////////////////	249	//////////////////
		
		
	//////////////////	250	//////////////////
		
		
	//////////////////	251	//////////////////
		
		
	//////////////////	252	//////////////////
		
		
	//////////////////	253	//////////////////
		
		
	//////////////////	254	//////////////////
		
		
	//////////////////	255	//////////////////
		
		
	//////////////////	256	//////////////////
		
		
	//////////////////	257	//////////////////
		
		
	//////////////////	258	//////////////////
		
		
	//////////////////	259	//////////////////
		
		
	//////////////////	260	//////////////////
		
		
	//////////////////	261	//////////////////
		
		
	//////////////////	262	//////////////////
		
		
	//////////////////	263	//////////////////
		
		
	//////////////////	264	//////////////////
		
		
	//////////////////	265	//////////////////
		
		
	//////////////////	266	//////////////////
		
		
	//////////////////	267	//////////////////
		
		
	//////////////////	268	//////////////////
		
		
	//////////////////	269	//////////////////
		
		
	//////////////////	270	//////////////////
		
		
	//////////////////	271	//////////////////
		
		
	//////////////////	272	//////////////////
		
		
	//////////////////	273	//////////////////
		
		
	//////////////////	274	//////////////////
		
		
	//////////////////	275	//////////////////
		
		
	//////////////////	276	//////////////////
		
		
	//////////////////	277	//////////////////
		
		
	//////////////////	278	//////////////////
		
		
	//////////////////	279	//////////////////
		
		
	//////////////////	280	//////////////////
		
		
	//////////////////	281	//////////////////
		
		
	//////////////////	282	//////////////////
		
		
	//////////////////	283	//////////////////
		
		
	//////////////////	284	//////////////////
		
		
	//////////////////	285	//////////////////
		
		
	//////////////////	286	//////////////////
		
		
	//////////////////	287	//////////////////
		
		
	//////////////////	288	//////////////////
		
		
	//////////////////	289	//////////////////
		
		
	//////////////////	290	//////////////////
		
		
	//////////////////	291	//////////////////
		
		
	//////////////////	292	//////////////////
		
		
	//////////////////	293	//////////////////
		
		
	//////////////////	294	//////////////////
		
		
	//////////////////	295	//////////////////
		
		
	//////////////////	296	//////////////////
		
		
	//////////////////	297	//////////////////
		
		
	//////////////////	298	//////////////////
		
		
	//////////////////	299	//////////////////
		
		
	//////////////////	300	//////////////////
		
		
	//////////////////	301	//////////////////
		
		
	//////////////////	302	//////////////////
		
		
	//////////////////	303	//////////////////
		
		
	//////////////////	304	//////////////////
		
		
	//////////////////	305	//////////////////
		
		
	//////////////////	306	//////////////////
		
		
	//////////////////	307	//////////////////
		
		
	//////////////////	308	//////////////////
		
		
	//////////////////	309	//////////////////
		
		
	//////////////////	310	//////////////////
		
		
	//////////////////	311	//////////////////
		
		
	//////////////////	312	//////////////////
		
		
	//////////////////	313	//////////////////
		
		
	//////////////////	314	//////////////////
		
		
	//////////////////	315	//////////////////
		
		
	//////////////////	316	//////////////////
		
		
	//////////////////	317	//////////////////
		
		
	//////////////////	318	//////////////////
		
		
	//////////////////	319	//////////////////
		
		
	//////////////////	320	//////////////////
		
		
	//////////////////	321	//////////////////
		
		
	//////////////////	322	//////////////////
		
		
	//////////////////	323	//////////////////
		
		
	//////////////////	324	//////////////////
		
		
	//////////////////	325	//////////////////
		
		
	//////////////////	326	//////////////////
		
		
	//////////////////	327	//////////////////
		
		
	//////////////////	328	//////////////////
		
		
	//////////////////	329	//////////////////
		
		
	//////////////////	330	//////////////////
		
		
	//////////////////	331	//////////////////
		
		
	//////////////////	332	//////////////////
		
		
	//////////////////	333	//////////////////
		
		
	//////////////////	334	//////////////////
		
		
	//////////////////	335	//////////////////
		
		
	//////////////////	336	//////////////////
		
		
	//////////////////	337	//////////////////
		
		
	//////////////////	338	//////////////////
		
		
	//////////////////	339	//////////////////
		
		
	//////////////////	340	//////////////////
		
		
	//////////////////	341	//////////////////
		
		
	//////////////////	342	//////////////////
		
		
	//////////////////	343	//////////////////
		
		
	//////////////////	344	//////////////////
		
		
	//////////////////	345	//////////////////
		
		
	//////////////////	346	//////////////////
		
		
	//////////////////	347	//////////////////
		
		
	//////////////////	348	//////////////////
		
		
	//////////////////	349	//////////////////
		
		
	//////////////////	350	//////////////////
		
		
	//////////////////	351	//////////////////
		
		
	//////////////////	352	//////////////////
		
		
	//////////////////	353	//////////////////
		
		
	//////////////////	354	//////////////////
		
		
	//////////////////	355	//////////////////
		
		
	//////////////////	356	//////////////////
		
		
	//////////////////	357	//////////////////
		
		
	//////////////////	358	//////////////////
		
		
	//////////////////	359	//////////////////
		
		
	//////////////////	360	//////////////////
		
		
	//////////////////	361	//////////////////
		
		
	//////////////////	362	//////////////////
		
		
	//////////////////	363	//////////////////
		
		
	//////////////////	364	//////////////////
		
		
	//////////////////	365	//////////////////
		
		
	//////////////////	366	//////////////////
		
		
	//////////////////	367	//////////////////
		
		
	//////////////////	368	//////////////////
		
		
	//////////////////	369	//////////////////
		
		
	//////////////////	370	//////////////////
		
		
	//////////////////	371	//////////////////
		
		
	//////////////////	372	//////////////////
		
		
	//////////////////	373	//////////////////
		
		
	//////////////////	374	//////////////////
		
		
	//////////////////	375	//////////////////
		
		
	//////////////////	376	//////////////////
		
		
	//////////////////	377	//////////////////
		
		
	//////////////////	378	//////////////////
		
		
	//////////////////	379	//////////////////
		
		
	//////////////////	380	//////////////////
		
		
	//////////////////	381	//////////////////
		
		
	//////////////////	382	//////////////////
		
		
	//////////////////	383	//////////////////
		
		
	//////////////////	384	//////////////////
		
		
	//////////////////	385	//////////////////
		
		
	//////////////////	386	//////////////////
		
		
	//////////////////	387	//////////////////
		
		
	//////////////////	388	//////////////////
		
		
	//////////////////	389	//////////////////
		
		
	//////////////////	390	//////////////////
		
		
	//////////////////	391	//////////////////
		
		
	//////////////////	392	//////////////////
		
		
	//////////////////	393	//////////////////
		
		
	//////////////////	394	//////////////////
		
		
	//////////////////	395	//////////////////
		
		
	//////////////////	396	//////////////////
		
		
	//////////////////	397	//////////////////
		
		
	//////////////////	398	//////////////////
		
		
	//////////////////	399	//////////////////
		
		
	//////////////////	400	//////////////////
		
		
	//////////////////	401	//////////////////
		
		
	//////////////////	402	//////////////////
		
		
	//////////////////	403	//////////////////
		
		
	//////////////////	404	//////////////////
		
		
	//////////////////	405	//////////////////
		
		
	//////////////////	406	//////////////////
		
		
	//////////////////	407	//////////////////
		
		
	//////////////////	408	//////////////////
		
		
	//////////////////	409	//////////////////
		
		
	//////////////////	410	//////////////////
		
		
	//////////////////	411	//////////////////
		
		
	//////////////////	412	//////////////////
		
		
	//////////////////	413	//////////////////
		
		
	//////////////////	414	//////////////////
		
		
	//////////////////	415	//////////////////
		
		
	//////////////////	416	//////////////////
		
		
	//////////////////	417	//////////////////
		
		
	//////////////////	418	//////////////////
		
		
	//////////////////	419	//////////////////
		
		
	//////////////////	420	//////////////////
		
		
	//////////////////	421	//////////////////
		
		
	//////////////////	422	//////////////////
		
		
	//////////////////	423	//////////////////
		
		
	//////////////////	424	//////////////////
		
		
	//////////////////	425	//////////////////
		
		
	//////////////////	426	//////////////////
		
		
	//////////////////	427	//////////////////
		
		
	//////////////////	428	//////////////////
		
		
	//////////////////	429	//////////////////
		
		
	//////////////////	430	//////////////////
		
		
	//////////////////	431	//////////////////
		
		
	//////////////////	432	//////////////////
		
		
	//////////////////	433	//////////////////
		
		
	//////////////////	434	//////////////////
		
		
	//////////////////	435	//////////////////
		
		
	//////////////////	436	//////////////////
		
		
	//////////////////	437	//////////////////
		
		
	//////////////////	438	//////////////////
		
		
	//////////////////	439	//////////////////
		
		
	//////////////////	440	//////////////////
		
		
	//////////////////	441	//////////////////
		
		
	//////////////////	442	//////////////////
		
		
	//////////////////	443	//////////////////
		
		
	//////////////////	444	//////////////////
		
		
	//////////////////	445	//////////////////
		
		
	//////////////////	446	//////////////////
		
		
	//////////////////	447	//////////////////
		
		
	//////////////////	448	//////////////////
		
		
	//////////////////	449	//////////////////
		
		
	//////////////////	450	//////////////////
		
		
	//////////////////	451	//////////////////
		
		
	//////////////////	452	//////////////////
		
		
	//////////////////	453	//////////////////
		
		
	//////////////////	454	//////////////////
		
		
	//////////////////	455	//////////////////
		
		
	//////////////////	456	//////////////////
		
		
	//////////////////	457	//////////////////
		
		
	//////////////////	458	//////////////////
		
		
	//////////////////	459	//////////////////
		
		
	//////////////////	460	//////////////////
		
		
	//////////////////	461	//////////////////
		
		
	//////////////////	462	//////////////////
		
		
	//////////////////	463	//////////////////
		
		
	//////////////////	464	//////////////////
		
		
	//////////////////	465	//////////////////
		
		
	//////////////////	466	//////////////////
		
		
	//////////////////	467	//////////////////
		
		
	//////////////////	468	//////////////////
		
		
	//////////////////	469	//////////////////
		
		
	//////////////////	470	//////////////////
		
		
	//////////////////	471	//////////////////
		
		
	//////////////////	472	//////////////////
		
		
	//////////////////	473	//////////////////
		
		
	//////////////////	474	//////////////////
		
		
	//////////////////	475	//////////////////
		
		
	//////////////////	476	//////////////////
		
		
	//////////////////	477	//////////////////
		
		
	//////////////////	478	//////////////////
		
		
	//////////////////	479	//////////////////
		
		
	//////////////////	480	//////////////////
		
		
	//////////////////	481	//////////////////
		
		
	//////////////////	482	//////////////////
		
		
	//////////////////	483	//////////////////
		
		
	//////////////////	484	//////////////////
		
		
	//////////////////	485	//////////////////
		
		
	//////////////////	486	//////////////////
		
		
	//////////////////	487	//////////////////
		
		
	//////////////////	488	//////////////////
		
		
	//////////////////	489	//////////////////
		
		
	//////////////////	490	//////////////////
		
		
	//////////////////	491	//////////////////
		
		
	//////////////////	492	//////////////////
		
		
	//////////////////	493	//////////////////
		
		
	//////////////////	494	//////////////////
		
		
	//////////////////	495	//////////////////
		
		
	//////////////////	496	//////////////////
		
		
	//////////////////	497	//////////////////
		
		
	//////////////////	498	//////////////////
		
		
	//////////////////	499	//////////////////
		
		
	//////////////////	500	//////////////////
		
		
	//////////////////	501	//////////////////
		
		
	//////////////////	502	//////////////////
		
		
	//////////////////	503	//////////////////
		
		
	//////////////////	504	//////////////////
		
		
	//////////////////	505	//////////////////
		
		
	//////////////////	506	//////////////////
		
		
	//////////////////	507	//////////////////
		
		
	//////////////////	508	//////////////////
		
		
	//////////////////	509	//////////////////
		
		
	//////////////////	510	//////////////////
		
		
	//////////////////	511	//////////////////
		
		
	//////////////////	512	//////////////////
		
		
	//////////////////	513	//////////////////
		
		
	//////////////////	514	//////////////////
		
		
	//////////////////	515	//////////////////
		
		
	//////////////////	516	//////////////////
		
		
	//////////////////	517	//////////////////
		
		
	//////////////////	518	//////////////////
		
		
	//////////////////	519	//////////////////
		
		
	//////////////////	520	//////////////////
		
		
	//////////////////	521	//////////////////
		
		
	//////////////////	522	//////////////////
		
		
	//////////////////	523	//////////////////
		
		
	//////////////////	524	//////////////////
		
		
	//////////////////	525	//////////////////
		
		
	//////////////////	526	//////////////////
		
		
	//////////////////	527	//////////////////
		
		
	//////////////////	528	//////////////////
		
		
	//////////////////	529	//////////////////
		
		
	//////////////////	530	//////////////////
		
		
	//////////////////	531	//////////////////
		
		
	//////////////////	532	//////////////////
		
		
	//////////////////	533	//////////////////
		
		
	//////////////////	534	//////////////////
		
		
	//////////////////	535	//////////////////
		
		
	//////////////////	536	//////////////////
		
		
	//////////////////	537	//////////////////
		
		
	//////////////////	538	//////////////////
		
		
	//////////////////	539	//////////////////
		
		
	//////////////////	540	//////////////////
		
		
	//////////////////	541	//////////////////
		
		
	//////////////////	542	//////////////////
		
		
	//////////////////	543	//////////////////
		
		
	//////////////////	544	//////////////////
		
		
	//////////////////	545	//////////////////
		
		
	//////////////////	546	//////////////////
		
		
	//////////////////	547	//////////////////
		
		
	//////////////////	548	//////////////////
		
		
	//////////////////	549	//////////////////
		
		
	//////////////////	550	//////////////////
		
		
	//////////////////	551	//////////////////
		
		
	//////////////////	552	//////////////////
		
		
	//////////////////	553	//////////////////
		
		
	//////////////////	554	//////////////////
		
		
	//////////////////	555	//////////////////
		
		
	//////////////////	556	//////////////////
		
		
	//////////////////	557	//////////////////
		
		
	//////////////////	558	//////////////////
		
		
	//////////////////	559	//////////////////
		
		
	//////////////////	560	//////////////////
		
		
	//////////////////	561	//////////////////
		
		
	//////////////////	562	//////////////////
		
		
	//////////////////	563	//////////////////
		
		
	//////////////////	564	//////////////////
		
		
	//////////////////	565	//////////////////
		
		
	//////////////////	566	//////////////////
		
		
	//////////////////	567	//////////////////
		
		
	//////////////////	568	//////////////////
		
		
	//////////////////	569	//////////////////
		
		
	//////////////////	570	//////////////////
		
		
	//////////////////	571	//////////////////
		
		
	//////////////////	572	//////////////////
		
		
	//////////////////	573	//////////////////
		
		
	//////////////////	574	//////////////////
		
		
	//////////////////	575	//////////////////
		
		
	//////////////////	576	//////////////////
		
		
	//////////////////	577	//////////////////
		
		
	//////////////////	578	//////////////////
		
		
	//////////////////	579	//////////////////
		
		
	//////////////////	580	//////////////////
		
		
	//////////////////	581	//////////////////
		
		
	//////////////////	582	//////////////////
		
		
	//////////////////	583	//////////////////
		
		
	//////////////////	584	//////////////////
		
		
	//////////////////	585	//////////////////
		
		
	//////////////////	586	//////////////////
		
		
	//////////////////	587	//////////////////
		
		
	//////////////////	588	//////////////////
		
		
	//////////////////	589	//////////////////
		
		
	//////////////////	590	//////////////////
		
		
	//////////////////	591	//////////////////
		
		
	//////////////////	592	//////////////////
		
		
	//////////////////	593	//////////////////
		
		
	//////////////////	594	//////////////////
		
		
	//////////////////	595	//////////////////
		
		
	//////////////////	596	//////////////////
		
		
	//////////////////	597	//////////////////
		
		
	//////////////////	598	//////////////////
		
		
	//////////////////	599	//////////////////
		
		
	//////////////////	600	//////////////////
		
		
	//////////////////	601	//////////////////
		
		
	//////////////////	602	//////////////////
		
		
	//////////////////	603	//////////////////
		
		
	//////////////////	604	//////////////////
		
		
	//////////////////	605	//////////////////
		
		
	//////////////////	606	//////////////////
		
		
	//////////////////	607	//////////////////
		
		
	//////////////////	608	//////////////////
		
		
	//////////////////	609	//////////////////
		
		
	//////////////////	610	//////////////////
		
		
	//////////////////	611	//////////////////
		
		
	//////////////////	612	//////////////////
		
		
	//////////////////	613	//////////////////
		
		
	//////////////////	614	//////////////////
		
		
	//////////////////	615	//////////////////
		
		
	//////////////////	616	//////////////////
		
		
	//////////////////	617	//////////////////
		
		
	//////////////////	618	//////////////////
		
		
	//////////////////	619	//////////////////
		
		
	//////////////////	620	//////////////////
		
		
	//////////////////	621	//////////////////
		
		
	//////////////////	622	//////////////////
		
		
	//////////////////	623	//////////////////
		
		
	//////////////////	624	//////////////////
		
		
	//////////////////	625	//////////////////
		
		
	//////////////////	626	//////////////////
		
		
	//////////////////	627	//////////////////
		
		
	//////////////////	628	//////////////////
		
		
	//////////////////	629	//////////////////
		
		
	//////////////////	630	//////////////////
		
		
	//////////////////	631	//////////////////
		
		
	//////////////////	632	//////////////////
		
		
	//////////////////	633	//////////////////
		
		
	//////////////////	634	//////////////////
		
		
	//////////////////	635	//////////////////
		
		
	//////////////////	636	//////////////////
		
		
	//////////////////	637	//////////////////
		
		
	//////////////////	638	//////////////////
		
		
	//////////////////	639	//////////////////
		
		
	//////////////////	640	//////////////////
		
		
	//////////////////	641	//////////////////
		
		
	//////////////////	642	//////////////////
		
		
	//////////////////	643	//////////////////
		
		
	//////////////////	644	//////////////////
		
		
	//////////////////	645	//////////////////
		
		
	//////////////////	646	//////////////////
		
		
	//////////////////	647	//////////////////
		
		
	//////////////////	648	//////////////////
		
		
	//////////////////	649	//////////////////
		
		
	//////////////////	650	//////////////////
		
		
	//////////////////	651	//////////////////
		
		
	//////////////////	652	//////////////////
		
		
	//////////////////	653	//////////////////
		
		
	//////////////////	654	//////////////////
		
		
	//////////////////	655	//////////////////
		
		
	//////////////////	656	//////////////////
		
		
	//////////////////	657	//////////////////
		
		
	//////////////////	658	//////////////////
		
		
	//////////////////	659	//////////////////
		
		
	//////////////////	660	//////////////////
		
		
	//////////////////	661	//////////////////
		
		
	//////////////////	662	//////////////////
		
		
	//////////////////	663	//////////////////
		
		
	//////////////////	664	//////////////////
		
		
	//////////////////	665	//////////////////
		
		
	//////////////////	666	//////////////////
		
		
	//////////////////	667	//////////////////
		
		
	//////////////////	668	//////////////////
		
		
	//////////////////	669	//////////////////
		
		
	//////////////////	670	//////////////////
		
		
	//////////////////	671	//////////////////
		
		
	//////////////////	672	//////////////////
		
		
	//////////////////	673	//////////////////
		
		
	//////////////////	674	//////////////////
		
		
	//////////////////	675	//////////////////
		
		
	//////////////////	676	//////////////////
		
		
	//////////////////	677	//////////////////
		
		
	//////////////////	678	//////////////////
		
		
	//////////////////	679	//////////////////
		
		
	//////////////////	680	//////////////////
		
		
	//////////////////	681	//////////////////
		
		
	//////////////////	682	//////////////////
		
		
	//////////////////	683	//////////////////
		
		
	//////////////////	684	//////////////////
		
		
	//////////////////	685	//////////////////
		
		
	//////////////////	686	//////////////////
		
		
	//////////////////	687	//////////////////
		
		
	//////////////////	688	//////////////////
		
		
	//////////////////	689	//////////////////
		
		
	//////////////////	690	//////////////////
		
		
	//////////////////	691	//////////////////
		
		
	//////////////////	692	//////////////////
		
		
	//////////////////	693	//////////////////
		
		
	//////////////////	694	//////////////////
		
		
	//////////////////	695	//////////////////
		
		
	//////////////////	696	//////////////////
		
		
	//////////////////	697	//////////////////
		
		
	//////////////////	698	//////////////////
		
		
	//////////////////	699	//////////////////
		
		
	//////////////////	700	//////////////////
		
		
	//////////////////	701	//////////////////
		
		
	//////////////////	702	//////////////////
		
		
	//////////////////	703	//////////////////
		
		
	//////////////////	704	//////////////////
		
		
	//////////////////	705	//////////////////
		
		
	//////////////////	706	//////////////////
		
		
	//////////////////	707	//////////////////
		
		
	//////////////////	708	//////////////////
		
		
	//////////////////	709	//////////////////
		
		
	//////////////////	710	//////////////////
		
		
	//////////////////	711	//////////////////
		
		
	//////////////////	712	//////////////////
		
		
	//////////////////	713	//////////////////
		
		
	//////////////////	714	//////////////////
		
		
	//////////////////	715	//////////////////
		
		
	//////////////////	716	//////////////////
		
		
	//////////////////	717	//////////////////
		
		
	//////////////////	718	//////////////////
		
		
	//////////////////	719	//////////////////
		
		
	//////////////////	720	//////////////////
		
		
	//////////////////	721	//////////////////
		
		
	//////////////////	722	//////////////////
		
		
	//////////////////	723	//////////////////
		
		
	//////////////////	724	//////////////////
		
		
	//////////////////	725	//////////////////
		
		
	//////////////////	726	//////////////////
		
		
	//////////////////	727	//////////////////
		
		
	//////////////////	728	//////////////////
		
		
	//////////////////	729	//////////////////
		
		
	//////////////////	730	//////////////////
		
		
	//////////////////	731	//////////////////
		
		
	//////////////////	732	//////////////////
		
		
	//////////////////	733	//////////////////
		
		
	//////////////////	734	//////////////////
		
		
	//////////////////	735	//////////////////
		
		
	//////////////////	736	//////////////////
		
		
	//////////////////	737	//////////////////
		
		
	//////////////////	738	//////////////////
		
		
	//////////////////	739	//////////////////
		
		
	//////////////////	740	//////////////////
		
		
	//////////////////	741	//////////////////
		
		
	//////////////////	742	//////////////////
		
		
	//////////////////	743	//////////////////
		
		
	//////////////////	744	//////////////////
		
		
	//////////////////	745	//////////////////
		
		
	//////////////////	746	//////////////////
		
		
	//////////////////	747	//////////////////
		
		
	//////////////////	748	//////////////////
		
		
	//////////////////	749	//////////////////
		
		
	//////////////////	750	//////////////////
		
		
	//////////////////	751	//////////////////
		
		
	//////////////////	752	//////////////////
		
		
	//////////////////	753	//////////////////
		
		
	//////////////////	754	//////////////////
		
		
	//////////////////	755	//////////////////
		
		
	//////////////////	756	//////////////////
		
		
	//////////////////	757	//////////////////
		
		
	//////////////////	758	//////////////////
		
		
	//////////////////	759	//////////////////
		
		
	//////////////////	760	//////////////////
		
		
	//////////////////	761	//////////////////
		
		
	//////////////////	762	//////////////////
		
		
	//////////////////	763	//////////////////
		
		
	//////////////////	764	//////////////////
		
		
	//////////////////	765	//////////////////
		




}