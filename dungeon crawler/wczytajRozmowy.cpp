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
	wstring temp; //do przechowywania pomocniczych tekst�w

	switch (id)
	{
#pragma region zakapturzona_postac
	case ListaPostaci::ZakapturzonaPostac:
		postac->rozmowa->obecnaKwestia = 2;

		kwestia = new Kwestia(1, 1,
			L"Witaj, czego ci trzeba?");
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�.", -1);
		kwestia->dodajOdpowiedz(L"Zabi�em szczury w piwniczce, tak jak chcia�e�.", 12)
			->DodajWymaganieQuestFaza(ListaQuestow::TajemniczyNieznajomy, { 2 });
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			L"Na �rodku pomieszczenia stoi tajemnicza osoba ubrana w d�ug� szat�. "
			L"Kaptur ca�kowicie zas�ania jej twarz. Kiedy tylko ci� zauwa�a odzywa si�: "
			L"\"Witaj " + gracz.imie + L"\".");
		kwestia->dodajOdpowiedz(L"\"Kim jeste�?\"", 3);
		kwestia->dodajOdpowiedz(L"\"Sk�d znasz moje imi�?\"", 4);
		kwestia->dodajOdpowiedz(L"\"Gdzie ja jestem?\"", 5);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(3, 3,
			L"\"Moje imi� jest niewa�ne, jestem tylko s�ug� i spe�niam swoje obowi�zki."
			L"Jestem tu aby ci� obserwowa� i pomaga� ci. Chcia�bym aby� wykona� dla mnie "
			L"pewne zadanie.\"");
		kwestia->dodajOdpowiedz(L"\"Sk�d znasz moje imi�?\"", 4);
		kwestia->dodajOdpowiedz(L"\"Gdzie ja jestem?\"", 5);
		kwestia->dodajOdpowiedz(L"\"Jakie zadanie?\"", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(4, 4,
			L"\"Wiem o tobie znacznie wi�cej, ale nie wi�cej ni� jest mi to potrzebne aby m�c "
			L"ci s�u�y� pomoc�. Chcia�bym aby� wykona� da mnie pewne zadanie.\"");
		kwestia->dodajOdpowiedz(L"\"Kim jeste�?\"", 3);
		kwestia->dodajOdpowiedz(L"\"Gdzie ja jestem?\"", 5);
		kwestia->dodajOdpowiedz(L"\"Jakie zadanie?\"", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(5, 5,
			L"\"Jeste� w podziemiach pewnej wie�y. Jedyne wyj�cie to klapa nad nami, niestety "
			L"w�a�ciciel wie�y zamkn�� j� na amen.\"");
		kwestia->dodajOdpowiedz(L"\"Wi�c jak si� st�d wydosta�?\"", 6);
		kwestia->dodajOdpowiedz(L"\"Co to za wie�a?\"", 7);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(6, 6,
			L"\"Wydostanie si� st�d nie b�dzie �atwe, ale pomog� ci. Najpierw musisz jednak "
			L"wype�ni� pewne zadanie.\"");
		kwestia->dodajOdpowiedz(L"\"Kim jeste�?\"", 3);
		kwestia->dodajOdpowiedz(L"\"Sk�d znasz moje imi�?\"", 4);
		kwestia->dodajOdpowiedz(L"\"Jakie zadanie?\"", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(7, 7,
			L"�Z czasem si� dowiesz.�");
		kwestia->dodajOdpowiedz(L"\"Kim jest w�a�ciciel wierzy?\"", 7);
		kwestia->dodajOdpowiedz(L"\"Wi�c jak si� st�d wydosta�?\"", 6);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(8, 8,
			L"\"Kiedy� by�e� wielkim wojownikiem. Chc�c wydosta� si� z tego miejsca b�dziesz "
			L"musia� przypomnie� sobie jak walczy�. Chc� aby� znalaz� sobie jak�� bro� i "
			L"zabi� wszystkie szczury w pomieszczeniu za moimi plecami.\"");
		kwestia->dodajOdpowiedz(L"\"Szczury?\"", 9);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(9, 9,
			L"\"Tak, szczury. Chc� si� upewni�, �e nadal wiesz jak walczy�, zanim staniesz "
			L"przed wi�kszymi wyzwaniami.\"");
		kwestia->dodajNagrodeQuestFaza(1, 1);
		kwestia->dodajOdpowiedz(L"\"Dobrze, zrobi� to.\"", 10);
		kwestia->dodajOdpowiedz(L"\"Szczury nie s� dla mnie wyzwaniem.\"", 10);
		kwestia->dodajOdpowiedz(L"\"Nie mam ochoty bawi� si� w zabijanie jakich� szczur�w.\"", 11, -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(10, 1,
			L"\"W takim razie id� i je zabij. Poczekam tutaj na ciebie.\"");
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�.", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(11, 1,
			L"\"Ale i tak to zrobisz. Poczekam tutaj a� sko�czysz.\"");
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�.", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(12, 12,
			L"\"Dobrze. Zapewne masz du�o pyta� dotycz�cych siebie, tego miejsca i ca�ej "
			L"tej sytuacji. Niestety teraz nie mog� ci powiedzie� du�o wi�cej ponadto co ci ju� powiedzia�em.\"");
		kwestia->dodajNagrodeGraczDoswiadczenie(5);
		kwestia->dodajOdpowiedz(L"\"Dlaczego nie mo�esz mi nic powiedzie�?\"", 13);
		kwestia->dodajOdpowiedz(L"\"Nie mo�esz czy raczej nie chcesz?\"", 14);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(13, 13,
			L"\"Jestem zwi�zany przysi�g� wobec tych, kt�rym s�u��. Odpowiem ci na wszystkie pytania kiedy oni stwierdz� i� nadszed� czas.\"");
		kwestia->dodajOdpowiedz(L"\"W takim razie pom�wmy o tym jak si� st�d wydosta�.\"", 15);
		kwestia->dodajOdpowiedz(L"\"G�wno mnie obchodz� jakie� durne przysi�gi. Chc� wiedzie� co si� tu u diab�a dzieje!\"", 17);
		kwestia->dodajOdpowiedz(L"\"Komu s�u�ysz?\"", 16);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(14, 14,
			L"\"I to i to po cz�ci. Jestem tu z obowi�zku i nie darz� ci� zbytni� sympati�. Zw�aszcza zwa�ywszy na to kim by�e� w przesz�o�ci.\"");
		kwestia->dodajOdpowiedz(L"\"W takim razie pom�wmy o tym jak si� st�d wydosta�.\"", 15);
		kwestia->dodajOdpowiedz(L"\"A kim by�em?\"", 16);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(15, 15,
			L"\"Dobrze. Znajdujemy si� w podziemiach wie�y pewnego maga. Stworzy� on rozbudowany system loch�w, L"
			L"chroni�cych dost�p do jego laboratorium na samym dole. Jedynie on posiada klucz otwieraj�cy "
			L"wyj�cie na powierzchni�. Je�eli chcesz st�d uciec, b�dziesz musia� go zdoby�.\"");
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(16, 16,
			L"\"Wszystkiego dowiesz si� w swoim czasie.\"");
		kwestia->dodajOdpowiedz(L"\"W takim razie pom�wmy o tym jak si� st�d wydosta�.\"", 15);
		kwestia->dodajOdpowiedz(L"\"Przesta� pierdoli� i zacznij gada� jak cz�owiek.\"", 17);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(17, 17,
			L"\"Jak zawsze porywczy� Poznasz odpowiedzi na swoje pytania, tylko jeszcze nie teraz. "
			L"P�ki co lepiej by by�o gdyby� skupi� si� na wydostaniu z tego miejsca.\"");
		kwestia->dodajOdpowiedz(L"\"W takim razie pom�wmy o tym jak si� st�d wydosta�.\"", 15);
		kwestia->dodajOdpowiedz(L"\"Spierdalaj.\"", 18);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(18, 1,
			L"\"W takim razie we� ten klucz i sam znajd� sobie wyj�cie. Jeszcze si� spodkamy.\"");
		kwestia->dodajNagrodeQuestFaza(ListaQuestow::TajemniczyNieznajomy, 4);
		kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZBrazuLvl2);
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�.", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(19, 19,
			L"\"Co jeszcze chcesz wiedzie�?\"");
		kwestia->dodajOdpowiedz(L"\"Rozbudowany system loch�w? Serio?\"", 20);
		kwestia->dodajOdpowiedz(L"\"Czy odda on ten klucz po dobroci?\"", 21);
		kwestia->dodajOdpowiedz(L"\"Nie mog� spr�bowa� wywa�y� tego wyj�cia?\"", 22);
		kwestia->dodajOdpowiedz(L"\"Pomo�esz mi?\"", 23);
		kwestia->dodajOdpowiedz(L"\"Nie mam wi�cej pyta�, chc� rusza� w drog�.\"", 24);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(20, 20,
			L"\"To nie ja jestem szalonym magiem. Najwidoczniej chce by� pewny, �e �adne jego "
			L"eksperymenty nie wydostan� si� na zewn�trz. I wice wersa. Na twoim miejscu by�bym ostro�ny.\"");
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(21, 21,
			L"\"Nie by�bym tego taki pewien, w ko�cu nie bez powodu zamkn�� to miejsce na klucz. "
			L"Pami�taj jednak, �e to cz�owiek, je�eli znajdzie korzy�� w oddaniu ci klucza to zrobi to. Wszystko zale�y od ciebie.\"");
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(22, 22,
			L"\"Strata czasu. Tylko sp�jrz na nie: solidna kupa stali. Trzeba by nie byle wo�a aby cho�by drgn�o.\"");
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(23, 23,
			L"\"Nie mog� z tob� wyruszy� i ci pomaga�, ale niebezpiecznie jest i�� samemu. Prosz� we� ten miecz, z "
			L"pewno�ci� przyda ci si� prawdziwa bro�. Poni�ej b�dziesz m�g� polega� tylko na sobie i na swojej broni. "
			L"Ponadto kiedy sko�czymy rozmow� ch�tnie pomog� ci potrenowa� twoje zdolno�ci bojowe. Ale sam trening to "
			L"nie wszystko, prawdziwy wojownik musi ��czy� trening z prawdziw� walk� je�eli chce si� doskonali�.\"");
		kwestia->dodajNagrodeGraczItem(ListaItemow::Bronie::MieczKrotkiBraz);
		kwestia->dodajOdpowiedz(L"Dalej.", 19);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(24, 1,
			L"\"Prosz�, oto klucz otwieraj�cy przej�cie na d�. Znajduje si� tam jaskinia w kt�rej �yje plemi� "
			L"prymitywnych goblin�w. Ich w�dz posiada klucz otwieraj�cy przej�cie w ni�sze partie jaskini, sam "
			L"zdecydujesz jak go zdob�dziesz. Kiedy ju� to zrobisz ruszaj w g��b podziemi, tw�j cel znajduje si� na "
			L"samym dole.  Jeszcze si� spotkamy. Powodzenia.\"");
		kwestia->dodajNagrodeQuestFaza(ListaQuestow::TajemniczyNieznajomy, 3);
		kwestia->dodajNagrodeQuestFaza(ListaQuestow::GoblinyWPodziemiach, 2);
		kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZBrazuLvl2);
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�.", -1);
		postac->dodajKwestie(kwestia);
		break;
