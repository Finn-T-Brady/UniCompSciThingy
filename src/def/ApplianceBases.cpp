#include <iostream>

#include <vector>
#include <iterator>
#include <algorithm>

#include "../headers/appliances.h"
#include "../headers/time.h"

#include "../headers/globalTracker.h"

//ApplianceBase
int Appliance::rename(std::string NewName){
	this->DevName=NewName;
	return 0;
}
std::string Appliance::getName(){
	return this->DevName;
}

int Appliance::menu(){
	bool running=true;
	bool invalid=false;
	int exitcode=0;
	std::string UserInput;
	std::vector<Appliance*>::iterator res;
	while(running){
		std::cout<<"\n--Device Submenu--\n";
		std::cout<<menuText();
		do{
			invalid=false;
			std::cout<<'>';
			std::getline(std::cin,UserInput);
			switch(UserInput[0]-'0'){
				case 0:
					running=false;
					break;
				case 1:
					std::cout<<"Enter Name:";
					std::getline(std::cin,UserInput);
					res=std::find_if(Globals::get()->Devices.begin(),Globals::get()->Devices.end(),[UserInput](Appliance* t){return t->getName()==UserInput;});
					if(res==Globals::get()->Devices.end()) this->rename(UserInput);
					else std::cout<<"Name Unavailable\n\n";
					break;
				case 9:
					std::cout<<"Are you sure? [Y/n]\n";
					std::getline(std::cin,UserInput);
					if(UserInput[0]=='Y'){
						exitcode=4;
						running=false;
					}
					break;
				default:
					exitcode=menuParse(UserInput);
					invalid=exitcode<0;
					break;
			}
		}while(invalid);
	}
	return exitcode;
}

//Toggleable
int Toggleable::OCF(){
	this->state^=true;
	return 0;
}
int Toggleable::setState(bool NewState){
	this->state=NewState;
	return 0;
}
bool Toggleable::getState(){
	return this->state;
}

//ToggleWithPercent
int ToggleWithPercent::setPercent(int newPercent){
	if(0>newPercent || newPercent>100)return -1;
	this->percentage=newPercent;
	return 0;
}
int ToggleWithPercent::getPercent(){
	return this->percentage;
}

//Schedule
int Schedule::setEnabled(bool n){
	scheduleEnabled=n;
	return 0;
}
bool Schedule::getEnabled(){
	return scheduleEnabled;
}

Rider::Time& Schedule::getOn(){
	return scheduleOn;
}
Rider::Time& Schedule::getOff(){
	return scheduleOff;
}

bool Schedule::timeState(Rider::Time time){
	//
	return 0;
}
