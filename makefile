obj = appliancefactory.cpp Appliance.cpp Toggleable.cpp Schedule.cpp Percentage.cpp Light.cpp Speaker.cpp sensor.cpp Valve.cpp Time.cpp HistoricDataGen.cpp Socket.cpp SleepTimer.cpp Thermostat.cpp globalTracker.cpp miscFunctions.cpp

inc=$(addprefix src\def\,$(obj))

all:
	g++ src\main.cpp $(inc) -static-libstdc++ -static-libgcc -o main
dbg:
	g++ src\main.cpp $(inc) -static-libstdc++ -static-libgcc -g3 -o main
