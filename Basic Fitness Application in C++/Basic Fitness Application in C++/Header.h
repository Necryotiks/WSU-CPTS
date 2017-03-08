#pragma once
#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include <cstdlib>
#include <cmath>


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



//TODO:expand and improve menu. overload file reading.Explicit Node Deconstructor and add color to terminal