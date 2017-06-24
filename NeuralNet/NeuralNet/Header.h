#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <array>
#include <cctype>
#include <locale>





#define NEURON_NUMBER n
#define ETA overallNetLearningRate
#define ALPHA momentum

// what about size of the hidden layer(s)--how many neurons? 
//There are some empirically-derived rules-of-thumb, of these, the most commonly relied on is 
//'the optimal size of the hidden layer is usually between the size of the input and size of the output layers'.
//FIX CIRCULAR DEPENDENCIES
using std::vector;
using std::cout;
using std::endl;
using std::getline;
using std::fstream;
using std::string;
using std::isdigit;

void printVector(string label, vector<double> &vect);
template<typename T, typename U>
T autoCast(U castTarget)
{
	return static_cast<T>(castTarget);
}