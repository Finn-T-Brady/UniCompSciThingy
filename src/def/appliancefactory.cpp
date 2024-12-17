#include "../headers/appliances.h"
#include "../headers/appliancefactory.h"

Appliance* ApplianceFactory::newAppliance(std::istream& i){
	Appliance* out=nullptr;
	int d=i.get()-'0';
	i.ignore(1);
	switch(d){
		case Devices::Light:
			out=new Light(i);
			break;
		case Devices::Sensor:
			out=new Sensor(i);
			break;
		case Devices::Speaker:
			out=new Speaker(i);
			break;
		case Devices::Thermostat:
			out=new Thermostat(i);
			break;
		case Devices::Socket:
			out=new Socket(i);
			break;
		case Devices::Valve:
			out=new Valve(i);
			break;
		default:
			break;
	}
	return out;
}

Appliance* ApplianceFactory::newAppliance(int t, std::string Name){
	Appliance* out=nullptr;
	switch(t){
		case Devices::Light:
			out=new Light(Name);
			break;
		case Devices::Sensor:
			out=new Sensor(Name);
			break;
		case Devices::Speaker:
			out=new Speaker(Name);
			break;
		case Devices::Thermostat:
			out=new Thermostat(Name);
			break;
		case Devices::Socket:
			out=new Socket(Name);
			break;
		case Devices::Valve:
			out=new Valve(Name);
			break;
		default:
			break;
	}	
	return out;
}
