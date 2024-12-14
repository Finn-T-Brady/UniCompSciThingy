#include "../headers/HistoricDataGen.h"
#include <iostream>


HistoricDataGen::HistoricDataGen(){
	genned=false;
}

HistoricDataGen::setMax(int r){
	if(genned)return 0;
	rangeMax=r;
	return 0;
}

int HistoricDataGen::manual(int r,int** dat){
	if(genned)return 0;
	genned=true;
	rangeMax=r;
	data=dat;
	return 0;
}

int HistoricDataGen::dataGen(){
	if(genned)std::cout<<"FUCK WHY GOD WHY";
	int range=rangeMax;
	data=(int**)std::malloc(this->nTypes()*sizeof(int*));
	for(int n=0;n<this->nTypes();n++){
		data[n]=(int*)std::malloc(range*sizeof(int));
	}
	for(int n=0;n<this->nTypes();n++){
		data[n][0]=initCall(n);
		for(int m=1;m<range;m++){
			data[n][m]=progCall(n,data[n][m-1]);
		}
	}
	genned=true;
	return 0;
};


int HistoricDataGen::dataView(int range){
	if(range>rangeMax)range=rangeMax;
	std::cout<<"[T-"<<range<<" ~ T-0]\n";
	for(int n=0;n<this->nTypes();n++){
		std::cout<<this->dName(n);
		for(int m=0;m<range-1;m++){
			std::cout<<data[n][m]<<',';
		}
		std::cout<<data[n][range-1]<<'\n';
	}
	return 0;
}

int HistoricDataGen::del(){//compiler got mad at me for using a deconstructor here
	if(!genned){
		for(int n=0;n<this->nTypes();n++){
			free(data[n]);
		}
		free(data);
	}
	genned=false;
	return 0;
}

int HistoricDataGen::dataDump(std::ostream& o){
	o<<rangeMax;
	for(int n=0;n<this->nTypes();n++){
		o<<',';
		o<<data[n][0];
		for(int m=1;m<rangeMax;m++){
			o<<',';
			o<<data[n][m];
		}
	}
	return 0;
};