#pragma endregion

#pragma region testNPC
	case ListaPostaci::TestNPC:
		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			L"Witaj, czego ci trzeba?");
		kwestia->dodajOdpowiedz(L"Daj mi z�oto. Przy okazji jest to jaka� niedorzecznie d�uga wypowied� maj�ca sprawdzi� jak dzia�a wersalikowanie odpowiedzi w rozmowie. ", 2);
		kwestia->dodajOdpowiedz(L"Zabierz mi z�oto.", 3)
			->DodajWymaganieZloto(100);
		kwestia->dodajOdpowiedz(L"Daj mi expy", 4);
		kwestia->dodajOdpowiedz(L"Daj mi klejnot.", 5);
		kwestia->dodajOdpowiedz(L"Zabierz mi klejnot.", 6)
			->DodajWymaganieItem(Questowe::OkraglySzafir);
		kwestia->dodajOdpowiedz(L"W podziemiach czuj� si� jak w domu!", 7)
			->DodajWymaganieRasa(RASA_GNOM | RASA_KRASNOLUD);
		kwestia->dodajOdpowiedz(L"Spr�buj mnie zabi� pusta pauko!", -2);
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�.", -1)
			->DodajWymaganieZdarzenieGlobalne(7);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			L"Dostajesz z�oto.");
		kwestia->dodajNagrodeGraczZloto(100);
		kwestia->dodajOdpowiedz(L"Dalej.", 1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(3, 3,
			L"Zabieram ci z�oto");
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
			L"No fajnie, jeste� krasnoludem lub gnomem, gratulacje.");
		kwestia->dodajOdpowiedz(L"Dalej.", 1);
		postac->dodajKwestie(kwestia);
		break;
