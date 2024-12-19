#pragma once
#include <iostream>
#include "appliance.h"
#include "toggleable.h"
#include "schedule.h"

//Serialiseable data
//-Name
//-Type
//-Boost
//-On
//-Schedule Enabled
//-On time
//-Off time
class Thermostat : public Schedule{
	private:
		static const std::string stateFormat[2];
		static const std::string menuFormat;
		std::string menuText();
		int menuParse(std::string& UserInput);

		bool Boost;
	public:
		Thermostat(std::string name);
		Thermostat(std::istream& i);

		int setBoost(bool b);
		
		int dump(std::ostream& o);
};

