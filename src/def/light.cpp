#include "../headers/appliances.h"
#include "../miscFunctions.h"

#include <iostream>
#include <string>
#include <sstream>

int Light::setLevel(int p){
	if(p==0)return setOn(false);
	else setOn(true);
	return this->setPercent(p);
}
int Light::getLevel(){
	return this->getPercent();
}
int Light::setOn(bool s){
	return this->setState(s);
}
bool Light::isOn(){
	return this->getState();
}

std::string Light::menuText(){
	std::string out;
	out.reserve(130);
	out+=getName();
	out+="\n-Light\n  Output:";
	if(isOn()){
		out+=std::to_string(getLevel());
		out+='%';
	}else out+="off";
	out+="\nTimer:";
	out+=std::to_string(getTimer());
	out+="m\n\n0:Exit\n1:Rename\n2:Toggle\n3 [Level(%)]:Set Level\n4 [Time(m)]\n9:Delete\n";
	return out;
}

int Light::menuParse(std::string& UserInput){
	int exitcode=0;
	switch(UserInput[0]-'0'){
		case 2:
			OCF();
			break;
		case 3:
			UserInput.erase(0,firstArg(UserInput)-1);
			if(UserInput[0]==0){
				std::cout<<"No level specified\n";
				exitcode=-1;
			}else{
				exitcode=setLevel(atoi(UserInput.c_str()));
				if(exitcode<0)std::cout<<"Invalid percentage given\n";
			}
			break;
		case 4:
			UserInput.erase(0,firstArg(UserInput)-1);
			if(UserInput[0]==0){
				std::cout<<"No time specified\n";
				exitcode=-1;
			}else exitcode=setTimer(atoi(UserInput.c_str()));
			break;
		default:
			exitcode=-1;
			break;
	}
	return exitcode;
}

static Light* read(std::istream&){
	Light* out=nullptr;
	//
	return out;
}
int Light::dump(std::ostream& o){
	std::stringstream buf;
	buf<<Devices::Light;
	buf<<',';
	buf<<getName();
	buf<<',';
	buf<<isOn();
	buf<<',';
	buf<<getLevel();
	buf<<',';
	buf<<getTimer();
	buf<<'\n';
	o<<buf.str();
	return 0;
}

