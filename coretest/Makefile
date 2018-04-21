CC = g++
TESTFLAGS = -g -Wall 
CFLAGS = -O3 -flto=16 -fgraphite-identity -ftree-loop-distribution -floop-nest-optimize 
INCLUDES = -I~/Documents/Repos/compute/include -I../ANSIcommands/include
LIBS = -L../ANSIcommands/lib/ -lANSIcommands -lOpenCL -lboost_system -lboost_filesystem 
DEFS = -DBOOST_COMPUTE_USE_OFFLINE_CACHE 
OBJ = main.o coretest.o


default: nodebug

nodebug: coretest.o main.o
	$(CC) $(CFLAGS) $(INCLUDES) -pthread -o coretest $(OBJ) $(LIBS) 
debug: coretest.o
	$(CC) $(TESTFLAGS) $(INCLUDES) $(LIBS) -o coretest coretest.o $(LIBS) 
coretest.o: coretest.hpp  coretest.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -c coretest.cpp $(LIBS) 
main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -c main.cpp $(LIBS) 
clean:
	rm main.o coretest.o
	
