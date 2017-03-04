#include "DietPlan.h"
#include "ExercisePlan.h"
#include "FitnessAppWrapper.h"
#include "Header.h"
#include "List.h"

DietPlan::DietPlan()
{
	mGoal = 0;
	mName = '\0';
	mDate = '\0';
	
}

DietPlan::DietPlan(DietPlan &newPlan)
{
	mGoal = newPlan.getGoal();
	mName = newPlan.getName();
	mDate = newPlan.getDate();
}

DietPlan::~DietPlan()
{
	cout << "DietPlan Object deconstructed...or something." << endl;
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

void DietPlan::setGoal(int goal)
{
	mGoal = std::abs(goal);
}

void DietPlan::setName(string name)
{
	mName = name;
}

void DietPlan::setDate(string date)
{
	mDate = date;
}

void DietPlan::editGoal()
{
	int newGoal;
	cout << "Set calorie goal: " << endl;
	cin >> newGoal;
	mGoal = std::abs(newGoal);//keep idiots from entering negative value.
}

void DietPlan::editName()
{
	string newName;
	cout << "Enter an exercise plan name: " << endl;
	std::getline(cin, newName);
	mName = newName;
}

void DietPlan::editDate()
{
	string newDate;
	cout << "Enter a date for plan completion" << endl;
	std::getline(cin, newDate);
	mDate = newDate;
}
