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
	auto newGoal = 0;
	cout << "Set calorie goal: " << endl;
	cin >> newGoal;
	newGoal = userErrorCorrection(newGoal);
	mGoal = abs(newGoal);
	system("pause");
}

void DietPlan::editName()
{
	string newName;
	cout << "Enter an diet plan name: " << endl;
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

std::ostream & operator << (std::ostream &lhs, DietPlan &rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl;
	lhs << '\n' << endl;
	return lhs;
}

std::istream & operator >> (std::istream & lhs, DietPlan & rhs)
{
	string Dname;
	int Dgoal;
	string Ddate;
	lhs >> Dname;
	lhs >> Dgoal;
	lhs >> Ddate;
	rhs.setName(Dname);
	rhs.setGoal(Dgoal);
	rhs.setDate(Ddate);
	return lhs;
}
