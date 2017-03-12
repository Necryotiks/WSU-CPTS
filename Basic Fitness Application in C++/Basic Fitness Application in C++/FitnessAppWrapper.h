#pragma once
#include "ExercisePlan.h"
#include "DietPlan.h"


class FitnessAppWrapper
{
public:
	FitnessAppWrapper();
	~FitnessAppWrapper();

	DietPlan DietOBJ;
	ExercisePlan ExerciseOBJ;
	
};

