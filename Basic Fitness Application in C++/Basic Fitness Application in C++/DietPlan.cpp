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
	cout << "DietPlan Object deconstructed...or something." << endl;
}



int DietPlan::getGoal() const
{
	return mGoal;
}

string DietPlan::getName() const
{
	return mName;
}

string DietPlan::getDate() const
{
	return mDate;
}

void DietPlan::setGoal(int goal)
{
	mGoal = abs(goal);
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
	mGoal = abs(newGoal);//keep idiots from entering negative value.
}

void DietPlan::editName()
{
	string newName;
	cout << "Enter an exercise plan name: " << endl;
	getline(cin, newName);
	mName = newName;
}

void DietPlan::editDate()
{
	string newDate;
	cout << "Enter a date for plan completion" << endl;
	getline(cin, newDate);
	mDate = newDate;
}

std::ostream & operator<<(std::ostream &lhs, DietPlan &rhs)
{
	lhs << "Name: " << rhs.getName() << endl;
	lhs << "Goal: " << rhs.getGoal() << endl;
	lhs << "Date" << rhs.getDate() << endl;
	lhs << '\n' << endl;
	return lhs;
}
