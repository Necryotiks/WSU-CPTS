#include "DietPlan.h"
#include "ExercisePlan.h"
#include "FitnessAppWrapper.h"
#include "Header.h"
#include "List.h"

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

void ExercisePlan::setGoal(int goal)
{
	mGoal = std::abs(goal);
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
	mGoal = std::abs(newGoal);
}

void ExercisePlan::editName()
{
	string newName;
	cout << "Enter an exercise plan name: " << endl;// need editBullshit();
	std::getline(cin, newName);
	mName = newName;
}

void ExercisePlan::editDate()//maybe remove void?
{
	string newDate;
	cout << "Enter a date for plan completion" << endl;
	std::getline(cin, newDate);
	mDate = newDate;
	
}
