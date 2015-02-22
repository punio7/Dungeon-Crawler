#include "Journal.h"
#include "gra.h"
#include "Quest.h"


Journal::Journal(Gra *gra):
	Komenda(gra)
{
	nazwa="journal";
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
			playerMsg("Brak aktywnego zadania o podanej nazwie");
			return;
		}
		journalQuestInfo(aktualny);
	}
}

void Journal::manual()
{
	playerMsg("Synonimy:\n"
				"   journal(j)\n\n"
				"U¿ycia:\n\n"
				"   journal - wyœwietla listê podjêtych oraz wykonanych zadañ.\n\n"
				"   journal <nazwa_zadania> - wyœwietla szczegó³y, cele oraz notatki dotycz¹ce wskazanego zadania.");
}

void Journal::journalList()
{
	playerMsg("Obecnie aktywne zadania:\n");
	bool jakiekolwiekAktywne=false;
	for (size_t i = 1; i < gra->questy.size(); i++)
	{
		if ( gra->questy[i] != NULL && gra->questy[i]->aktywny() )
		{
			jakiekolwiekAktywne = true;
			playerMsg("\t|^|0.", gra->questy[i]->nazwa);
		}
	}
	if (!jakiekolwiekAktywne) 
		playerMsg("\tBrak.");

	playerMsg("\nZadania zakoñczone:\n");
	jakiekolwiekAktywne=false;
	for (size_t i = 1; i < gra->questy.size(); i++)
	{
		if ( gra->questy[i] != NULL && gra->questy[i]->zakonczony() )
		{
			jakiekolwiekAktywne = true;
			playerMsg("\t|^|0.", gra->questy[i]->nazwa);
		}
	}
	if (!jakiekolwiekAktywne) 
		playerMsg("\tBrak.");
}

void Journal::journalQuestInfo(Quest *quest)
{
	playerMsg("Szczegó³y zadania |G|^|0 |W.", quest->nazwa);
	playerMsg("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	playerMsg("|GObecny cel:");
	if (!quest->zakonczony())
		playerMsg(quest->faza->cel);
	else
		playerMsg("Zadanie zakoñczone.");
	playerMsg("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	playerMsg("|GNotatki:");
	playerMsg(quest->notatki());
}