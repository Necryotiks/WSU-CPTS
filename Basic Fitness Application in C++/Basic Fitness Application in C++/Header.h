#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <cstdlib>
#include <cmath>
#include "DietPlan.h"
#include "ExercisePlan.h"
#include "FitnessAppWrapper.h"
#include "Header.h"
#include "List.h"

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

