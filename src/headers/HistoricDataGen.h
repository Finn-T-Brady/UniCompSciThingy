#pragma once
#include <iostream>
class HistoricDataGen{		
	protected:
		virtual int initCall(int n)=0;
		virtual int progCall(int n, int d)=0;
		virtual int nTypes()=0;
		virtual std::string dName(int n)=0;
	public:
		int dataView(int range);
};

