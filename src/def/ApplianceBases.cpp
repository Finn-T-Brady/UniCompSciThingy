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
					std::find_if(Globals::get()->Devices.begin(),Globals::get()->Devices.end(),[UserInput](Appliance* t){return t->getName()==UserInput;});
					if(res==Globals::get()->Devices.end())this->rename(UserInput);
					else std::cout<<"Name unavailable\n";
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
	return this->state;
}
int Toggleable::setState(bool NewState){
	this->state=NewState;
	return NewState;
}
bool Toggleable::getState(){
	return this->state;
}

//ToggleWithPercent
int ToggleWithPercent::setPercent(int newPercent){
	if(0>newPercent || newPercent>100)return -1;
	int old=this->percentage;
	this->percentage=newPercent;
	return old;
}
int ToggleWithPercent::getPercent(){
	return this->percentage;
}

//Schedule
int Schedule::setSchedule(Rider::Time on,Rider::Time off){
	this->scheduleOn=on;
	this->scheduleOff=off;
	this->scheduleEnabled=true;
	return 0;
}
int Schedule::disableSchedule(){
	this->scheduleEnabled=false;
	return 0;
}
bool Schedule::timeState(Rider::Time time){
	//
	return 0;
}
