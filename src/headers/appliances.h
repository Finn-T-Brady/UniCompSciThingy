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
		enum SensType{
			Humidity=0,
			Temperature=1
		};
		int OCF();
		int dataView();
		int dataView(int range);
		int dataView(int range, SensType data);
	friend std::ostream& operator<<(std::ostream& out,const Sensor& obj);
	friend std::ostream& operator||(std::ostream& out,const Sensor& obj);
};

class Speaker : public ToggleWithPercent{
	public:
		enum SpeakerState:bool;
		int Play();
		int Pause();
		bool isPlaying();
		int setVolume(int newVol);
		int getVolume();
	friend std::ostream& operator<<(std::ostream& out,const Speaker& obj);
};

class Light : public ToggleWithPercent{
	public:
		int setLevel(int p);
		int getLevel();
	friend std::ostream& operator<<(std::ostream& out,const Light& obj);
};

class Thermostat : public Schedule{
	private:
		//
	public:
		//
	friend std::ostream& operator<<(std::ostream& out,const Thermostat& obj);
};

class Socket : public Schedule{
	private:
		//
	public:
		//
	friend std::ostream& operator<<(std::ostream& out,const Socket& obj);
};

class Valve : public Schedule{
	private:
		//
	public:
		int getCurrentTemp();
	friend std::ostream& operator<<(std::ostream& out,const Valve& obj);
};
