#pragma once
#include "Header.h"
#include "DietPlan.h"
#include "ExercisePlan.h"
class FitnessAppWrapper
{
public:
	FitnessAppWrapper();//maybe add more like file initalization
	~FitnessAppWrapper();//see above
	
	DietPlan DietOBJ;
	ExercisePlan ExerciseOBJ;//WHAT THE FUCK, SAM PLS HELP.
	void loadDailyDietPlan(std::fstream &fileStream, DietPlan &Plan);
	void loadDailyExercisePlan(std::fstream &fileStream, ExercisePlan &Plan);
	void loadWeeklyDietPlan(std::fstream &fileStream, DietPlan weeklyplan[]);
	void loadWeeklyExercisePlan(std::fstream &fileStream, ExercisePlan weeklyplan[]);
	void displayDailyDietPlan();//needs parameters
	void displayDailyExercisePlan();//needs parameters
	void displayWeeklyDietPlan();//needs parameters
	void displayWeeklyExercisePlan();//needs parameters
	void storeDailyDietPlan();//needs parameters
	void storeDailyExercisePlan();//needs parameters
	void storeWeeklyDietPlan();//needs parameters
	void storeWeeklyExercisePlan();//needs parameters
	void displayMenu(); //does this even need parameters
};