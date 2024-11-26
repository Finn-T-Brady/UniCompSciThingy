#include "../headers/appliances.h"

int Valve::getCurrentTemp(){
	int* a=(int*)std::malloc(1);
	int b=(int)a;
	std::free(a);
	return b&63;
}
