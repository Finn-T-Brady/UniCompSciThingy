#include <iostream>

#include <vector>
#include <iterator>
#include <algorithm>

#include "../headers/appliance.h"

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
					if(res==Globals::get()->Devices.end() && UserInput.find(',')==-1) this->rename(UserInput);
					else std::cout<<"Name Unavailable\n\n";
					break;
				case 9:
					std::cout<<"Are you sure? [Y/n]\n>";
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

