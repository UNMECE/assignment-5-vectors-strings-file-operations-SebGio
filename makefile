main: main.o pixel.o
	g++ -o main main.o pixel.o -std=c++11
main.o: main.cpp
	g++ -c main.cpp -std=c++11
pixel.o: pixel.cpp
	g++ -c pixel.cpp -std=c++11
