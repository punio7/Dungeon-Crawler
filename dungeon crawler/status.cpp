#include "status.h"
#include "color.h"
#include "playerMsg.h"

StatusList::StatusList() : list<Status*>()
{
}

StatusList::~StatusList()
{

}

wstring StatusList::wypisz()
{
	wstringstream temp;
	temp << L"Obecnie znajdujesz siê pod wp³ywem:\n\n";
	if (empty())
	{
		temp << L"W sumie to czujesz siê ca³kiem normalnie.";
		return temp.str();
	}

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if ((*aktualny)->isPositive())
			temp << L"|G";
		else
			temp << L"|R";
		temp << (*aktualny)->nazwa;
		temp << L"|W - ";
		temp << (*aktualny)->opis;
		if (aktualny != end()--)
			temp << endl;
	}
	return temp.str();
}

Status* StatusList::znajdz(wstring szukany, int ktory)
{
	if (empty()) return NULL;

	for (iterator aktualny = begin(); aktualny != end(); aktualny++)
	{
		if (((*aktualny)->nazwa.find(szukany)) != -1)
		{
			if (ktory < 2) return *aktualny;
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
	for (int i = 0; i < ktory; i++)
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
	nazwa = L"";
	opis = L"";
	enterMsg = L"";
	exitMsg = L"";
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