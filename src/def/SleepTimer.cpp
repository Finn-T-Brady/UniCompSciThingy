#include "../headers/SleepTimer.h"

int SleepTimer::getTimer(){
	return timer;
}
int SleepTimer::setTimer(int t){
	int old=timer;
	timer=t;
	return old;
}
