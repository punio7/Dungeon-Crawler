#include "status.h"
#include "color.h"
#include "playerMsg.h"

StatusList::StatusList() : list<Status*>()
{
}

StatusList::~StatusList()
{

}

string StatusList::wypisz()
{
	string temp;
	temp += "Obecnie znajdujesz siê pod wp³ywem:\n\n";
	if (empty())
	{
		temp += "W sumie to czujesz siê ca³kiem normalnie.";
		return temp;
	}
	
	for (iterator aktualny = begin();aktualny != end();aktualny++)
	{
		if ((*aktualny)->isPositive()) 
			temp+="|G";
		else 
			temp+="|R";
		temp += (*aktualny)->nazwa;
		temp += "|W - ";
		temp += (*aktualny)->opis;
		if (aktualny != end()--)
			temp += '\n';
	}
	return temp;
}

Status* StatusList::znajdz(string szukany, int ktory)
{
	if (empty()) return NULL;

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if (((*aktualny)->nazwa.find(szukany))!=-1) 
		{
			if (ktory<2) return *aktualny;
			else ktory--;
		}
	}

	return NULL;
}

Status* StatusList::znajdz(int ktory)
{
	if (empty())
		return NULL;

	iterator aktualny = begin();
	for (int i=0; i < ktory; i++)
	{
		aktualny++;
		if (aktualny == end())
			return NULL;
	}

	return *aktualny;
}

void StatusList::dodaj(Status* status)
{
	push_back(status);
}

bool StatusList::pusta()
{
	return this->empty();
}

Status::Status()
{
	nazwa = "";
	opis = "";
	enterMsg = "";
	exitMsg = "";
	czas = 0;
}

void Status::aktywujPasyw(Postac *postac)
{

}

void Status::aktywujExplor(Gracz *gracz, int time)
{

}

void Status::aktywujWalka(Postac &postac, Postac &wrog)
{

}

bool Status::isActive()
{
	return false;
}

bool Status::isBattleOnly()
{
	return false;
}

bool Status::isPositive()
{
	return false;
}