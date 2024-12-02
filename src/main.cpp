#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <ctime>

#include "headers/appliances.h"
#include "headers/appliancefactory.h"

#include "headers/time.h"

using namespace std;

int main(){
	std::srand(std::time(0));

	vector<Appliance*> Devices;
	//Test
	Light* J=new Light();
	J->rename("FUCK");
	Devices.push_back(J);
	Sensor* A=new Sensor();
	A->rename("AAA");
	Devices.push_back(A);
	J=new Light();
	J->rename("WHY");
	Devices.push_back(J);

	string UserInput;

	bool invalid=false;
	bool active=true;

	vector<Appliance*>::iterator res;
	int p;
	int exitcode;
	while(active){
		cout<<"[Device Name]:One Click Function\n1:List\n2:Sort by Name\n3:Sort by Type\n4:View device menue\n5:Add device\n9:Quit program\n";
		do{
			invalid=false;
			cout<<'>';
			getline(cin,UserInput);//							Remove this when porting to visual studio
			switch(UserInput[0]-'0'){//							is only needed to handle g++ mangling type names
				case 1://List										V
					for_each(Devices.begin(),Devices.end(),[](Appliance* d){cout<<(typeid(*d).name()+1)<<" : "<<d->getName()<<'\n';});
				case 2://Sort Name
					break;
				case 3://Sort Type,Name
					//
					break;
				case 4://View
					p=0;
					while(UserInput[p]!=' ')++p;
					while(UserInput[p]==' ')++p;
					UserInput=UserInput.substr(p,UserInput.length());
					res = std::find_if(Devices.begin(),Devices.end(),[UserInput](Appliance* t){return t->getName()==UserInput;});
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
					//
					break;
				case 9://Quit
					active=false;
					break;
				default:
					res = std::find_if(Devices.begin(),Devices.end(),[UserInput](Appliance* t){return t->getName()==UserInput;});
					if(res!=Devices.end())(*res)->OCF();
					else invalid=true;
					break;
				}
		}while(invalid);
	}
	return 0;
}
