#include <iostream>


#include "../headers/schedule.h"

#include "../headers/time.h"




//Schedule
Schedule::Schedule():Toggleable(false){
	scheduleEnabled=false;
}
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

bool Schedule::timeState(Rider::Time& curr){
	//
	return 0;
}
