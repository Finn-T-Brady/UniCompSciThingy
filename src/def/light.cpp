#include "../headers/appliances.h"
#include <iostream>

int Light::setLevel(int p){
	return this->setPercent(p);
}
int Light::getLevel(){
	return this->getPercent();
}
int Light::setOn(bool s){
	return this->setState(s);
}
bool Light::isOn(){
	return this->getState();

int Light::dump(std::ostream& o){
	
