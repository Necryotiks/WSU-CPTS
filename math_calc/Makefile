CC = g++
CLANG = clang++
DEBUG= -g -Wall -std=c++1z
DEBUG-C = -g -Weverything -Wno-global-constructors -Wno-exit-time-destructors -Wno-newline-eof -Wno-c++98-compat-pedantic -std=c++1z 
FILENAME= math_calculator
OBJ = main.o vectorCalc.o functions.o

default: all
all:build

build: main.o vectorCalc.o functions.o
	$(CC) $(DEBUG) $(OBJ) -o $(FILENAME) 
	$(CLANG) $(DEBUG-C) $(OBJ) -o $(FILENAME) 
	rm $(OBJ)

main.o: main.cpp
	$(CC) $(DEBUG) -c main.cpp
	$(CLANG) $(DEBUG-C) -c main.cpp
vectorCalc.o: vectorCalc.cpp vectorCalc.h
	$(CC) $(DEBUG) -c vectorCalc.cpp
	$(CLANG) $(DEBUG-C) -c vectorCalc.cpp
functions.o: functions.cpp
	$(CC) $(DEBUG) -c functions.cpp
	$(CLANG) $(DEBUG-C) -c functions.cpp
run: build
	./$(FILENAME)
clean:
	rm $(FILENAME)


