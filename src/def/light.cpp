#include "../headers/appliances.h"
#include <iostream>

int Light::setLevel(int p){
	return this->setPercent(p);
}
int Light::getLevel(){
	return this->getPercent();
}
