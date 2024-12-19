#pragma once

#include "appliance.h"

class ApplianceFactory{
	public:
		static Appliance* newAppliance(std::istream& i);
		static Appliance* newAppliance(int t,std::string Name);
};
