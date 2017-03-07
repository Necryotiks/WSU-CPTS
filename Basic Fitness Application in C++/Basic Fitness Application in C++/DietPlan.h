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
	void editGoal();
	void editName();//pending deletion/remove void
	void editDate();//pending deletion

	friend std::ostream & operator<<(std::ostream &lhs, DietPlan &rhs);//place file object on the right
private:
	int mGoal;
	string mName;
	string mDate;
	//maybe fstream
};