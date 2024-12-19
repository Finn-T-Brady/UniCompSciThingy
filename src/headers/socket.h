#pragma once
#include <iostream>
#include "appliance.h"
#include "toggleable.h"
#include "schedule.h"
#include "HistoricDataGen.h"
#include "SleepTimer.h"

//Serialiseable data
//-Name
//-Type
//-Enabled
//-Schedule Enabled
//-On time
//-Off time
class Socket : public Schedule,public HistoricDataGen,public SleepTimer{
	private:
		static const std::string stateFormat[2];
		std::string menuText();
		int menuParse(std::string& UserInput);

		int nTypes();
		std::string dName(int n);
		int initCall(int n);
		int progCall(int n,int d);
		Socket(bool gen);
	public:
		Socket(std::string name);
		Socket(std::istream& i);
		~Socket();

		int dump(std::ostream& o);
};
