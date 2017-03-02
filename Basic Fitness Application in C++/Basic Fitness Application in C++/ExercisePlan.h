#pragma once
#include "Header.h"

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
	bool editGoal();
	bool editName();//pending deletion
	bool editDate();//pending deletion

private:
	int mGoal;
	string mName = '\0';
	string mDate = '\0';
};
