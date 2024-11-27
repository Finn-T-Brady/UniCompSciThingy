#include "../headers/appliances.h"
#include <iostream>

enum Speaker::SpeakerState:bool{
	Playing=true,
	Paused=false
};

int Speaker::Play(){
	this->setState(Playing);
	return 0;
}
int Speaker::Pause(){
	this->setState(Paused);
	return 0;
}
bool Speaker::isPlaying(){
	return this->getState();
}
int Speaker::setVolume(int newVol){
	return this->setPercent(newVol);
}
int Speaker::getVolume(){
	return this->getPercent();
}
