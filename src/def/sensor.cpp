#include "../headers/appliances.h"
#include <ctime>

int Sensor::OCF(){
	return dataView();
}

int Sensor::dataView(){
	int* temp=(int*)std::malloc(4*sizeof(int));
	int* humi=(int*)std::malloc(4*sizeof(int));
	temp[0]=(std::rand()&15)-4;
	for(int n=1;n<4;n++){
		temp[n]=temp[n-1]+(std::rand()&7)-3;
	}
	humi[0]=(std::rand()&7);
	for(int n=1;n<4;n++){
		humi[n]=humi[n-1]+(std::rand()&3);
	}
	std::cout<<"[T-4 ~ T-0]\n";
	std::cout<<"Temperature:";
	for(int n=0;n<3;n++){
		std::cout<<temp[n]<<",";
	}
	std::cout<<temp[3]<<'\n';
	std::cout<<"Humidity:   ";
	for(int n=0;n<3;n++){
		std::cout<<humi[n]<<",";
	}
	std::cout<<humi[3]<<'\n';
	std::free(temp);
	std::free(humi);
	return 0;
}
