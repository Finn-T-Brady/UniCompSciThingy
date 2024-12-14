#include "../headers/appliances.h"
#include <iostream>

int Valve::getCurrentTemp(){
	return 20+60*this->getState();
}


std::string Valve::menuText(){
	std::string out;
	out.reserve(100);
	out+=getName();
	out+="\n-Valve\n  Enabled:";
	//out+=stateFormat[getEnabled()];
	out+="\n  Temperature:";
	out+=std::to_string(getCurrentTemp());
	out+="°C\n";
	return "";
}

int Valve::menuParse(std::string& UserInput){
	//
	//
	return 0;
}

static Speaker* read(std::istream&){
	Speaker* out=nullptr;
	//
	return out;
}
int Valve::dump(std::ostream& o){
	o<<Devices::Valve<<',';
	o<<getName()<<',';
	o<<getState()<<',';
	o<<getEnabled()<<',';
	o<<getOn().getHours()<<',';
	o<<getOn().getMinutes()<<',';
	o<<getOff().getHours()<<',';
	o<<getOff().getMinutes()<<',';
	return 0;
}
