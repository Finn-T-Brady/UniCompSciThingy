#include "../headers/appliances.h"

int Schedule::setSchedule(Rider::Time on,Rider::Time off){
	this->scheduleEnabled=true;
	scheduleOn=on;
	scheduleOff=off;
	return 0;
}

int Schedule::setEnabled(bool n){
	scheduleEnabled=n;
	return 0;
}
bool Schedule::getEnabled(){
	return scheduleEnabled;
}

Rider::Time& Thermostat::getOn(){
	return scheduleOn;
}
Rider::Time& Thermostat::getOff(){
	return scheduleOff;
}

bool schedule::timeState(Rider::Time curr){
	//
	//
	return false;
}
