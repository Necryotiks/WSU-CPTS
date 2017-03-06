#pragma once
#include "ExercisePlan.h"
#include "DietPlan.h"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper();//maybe add more like file initalization
	~FitnessAppWrapper();//see above

	DietPlan DietOBJ;
	ExercisePlan ExerciseOBJ;
	/*void loadDailyDietPlan(std::fstream &fileStream, DietPlan &Plan);
	void loadDailyExercisePlan(std::fstream &fileStream, ExercisePlan &Plan);*/ 
	//WE CAN JUST LOAD THE WHOLE FILE.

	//void loadWeeklyDietPlan(std::fstream &fileStream, DietPlan weeklyplan[]);
	//void loadWeeklyExercisePlan(std::fstream &fileStream, ExercisePlan weeklyplan[]);
	//REDUNDANT AS SHIT:WE BOTH FILES TO COMPILE THE LIST

	

	//MOVED FUNCTIONS TO HIGHER ECHELON
};