#pragma once
#include <thread>
#include <string>

namespace MidiFiles
{
	enum MidiFile {
		LVL1,
		LVL2,
		DREAM,
		BATTLE1,
		COUNT
	};
}

int midi();

class MidiPlayer
{
public:
	MidiPlayer(std::string path);

	friend class std::thread;

	static bool stopped;
	static MidiFiles::MidiFile current;
	std::thread *player;
	static std::string path;
	static std::string fileNames[MidiFiles::COUNT];
	static int fileLen[MidiFiles::COUNT];

	void play(MidiFiles::MidiFile midi);
	void stop();
	static void loopPlay();
	void loadFiles();
};