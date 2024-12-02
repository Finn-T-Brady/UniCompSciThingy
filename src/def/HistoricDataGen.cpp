#include "../headers/appliances.h"

int HistoricDataGen::getTypes(){
	return this->dataTypes;
}

int HistoricDataGen::dataView(int range){
	int* data[dataTypes];
	for(int n=0;n<this->dataTypes;n++){
		data[n]=(int*)std::malloc(range*sizeof(int));
		std::cout<<n;
	}
	for(int n=0;n<this->dataTypes;n++){
		data[n][0]=(*dataInit[n])();
		for(int m=1;m<range;m++){
			data[n][m]=(*dataProg[n])(data[n][m-1]);
		}
	}
	std::cout<<"[T-"<<range<<" ~ T-0]\n";
	for(int n=0;n<dataTypes;n++){
		std::cout<<this->dataNames[n]<<':';
		for(int m=0;m<range-2;m++){
			std::cout<<data[n][m]<<',';
		}
		std::cout<<data[n][range-1]<<'\n';
	}
	for(int n=0;n<dataTypes;n++){
		std::free(data[n]);
	}
};

