#pragma once
#include <iostream>
#include "appliance.h"
#include "toggleable.h"
#include "schedule.h"

//Serialiseable data
//-Name
//-Type
//-Enabled
//-Temperature
//-Schedule Enable
//-On time
//-Off time
class Valve : public Schedule{
	private:
		static std::string stateFormat[2];
		std::string menuText();
		int menuParse(std::string& UserInput);
	public:
		Valve(std::string name);
		Valve(std::istream& i);

		int getCurrentTemp();
		
		int dump(std::ostream& o);
};

