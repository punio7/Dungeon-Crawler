#include "Journal.h"
#include "gra.h"
#include "Quest.h"


Journal::Journal(Gra *gra):
	Komenda(gra)
{
	nazwa = L"journal";
}


Journal::~Journal(void)
{
}

void Journal::execute(ParseDTO argumenty)
{
	if (argumenty.argument1.empty())	//gracz nie podal nic w argumentach- wyswietlanie listy zadan
	{
		journalList();
	}
	else		//gracz podal w argumencie cos- wyswietlanie szczegolow podanego zadania
	{
		Quest* aktualny = gra->znajdzQuest(argumenty.argument1, argumenty.ktory1);

		if (!aktualny)	//jezeli nie znaleziono zadnego zadania
		{
			playerMsg(L"Brak aktywnego zadania o podanej nazwie");
			return;
		}
		journalQuestInfo(aktualny);
	}
}

void Journal::manual()
{
	playerMsg(L"Synonimy:\n"
			 L"   journal(j)\n\n"
			 L"U¿ycia:\n\n"
			 L"   journal - wyœwietla listê podjêtych oraz wykonanych zadañ.\n\n"
			 L"   journal <nazwa_zadania> - wyœwietla szczegó³y, cele oraz notatki dotycz¹ce wskazanego zadania.");
}

void Journal::journalList()
{
	playerMsg(L"Obecnie aktywne zadania:\n");
	bool jakiekolwiekAktywne=false;
	for (size_t i = 1; i < gra->questy.size(); i++)
	{
		if ( gra->questy[i] != NULL && gra->questy[i]->aktywny() )
		{
			jakiekolwiekAktywne = true;
			playerMsg(L"\t|^|0.", gra->questy[i]->nazwa);
		}
	}
	if (!jakiekolwiekAktywne) 
		playerMsg(L"\tBrak.");

	playerMsg(L"\nZadania zakoñczone:\n");
	jakiekolwiekAktywne=false;
	for (size_t i = 1; i < gra->questy.size(); i++)
	{
		if ( gra->questy[i] != NULL && gra->questy[i]->zakonczony() )
		{
			jakiekolwiekAktywne = true;
			playerMsg(L"\t|^|0.", gra->questy[i]->nazwa);
		}
	}
	if (!jakiekolwiekAktywne) 
		playerMsg(L"\tBrak.");
}

void Journal::journalQuestInfo(Quest *quest)
{
	playerMsg(L"Szczegó³y zadania |G|^|0 |W.", quest->nazwa);
	playerMsg(L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	playerMsg(L"|GObecny cel:");
	if (!quest->zakonczony())
		playerMsg(quest->faza->cel);
	else
		playerMsg(L"Zadanie zakoñczone.");
	playerMsg(L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	playerMsg(L"|GNotatki:");
	playerMsg(quest->notatki());
}