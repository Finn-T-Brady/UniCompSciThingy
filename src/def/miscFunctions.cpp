#include <string>
int firstArg(std::string& x){
	int p=0;
	while(x[p] && x[p]!=' ')++p;
	while(x[p] && x[p]==' ')++p;
	return p;
}
