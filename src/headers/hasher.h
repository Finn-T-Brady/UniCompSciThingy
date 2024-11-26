//https://www.partow.net/programming/hashfunctions/index.html#RSHashFunction
#include <iostream>

unsigned int RSHash(std::string in){
	unsigned int a=378551;
	unsigned int b=63689;
	unsigned int hash=0;
	int p=0;
	while(in[p]&&in[p]!=' '){
		hash=hash*a + in[p]+32*(in[p]>='A'&&in[p]<='Z');
		a=a*b;
		p++;
	}
	return hash;
}
unsigned int RSHash(std::string in,int p){
	unsigned int a=378551;
	unsigned int b=63689;
	unsigned int hash=0;
	while(in[p]&&in[p]!=' '){
		hash=hash*a + in[p]+32*(in[p]>='A'&&in[p]<='Z');
		a=a*b;
		p++;
	}
	return hash;
}

