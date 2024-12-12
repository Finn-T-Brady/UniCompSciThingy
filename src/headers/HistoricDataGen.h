#pragma once
#include <iostream>
class HistoricDataGen{
	private:
		int rangeMax;
		int** data;
		bool genned;
	protected:
		int setMax(int r);
		int manual(int r,int** dat);
		virtual int initCall(int n)=0;
		virtual int progCall(int n, int d)=0;
		virtual int nTypes()=0;
		virtual std::string dName(int n)=0;
	public:
		int dataGen();
		int dataView(int range);
		
		int dataDump(std::ostream& o);
		int del();
};

