#include "../headers/appliances.h"
#include "../headers/appliancefactory.h"

Appliance* ApplianceFactory::newAppliance(std::istream& i){
	Appliance* out=nullptr;
	int d=i.get()-'0';
	i.ignore(1);
	switch(d){
		case Devices::Light:
			out=Light::read(i);
			break;
		case Devices::Sensor:
			out=Sensor::read(i);
			break;
		case Devices::Speaker:
			out=Speaker::read(i);
			break;
		case Devices::Thermostat:
			out=Thermostat::read(i);
			break;
		case Devices::Socket:
			out=Socket::read(i);
			break;
		case Devices::Valve:
			out=Valve::read(i);
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
