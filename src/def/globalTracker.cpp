#include "../headers/globalTracker.h"

void Globals::init(){
	Gl=new Globals();
}

Globals* Globals::get(){
	return Gl;
}

Globals* Globals::Gl=nullptr;
