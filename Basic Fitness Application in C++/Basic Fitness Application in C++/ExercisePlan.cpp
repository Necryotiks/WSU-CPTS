#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(int goal, string name, string date)
{
	mGoal = goal;
	mName = name;
	mDate = date;
}

ExercisePlan::ExercisePlan(ExercisePlan & copy)
{
	//fix copy
}

ExercisePlan::~ExercisePlan()
{
	cout << "ExercisePlan Object deconstructed...or something." << std::endl;
}

int ExercisePlan::getGoal()
{
	return mGoal;
}

string ExercisePlan::getName()
{
	return mName;
}

string ExercisePlan::getDate()
{
	return mDate;
}

void ExercisePlan::setGoal()
{
	int newGoal;
	cout << "Set calorie goal: " << endl;
	cin >> newGoal;
	mGoal = newGoal;;
}

void ExercisePlan::setName()
{
	string newName;
	cout << "Enter an exercise plan name: " << endl;
	std::getline(cin, newName);
	mName = newName;
}

void ExercisePlan::setDate()
{
	string newDate;
	cout << "Enter a date for plan completion" << endl;
	std::getline(cin, newDate);
	mDate = newDate;
}
