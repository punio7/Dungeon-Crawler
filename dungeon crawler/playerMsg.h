#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <locale>
#include "wersalikuj.h"
#include "color.h"

using namespace std;

enum Format
{
	FORMAT_NORMAL,
	FORMAT_UPPERCASE,
	FORMAT_LOWERCASE,
	FORMAT_NEXTUPPER
};

void playerMsg(string msg, string in0="", string in1="", string in2="", string in3="", string in4="", string in5="", string in6="", string in7="", string in8="", string in9="");
string intToStr(int i);
string floatToStr(float f);
string czystyTekst(string text);

/*
	Dostepne komendy formatu:
	|1 |2 |3 |4 |5 |6 |7 |8 |9 -wstawienie w dane miejsce podanego jako argument stringa
	|_ -usuniecie znaku nowej linii na koncu tekstu
	|+ |- -zamiana wszystkich znakow na duze/male, uzyj ponownie aby wylaczyc
	|^ -nastepny znak bedzie duzy natomiast reszta bedzie normalna
	|b |g |c |r |p |y |s
	|S |B |G |C |R |P |Y |W -roznorakie kolory sprawdz color.h
*/