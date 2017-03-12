#pragma once
#include "Header.h"


class ExercisePlan
{
public:
	ExercisePlan();
	ExercisePlan(ExercisePlan& newPlan);
	~ExercisePlan();
	
	//getters
	int getGoal() const;
	string getName() const;
	string getDate()const;
	//mutators
	void setGoal(int goal);
	void setName(string name);
	void setDate(string date);

	//edits
	void editGoal();
	void editName();
	void editDate();

	friend std::ostream & operator<<(std::ostream &lhs, ExercisePlan &rhs);//place file object on the left
	friend std::istream & operator>> (std::istream &lhs, ExercisePlan &rhs);
private:
	int mGoal;
	string mName;
	string mDate;
};