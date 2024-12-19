#pragma once
#include <iostream>
#include "appliance.h"
#include "toggleable.h"
#include "percentage.h"

//Serialiseable data
//-Name,
//-Type,
//-Playing,
//-Volume
class Speaker : public Toggleable,public Percentage{
	private:
		static const std::string menuFormat;
		static const std::string stateFormat[2];
		std::string menuText();
		int menuParse(std::string& UserInput);
	public:
		Speaker(std::string name);
		Speaker(std::istream& i);

		enum SpeakerState:bool;
		int Play();
		int Pause();
		bool isPlaying();
		int setVolume(int newVol);
		int getVolume();
		
		int dump(std::ostream& o);
};
