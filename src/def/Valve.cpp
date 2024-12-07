#include "../headers/appliances.h"
#include <iostream>

int Valve::getCurrentTemp(){
	return 40+40*this->getState();
}


std::string Valve::menuText(){
	//
	return "";
}

int Valve::menuParse(std::string& UserInput){
	//
	//
	return 0;
}

int Valve::dump(std::ostream& o){
	//
	return 0;
}
