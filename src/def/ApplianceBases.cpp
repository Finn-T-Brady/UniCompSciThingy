#include <iostream>
#include "../headers/appliances.h"
#include "../headers/time.h"

//ApplianceBase
int Appliance::rename(std::string NewName){
	this->DevName=NewName;
	return 0;
}
std::string Appliance::getName(){
	return this->DevName;
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
int Schedule::setSchedule(int on,int off){
	this->scheduleOn=on;
	this->scheduleOff=off;
	this->scheduleEnabled=true;
	return 0;
}
int Schedule::disableSchedule(){
	this->scheduleEnabled=false;
	return 0;
}
int Schedule::timeUpdate(int time){
	//
	return 0;
}
