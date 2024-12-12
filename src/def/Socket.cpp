#include "../headers/appliances.h"
#include "../miscFunctions.h"

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

Socket::Socket(){
	setMax(24);
	dataGen();
}
Socket::~Socket(){
	this->del();
}

const std::string Socket::menuFormat="";

std::string Socket::menuText(){
	std::string out;
	out.reserve(100);
	out+=getName();
	out+="\n -Socket\nEnabled";
	//
	out+="0:Exit\n1:Rename\n2:Toggle\n3 [timer(m)]:set timer\n4:Set schedule\n5:disable schedule\n6:View data\n6 [range]:View data\n9:Delete\n";
	return out;
}

int Socket::menuParse(std::string& UserInput){
	int exitcode=0;
	int p;
	int t[4];
	bool valid;
	switch(UserInput[0]-'0'){
		case 2:
			OCF();
			break;
		case 3:
			p=firstArg(UserInput);
			setTimer(atoi(UserInput.c_str()+p));
			break;
		case 4:
			std::cout<<"Enter on time[hh:mm](24)\n>";
			std::getline(std::cin,UserInput);
			valid=validTime(UserInput);
			if(!valid){
				exitcode=-1;
				std::cout<<"Invalid Time\n";
				break;
			}
			t[0]=atoi(UserInput.c_str());
			t[1]=atoi(UserInput.c_str()+3);
			std::cout<<"Enter off time[hh:mm](24)\n>";
			std::getline(std::cin,UserInput);
			valid=validTime(UserInput);
			if(!valid){
				exitcode=-1;
				std::cout<<"Invalid Time\n";
				break;
			}
			t[2]=atoi(UserInput.c_str());
			t[3]=atoi(UserInput.c_str()+3);
			getOn().setTime(t[0],t[1]);
			getOff().setTime(t[2],t[3]);
			setEnabled(true);
			break;
		case 5:
			setEnabled(false);
			break;
		case 6:
			p=firstArg(UserInput);
			UserInput.erase(0,p);
			if('0'<=UserInput[0] && UserInput[0]<='9')dataView(atoi(UserInput.c_str()));
			else dataView(24);
			break;
	}
	return exitcode;
}

static Socket* read(std::istream&){
	Socket* out=nullptr;
	//
	return out;
}
int Socket::dump(std::ostream& o){
	//
	return 0;
}
