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
	auto newGoal=0;
	cout << "Set calorie goal: " << endl;
	cin >> newGoal;
	newGoal = userErrorCorrection(newGoal);
	mGoal = abs(newGoal);
	system("pause");
}

void ExercisePlan::editName()
{
	string newName;
	cout << "Enter an exercise plan name: " << endl;// need editBullshit();
	cin.ignore();
	getline(cin, newName);
	mName = newName;
	system("pause");
}

void ExercisePlan::editDate()//maybe remove void?
{
	string newDate;
	cout << "Enter a date for plan completion(mm/dd/yyyy)" << endl;
	cin.ignore();
	getline(cin, newDate);
	mDate = newDate;
	system("pause");

}

std::ostream & operator<<(std::ostream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl;
	lhs << '\n' << endl;
	return lhs;
}
