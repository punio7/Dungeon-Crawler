#pragma once
#include <iostream>
#include <string>
#include "kierunkiSwiata.h"

class ItemList;
class CharList;
class Postac;
namespace MidiFiles 
{
enum MidiFile;
}
;using namespace std;

KierunekSwiata kierunekPrzeciwny(KierunekSwiata kierunek);	//zwraca kierunek przeciwny, np dla NORTH zwraca SOUTH

class Lokacja
{
public:
	Lokacja();

	wstring nazwa;
	wstring opis;
	ItemList* przedmioty;
	CharList* postacie;
	int zamek[6];		//0- drzwi otwarte; 1- zamkniete, x>1; zakluczune kluczem nr. x; -1- przejœcie ukryte
	Lokacja* wyjscie[6];	//wskaŸniki do wyjœæ z lokacji
	int zdGlob;
	int jednorazoweZdGlob;
	MidiFiles::MidiFile backgroundMusic;
	bool naturalneOswietlenie;
private:

};

class ListaLokacji
{
public:
	ListaLokacji();
	Lokacja* znajdz(int a);	//znajduje na liscie lokalizacje o zadanym id
	
	int id;
	Lokacja* element;
	ListaLokacji* nast;
};