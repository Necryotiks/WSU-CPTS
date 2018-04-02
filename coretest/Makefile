CC = g++
TESTFLAGS = -g -Wall
CFLAGS = -O3 
INCLUDES = -I~/Documents/Repos/compute/include
LIBS = -lOpenCL -L/usr/lib/  


default: nodebug

nodebug: coretest.o main.o
	$(CC) $(CFLAGS) $(INCLUDES) -pthread -o coretest coretest.o main.o $(LIBS)
debug: coretest.o
	$(CC) $(TESTFLAGS) $(INCLUDES) -o coretest coretest.o $(LIBS)
coretest.o: coretest.hpp  coretest.cpp
	$(CC) $(CFLAGS) -c coretest.cpp
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
clean:
	rm main.o coretest.o
	