#pragma endregion

#pragma region Goblin szaman
	case ListaPostaci::GoblinSzaman:
		temp = gracz.rasa->nazwaGoblinska;

		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			L"�Sta�! Ty zabija� nie wi�cej. Torag Mora, m�dry, jego bracia martwi. Nie wi�cej! My rozmawia�.�");
		kwestia->dodajOdpowiedz(L"�Nie obchodzi mnie co masz do powiedzenia. Bro� si�!�", -2);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu", 2, -10)
			->DodajWymaganieRasa(RASA_ELF | RASA_POLELF | RASA_MROCZNYELF | RASA_NIZIOLEK | RASA_SIDAN | RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu", 3, -5)
			->DodajWymaganieRasa(RASA_KRASNOLUD | RASA_ORK | RASA_LACERT | RASA_GNOM);
		kwestia->dodajOdpowiedz(L"�Co niby taka poczwara mo�e mie� do powiedzenia?�", 4);
		kwestia->dodajOdpowiedz(L"�M�w, s�ucham Ci�.�", 4);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			L"Wykorzystuj�c element zaskoczenia podnosisz bro� i atakujesz ni� rozm�wc�. Trafiasz go prosto w g�ow� i goblin pada na ziemi�. Reszta plemienia widz�c to, z krzykiem rzuca si� na ciebie.");
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::MorderstwoSzamanaGoblinow);
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(3, 3,
			L"Wykorzystuj�c element zaskoczenia podnosisz bro� i atakujesz ni� rozm�wc�. Robisz to jednak niezdarnie i goblin wykonuje unik, po czym zaczyna ucieka�. Drog� zast�puje ci reszta plemienia.");
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::UcieczkaSzamanaGoblinow);
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(4, 4,
			L"�Goba nie tw�j wr�g. Bia�y demon wi�zi� goba, my nie jego s�ugi. Torag rozmawia� " + temp + L", goba nie gin�� wi�cej.�");
		kwestia->dodajOdpowiedz(L"Dalej", 5)
			->DodajWymaganieQuestFaza(ListaQuestow::GoblinyWPodziemiach, { 3 });
		kwestia->dodajOdpowiedz(L"Dalej", 6)
			->DodajWymaganieQuestFaza(ListaQuestow::GoblinyWPodziemiach, { 0, 1, 2 });
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(5, 5,
			L"�Twoja bro� mie� krew goba, Torag martwi� si� nie zgin��. " + temp + L" odda� bro� i my i�� do chata, tam my rozmawia�.�");
		kwestia->dodajOdpowiedz(L"Oddaj mu bro�", 7);
		kwestia->dodajOdpowiedz(L"�Nie nabierzesz mnie na takie sztuczki! Gi�!�", -2);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu", 2, -10)
			->DodajWymaganieRasa(RASA_ELF | RASA_POLELF | RASA_MROCZNYELF | RASA_NIZIOLEK | RASA_SIDAN | RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu", 3, -5)
			->DodajWymaganieRasa(RASA_KRASNOLUD | RASA_ORK | RASA_LACERT | RASA_GNOM);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(6, 6,
			L"�Tu my nie rozmawia�. Du�o uchi goba nie trzeba. My i�� do chata, tam Torag m�wi�, L" + temp + L" s�ucha�.�");
		kwestia->dodajOdpowiedz(L"�Sk�d mam wiedzie�, �e nie chcecie mnie otoczy� i zabi�?�", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(7, 9,
			L"�Torag rad, L" + temp + L" wiedza.Rozmowa du�o dobra.My i��.�");
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinowZOddaniemBroni);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(8, 9,
			L"�" + temp + L" zabi� silne goba.My nie wi�cej tutaj, nie chcie� gin��.Bia�y demon s�ucha�.Torag m�wi� tutaj demon zabija� goba.Is�!I��!�");
		kwestia->dodajOdpowiedz(L"�Niech b�dzie. Prowad�.�", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow);
		kwestia->dodajOdpowiedz(L"�Nie ufam Ci ropucho. Prowad�, ale nie wykonuj �adnych gwa�townych ruch�w.�", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow);
		kwestia->dodajOdpowiedz(L"�Bardzo sprytne, jednak chyba wol� po prostu zabi�.�", -2);
		kwestia->dodajOdpowiedz(L"Zabij go na miejscu�", 2);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(9, 9,
			L"�My tu m�wi� bezpiecznie. Ja Torag Mora, by� kiedy� silny wielki w�dz. Zabi� i zje�� inne Goba, zbiera� ich samice. Ale Torag zha�biony, nie godzien swoje imi�. Nie godzien wielki w�dz.�");
		kwestia->dodajOdpowiedz(L"Dalej", 10);
		kwestia->dodajOdpowiedz(L"�Streszczaj si�, twoje st�kanie dzia�a mi ju� na nerwy.�", 11, -2);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(10, 10,
			L"�Torag zdoby� �atwy �up, wpa�� w pu�apka. Bia�y demon uwi�zi� Torag, jego braci i samice. Goba musie� s�ucha� demon aby mie� co je��. Goba strzec jaskinia, wtedy goba �yj�. Inaczej bia�y demon ubija� goba.�");
		kwestia->dodajOdpowiedz(L"Dalej", 11);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(11, 11,
			L"�Goba nie znie�� tego wi�cej, woli raczej zgni�. Ty " + temp + L" wielki wojownik.Wzi�� ten klucz, one otworz� drzwi bia�ego demona.Ty z nim walczy� i zabi� - goba by� wolne.Ty zgin��, goba zgin�� tak�e.�");
		kwestia->dodajOdpowiedz(L"�Dlaczego niby mia�bym to robi�?�", 12);
		kwestia->dodajOdpowiedz(L"�Co to jest ten ca�y bia�y demon?�", 16);
		kwestia->dodajOdpowiedz(L"�Co b�dziecie robi� kiedy odzyskacie wolno��?�", 14);
		kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZSrebraLvl3);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(12, 12,
			L"�Torag pom�c " + temp + L" i da� klucz. Teraz " + temp + L" musie� pom�c Goba.�");
		kwestia->dodajOdpowiedz(L"�Zatem niech tak b�dzie. Spr�buj� wam pom�c.�", 13);
		kwestia->dodajOdpowiedz(L"�Ma�o mnie obchodz� wasze problemy, ale chyba i tak przyjdzie mi si� zmierzy� z tym ca�ym bia�ym demonem.", 13);
		kwestia->dodajOdpowiedz(L"�Co b�dziecie robi� kiedy odzyskacie wolno��?�", 14);
		kwestia->dodajOdpowiedz(L"�Co to jest ten ca�y bia�y demon?�", 16);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(13, 17,
			L"�|^" + temp + L" rusza� natychmiast. Bia�y demon wielka magia, wiedzie� du�o. Torag zmartwiony o �ycie goba. I��! I��!�");
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�.", KoniecRozmowy);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(14, 14,
			L"�Torag Mora chcie� odzyska� zaszczyt swojego imienia. Robi� wielkie rzeczy aby jego bracia znowu robi� strach. |+ L" + temp + L" nie rozumie�.�");
		kwestia->dodajOdpowiedz(L" �Rozumiem wi�cej ni� Ci si� zdaje.�", 15)
			->DodajWymaganieRasa(RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz(L"�W sumie i tak ma�o mnie to obchodzi.�", 13);
		kwestia->dodajOdpowiedz(L"�Nie wierz� w ani jedno twoje s�owo, pod�a kreaturo, a teraz gi�!�", KoniecRozmowyWalka);
		kwestia->dodajOdpowiedz(L"�Bardzo ciekawa historia, ale wol� nie zostawia� zgrai gobelin�w za plecami. Da�e� mi klucz, wi�c mo�esz spokojnie zdycha�.�", KoniecRozmowyWalka);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(15, 15,
			L"�Co Tora m�wi�?�");
		kwestia->dodajOdpowiedz(L"�Ci�gle m�wisz na mnie Tora, musi to oznacza� �cz�owiek�. Mora brzmi jak �zag�ada�. Twoje parszywe plemi� scze�nie w tej jaskini, a ty zap�acisz za swoje zbrodnie!�", KoniecRozmowyWalka);
		kwestia->dodajOdpowiedz(L"�W sumie nie wa�ne.�", 13);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(16, 16,
			L"�Demon jest magia. Wielki, stary, z�y i straszny. Zabija� Goba ruchem r�ki i kruszy� g�azy s�owami.�");
		kwestia->dodajOdpowiedz(L"�Dlaczego mia�bym wam pom�c?�", 12);
		kwestia->dodajOdpowiedz(L"�Zatem niech b�dzie, spr�buj� wam pom�c.�", 13);
		kwestia->dodajOdpowiedz(L"�Co b�dziecie robi� kiedy odzyskacie wolno��?�", 14);
		kwestia->dodajOdpowiedz(L"�Wkurza mnie ju� to twoje pieprzenie, my�l�, �e ci� zabij�.�", KoniecRozmowyWalka);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(17, 17,
			L"�|^" + temp + L" dzia�a�, Goba nic nie mie� m�wi� wi�cej!�");
		kwestia->dodajOdpowiedz(L"Zako�cz rozmow�.", KoniecRozmowy);
		postac->dodajKwestie(kwestia);

		break;

#pragma endregion

#pragma region Cz�owiek z t�umu
	case ListaPostaci::Cz�owiekZTlumu:
		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			L"Klepiesz pierwszego lepszego cz�owieka z brzegu, chc�c zada� mu kilka pyta�. Cz�owiek odwraca si� do ciebie i niezbyt mi�ym tonem oznajmia: �Czego?�");
		kwestia->dodajOdpowiedz(L"�Gdzie ja jestem?�", 2);
		kwestia->dodajOdpowiedz(L"�Co tu si� dzieje?�", 2);
		kwestia->dodajOdpowiedz(L"�Kogo wieszaj�?�", 2);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			L"�Nie zadawaj g�upich pyta� tylko patrz. Patrz. Patrz...�");
		kwestia->dodajOdpowiedz(L"Patrz...", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::Sen1Wstawka2);
		postac->dodajKwestie(kwestia);
		break;
#pragma endregion

#pragma region Kucharka
	case ListaPostaci::Kucharka:
		postac->rozmowa->obecnaKwestia = 1;

		kwestia = new Kwestia(1, 1,
			L"Stara Kucharka patrzy na ciebie z nieukrywanym wyrzutem. �Patrz co�e� zrobi�a, m�wi�am uwa�aj! Teraz ca�e mi�so p�jdzie najwy�ej na mielone!�");
		kwestia->dodajOdpowiedz(L"�Przepraszam ciociu.�", 2);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, -1,
			L"�Pan ma go�cia, lepiej id� spytaj si� czy czego� potrzebuj�. Tylko migiem! Potrzebujem jeszcze twojej pomocy przy obiedzie.�");
		kwestia->dodajOdpowiedz(L"�Ju�, ju� ciociu.�", -1);
		postac->dodajKwestie(kwestia);
		break;
#pragma endregion
	default:
		break;
	}
}