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

//Serialiseable data
//-Name
class Appliance{
	private:
		std::string DevName;
	public:
		virtual int OCF()=0;
		int rename(std::string NewName);
		std::string getName();
		
		virtual int menu()=0;
		virtual int dump(std::ostream& o)=0;
};

//Serialiseable data
//-State
class Toggleable : public Appliance{
	private:
		bool state;
	public:
		int OCF();
	protected:
		int setState(bool nState);
		bool getState();
};

//Serialiseable data
//-Percentage
class ToggleWithPercent : public Toggleable{
	private:
		int percentage;
	protected:
		int setPercent(int newPercent);
		int getPercent();
};

//Serialiseable data
//-ScheduleEnabled
//-On time
//-Off time
class Schedule : public Toggleable{
	private:
		bool scheduleEnabled;
		Rider::Time scheduleOn;
		Rider::Time scheduleOff;
	public:
		int setSchedule(Rider::Time on,Rider::Time off);
		int disableSchedule();
		bool timeState(Rider::Time curr);
};

//Does not inherit from Appliance
//Nothing to serialize
class HistoricDataGen{		
	protected:
		virtual int initCall(int n)=0;
		virtual int progCall(int n, int d)=0;
		virtual int nTypes()=0;
		virtual std::string dName(int n)=0;
	public:
		int dataView(int range);
};

//Serialiseable data:
//-Name,
//-Type,
class Sensor : public Appliance,public HistoricDataGen{
	private:
		const static int dataTypes=2;
		int nTypes();
		std::string dName(int n);
		const std::string dataNames[dataTypes]={"Temperature:","Humidity:   "};
		int initCall(int n);
		int progCall(int n,int d);

		static int TempInit();
		static int HumiInit();
		static int TempProg(int x);
		static int HumiProg(int x);
		static constexpr int (*dataInit[dataTypes])(void)={TempInit,HumiInit};
		static constexpr int (*dataProg[dataTypes])(int)={TempProg,HumiProg};
	public:
		int OCF();
		int dump(std::ostream& o);
		int menu();
};

//Serialiseable data
//-Name,
//-Type,
//-Playing,
//-Volume
class Speaker : public ToggleWithPercent{
	public:
		enum SpeakerState:bool;
		int Play();
		int Pause();
		bool isPlaying();
		int setVolume(int newVol);
		int getVolume();
		int dump(std::ostream& o);
};

//Serialiseable data
//-Name
//-Type
//-On
//-Level
class Light : public ToggleWithPercent{
	public:
		int setLevel(int p);
		int getLevel();
		int setOn(bool s);
		bool isOn();
		int dump(std::ostream& o);
};

//Serialiseable data
//-Name
//-Type
//-Enabled
//-On time
//-Off time
class Thermostat : public Schedule{
	private:
		bool Boost;//Will not be serialised
	public:
		int setBoost(bool b){
			Boost=b;
			return 0;
		}
		int dump(std::ostream& o);
};

//Serialiseable data
//-Name
//-Type
class Socket : public Schedule,public HistoricDataGen{
	private:
		int nTypes();
		std::string dName(int n);
		int initCall(int n);
		int progCall(int n,int d);
	public:
		Socket();
		int menu();
		int dump(std::ostream& o);
};

class Valve : public Schedule{
	private:
		//
	public:
		int getCurrentTemp();
		int dump(std::ostream& o);
};
