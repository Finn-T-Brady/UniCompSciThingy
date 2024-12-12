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
		out+=std::to_string(getOn().getHours());
		out+=':';
		out+=std::to_string(getOn().getMinutes());
		out+='~';
		out+=std::to_string(getOff().getHours());
		out+=':';
		out+=std::to_string(getOff().getMinutes());
	}else out+="Off";
	out+="\n1:Rename\n2:Turn on\n3:Turn off\n4:Boost on\n5:Boost off\n6:Set schedule\n7:Disable schedule\n9:Delete\n";
	return out;
}
int Thermostat::menuParse(std::string& UserInput){
	int exitcode=0;
	int t[4];
	bool valid;
	switch(UserInput[0]-'0'){
		case 2:
			setState(true);
			break;
		case 3:
			setState(false);
			break;
		case 4:
			setBoost(true);
			break;
		case 5:
			setBoost(false);
		case 6:
			std::cout<<"Enter on time[hh:mm](24)\n>";
			std::getline(std::cin,UserInput);
			valid=validTime(UserInput);
			if(!valid){
				exitcode=-1;
				std::cout<<"Invalid Time\n";
				break;
			}
			t[0]=atoi(UserInput.c_str());
			t[1]=atoi(UserInput.c_str()+3);
			std::cout<<"Enter off time[hh:mm](24)\n>";
			std::getline(std::cin,UserInput);
			valid=validTime(UserInput);
			if(!valid){
				exitcode=-1;
				std::cout<<"Invalid Time\n";
				break;
			}
			t[2]=atoi(UserInput.c_str());
			t[3]=atoi(UserInput.c_str()+3);
			getOn().setTime(t[0],t[1]);
			getOff().setTime(t[2],t[3]);
			setEnabled(true);
			break;
		case 7:
			setEnabled(false);
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
