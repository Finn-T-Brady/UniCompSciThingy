#include "../headers/appliances.h"
#include <iostream>
#include "../miscFunctions.h"
#include <string>
#include <sstream>


int Valve::getCurrentTemp(){
	return 20+60*this->getState();
}

Valve::Valve(std::string name):Schedule(){
	this->rename(name);
}

std::string Valve::stateFormat[2]={"Off","On"};
std::string Valve::menuText(){
	std::string out;
	out.reserve(100);
	out+=getName();
	out+="\n-Valve\n  Enabled:";
	out+=stateFormat[getEnabled()];
	out+="\n  Temperature:";
	out+=std::to_string(getCurrentTemp());
	out+="C\n  Schedule:";
	if(getEnabled()){
		out+=std::to_string(getOn().getHours());
		out+=':';
		out+=std::to_string(getOn().getMinutes());
		out+='~';
		out+=std::to_string(getOff().getHours());
		out+=':';
		out+=std::to_string(getOff().getMinutes());
	}else out+="Off";
	out+="\n0:Exit\n1:Rename\n2:Turn on\n3:Turn off\n4:Set schedule\n5:Disable Schedule\n9:Delete\n";
	return out;
}

int Valve::menuParse(std::string& UserInput){
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
		case 5:
			setEnabled(false);
			break;
		default:
			exitcode=-1;
			break;
	}
	return exitcode;
}

Valve::Valve(std::istream& i){
	int t[2];
	char buffer[5];
	std::string name;
	name.reserve(10);
	while((buffer[0]=i.get())!=',')name+=buffer[0];
	name.shrink_to_fit();
	this->rename(name);

	this->setState(i.get()=='1');
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
int Valve::dump(std::ostream& o){
	std::stringstream buf;
	buf<<Devices::Valve<<',';
	buf<<getName()<<',';
	buf<<getState()<<',';
	buf<<getEnabled()<<',';
	buf<<getOn().getHours()<<',';
	buf<<getOn().getMinutes()<<',';
	buf<<getOff().getHours()<<',';
	buf<<getOff().getMinutes()<<'\n';
	return 0;
}
