#include "../headers/appliances.h"

int HistoricDataGen::dataView(int range){
	int* data[this->nTypes()];
	for(int n=0;n<this->nTypes();n++){
		data[n]=(int*)std::malloc(range*sizeof(int));
	}
	for(int n=0;n<this->nTypes();n++){
		data[n][0]=initCall(n);
		for(int m=1;m<range;m++){
			data[n][m]=progCall(n,data[n][m-1]);
		}
	}
	std::cout<<"[T-"<<range<<" ~ T-0]\n";
	for(int n=0;n<this->nTypes();n++){
		std::cout<<this->dName(n);
		for(int m=0;m<range-1;m++){
			std::cout<<data[n][m]<<',';
		}
		std::cout<<data[n][range-1]<<'\n';
	}
	for(int n=0;n<this->nTypes();n++){
		std::free(data[n]);
	}
};

