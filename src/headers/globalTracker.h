#include <vector>

#include "appliances.h"

class Globals{
	public:
		static Globals* get();
		static void init();
		std::vector<Appliance*> Devices;
	private:
		Globals(){};
		static Globals* Gl;
};
