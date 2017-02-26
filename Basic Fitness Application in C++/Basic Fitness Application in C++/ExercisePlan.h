#pragma once
#include "Header.h"

class ExercisePlan
{
public:
	ExercisePlan(int goal = 1, string name = '\0', string date = '\0');
	ExercisePlan(ExercisePlan &copy);
	~ExercisePlan();
	//getters
	int getGoal();
	string getName();
	string getDate();
	//mutators
	void setGoal();
	void setName();
	void setDate();


private:
	int mGoal;
	string mName = '\0';
	string mDate = '\0';
	//maybe fstream
};
