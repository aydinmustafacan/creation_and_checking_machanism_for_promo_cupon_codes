output: main.o md5.o
	g++ main.o md5.o -o output
main.o: main.cpp	
	g++ -c main.cpp
md5.o:
	g++ -c md5.cpp


	
