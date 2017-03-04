#pragma once
#include "DietPlan.h"
#include "ExercisePlan.h"
#include "FitnessAppWrapper.h"
#include "Header.h"
#include "List.h"

class ExercisePlan
{
public:
	ExercisePlan();
	ExercisePlan(ExercisePlan& newPlan);
	~ExercisePlan();
	
	//getters
	int getGoal();
	string getName();
	string getDate();
	//mutators
	void setGoal(int goal);
	void setName(string name);
	void setDate(string date);

	//edits
	void editGoal();
	void editName();//pending deletion
	void editDate();//pending deletion

private:
	int mGoal;
	string mName;
	string mDate;
};