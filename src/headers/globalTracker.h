#include <vector>

#include "appliance.h"

class Globals{
	public:
		static Globals* get();
		static void init();
		std::vector<Appliance*> Devices;
	private:
		Globals(){};
		static Globals* Gl;
};
