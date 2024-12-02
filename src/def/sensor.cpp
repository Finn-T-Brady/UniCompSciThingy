#include "../headers/appliances.h"

constexpr int (*Sensor::dataInit[])(void);
constexpr int (*Sensor::dataProg[])(int);

int Sensor::OCF(){
	return dataView(4);
}

int Sensor::nTypes(){
	return this->dataTypes;
}
std::string Sensor::dName(int n){
	return dataNames[n];
}
int Sensor::initCall(int n){
	return dataInit[n]();
}
int Sensor::progCall(int n,int d){
	return dataProg[n](d);
}

int Sensor::TempInit(){
	return (std::rand()&15)-4;
}
int Sensor::HumiInit(){
	return 70+(std::rand()&15);
}
int Sensor::TempProg(int x){
	return x+(std::rand()&7)-3;
}
int Sensor::HumiProg(int x){
	int out=x+(std::rand()&7)-4;
	if(out>94)out=94;
	else if(out<70)out=70;
	return out;
}

int Sensor::menu(){
	//
	return 0;
}
int Sensor::dump(std::ostream& o){
	//
	return 0;
}
