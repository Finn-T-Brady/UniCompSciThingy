#include <iostream>
#include <vector>
#include <ctime>

#include "headers/appliances.h"
#include "headers/appliancefactory.h"

#include "headers/time.h"

using namespace std;

int main(){
	std::srand(std::time(0));
	
	Sensor* J = new Sensor();

	J->OCF();
	cout<<"AAAA";
	return 0;

	vector<Appliance*> Devices;
	
	string UserInput;

	bool invalid=false;
	bool active=true;

	while(active){
		cout<<"[Device Name]:One Click Function\n1:List\n2:Sort by Name\n3:Sort by Type\n4:View device menue\n5:Add device\n9:Quit program\n";
		do{
			invalid=false;
			cout<<'>';
			getline(cin,UserInput);
			switch(UserInput[0]-'0'){
				case 1://List
					break;
				case 2://Sort Name
					break;
				case 3://Sort Type,Name
					//
					break;
				case 4://View
					//
					break;
				case 5://Add
					//
					break;
				case 9://Quit
					active=false;
					break;
				default:
					//Search here

					//else
					invalid=true;
					break;
				}
		}while(invalid);
	}
	return 0;
}
