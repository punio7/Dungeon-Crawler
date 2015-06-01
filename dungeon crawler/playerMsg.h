#pragma once
#include <string>

using namespace std;

enum Format
{
	FORMAT_NORMAL,
	FORMAT_UPPERCASE,
	FORMAT_LOWERCASE,
	FORMAT_NEXTUPPER
};

void playerMsg(wstring msg, wstring in0=L"", wstring in1=L"", wstring in2=L"", wstring in3=L"", wstring in4=L"", wstring in5=L"", wstring in6=L"", wstring in7=L"", wstring in8=L"", wstring in9=L"");
wstring intToStr(int i);
wstring floatToStr(float f);
wstring czystyTekst(wstring text);

/*
	Dostepne komendy formatu:
	|1 |2 |3 |4 |5 |6 |7 |8 |9 -wstawienie w dane miejsce podanego jako argument wstringa
	|_ -usuniecie znaku nowej linii na koncu tekstu
	|+ |- -zamiana wszystkich znakow na duze/male, uzyj ponownie aby wylaczyc
	|^ -nastepny znak bedzie duzy natomiast reszta bedzie normalna
	|b |g |c |r |p |y |s
	|S |B |G |C |R |P |Y |W -roznorakie kolory sprawdz Color.h
*/