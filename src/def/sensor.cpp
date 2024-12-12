#include "../headers/appliances.h"
#include "../miscFunctions.h"

#include <string>

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

std::string Sensor::menuText(){
	std::string out;
	out.reserve(70);
	out+=getName();
	out+="\n-Sensor\n\n0:Exit\n1:Rename\n2:View data\n2 [range]:View data\n9:Delete\n";
	return out;
}
int Sensor::menuParse(std::string& UserInput){
	int exitcode=0;
	int p=0;
	switch(UserInput[0]-'0'){
		case 2:
			p=firstArg(UserInput);
			UserInput.erase(0,p);
			std::cout<<UserInput;
			if('0'<=UserInput[0] && UserInput[0]<='9')dataView(atoi(UserInput.c_str()));
			else dataView(4);
			break;
		default:
			exitcode=-1;
			break;
	}
	return exitcode;
}
int Sensor::dump(std::ostream& o){
	//
	return 0;
}
