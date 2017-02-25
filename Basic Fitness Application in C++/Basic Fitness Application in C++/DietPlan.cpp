#include "DietPlan.h"
#include "Header.h"

DietPlan::DietPlan(int goal, string name, string date)
{
	mGoal = goal;
	mName = name;
	mDate = date;
}

DietPlan::DietPlan(DietPlan &copy)
{
	//fix copy
}

DietPlan::~DietPlan()
{
	cout << "DietPlan Object deconstructed...or something." << std::endl;
}

int DietPlan::getGoal()
{
	return mGoal;
}

string DietPlan::getName()
{
	return mName;
}

string DietPlan::getDate()
{
	return mDate;
}

void DietPlan::setGoal()
{
	int newGoal;
	cout << "Set calorie goal: " << endl;
	cin >> newGoal;
	mGoal = newGoal;
}

void DietPlan::setName()
{
	string newName;
	cout << "Enter a diet plan name: " << endl;
	std::getline(cin, newName);
	mName = newName;
}

void DietPlan::setDate()
{
	string newDate;
	cout << "Enter a date for plan completion" << endl;
	std::getline(cin, newDate);
	mDate = newDate;
}
