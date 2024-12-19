#pragma once

#include <iostream>
#include "appliance.h"
#include "HistoricDataGen.h"

//Serialiseable data:
//-Name,
//-Type,
//-Data
class Sensor : public Appliance,public HistoricDataGen{
	private:
		std::string menuText();
		int menuParse(std::string& UserInput);

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
		Sensor(std::string name);
		Sensor(std::istream& i);
		~Sensor();

		int OCF();

		int dump(std::ostream& o);
};

