#include <iostream>
#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <string>
#include "gra.h"
#include "Quest.h"
#include "parser.h"
#include <csignal>
#include "StackCrawler.h"
//#include "Log4CppLogger.h"
#include "ListaKomend.h"

;using namespace std;

void segmentationFaultHandler( int signum )
{
    wcout << endl << "Otrzymano sygna³ SEGV (L" << signum <<endl;
	wcout << "Najwidoczniej ktoœ chcia³ pomazaæ tam gdzie mu nie wolno by³o."<<endl;
	wcout << "Nasza przyjazna u¿ytkownikom biblioteka wygenerowa³a kilka wskazówek:"<<endl<<endl;

    // cleanup and close up stuff here  
    // terminate program  

	StackCrawler sw;
	sw.ShowCallstack();
	system("PAUSE");
	exit(signum);  
}

void wykonaj_komende(Ekomenda command, ParseDTO argumenty, Gra &gra) 
{
	gra.stoper.stop();
	gra.zdarzeniaCiagle();
	
	gra.licznikWywolanKomend.zwieksz(command);
	wcout<<endl;
	
	if (command != COMM_NOCOMM)
	{
		listaKomend->komendy[command]->execute(argumenty);
	}

	gra.prompt();
	gra.stoper.start();
}

int main(int argc, const char* argv[])
{
	//system (L"chcp 1250");
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	//Log4CppLogger *logger = new Log4CppLogger();
	//if ( !logger->Init(L"res\\log4cpp.property"))
	//	return 0;
	//logger->LogDebug(L"Enter main...");
	//logger->LogInfo(L"Main...");

	signal(SIGSEGV, segmentationFaultHandler);
	Gra gra(argc, argv);
	Parser parser;
	while (!gra.gra_zakoncz())
	{
		parser.pobierz_linie();
		parser.parsuj();
		wykonaj_komende(parser.komenda, parser.argumenty, gra);
	}

	//logger->LogDebug(L"Exit main");
	system("PAUSE");
}

