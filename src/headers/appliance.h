#pragma once
#include <iostream>

namespace Devices{
	enum AppType:int{
		Light=0,
		Sensor=1,
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
	protected:
		virtual std::string menuText()=0;
		virtual int menuParse(std::string& UserInput)=0;
	public:
		virtual int OCF()=0;
		int rename(std::string NewName);
		std::string getName();
		
		virtual int menu() final;
		virtual int dump(std::ostream& o)=0;
};
