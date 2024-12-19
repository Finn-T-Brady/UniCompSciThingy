///////////////////////////
//Proof of work and stuff
//https://github.com/Finn-T-Brady/UniCompSciThingy
///////////////////////////
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <ctime>
#include <string.h>
#include <fstream>

#include "headers/appliance.h"
#include "headers/toggleable.h"
#include "headers/schedule.h"
#include "headers/light.h"
#include "headers/sensor.h"
#include "headers/speaker.h"
#include "headers/thermostat.h"
#include "headers/socket.h"
#include "headers/valve.h"

#include "headers/appliancefactory.h"

#include "headers/globalTracker.h"

#include "headers/time.h"

using namespace std;


int main(){
	std::srand(std::time(0));
	Globals::init();
	
	vector<Appliance*>& Devices=Globals::get()->Devices;
	Appliance* temp;

	string fName=".devices";

	ifstream inFile;
	inFile.open(fName);
	if(inFile.good()&&inFile.is_open()){
		while(inFile.peek()!=EOF){
			temp=ApplianceFactory::newAppliance(inFile);
			if(temp!=nullptr)Devices.push_back(temp);
		}
	}
	inFile.close();
	
	string UserInput;

	bool invalid=false;
	bool active=true;

	bool subInvalid=false;
	
	vector<Appliance*>::iterator res;
	int p;
	int exitcode;

	auto findName = [&UserInput](Appliance* t){return t->getName()==UserInput;};
	auto sortName = [](Appliance* l,Appliance* r){return l->getName()<r->getName();};
	auto sortType = [](Appliance* l,Appliance* r){
		int temp=strcmp(typeid(*l).name(),typeid(*r).name());//FUCK C STRINGS AND FUCK GCC FOR MANGLING TYPE NAMES I HATE IT HERE
		if(temp!=0)return temp<0;
		else return l->getName()<r->getName();
	};

	while(active){
		cout<<"\n[Device Name]:One Click Function\n1:List\n2:Sort by Name\n3:Sort by Type\n4 [Device Name]:View device menu\n5:Add device\n9:Quit program\n";
		do{
			invalid=false;
			cout<<'>';
			getline(cin,UserInput);
			switch(UserInput[0]-'0'){
				case 1://List
					for_each(Devices.begin(),Devices.end(),[](Appliance* d){cout<<typeid(*d).name()<<" : "<<d->getName()<<'\n';});
					break;
				case 2://Sort Name
					sort(Devices.begin(),Devices.end(),sortName);
					break;
				case 3://Sort Type,Name
					sort(Devices.begin(),Devices.end(),sortType);
					break;
				case 4://View
					p=0;
					while(UserInput[p]!=' ' && UserInput[p])++p;
					while(UserInput[p]==' ' && UserInput[p])++p;
					UserInput.erase(0,p);
					res = find_if(Devices.begin(),Devices.end(),findName);
					if(res!=Devices.end()){
						exitcode = (*res)->menu();
						if(exitcode==4){
							delete *res;
							Devices.erase(res);
						}
					}
					else{
						cout<<"Device not found\n";
						invalid=true;
					}
					break;
				case 5://Add
					do{
						cout<<"Enter device type\n";
						cout<<"1: Light\n2: Sensor\n3: Speaker\n4: Thermostat\n5: Socket\n6: Valve\n0: Cancel\n>";
						getline(cin,UserInput);
						subInvalid='0'>UserInput[0] || UserInput[0]>'6';
					}while(subInvalid);
					if(UserInput[0]!='0'){
						do{
							subInvalid=false;
							p=UserInput[0]-'1';
							cout<<"Enter name:";
							getline(cin,UserInput);
							res=find_if(Devices.begin(),Devices.end(),findName);
							if(res==Devices.end() && UserInput.find(',')==-1){
								temp=ApplianceFactory::newAppliance(p,UserInput);
								if(temp!=nullptr)Devices.push_back(temp);
							}else{
								cout<<"Name Unavailable\n";
								subInvalid=true;
							}
						}while(subInvalid);
					}
					break;
				case 9://Quit
					active=false;
					break;
				default:
					res = std::find_if(Devices.begin(),Devices.end(),findName);
					if(res!=Devices.end())(*res)->OCF();
					else{
						invalid=true;
						cout<<"Invalid command or device name\n";
					}
					break;
				}
		}while(invalid);
	}
	ofstream outFile;
	outFile.open(fName);
	
	if(outFile.good()&&outFile.is_open()){
		for_each(Devices.begin(),Devices.end(),[&outFile](Appliance* t){t->dump(outFile);outFile.flush();});
	}else cout<<"Unable to write file\n";
	outFile.close();
	return 0;
}
