#pragma once
#include "komenda.h"

class Postac;
class Lokacja;

class Kill :
	public Komenda
{
public:
	Kill(Gra *gra);
	~Kill(void);

	void execute(ParseDTO argumenty);
	void manual();
	void rozpocznijWalke(Postac *Wrog);
	//kasuje dana postac z pamieci, tworzy zwloki i umeiszcza je w lokacji, gracz zbiera z nich zloto
	void zabijPostac(Postac *postac, Lokacja *Lokacja);
};

