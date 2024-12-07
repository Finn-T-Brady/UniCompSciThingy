#include "../headers/SleepTimer.h"

int SleepTimer::getTimer(){
	return timer;
}
int SleepTimer::setTimer(int t){
	timer=t;
	return 0;
}
