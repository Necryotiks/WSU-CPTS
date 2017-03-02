#include "DietPlan.h"
#include "Header.h"

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

bool DietPlan::editGoal()
{
	int newGoal;
	cout << "Set calorie goal: " << endl;
	cin >> newGoal;
	mGoal = std::abs(newGoal);//keep idiots from entering negative value.
	if ((mGoal = newGoal) == newGoal)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DietPlan::editName()
{
	string newName;
	cout << "Enter an exercise plan name: " << endl;
	std::getline(cin, newName);
	mName = newName;
	if ((mDate = newName) == newName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DietPlan::editDate()//maybe remove bool?
{
	string newDate;
	cout << "Enter a date for plan completion" << endl;
	std::getline(cin, newDate);
	mDate = newDate;
	if ((mDate = newDate) == newDate)//change conditon
	{
		return true;
	}
	else
	{
		return false;
	}
}
