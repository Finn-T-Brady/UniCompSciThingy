#pragma once
#include <iostream>
#include "appliance.h"
#include "toggleable.h"
#include "time.h"

//Serialiseable data
//-ScheduleEnabled
//-On time
//-Off time
class Schedule : public Toggleable{
	private:
		bool scheduleEnabled;
		Rider::Time scheduleOn;
		Rider::Time scheduleOff;
	protected:
		Rider::Time& getOn();
		Rider::Time& getOff();
		Schedule();
	public:
		int setEnabled(bool n);
		bool getEnabled();
		bool timeState(Rider::Time& curr);
};
