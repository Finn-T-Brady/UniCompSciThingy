#include "../headers/appliances.h"

int Sensor::OCF(){
	return dataView(4);
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
