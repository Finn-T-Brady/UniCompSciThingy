#pragma once
#include <iostream>
#include "appliance.h"

//Serialiseable data
//-State
class Toggleable : public Appliance{
	private:
		bool state;
	public:
		int OCF();
	protected:
		int setState(bool nState);
		bool getState();
		Toggleable(bool s);
		Toggleable();
};

