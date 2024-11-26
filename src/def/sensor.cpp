#include "../headers/appliances.h"

int Sensor::OCF(){
	return dataView();
}

int Sensor::dataView(){
	int* temp=(int*)std::malloc(4*sizeof(int));
	int* humi=(int*)std::malloc(4*sizeof(int));
	int seed=(int)temp;//evil rng implementation lol
	temp[0]=(seed&15)-4;
	for(int n=1;n<4;n++){
		seed^=(seed<<3);
		seed^=(seed>>5);
		temp[n]=temp[n-1]+(seed&7)-3;
	}
	humi[0]=(seed&7);
	for(int n=1;n<4;n++){
		seed^=(seed<<3);
		seed^=(seed>>5);
		humi[n]=humi[n-1]+(seed&3);
	}
	std::cout<<"             T-3     T-2    T-1    T-0\n";
	std::cout<<"Temperature:   ";
	for(int n=0;n<3;n++){
		std::cout<<temp[n]<<"      ";
	}
	std::cout<<temp[3]<<'\n';
	std::cout<<"Humidity:      ";
	for(int n=0;n<3;n++){
		std::cout<<humi[n]<<"      ";
	}
	std::cout<<humi[3]<<'\n';
	std::free(temp);
	std::free(humi);
	return 0;
}
