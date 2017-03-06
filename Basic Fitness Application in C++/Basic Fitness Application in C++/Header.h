#pragma once
#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include "FitnessAppWrapper.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct node
{
	FitnessAppWrapper FObj;//QUERY SAM/EDGAR ON HOW TO MAKE THIS PRIVATE
	struct node * pNext = nullptr;
}Node;

void runapp();

