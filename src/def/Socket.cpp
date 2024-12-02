#include "../headers/appliances.h"

int Socket::nTypes(){
	return 1;
}
std::string Socket::dName(int n){
	return "Watt hours:";
}

int Socket::initCall(int n){
	return (std::rand()&511)+200;
}
int Socket::progCall(int n,int d){
	return d+(std::rand()&255)-120;
}

int Socket::menu(){
	//
	return 0;
}

int Socket::dump(std::ostream& o){
	//
	return 0;
}
