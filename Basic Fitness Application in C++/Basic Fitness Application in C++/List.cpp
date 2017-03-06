#include "DietPlan.h"
#include "List.h"


List::List()
{
	Node headnode;
}
List::~List()
{
	// I WILL FUCK WITH THIS LATER;
}

Node * List::makeNode()
{
	return new Node;//IS THIS A THING
}

void List::insertInFront(Node * pMem)
{
	auto * pCur = &headnode;
	while (pCur != nullptr)
	{
		pCur = pCur->pNext;
	}
	pCur = pMem;

}
void List::displayDailyDietPlan()
{
	auto * pCur = &headnode;
	int input;//maybe do-while
	do
	{
		system("cls");
		cout << "Select a day: " << endl;
		cout << "1. Sunday" << endl;
		cout << "2. Monday" << endl;
		cout << "3. Tuesday" << endl;
		cout << "4. Wednesday" << endl;
		cout << "5. Thursday" << endl;
		cout << "6. Friday" << endl;
		cout << "7. Saturday" << endl;
		cin >> input;
	} while (input < 1 || input > 8);
	switch (input)
	{
	case 1:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.DietOBJ;
		break;
	case 2:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.DietOBJ;
		break;
	case 3:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.DietOBJ;
		break;
	case 4:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.DietOBJ;
		break;
	case 5:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.DietOBJ;
		break;
	case 6:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.DietOBJ;
		break;
	case 7:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.DietOBJ;
		break;
	default:
		cout << "This will never be accessed, EVER!" << endl;
		break;
	}
}

void List::displayDailyExercisePlan()
{
	auto * pCur = &headnode;
	int input;
	do
	{
		system("cls");
		cout << "Select a day: " << endl;
		cout << "1. Sunday" << endl;
		cout << "2. Monday" << endl;
		cout << "3. Tuesday" << endl;
		cout << "4. Wednesday" << endl;
		cout << "5. Thursday" << endl;
		cout << "6. Friday" << endl;
		cout << "7. Saturday" << endl;
		cin >> input;
	} while (input < 1 || input > 8);
	switch (input)
	{
	case 1:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.ExerciseOBJ;
		break;
	case 2:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.ExerciseOBJ;
		break;
	case 3:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.ExerciseOBJ;
		break;
	case 4:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.ExerciseOBJ;
		break;
	case 5:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.ExerciseOBJ;
		break;
	case 6:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.ExerciseOBJ;
		break;
	case 7:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		cout << pCur->FObj.ExerciseOBJ;
		break;
	default:
		cout << "This will never be accessed, EVER!" << endl;
		break;
	}
}

void List::displayWeeklyDietPlan()
{
	auto * pCur = &headnode;
	while(pCur != nullptr)
	{
		cout << pCur->FObj.DietOBJ;
		pCur = pCur->pNext;
	}
}

void List::displayWeeklyExercisePlan()
{
	auto * pCur = &headnode;
	while (pCur != nullptr)
	{
		cout << pCur->FObj.ExerciseOBJ;
		pCur = pCur->pNext;
	}
}

void List::storeDailyDietPlan(fstream& Dietfile)//needs more
{
	auto * pCur = &headnode;
	int input;//maybe do-while
	do
	{
		system("cls");
		cout << "Select a day: " << endl;
		cout << "1. Sunday" << endl;
		cout << "2. Monday" << endl;
		cout << "3. Tuesday" << endl;
		cout << "4. Wednesday" << endl;
		cout << "5. Thursday" << endl;
		cout << "6. Friday" << endl;
		cout << "7. Saturday" << endl;
		cin >> input;
	} while (input < 1 || input > 8);
	switch (input)
	{
	case 1:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Dietfile << pCur->FObj.DietOBJ;
		break;
	case 2:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Dietfile << pCur->FObj.DietOBJ;
		break;
	case 3:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Dietfile << pCur->FObj.DietOBJ;
		break;
	case 4:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Dietfile << pCur->FObj.DietOBJ;
		break;
	case 5:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Dietfile << pCur->FObj.DietOBJ;
		break;
	case 6:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Dietfile << pCur->FObj.DietOBJ;
		break;
	case 7:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Dietfile << pCur->FObj.DietOBJ;
		break;
	default:
		cout << "This will never be accessed, EVER!" << endl;
		break;
	}
}

void List::storeDailyExercisePlan(fstream& Exercisefile)//needs more 
{
	auto * pCur = &headnode;
	int input;//maybe do-while
	do
	{
		system("cls");
		cout << "Select a day: " << endl;
		cout << "1. Sunday" << endl;
		cout << "2. Monday" << endl;
		cout << "3. Tuesday" << endl;
		cout << "4. Wednesday" << endl;
		cout << "5. Thursday" << endl;
		cout << "6. Friday" << endl;
		cout << "7. Saturday" << endl;
		cin >> input;
	} while (input < 1 || input > 8);
	switch (input)
	{
	case 1:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Exercisefile << pCur->FObj.ExerciseOBJ;
		break;
	case 2:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Exercisefile << pCur->FObj.ExerciseOBJ;
		break;
	case 3:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Exercisefile << pCur->FObj.ExerciseOBJ;
		break;
	case 4:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Exercisefile << pCur->FObj.ExerciseOBJ;
		break;
	case 5:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Exercisefile << pCur->FObj.ExerciseOBJ;
		break;
	case 6:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Exercisefile << pCur->FObj.ExerciseOBJ;
		break;
	case 7:
		for (auto i = 1; i < input; i++)
		{
			pCur = pCur->pNext;
		}
		Exercisefile << pCur->FObj.ExerciseOBJ;
		break;
	default:
		cout << "This will never be accessed, EVER!" << endl;
		break;
	}
}

void List::storeWeeklyDietPlan(fstream& Dietfile)
{
	auto * pCur = &headnode;
	while (pCur != nullptr)
	{
		Dietfile << pCur->FObj.DietOBJ;
		pCur = pCur->pNext;
	}

}

void List::storeWeeklyExercisePlan(fstream& Exercisefile)
{
	auto * pCur = &headnode;
	while (pCur != nullptr)
	{
		Exercisefile << pCur->FObj.ExerciseOBJ;
		pCur = pCur->pNext;
	}
}

void List::displayMenu()
{
	int inval;

}

void List::editNode()
{
}

std::ostream & operator<<(std::ostream lhs, FitnessAppWrapper & rhs)
{
	lhs << "Diet Plan Name: " << rhs.DietOBJ.getName() << endl;
	lhs << "Diet Plan Goal: " << rhs.DietOBJ.getGoal() << endl;
	lhs << "Diet Plan Date: " << rhs.DietOBJ.getDate() << endl;
	lhs << '\n' << endl;
	lhs << "Exercise Plan Name: " << rhs.ExerciseOBJ.getName() << endl;
	lhs << "Exercise Plan Goal: " << rhs.ExerciseOBJ.getGoal() << endl;
	lhs << "Exercise Plan Date: " << rhs.ExerciseOBJ.getDate() << endl;
	return lhs;
}
