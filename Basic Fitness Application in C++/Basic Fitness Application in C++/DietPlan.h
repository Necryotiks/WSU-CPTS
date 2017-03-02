#pragma once
#include "Header.h"
class DietPlan
{
public:
	DietPlan();
	DietPlan(DietPlan &newPlan);
	~DietPlan(); 
	
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
	bool editName();//pending deletion/remove bool
	bool editDate();//pending deletion

private:
	int mGoal;
	string mName = '\0';
	string mDate = '\0';
	//maybe fstream
};
