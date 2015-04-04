// use mciSendwstring() to play and stop a midi music file
// you have to link with the winmm.lib file, or
// in the case of Dev-C++ link with libwinmm.a via
// Project>>Project Options>>Parameters>>Add Lib>>libwinmm.a
// a Dev-C++  console application
#include "midi.h"

using namespace MidiFiles;

bool MidiPlayer::stopped;
MidiFile MidiPlayer::current;
string MidiPlayer::path;
string MidiPlayer::fileNames[COUNT];
int MidiPlayer::fileLen[COUNT];

MidiPlayer::MidiPlayer(string path)
{
	this->path = path;
	current = (MidiFile)-1;
	stopped = true;
	loadFiles();
}

void MidiPlayer::loadFiles()
{
	fileNames[LVL1] = "res\\midi\\calm.mid";
	fileLen[LVL1] = 73;

	fileNames[DREAM] = "res\\midi\\explore.mid";
	fileLen[DREAM] = 51;

	fileNames[BATTLE1] = "res\\midi\\bitwa_podziemia_Rod Lazo.mid";
	fileLen[BATTLE1] = 261;
}

void MidiPlayer::play(MidiFile midi)
{
	if (current == midi) return;
	if (!stopped)
	{
		stop();
	}
	current = midi;
	stopped = false;
	player = new thread(&MidiPlayer::loopPlay);
}

void MidiPlayer::stop()
{
	stopped = true;
	player->join();
	delete player;
}

void MidiPlayer::loopPlay()
{
	int currentTime = 0;
	int repeatTime = fileLen[current] * 1000;
	string comm = "open \"";
	comm.append(path);
	comm.append(fileNames[current]);
	comm.append("\" type sequencer alias midi");
	mciSendString(comm.c_str(), NULL, 0, NULL);
	mciSendString("play midi", NULL, 0, NULL);
	while (1)
	{
		for (currentTime = 0; currentTime < repeatTime; currentTime += 200)
		{
			if (stopped)
			{
				mciSendString("stop midi", NULL, 0, NULL);
				mciSendString("close midi", NULL, 0, NULL);
				return;
			}
			Sleep(200);
		}
		mciSendString("play midi from 0", NULL, 0, NULL);
	}
}