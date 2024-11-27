#include <iostream>
#include <ctime>

#include "headers/appliances.h"
#include "headers/appliancefactory.h"
#include "headers/hasher.h"
#include "headers/time.h"

namespace Command{
	enum Commands{
		list=1398,
		add=633,
		view=9805,
		quit=8015,
		exit=6134,
		by=1943,
		only=5028,
		just=8788
	};
	enum Devices{
		light=3662,
		sensor=4034,
		speaker=7911,
		thermostat=4455,
		socket=2515,
		valve=4080
	};
};

using namespace std;

int main(){
	std::srand(std::time(0));

	string UserInput;
	int UserHash;
	
	Sensor* aaa=new Sensor();
	aaa->dataView();
	aaa->dataView();
	return 0;	


	Appliance* temp1=nullptr;
	

	bool invalid=false;
	bool active=true;

	int arg1;
	int arg2;
	while(active){
		cout<<"[options here]\n";
		do{
			invalid=false;
			cout<<'>';
			getline(cin,UserInput);
			cout<<UserInput<<'\n';
			UserHash=RSHash(UserInput)%10000;
			cout<<UserHash<<'\n';
			switch(UserHash){
				case 0:
					invalid=true;
					break;
				case Command::list:
					arg1=RSHash(UserInput,5)%10000;
					if(arg1==0){
						//
					}else if(arg1==Command::by){
						arg2=RSHash(UserInput,8);

					}else if(arg1==Command::only||arg1==Command::just){
						arg2=RSHash(UserInput,10);
					}else{
						invalid=true;
						cout<< "Usage: List [by/only] [name/device/[device type]]\n";
					}
					break;
				case Command::add:
					arg1=RSHash(UserInput,4)%10000;
					cout<<arg1<<'\n';
					break;
				case Command::view:
					//
					break;
				
				case Command::quit:
				case Command::exit:
					active=false;
					break;
				default:
					invalid=true;
					break;
				}
		}while(invalid);
	}
	return 0;
}
