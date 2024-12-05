#pragma once

#include "appliances.h"

class ApplianceFactory{
	public:
		static Appliance* newAppliance(Devices::AppType t,std::string Name,std::istream& i);
		static Appliance* newAppliance(int t,std::string Name);
};
