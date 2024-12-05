#include "../headers/appliancefactory.h"

Appliance* ApplianceFactory::newAppliance(Devices::AppType t,std::string Name,std::istream& i){
	Appliance* out=nullptr;
	switch(t){
		case Devices::Light:
			//
			break;
		case Devices::Sensor:
			//
			break;
		case Devices::Speaker:
			//
			break;
		case Devices::Thermostat:
			//
			break;
		case Devices::Socket:
			//
			break;
		case Devices::Valve:
			//
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
			out=new Light();
			break;
		case Devices::Sensor:
			out=new Sensor();
			break;
		case Devices::Speaker:
			out=new Speaker();
			break;
		case Devices::Thermostat:
			out=new Thermostat();
			break;
		case Devices::Socket:
			out=new Socket();
			break;
		case Devices::Valve:
			out=new Valve();
			break;
		default:
			break;
	}
	out->rename(Name);
	return out;
}
