#include "../headers/thermostat.h"
#include "../headers/Time.h"
#include "../miscFunctions.h"

#include <iostream>
#include <string>

int Thermostat::setBoost(bool b){
	Boost=b;
	return 0;
}

Thermostat::Thermostat(std::string name):Schedule(){
	this->rename(name);
	Boost=false;
}

const std::string Thermostat::stateFormat[2]={"Off","On"};
std::string Thermostat::menuText(){
	std::string out;
	//out.reserve();
	out+=getName();
	out+="\n-Thermostat\n  State:";
	out+=stateFormat[getState()||Boost];
	out+="\n  -Enabled:";
	out+=stateFormat[getState()];
	out+="\n  -Boost:";
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
			break;
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

Thermostat::Thermostat(std::istream& i){	
	char buffer[5];
	int t[2];
	std::string name;
	name.reserve(10);
	while((buffer[0]=i.get())!=',')name+=buffer[0];
	name.shrink_to_fit();
	this->rename(name);
	this->setState(i.get()=='1');
	i.ignore(1);
	this->Boost=(i.get()=='1');
	i.ignore(1);
	this->setEnabled(i.get()=='1');
	i.ignore(1);
	i.getline(buffer,5,',');
	t[0]=atoi(buffer);
	i.getline(buffer,5,',');
	t[1]=atoi(buffer);
	this->getOn().setTime(t[0],t[1]);

	i.getline(buffer,5,',');
	t[0]=atoi(buffer);
	i.getline(buffer,5,'\n');
	t[1]=atoi(buffer);
	this->getOff().setTime(t[0],t[1]);
}
int Thermostat::dump(std::ostream& o){
	o<<Devices::Thermostat<<',';
	o<<getName()<<',';
	o<<getState()<<',';
	o<<Boost<<',';
	o<<getEnabled()<<',';
	o<<getOn().getHours()<<',';
	o<<getOn().getMinutes()<<',';
	o<<getOff().getHours()<<',';
	o<<getOff().getMinutes()<<'\n';
	return 0;
}
