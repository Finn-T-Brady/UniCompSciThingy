obj = appliancefactory.cpp ApplianceBases.cpp Light.cpp Speaker.cpp sensor.cpp Valve.cpp Time.cpp HistoricDataGen.cpp Socket.cpp SleepTimer.cpp

inc=$(addprefix src\def\,$(obj))

all:
	g++ src\main.cpp $(inc) -o main
dbg:
	g++ src\main.cpp $(inc) -g3 -o main
