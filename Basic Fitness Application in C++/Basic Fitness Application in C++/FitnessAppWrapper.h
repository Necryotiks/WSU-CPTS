#pragma once
#include "ExercisePlan.h"
<<<<<<< HEAD
=======
#include "DietPlan.h"
>>>>>>> 7c0c1a78917cb87994111e6f727516900940ecc5

class FitnessAppWrapper
{
public:
	FitnessAppWrapper();//maybe add more like file initalization
	~FitnessAppWrapper();//see above

	DietPlan DietOBJ;
<<<<<<< HEAD
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
=======
	ExercisePlan ExerciseOBJ;
	/*void loadDailyDietPlan(std::fstream &fileStream, DietPlan &Plan);
	void loadDailyExercisePlan(std::fstream &fileStream, ExercisePlan &Plan);*/ 
	//WE CAN JUST LOAD THE WHOLE FILE.

	//void loadWeeklyDietPlan(std::fstream &fileStream, DietPlan weeklyplan[]);
	//void loadWeeklyExercisePlan(std::fstream &fileStream, ExercisePlan weeklyplan[]);
	//REDUNDANT AS SHIT:WE BOTH FILES TO COMPILE THE LIST

	

	//MOVED FUNCTIONS TO HIGHER ECHELON
};
>>>>>>> 7c0c1a78917cb87994111e6f727516900940ecc5
