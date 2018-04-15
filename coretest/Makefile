CC = g++
TESTFLAGS = -g -Wall
CFLAGS = -O3 -flto=16 -fgraphite-identity -ftree-loop-distribution -floop-nest-optimize
INCLUDES = -I~/Documents/Repos/compute/include -I~/Documents/Repos/WSU-CPTS/ANSIcommands/include/
LIBS = -lOpenCL -L/usr/lib/ -lboost_system -lboost_filesystem -L~/Documents/Repos/WSU-CPTS/ANSIcommands/lib/ -lANSIcommands
DEFS = -DBOOST_COMPUTE_USE_OFFLINE_CACHE 


default: nodebug

nodebug: coretest.o main.o
	$(CC) $(CFLAGS) $(INCLUDES) -pthread -o coretest coretest.o main.o $(LIBS)
debug: coretest.o
	$(CC) $(TESTFLAGS) $(INCLUDES) -o coretest coretest.o $(LIBS)
coretest.o: coretest.hpp  coretest.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c coretest.cpp $(LIBS)
main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp $(LIBS)
clean:
	rm main.o coretest.o
	
