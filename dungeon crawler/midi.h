#pragma once

#include <iostream>
#include <windows.h>
#include <mmsystem.h>  // mciSendwstring()
#include <iostream>
#include <conio.h>
#include <thread>
using namespace std;   // std::wcout, std::cin

namespace MidiFiles
{
	enum MidiFile {
		LVL1,
		DREAM,
		BATTLE1,
		COUNT
	};
}

int midi();

class MidiPlayer
{
public:
	MidiPlayer(string path);

	friend class thread;

	static bool stopped;
	static MidiFiles::MidiFile current;
	thread *player;
	static string path;
	static string fileNames[MidiFiles::COUNT];
	static int fileLen[MidiFiles::COUNT];

	void play(MidiFiles::MidiFile midi);
	void stop();
	static void loopPlay();
	void loadFiles();
};