#include <iostream>

#include "../hasher.h"

using namespace std;

int main(){
	while(true){
		string a;
		cin>>a;
		cout<<RSHash(a)%10000;
		cout<<'\n';
	}
	return 0;
}
