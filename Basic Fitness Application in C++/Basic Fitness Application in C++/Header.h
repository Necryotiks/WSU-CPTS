#pragma once
#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include <cmath>
#include <Windows.h>
#define TEXT_RED 12
#define TEXT_BLUE 1
#define TEXT_GREEN 10


//Name:Elliott Villars
//SID:11463956
//Date: 3/8/2017
//Worked With: Edgar Perez,Josh Cross

//maybe causing circular dependence?

//BEWARE CIRCULAR DEPENDENCE
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::abs;
using std::fstream;


void runapp();
int userErrorCorrection(int target);
int userErrorCorrection(char target);
int userErrorCorrection(double target);

char* Color(int color = 7, char* Message = "");



//TODO:Explicit Node Deconstructor, Fix writing to file. improve file storage UX

