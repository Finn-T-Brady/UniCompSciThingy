#include <string>
int firstArg(std::string& x){
	int p=0;
	while(x[p] && x[p]!=' ')++p;
	while(x[p] && x[p]==' ')++p;
	return p;
}

bool validTime(std::string& x){
	bool valid;
	valid='0'<=x[0]&&x[0]<='2';
	valid=valid && ('0'<=x[1]&&x[1]<='9');//Technically allows 25~29 as valid houra, but the Time class can handle that 
	valid=valid && (':'==x[2]);
	valid=valid && ('0'<=x[3]&&x[3]<='5');
	valid=valid && ('0'<=x[4]&&x[4]<='9');
	valid=valid && !('0'<=x[5]&&x[5]<='9');
	return valid;
}
