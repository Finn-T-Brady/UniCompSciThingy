#pragma once

#include <iostream>

namespace Rider{
	class Time{//IWAE
		private:
			short Hours;//24 hour
			short Minutes;
		public:
			Time(short m);
			Time(short h,short m);
			int pass(short m);
			int pass(short h,short m);
			int setTime(short h, short m);
			int getMinutes();
			int getHours();
	
			bool operator<(const Time& t);
			bool operator>(const Time& t);
	
			friend std::ostream& operator<<(std::ostream& o,Time& t);
			friend std::ostream& operator||(std::ostream& o,Time& t);
	};
};
