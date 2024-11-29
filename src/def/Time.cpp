#include "../headers/time.h"

#include <iostream>


namespace Rider{
	Time::Time(short m){
		Hours=m/60;
		Hours=Hours%24;
		Minutes=m%60;
	}
	Time::Time(short h,short m){
		Hours=h;
		Hours+=m/60;
		Hours=Hours%24;
		Minutes=m%60;
	}
	int Time::pass(short m){
		Minutes+=m;
		Hours+=Minutes/60;
		Hours=Hours%24;
		Minutes=Minutes%60;
		return 0;
	}
	int Time::pass(short h,short m){
		Hours+=h;
		Minutes+=m;
		Hours+=Minutes/60;
		Hours=Hours%24;
		Minutes=Minutes%60;
		return 0;
	}
	int Time::setTime(short h,short m){
		Hours=h;
		Hours+=m/60;
		Hours=Hours%24;
		Minutes=m%60;
		return 0;
	}
	int Time::getMinutes(){
		return Minutes;
	}
	int Time::getHours(){
		return Hours;
	}
	bool Time::operator<(const Time& t){
		if(this->Hours!=t.Hours)return this->Hours<t.Hours;
		return this->Minutes<t.Minutes;
	}
	bool Time::operator>(const Time& t){
		if(this->Hours!=t.Hours)return this->Hours>t.Hours;
		return this->Minutes>t.Minutes;
	}

	std::ostream& operator<<(std::ostream& o,Time& t){
		o<<t.Hours;
		o<<":";
		o<<t.Minutes;
		return o;
	}
	std::ostream& operator||(std::ostream& o,Time& t){
		//dump to file
	}
};
