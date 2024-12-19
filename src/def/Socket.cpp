#include "../headers/socket.h"
#include "../miscFunctions.h"

#include <iostream>
#include <string>
#include <sstream>

int Socket::nTypes(){
	return 1;
}
std::string Socket::dName(int n){
	return "Watt hours:";
}

int Socket::initCall(int n){
	return (std::rand()&511)+200;
}
int Socket::progCall(int n,int d){
	return d+(std::rand()&255)-120;
}

Socket::Socket(std::string name):HistoricDataGen(),Schedule(){
	this->rename(name);
	setMax(24);
	dataGen();
	setTimer(0);
}

Socket::~Socket(){
	this->del();
}

const std::string Socket::stateFormat[2]={"Off","On"};

std::string Socket::menuText(){
	std::string out;
	out.reserve(100);
	out+=getName();
	out+="\n -Socket\n  Enabled:";
	out+=stateFormat[getState()];
	out+="\n  Timer:";
	out+=std::to_string(getTimer());
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
	out+="\n0:Exit\n1:Rename\n2:Toggle\n3 [timer(m)]:set timer\n4:Set schedule\n5:disable schedule\n6:View data\n6 [range]:View data\n9:Delete\n";
	return out;
}

int Socket::menuParse(std::string& UserInput){
	int exitcode=0;
	int p;
	int t[4];
	bool valid;
	switch(UserInput[0]-'0'){
		case 2:
			OCF();
			break;
		case 3:
			p=firstArg(UserInput);
			setTimer(atoi(UserInput.c_str()+p));
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
		case 6:
			p=firstArg(UserInput);
			UserInput.erase(0,p);
			if('0'<=UserInput[0] && UserInput[0]<='9')dataView(atoi(UserInput.c_str()));
			else dataView(24);
			break;
	}
	return exitcode;
}

Socket::Socket(std::istream& i):HistoricDataGen(){
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
	i.getline(buffer,5,',');
	t[1]=atoi(buffer);
	this->getOff().setTime(t[0],t[1]);

	i.getline(buffer,5,',');
	this->setTimer(atoi(buffer));

	this->manual(i);
}
int Socket::dump(std::ostream& o){
	std::stringstream buf;
	buf<<Devices::Socket<<',';
	buf<<getName()<<',';
	buf<<getState()<<',';
	buf<<getEnabled()<<',';
	buf<<getOn().getHours()<<',';
	buf<<getOn().getMinutes()<<',';
	buf<<getOff().getHours()<<',';
	buf<<getOff().getMinutes()<<',';
	buf<<getTimer()<<',';
	dataDump(buf);
	buf<<'\n';
	o<<buf.str();
	return 0;
}
