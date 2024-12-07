#include "../headers/appliances.h"
#include "../headers/Time.h"
#include "../miscFunctions.h"

#include <iostream>
#include <string>

int Thermostat::setBoost(bool b){
	Boost=b;
	return 0;
}

const std::string Thermostat::stateFormat[2]={"Off","On"};
std::string Thermostat::menuText(){
	std::string out;
	//out.reserve();
	out+=getName();
	out+="\n-Thermostat\n  State:";
	out+=stateFormat[getState()||Boost];
	out+="\n  Enabled:";
	out+=stateFormat[getState()];
	out+="\n  Boost:";
	out+=stateFormat[Boost];
	out+="\n  Schedule:";
	if(getEnabled()){
		out+=getOn().getHours();
		out+=':';
		out+=getOn().getMinutes();
		out+='~';
		out+=getOff().getHours();
		out+=':';
		out+=getOff().getMinutes();
	}else out+="Off";
	out+="\n1:Rename\n2:Turn on\n3:Turn off\n4:Boost on\n5:Boost off\n6:Enable schedule\n7:Disable schedule\n8:Set schedule\n9:Delete\n";
	return out;
}
int Thermostat::menuParse(std::string& UserInput){
	int exitcode=0;
	switch(UserInput[0]){
		case 2:
			//
			break;
		default:
			exitcode=-1;
			break;
	}
	return exitcode;
}

int Thermostat::dump(std::ostream& o){
	//
	return 0;
}
