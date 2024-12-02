#include "../headers/appliances.h"

int Schedule::setSchedule(Rider::Time on,Rider::Time off){
	this->scheduleEnabled=true;
	scheduleOn=on;
	scheduleOff=off;
	return 0;
}

int Schedule::disableSchedule(){
	this-scheduleEnabled=false;
	return 0;
}

bool schedule::timeState(Rider::Time curr){
	//
	//
	return false;
}
