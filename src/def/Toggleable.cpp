#include <iostream>
#include "../headers/toggleable.h"

//Toggleable
int Toggleable::OCF(){
	this->state^=true;
	return 0;
}
int Toggleable::setState(bool NewState){
	this->state=NewState;
	return 0;
}
bool Toggleable::getState(){
	return this->state;
}

Toggleable::Toggleable(bool s){
	state=s;
}
Toggleable::Toggleable(){}
