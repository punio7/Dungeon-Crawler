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
	string temp; //do przechowywania pomocniczych tekst�w

	switch (id)
	{
#pragma region zakapturzona_postac
	case 2:
		{
			postac->rozmowa->obecnaKwestia=2;

			kwestia = new Kwestia(1, 1, 
				"Witaj, czego ci trzeba?");
			kwestia->dodajOdpowiedz("Zako�cz rozmow�.",-1);
			kwestia->dodajOdpowiedz("Zabi�em szczury w piwniczce, tak jak chcia�e�.", 12)
				->DodajWymaganieQuestFaza(ListaQuestow::TajemniczyNieznajomy, { 2 });
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(2,2,
				"Na �rodku pomieszczenia stoi tajemnicza osoba ubrana w d�ug� szat�. "
				"Kaptur ca�kowicie zas�ania jej twarz. Kiedy tylko ci� zauwa�a odzywa si�: "
				"\"Witaj "+gracz.imie+"\".");
			kwestia->dodajOdpowiedz("\"Kim jeste�?\"",3);
			kwestia->dodajOdpowiedz("\"Sk�d znasz moje imi�?\"",4);
			kwestia->dodajOdpowiedz("\"Gdzie ja jestem?\"",5);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(3,3,
				"\"Moje imi� jest niewa�ne, jestem tylko s�ug� i spe�niam swoje obowi�zki."
				"Jestem tu aby ci� obserwowa� i pomaga� ci. Chcia�bym aby� wykona� dla mnie "
				"pewne zadanie.\"");
			kwestia->dodajOdpowiedz("\"Sk�d znasz moje imi�?\"",4);
			kwestia->dodajOdpowiedz("\"Gdzie ja jestem?\"",5);
			kwestia->dodajOdpowiedz("\"Jakie zadanie?\"",8);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(4,4,
				"\"Wiem o tobie znacznie wi�cej, ale nie wi�cej ni� jest mi to potrzebne aby m�c "
				"ci s�u�y� pomoc�. Chcia�bym aby� wykona� da mnie pewne zadanie.\"");
			kwestia->dodajOdpowiedz("\"Kim jeste�?\"",3);
			kwestia->dodajOdpowiedz("\"Gdzie ja jestem?\"",5);
			kwestia->dodajOdpowiedz("\"Jakie zadanie?\"",8);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(5,5,
				"\"Jeste� w podziemiach pewnej wie�y. Jedyne wyj�cie to klapa nad nami, niestety "
				"w�a�ciciel wie�y zamkn�� j� na amen.\"");
			kwestia->dodajOdpowiedz("\"Wi�c jak si� st�d wydosta�?\"",6);
			kwestia->dodajOdpowiedz("\"Co to za wie�a?\"",7);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(6,6,
				"\"Wydostanie si� st�d nie b�dzie �atwe, ale pomog� ci. Najpierw musisz jednak "
				"wype�ni� pewne zadanie.\"");
			kwestia->dodajOdpowiedz("\"Kim jeste�?\"",3);
			kwestia->dodajOdpowiedz("\"Sk�d znasz moje imi�?\"",4);
			kwestia->dodajOdpowiedz("\"Jakie zadanie?\"",8);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(7,7,
				"�Z czasem si� dowiesz.�");
			kwestia->dodajOdpowiedz("\"Kim jest w�a�ciciel wierzy?\"",7);
			kwestia->dodajOdpowiedz("\"Wi�c jak si� st�d wydosta�?\"",6);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(8,8,
				"\"Kiedy� by�e� wielkim wojownikiem. Chc�c wydosta� si� z tego miejsca b�dziesz "
				"musia� przypomnie� sobie jak walczy�. Chc� aby� znalaz� sobie jak�� bro� i "
				"zabi� wszystkie szczury w pomieszczeniu za moimi plecami.\"");
			kwestia->dodajOdpowiedz("\"Szczury?\"",9);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(9,9,
				"\"Tak, szczury. Chc� si� upewni�, �e nadal wiesz jak walczy�, zanim staniesz "
				"przed wi�kszymi wyzwaniami.\"");
			kwestia->dodajNagrodeQuestFaza(1, 1);
			kwestia->dodajOdpowiedz("\"Dobrze, zrobi� to.\"",10);
			kwestia->dodajOdpowiedz("\"Szczury nie s� dla mnie wyzwaniem.\"",10);
			kwestia->dodajOdpowiedz("\"Nie mam ochoty bawi� si� w zabijanie jakich� szczur�w.\"",11,-1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(10,1,
				"\"W takim razie id� i je zabij. Poczekam tutaj na ciebie.\"");
			kwestia->dodajOdpowiedz("Zako�cz rozmow�.",-1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(11,1,
				"\"Ale i tak to zrobisz. Poczekam tutaj a� sko�czysz.\"");
			kwestia->dodajOdpowiedz("Zako�cz rozmow�.",-1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(12,12,
				"\"Dobrze. Zapewne masz du�o pyta� dotycz�cych siebie, tego miejsca i ca�ej "
				"tej sytuacji. Niestety teraz nie mog� ci powiedzie� du�o wi�cej ponadto co ci ju� powiedzia�em.\"");
			kwestia->dodajNagrodeGraczDoswiadczenie(5);
			kwestia->dodajOdpowiedz("\"Dlaczego nie mo�esz mi nic powiedzie�?\"",13);
			kwestia->dodajOdpowiedz("\"Nie mo�esz czy raczej nie chcesz?\"",14);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(13,13,
				"\"Jestem zwi�zany przysi�g� wobec tych, kt�rym s�u��. Odpowiem ci na wszystkie pytania kiedy oni stwierdz� i� nadszed� czas.\"");
			kwestia->dodajOdpowiedz("\"W takim razie pom�wmy o tym jak si� st�d wydosta�.\"",15);
			kwestia->dodajOdpowiedz("\"G�wno mnie obchodz� jakie� durne przysi�gi. Chc� wiedzie� co si� tu u diab�a dzieje!\"",17);
			kwestia->dodajOdpowiedz("\"Komu s�u�ysz?\"",16);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(14,14,
				"\"I to i to po cz�ci. Jestem tu z obowi�zku i nie darz� ci� zbytni� sympati�. Zw�aszcza zwa�ywszy na to kim by�e� w przesz�o�ci.\"");
			kwestia->dodajOdpowiedz("\"W takim razie pom�wmy o tym jak si� st�d wydosta�.\"",15);
			kwestia->dodajOdpowiedz("\"A kim by�em?\"",16);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(15,15,
				"\"Dobrze. Znajdujemy si� w podziemiach wie�y pewnego maga. Stworzy� on rozbudowany system loch�w, "
				"chroni�cych dost�p do jego laboratorium na samym dole. Jedynie on posiada klucz otwieraj�cy "
				"wyj�cie na powierzchni�. Je�eli chcesz st�d uciec, b�dziesz musia� go zdoby�.\"");
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(16,16,
				"\"Wszystkiego dowiesz si� w swoim czasie.\"");
			kwestia->dodajOdpowiedz("\"W takim razie pom�wmy o tym jak si� st�d wydosta�.\"",15);
			kwestia->dodajOdpowiedz("\"Przesta� pierdoli� i zacznij gada� jak cz�owiek.\"",17);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(17,17,
				"\"Jak zawsze porywczy� Poznasz odpowiedzi na swoje pytania, tylko jeszcze nie teraz. "
				"P�ki co lepiej by by�o gdyby� skupi� si� na wydostaniu z tego miejsca.\"");
			kwestia->dodajOdpowiedz("\"W takim razie pom�wmy o tym jak si� st�d wydosta�.\"",15);
			kwestia->dodajOdpowiedz("\"Spierdalaj.\"",18);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(18,1,
				"\"W takim razie we� ten klucz i sam znajd� sobie wyj�cie. Jeszcze si� spodkamy.\"");
			kwestia->dodajNagrodeQuestFaza(ListaQuestow::TajemniczyNieznajomy, 4);
			kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZBrazuLvl2);
			kwestia->dodajOdpowiedz("Zako�cz rozmow�.",-1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(19,19,
				"\"Co jeszcze chcesz wiedzie�?\"");
			kwestia->dodajOdpowiedz("\"Rozbudowany system loch�w? Serio?\"",20);
			kwestia->dodajOdpowiedz("\"Czy odda on ten klucz po dobroci?\"",21);
			kwestia->dodajOdpowiedz("\"Nie mog� spr�bowa� wywa�y� tego wyj�cia?\"",22);
			kwestia->dodajOdpowiedz("\"Pomo�esz mi?\"",23);
			kwestia->dodajOdpowiedz("\"Nie mam wi�cej pyta�, chc� rusza� w drog�.\"",24);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(20,20,
				"\"To nie ja jestem szalonym magiem. Najwidoczniej chce by� pewny, �e �adne jego "
				"eksperymenty nie wydostan� si� na zewn�trz. I wice wersa. Na twoim miejscu by�bym ostro�ny.\"");
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(21,21,
				"\"Nie by�bym tego taki pewien, w ko�cu nie bez powodu zamkn�� to miejsce na klucz. "
				"Pami�taj jednak, �e to cz�owiek, je�eli znajdzie korzy�� w oddaniu ci klucza to zrobi to. Wszystko zale�y od ciebie.\"");
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(22,22,
				"\"Strata czasu. Tylko sp�jrz na nie: solidna kupa stali. Trzeba by nie byle wo�a aby cho�by drgn�o.\"");
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(23,23,
				"\"Nie mog� z tob� wyruszy� i ci pomaga�, ale niebezpiecznie jest i�� samemu. Prosz� we� ten miecz, z "
				"pewno�ci� przyda ci si� prawdziwa bro�. Poni�ej b�dziesz m�g� polega� tylko na sobie i na swojej broni. "
				"Ponadto kiedy sko�czymy rozmow� ch�tnie pomog� ci potrenowa� twoje zdolno�ci bojowe. Ale sam trening to "
				"nie wszystko, prawdziwy wojownik musi ��czy� trening z prawdziw� walk� je�eli chce si� doskonali�.\"");
			kwestia->dodajNagrodeGraczItem(ListaItemow::Bronie::MieczKrotkiBraz);
			kwestia->dodajOdpowiedz("Dalej.",19);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(24,1,
				"\"Prosz�, oto klucz otwieraj�cy przej�cie na d�. Znajduje si� tam jaskinia w kt�rej �yje plemi� "
				"prymitywnych goblin�w. Ich w�dz posiada klucz otwieraj�cy przej�cie w ni�sze partie jaskini, sam "
				"zdecydujesz jak go zdob�dziesz. Kiedy ju� to zrobisz ruszaj w g��b podziemi, tw�j cel znajduje si� na "
				"samym dole.  Jeszcze si� spotkamy. Powodzenia.\"");
			kwestia->dodajNagrodeQuestFaza(ListaQuestow::TajemniczyNieznajomy, 3);
			kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZBrazuLvl2);
			kwestia->dodajOdpowiedz("Zako�cz rozmow�.",-1);
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
			kwestia->dodajOdpowiedz("Daj mi z�oto. Przy okazji jest to jaka� niedorzecznie d�uga wypowied� maj�ca sprawdzi� jak dzia�a wersalikowanie odpowiedzi w rozmowie. ",2);
			kwestia->dodajOdpowiedz("Zabierz mi z�oto.",3)
				->DodajWymaganieZloto(100);
			kwestia->dodajOdpowiedz("Daj mi expy",4);
			kwestia->dodajOdpowiedz("Daj mi klejnot.",5);
			kwestia->dodajOdpowiedz("Zabierz mi klejnot.",6)
				->DodajWymaganieItem(Questowe::OkraglySzafir);
			kwestia->dodajOdpowiedz("W podziemiach czuj� si� jak w domu!", 7)
				->DodajWymaganieRasa(RASA_GNOM | RASA_KRASNOLUD);
			kwestia->dodajOdpowiedz("Spr�buj mnie zabi� pusta pauko!",-2);
			kwestia->dodajOdpowiedz("Zako�cz rozmow�.",-1)
				->DodajWymaganieZdarzenieGlobalne(7);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(2, 2,
				"Dostajesz z�oto.");
			kwestia->dodajNagrodeGraczZloto(100);
			kwestia->dodajOdpowiedz("Dalej.",1);
			postac->dodajKwestie(kwestia);

			kwestia = new Kwestia(3, 3,
				"Zabieram ci z�oto");
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
				"No fajnie, jeste� krasnoludem lub gnomem, gratulacje.");
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
			"�Sta�! Ty zabija� nie wi�cej. Torag Mora, m�dry, jego bracia martwi. Nie wi�cej! My rozmawia�.�");
		kwestia->dodajOdpowiedz("�Nie obchodzi mnie co masz do powiedzenia. Bro� si�!�", -2);
		kwestia->dodajOdpowiedz("Zabij go na miejscu", 2, -10)
			->DodajWymaganieRasa(RASA_ELF | RASA_POLELF | RASA_MROCZNYELF | RASA_NIZIOLEK | RASA_SIDAN | RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz("Zabij go na miejscu", 3, -5)
			->DodajWymaganieRasa(RASA_KRASNOLUD | RASA_ORK | RASA_LACERT | RASA_GNOM);
		kwestia->dodajOdpowiedz("�Co niby taka poczwara mo�e mie� do powiedzenia?�", 4);
		kwestia->dodajOdpowiedz("�M�w, s�ucham Ci�.�", 4);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(2, 2,
			"Wykorzystuj�c element zaskoczenia podnosisz bro� i atakujesz ni� rozm�wc�. Trafiasz go prosto w g�ow� i goblin pada na ziemi�. Reszta plemienia widz�c to, z krzykiem rzuca si� na ciebie.");
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::ZabicieSzamanaGoblinow);
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		kwestia->dodajOdpowiedz("Zako�cz rozmow�", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(3, 3,
			"Wykorzystuj�c element zaskoczenia podnosisz bro� i atakujesz ni� rozm�wc�. Robisz to jednak niezdarnie i goblin wykonuje unik, po czym zaczyna ucieka�. Drog� zast�puje ci reszta plemienia.");
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::UcieczkaSzamanaGoblinow);
		kwestia->dodajNagrodeZdarzenieGlobalne(ListaZdarzenGlobalnych::AgresjaGoblinow);
		kwestia->dodajOdpowiedz("Zako�cz rozmow�", -1);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(4, 4,
			"�Goba nie tw�j wr�g. Bia�y demon wi�zi� goba, my nie jego s�ugi. Torag rozmawia� " + temp + ", goba nie gin�� wi�cej.�");
		kwestia->dodajOdpowiedz("Dalej", 5)
			->DodajWymaganieQuestFaza(ListaQuestow::GoblinyWPodziemiach, { 3 });
		kwestia->dodajOdpowiedz("Dalej", 6)
			->DodajWymaganieQuestFaza(ListaQuestow::GoblinyWPodziemiach, { 0, 1, 2 });
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(5, 5,
			"�Twoja bro� mie� krew goba, Torag martwi� si� nie zgin��. " + temp + " odda� bro� i my i�� do chata, tam my rozmawia�.�");
		kwestia->dodajOdpowiedz("Oddaj mu bro�", 7);
		kwestia->dodajOdpowiedz("�Nie nabierzesz mnie na takie sztuczki! Gi�!�", -2);
		kwestia->dodajOdpowiedz("Zabij go na miejscu", 2, -10)
			->DodajWymaganieRasa(RASA_ELF | RASA_POLELF | RASA_MROCZNYELF | RASA_NIZIOLEK | RASA_SIDAN | RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz("Zabij go na miejscu", 3, -5)
			->DodajWymaganieRasa(RASA_KRASNOLUD | RASA_ORK | RASA_LACERT | RASA_GNOM);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(6, 6,
			"�Tu my nie rozmawia�. Du�o uchi goba nie trzeba. My i�� do chata, tam Torag m�wi�, " + temp + " s�ucha�.�");
		kwestia->dodajOdpowiedz("�Sk�d mam wiedzie�, �e nie chcecie mnie otoczy� i zabi�?�", 8);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(7, 9,
			"�Torag rad, " + temp + " wiedza.Rozmowa du�o dobra.My i��.�");
		kwestia->dodajOdpowiedz("Zako�cz rozmow�", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinowZOddaniemBroni);
		postac->dodajKwestie(kwestia);
		
		kwestia = new Kwestia(8, 9,
			"�" + temp + " zabi� silne goba.My nie wi�cej tutaj, nie chcie� gin��.Bia�y demon s�ucha�.Torag m�wi� tutaj demon zabija� goba.Is�!I��!�");
		kwestia->dodajOdpowiedz("�Niech b�dzie. Prowad�.�", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow);
		kwestia->dodajOdpowiedz("�Nie ufam Ci ropucho. Prowad�, ale nie wykonuj �adnych gwa�townych ruch�w.�", -1)
			->DodajWymaganieZdarzenieGlobalne(ListaZdarzenGlobalnych::TeleportacjaDoChatySzamanaGoblinow);
		kwestia->dodajOdpowiedz("�Bardzo sprytne, jednak chyba wol� po prostu zabi�.�", -2);
		kwestia->dodajOdpowiedz("Zabij go na miejscu�", 2);
		postac->dodajKwestie(kwestia);
		
		kwestia = new Kwestia(9, 9,
			"�My tu m�wi� bezpiecznie. Ja Torag Mora, by� kiedy� silny wielki w�dz. Zabi� i zje�� inne Goba, zbiera� ich samice. Ale Torag zha�biony, nie godzien swoje imi�. Nie godzien wielki w�dz.�");
		kwestia->dodajOdpowiedz("Dalej", 10);
		kwestia->dodajOdpowiedz("�Streszczaj si�, twoje st�kanie dzia�a mi ju� na nerwy.�", 11, -2);
		postac->dodajKwestie(kwestia);
		
		kwestia = new Kwestia(10, 10,
			"�Torag zdoby� �atwy �up, wpa�� w pu�apka. Bia�y demon uwi�zi� Torag, jego braci i samice. Goba musie� s�ucha� demon aby mie� co je��. Goba strzec jaskinia, wtedy goba �yj�. Inaczej bia�y demon ubija� goba.�");
		kwestia->dodajOdpowiedz("Dalej", 11);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(11, 11,
			"�Goba nie znie�� tego wi�cej, woli raczej zgni�. Ty " + temp + " wielki wojownik.Wzi�� ten klucz, one otworz� drzwi bia�ego demona.Ty z nim walczy� i zabi� - goba by� wolne.Ty zgin��, goba zgin�� tak�e.�");
		kwestia->dodajOdpowiedz("�Dlaczego niby mia�bym to robi�?�", 12);
		kwestia->dodajOdpowiedz("�Co to jest ten ca�y bia�y demon?�", 16);
		kwestia->dodajOdpowiedz("�Co b�dziecie robi� kiedy odzyskacie wolno��?�", 14);
		kwestia->dodajNagrodeGraczItem(ListaItemow::Klucze::KluczZSrebraLvl3);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(12, 12,
			"�Torag pom�c " + temp + " i da� klucz. Teraz " + temp + " musie� pom�c Goba.�");
		kwestia->dodajOdpowiedz("�Zatem niech tak b�dzie. Spr�buj� wam pom�c.�", 13);
		kwestia->dodajOdpowiedz("�Ma�o mnie obchodz� wasze problemy, ale chyba i tak przyjdzie mi si� zmierzy� z tym ca�ym bia�ym demonem.", 13);
		kwestia->dodajOdpowiedz("�Co b�dziecie robi� kiedy odzyskacie wolno��?�", 14);
		kwestia->dodajOdpowiedz("�Co to jest ten ca�y bia�y demon?�", 16);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(13, 17,
			"�|^" + temp + " rusza� natychmiast. Bia�y demon wielka magia, wiedzie� du�o. Torag zmartwiony o �ycie goba. I��! I��!�");
		kwestia->dodajOdpowiedz("Zako�cz rozmow�.", KoniecRozmowy);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(14, 14,
			"�Torag Mora chcie� odzyska� zaszczyt swojego imienia. Robi� wielkie rzeczy aby jego bracia znowu robi� strach. |+ " + temp + " nie rozumie�.�");
		kwestia->dodajOdpowiedz(" �Rozumiem wi�cej ni� Ci si� zdaje.�", 15)
			->DodajWymaganieRasa(RASA_CZLOWIEK);
		kwestia->dodajOdpowiedz("�W sumie i tak ma�o mnie to obchodzi.�", 13);
		kwestia->dodajOdpowiedz("�Nie wierz� w ani jedno twoje s�owo, pod�a kreaturo, a teraz gi�!�", KoniecRozmowyWalka);
		kwestia->dodajOdpowiedz("�Bardzo ciekawa historia, ale wol� nie zostawia� zgrai gobelin�w za plecami. Da�e� mi klucz, wi�c mo�esz spokojnie zdycha�.�", KoniecRozmowyWalka);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(15, 15,
			"�Co Tora m�wi�?�");
		kwestia->dodajOdpowiedz("�Ci�gle m�wisz na mnie Tora, musi to oznacza� �cz�owiek�. Mora brzmi jak �zag�ada�. Twoje parszywe plemi� scze�nie w tej jaskini, a ty zap�acisz za swoje zbrodnie!�", KoniecRozmowyWalka);
		kwestia->dodajOdpowiedz("�W sumie nie wa�ne.�", 13);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(16, 16,
			"�Demon jest magia. Wielki, stary, z�y i straszny. Zabija� Goba ruchem r�ki i kruszy� g�azy s�owami.�");
		kwestia->dodajOdpowiedz("�Dlaczego mia�bym wam pom�c?�", 12);
		kwestia->dodajOdpowiedz("�Zatem niech b�dzie, spr�buj� wam pom�c.�", 13);
		kwestia->dodajOdpowiedz("�Co b�dziecie robi� kiedy odzyskacie wolno��?�", 14);
		kwestia->dodajOdpowiedz("�Wkurza mnie ju� to twoje pieprzenie, my�l�, �e ci� zabij�.�", KoniecRozmowyWalka);
		postac->dodajKwestie(kwestia);

		kwestia = new Kwestia(17, 17,
			"�|^" + temp +" dzia�a�, Goba nic nie mie� m�wi� wi�cej!�");
		kwestia->dodajOdpowiedz("Zako�cz rozmow�.", KoniecRozmowy);
		postac->dodajKwestie(kwestia);

		break;

#pragma endregion

	default:
		break;
	}
}