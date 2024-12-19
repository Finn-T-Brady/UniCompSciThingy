#pragma once
#include <iostream>
#include "appliance.h"
#include "toggleable.h"
#include "percentage.h"
#include "SleepTimer.h"

//Serialiseable data
//-Name
//-Type
//-On
//-Level
//-Timer
class Light : public Toggleable,public Percentage,public SleepTimer{
	private:
		static const std::string menuFormat;
		std::string menuText();
		int menuParse(std::string& UserInput);
	public:
		Light(std::string name);
		Light(std::istream& i);

		int setLevel(int p);
		int getLevel();
		int setOn(bool s);
		bool isOn();

		int dump(std::ostream& o);
};

