#include "ExercisePlan.h"
#include "Header.h"

ExercisePlan::ExercisePlan()
{
	mGoal = 0;
	mName = '\0';
	mDate = '\0';

}

ExercisePlan::ExercisePlan(ExercisePlan & newPlan)
{
	mGoal = newPlan.getGoal();
	mName = newPlan.getName();
	mDate = newPlan.getDate();
}

ExercisePlan::~ExercisePlan()
{
}
int ExercisePlan::getGoal()const
{
	return mGoal;
}

string ExercisePlan::getName()const
{
	return mName;
}

string ExercisePlan::getDate() const
{
	return mDate;
}

void ExercisePlan::setGoal(int goal)
{
	mGoal = abs(goal);
}


void ExercisePlan::setName(string name)
{
	mName = name;
}

void ExercisePlan::setDate(string date)
{

	mDate = date;
}

void ExercisePlan::editGoal()
{
	int newGoal;
	cout << "Set calorie goal: " << endl;
	cin >> newGoal;
	mGoal = abs(newGoal);
}

void ExercisePlan::editName()
{
	string newName;
	cout << "Enter an exercise plan name: " << endl;// need editBullshit();
	getline(cin, newName);
	mName = newName;
}

void ExercisePlan::editDate()//maybe remove void?
{
	string newDate;
	cout << "Enter a date for plan completion" << endl;
	getline(cin, newDate);
	mDate = newDate;

}

std::ostream & operator<<(std::ostream &lhs, ExercisePlan &rhs)
{
	lhs << "Name: " << rhs.getName() << endl;
	lhs << "Goal: " << rhs.getGoal() << endl;
	lhs << "Date: " << rhs.getDate() << endl;
	lhs << '\n' << endl;
	return lhs;
}
