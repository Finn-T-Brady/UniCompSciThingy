#include <iostream>
#include "../headers/percentage.h"

//Percentage
int Percentage::setPercent(int newPercent){
	if(0>newPercent || newPercent>100)return -1;
	this->percentage=newPercent;
	return 0;
}
int Percentage::getPercent(){
	return this->percentage;
}

