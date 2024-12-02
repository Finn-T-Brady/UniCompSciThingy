#pragma once

#include "appliances.h"

class ApplianceFactory{
	static Appliance* newAppliance(Devices::AppType t,std::string Name,std::istream& i);
};
