#include "../headers/appliances.h"
#include <iostream>

int Valve::getCurrentTemp(){
	return 40+40*this->getState();
}

int Valve::menu(){
	//
	//
	return 0;
}

int Valve::dump(std::ostream& o){
	//
	return 0;
}
