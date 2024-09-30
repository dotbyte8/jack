build:
	g++ -Wall -o bin/jack src/*.cpp

build.run:
	g++ -Wall -o bin/jack src/*.cpp
	bin/jack
