all: permtool.cpp
	g++ permtool.cpp -o permtool -std=c++11
clean:
	rm permtool
