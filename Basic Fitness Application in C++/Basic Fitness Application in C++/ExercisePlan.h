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
	void editGoal();
	void editName();//pending deletion
	void editDate();//pending deletion

	friend std::ostream & operator<<(std::ostream &lhs, ExercisePlan &rhs);//place file object on the right
private:
	int mGoal;
	string mName;
	string mDate;
};