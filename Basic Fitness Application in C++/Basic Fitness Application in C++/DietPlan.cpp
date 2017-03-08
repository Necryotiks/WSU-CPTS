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
	mGoal = abs(newGoal);
	system("pause");
}

void DietPlan::editName()
{
	string newName;
	cout << "Enter an diet plan name: " << endl;
	cin.ignore();
	getline(cin, newName);
	mName = newName;
	system("pause");
}

void DietPlan::editDate()
{
	string newDate;
	cout << "Enter a date for plan completion(mm/dd/yyyy)" << endl;
	cin.ignore();
	getline(cin, newDate);
	mDate = newDate;
	system("pause");
}

std::ostream & operator<<(std::ostream &lhs, DietPlan &rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl;
	lhs << '\n' << endl;
	return lhs;
}
