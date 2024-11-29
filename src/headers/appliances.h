#pragma once
#include <iostream>
#include "time.h"

namespace Devices{
	enum AppType{
		Light=0,
		Sensor,
		Speaker,
		Thermostat,
		Socket,
		Valve=5
	};
};

class Appliance{
	private:
		std::string DevName;
	public:
		virtual int OCF()=0;
		int rename(std::string NewName);
		std::string getName();

		virtual int dump(std::ostream& o)=0;
};

class Toggleable : public Appliance{
	private:
		bool state;
	public:
		int OCF();
	protected:
		int setState(bool nState);
		bool getState();
};

class ToggleWithPercent : public Toggleable{
	private:
		int percentage;
	protected:
		int setPercent(int newPercent);
		int getPercent();
};

class Schedule : public Toggleable{
	private:
		bool scheduleEnabled;
		int scheduleOn;
		int scheduleOff;
	public:
		int setSchedule(int on,int off);
		int disableSchedule();
		int timeUpdate(int time);
};


class Sensor : public Appliance{
	public:
		enum SensType:int;
		int OCF();
		int dataView();
		int dataView(int range);
		int dataView(int range, SensType data);
};

class Speaker : public ToggleWithPercent{
	public:
		enum SpeakerState:bool;
		int Play();
		int Pause();
		bool isPlaying();
		int setVolume(int newVol);
		int getVolume();
};

class Light : public ToggleWithPercent{
	public:
		int setLevel(int p);
		int getLevel();
		int setOn(bool s);
		bool isOn();
};

class Thermostat : public Schedule{
	private:
		//
	public:
		//
};

class Socket : public Schedule{
	private:
		//
	public:
		//
};

class Valve : public Schedule{
	private:
		//
	public:
		int getCurrentTemp();
};
