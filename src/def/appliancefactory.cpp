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
