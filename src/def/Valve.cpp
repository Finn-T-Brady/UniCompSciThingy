#include "../headers/appliances.h"
#include <iostream>

int Valve::getCurrentTemp(){
	return 40+40*this->getState();
}


std::string Valve::menuText(){
	std::string out;
	out.reserve(100);
	out+=getName();
	out+="\n-Valve\n  Enabled:";
	//out+=stateFormat[getEnabled()];
	out+="\n  Temperature:";
	out+=std::to_string(temperature);
	out+="°C\n";
	return "";
}

int Valve::menuParse(std::string& UserInput){
	//
	//
	return 0;
}

int Valve::dump(std::ostream& o){
	//
	return 0;
}
