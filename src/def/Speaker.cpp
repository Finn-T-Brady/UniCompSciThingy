#include "../headers/appliances.h"
#include "../miscFunctions.h"
#include <iostream>
#include <string>

enum Speaker::SpeakerState:bool{
	Playing=true,
	Paused=false
};

int Speaker::Play(){
	setState(Playing);
	return 0;
}
int Speaker::Pause(){
	setState(Paused);
	return 0;
}
bool Speaker::isPlaying(){
	return getState();
}
int Speaker::setVolume(int newVol){
	return setPercent(newVol);
}
int Speaker::getVolume(){
	return getPercent();
}

const std::string Speaker::stateFormat[2]={"Paused","Playing"};
std::string Speaker::menuText(){
	std::string out;
	out.reserve(150);
	out+=getName();
	out+="\n-Speaker\n  ";
	out+=stateFormat[isPlaying()];
	out+="\n  Volume:";
	out+=std::to_string(getVolume());
	out+="%\n\n0:Exit\n1:Rename\n2:Toggle play\n3:Play\n4:Pause\n5 [vol(%)]:Change volume\n9:Delete\n";
	return out;
}

int Speaker::menuParse(std::string& UserInput){
	int exitcode=0;
	switch(UserInput[0]-'0'){
		case 2:
			OCF();
			break;
		case 3:
			Play();
			break;
		case 4:
			Pause();
			break;
		case 5:
			UserInput.erase(0,firstArg(UserInput)-1);
			if(UserInput[0]==0){
				std::cout<<"No volume specified\n";
				exitcode=-1;
			}else{
				exitcode = setVolume(atoi(UserInput.c_str()));
				if(exitcode<0)std::cout<<"Invalid percentage given\n";
			}
			break;
		default:
			exitcode=-1;
			break;
	}
	return exitcode;
}

int Speaker::dump(std::ostream& o){
	//
	return 0;
}
