#include "DietPlan.h"
#include "Header.h"
#include "List.h"


List::List()
{
	headnode = nullptr;
}
List::~List()
{
	//needs deconstructors 
}

Node * List::makeNode()
{
	return new Node;//IS THIS A THING
}

void List::insertInEnd(Node * pMem, Node ** headnode)
{
	auto pCur = *headnode;
	if(*headnode == nullptr)
	{
		*headnode = pMem;
	}
	else
	{
		while (pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;//FIX THIS
		}
		pCur->pNext = pMem;
		
	}
}
void List::displayDailyDietPlan() const
{
	auto pCur = headnode;
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
		cout << "8. Exit" << endl;
		cin >> input;
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
		case 8:
			break;
		default:
			cout << "This will never be accessed, EVER!" << endl;
			break;
		}
	} while (input !=8);
	
}

void List::displayDailyExercisePlan() const
{
	auto *pCur = headnode;
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
		cout << "8. Exit" << endl;
		cin >> input;
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
		case 8:break;
		default:
			cout << "Improper value entered!" << endl;
			input = 0;
			break;
		}
	} while (input != 8);
	
}

void List::displayWeeklyDietPlan() const// FIx THIS
{
	auto pCur = headnode;
	while (pCur != nullptr)
	{
		cout << pCur->FObj.DietOBJ;
		pCur = pCur->pNext;
	}
}

void List::displayWeeklyExercisePlan() const
{
	auto pCur = headnode;
	while (pCur != nullptr)
	{
		cout << pCur->FObj.ExerciseOBJ;
		pCur = pCur->pNext;
	}
}

void List::storeDailyDietPlan(fstream& Dietfile) const//needs more
{
	auto * pCur = headnode;
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
		cout << "8. Exit" << endl;
		cin >> input;
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
		case 8:
			break;
		default:
			cout << "Improper value entered!" << endl;
			input = 0;
			break;
		}
	} while (input !=8);
	
}

void List::storeDailyExercisePlan(fstream& Exercisefile) const//needs more 
{
	auto * pCur = headnode;
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
		cout << "8. Exit" << endl;
		cin >> input;
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
		case 8:break;
		default:
			cout << "Improper value entered!" << endl;
			input = 0;
			break;
		}
	} while (input != 8);
	
}

void List::storeWeeklyDietPlan(fstream& Dietfile) const
{
	auto  * pCur = headnode;
	while (pCur != nullptr)
	{
		Dietfile << pCur->FObj.DietOBJ;
		pCur = pCur->pNext;
	}

}

void List::storeWeeklyExercisePlan(fstream& Exercisefile) const
{
	auto  *pCur = headnode;
	while (pCur != nullptr)
	{
		Exercisefile << pCur->FObj.ExerciseOBJ;
		pCur = pCur->pNext;
	}
}

void List::displayMenu(fstream& Dietfile, fstream& Exercisefile) const
{
	auto inval = 0;
	do
	{
		cout << "Select an option: " << endl;
		cout << "1. NULL" << endl;
		cout << "2. NULL" << endl;
		cout << "3. Store weekly diet plan to file." << endl;
		cout << "4. Store weekly exercise plan to file." << endl;
		cout << "5. Display weekly diet plan to screen." << endl;
		cout << "6. Display weekly exercise plan to screen." << endl;
		cout << "7. Edit daily plans." << endl;
		cout << "8. NULL" << endl;
		cout << "9. Edit Node." << endl;
		cout << "10. Exit" << endl;
		cin >> inval;
		switch (inval)
		{
		case 1:
			cout << "NO" << endl;
			inval = 0;
			break;
		case 2:
			cout << "NO" << endl;
			inval = 0;
			break;
		case 3: storeWeeklyDietPlan(Dietfile);
			break;
		case 4:storeWeeklyExercisePlan(Exercisefile);
			break;
		case 5:displayWeeklyDietPlan();
			break;
		case 6: displayWeeklyExercisePlan();
			break;
		case 7:editNode(Dietfile, Exercisefile);//UNFINSIHED
			break;
		case 8:
			cout << "NO" << endl;
			inval = 0;
			break;
		case 9:editNode(Dietfile, Exercisefile);
			break;
		case 10: 
			break;
		default:
			cout << "Improper value entered!" << endl;
			inval = 0;
			break;
		}
	} while (inval != 10);
	

}

void List::editNode(fstream& Dietfile, fstream& Exercisefile) const
{
	auto * pCur = headnode;
	auto option = 0;
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
		cout << "8. Exit" << endl;
		cin >> input;
		switch (input)
		{
		case 1:

			for (auto i = 1; i < input; i++)
			{
				pCur = pCur->pNext;
			}
			system("cls");
			cout << "Edit Diet or Exercise plans:" << endl;
			cout << "1. Edit Diet Plan." << endl;
			cout << "2. Edit Exercise Plan." << endl;
			cin >> option;
			option = abs(option);
			switch (option)
			{
			case 1:
				pCur->FObj.DietOBJ.editName();
				pCur->FObj.DietOBJ.editGoal();
				pCur->FObj.DietOBJ.editDate();
				break;
			case 2:
				pCur->FObj.ExerciseOBJ.editName();
				pCur->FObj.ExerciseOBJ.editGoal();
				pCur->FObj.ExerciseOBJ.editDate();
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					system("cls");
				} while (option < 1 || option > 2);
				if (option == 1)
				{
					pCur->FObj.DietOBJ.editName();
					pCur->FObj.DietOBJ.editGoal();
					pCur->FObj.DietOBJ.editDate();
				}
				else
				{
					pCur->FObj.ExerciseOBJ.editName();
					pCur->FObj.ExerciseOBJ.editGoal();
					pCur->FObj.ExerciseOBJ.editDate();
				}
			}

			break;
		case 2:
			for (auto i = 1; i < input; i++)
			{
				pCur = pCur->pNext;
			}
			system("cls");
			cout << "Edit Diet or Exercise plans:" << endl;
			cout << "1. Edit Diet Plan." << endl;
			cout << "2. Edit Exercise Plan." << endl;
			cin >> option;
			option = abs(option);
			switch (option)
			{
			case 1:
				pCur->FObj.DietOBJ.editName();
				pCur->FObj.DietOBJ.editGoal();
				pCur->FObj.DietOBJ.editDate();
				break;
			case 2:
				pCur->FObj.ExerciseOBJ.editName();
				pCur->FObj.ExerciseOBJ.editGoal();
				pCur->FObj.ExerciseOBJ.editDate();
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					system("cls");
				} while (option < 1 || option > 2);
				if (option == 1)
				{
					pCur->FObj.DietOBJ.editName();
					pCur->FObj.DietOBJ.editGoal();
					pCur->FObj.DietOBJ.editDate();
				}
				else
				{
					pCur->FObj.ExerciseOBJ.editName();
					pCur->FObj.ExerciseOBJ.editGoal();
					pCur->FObj.ExerciseOBJ.editDate();
				}
			}

			break;
		case 3:
			for (auto i = 1; i < input; i++)
			{
				pCur = pCur->pNext;
			}
			system("cls");
			cout << "Edit Diet or Exercise plans:" << endl;
			cout << "1. Edit Diet Plan." << endl;
			cout << "2. Edit Exercise Plan." << endl;
			cin >> option;
			option = abs(option);
			switch (option)
			{
			case 1:
				pCur->FObj.DietOBJ.editName();
				pCur->FObj.DietOBJ.editGoal();
				pCur->FObj.DietOBJ.editDate();
				break;
			case 2:
				pCur->FObj.ExerciseOBJ.editName();
				pCur->FObj.ExerciseOBJ.editGoal();
				pCur->FObj.ExerciseOBJ.editDate();
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					system("cls");
				} while (option < 1 || option > 2);
				if (option == 1)
				{
					pCur->FObj.DietOBJ.editName();
					pCur->FObj.DietOBJ.editGoal();
					pCur->FObj.DietOBJ.editDate();
				}
				else
				{
					pCur->FObj.ExerciseOBJ.editName();
					pCur->FObj.ExerciseOBJ.editGoal();
					pCur->FObj.ExerciseOBJ.editDate();
				}
			}

			break;
		case 4:
			for (auto i = 1; i < input; i++)
			{
				pCur = pCur->pNext;
			}
			system("cls");
			cout << "Edit Diet or Exercise plans:" << endl;
			cout << "1. Edit Diet Plan." << endl;
			cout << "2. Edit Exercise Plan." << endl;
			cin >> option;
			option = abs(option);
			switch (option)
			{
			case 1:
				pCur->FObj.DietOBJ.editName();
				pCur->FObj.DietOBJ.editGoal();
				pCur->FObj.DietOBJ.editDate();
				break;
			case 2:
				pCur->FObj.ExerciseOBJ.editName();
				pCur->FObj.ExerciseOBJ.editGoal();
				pCur->FObj.ExerciseOBJ.editDate();
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					system("cls");
				} while (option < 1 || option > 2);
				if (option == 1)
				{
					pCur->FObj.DietOBJ.editName();
					pCur->FObj.DietOBJ.editGoal();
					pCur->FObj.DietOBJ.editDate();
				}
				else
				{
					pCur->FObj.ExerciseOBJ.editName();
					pCur->FObj.ExerciseOBJ.editGoal();
					pCur->FObj.ExerciseOBJ.editDate();
				}
			}

			break;
		case 5:
			for (auto i = 1; i < input; i++)
			{
				pCur = pCur->pNext;
			}
			system("cls");
			cout << "Edit Diet or Exercise plans:" << endl;
			cout << "1. Edit Diet Plan." << endl;
			cout << "2. Edit Exercise Plan." << endl;
			cin >> option;
			option = abs(option);
			switch (option)
			{
			case 1:
				pCur->FObj.DietOBJ.editName();
				pCur->FObj.DietOBJ.editGoal();
				pCur->FObj.DietOBJ.editDate();
				break;
			case 2:
				pCur->FObj.ExerciseOBJ.editName();
				pCur->FObj.ExerciseOBJ.editGoal();
				pCur->FObj.ExerciseOBJ.editDate();
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					system("cls");
				} while (option < 1 || option > 2);
				if (option == 1)
				{
					pCur->FObj.DietOBJ.editName();
					pCur->FObj.DietOBJ.editGoal();
					pCur->FObj.DietOBJ.editDate();
				}
				else
				{
					pCur->FObj.ExerciseOBJ.editName();
					pCur->FObj.ExerciseOBJ.editGoal();
					pCur->FObj.ExerciseOBJ.editDate();
				}
			}

			break;
		case 6:
			for (auto i = 1; i < input; i++)
			{
				pCur = pCur->pNext;
			}
			system("cls");
			cout << "Edit Diet or Exercise plans:" << endl;
			cout << "1. Edit Diet Plan." << endl;
			cout << "2. Edit Exercise Plan." << endl;
			cin >> option;
			option = abs(option);
			switch (option)
			{
			case 1:
				pCur->FObj.DietOBJ.editName();
				pCur->FObj.DietOBJ.editGoal();
				pCur->FObj.DietOBJ.editDate();
				break;
			case 2:
				pCur->FObj.ExerciseOBJ.editName();
				pCur->FObj.ExerciseOBJ.editGoal();
				pCur->FObj.ExerciseOBJ.editDate();
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					system("cls");
				} while (option < 1 || option > 2);
				if (option == 1)
				{
					pCur->FObj.DietOBJ.editName();
					pCur->FObj.DietOBJ.editGoal();
					pCur->FObj.DietOBJ.editDate();
				}
				else
				{
					pCur->FObj.ExerciseOBJ.editName();
					pCur->FObj.ExerciseOBJ.editGoal();
					pCur->FObj.ExerciseOBJ.editDate();
				}
			}

			break;
		case 7:
			for (auto i = 1; i < input; i++)
			{
				pCur = pCur->pNext;
			}
			system("cls");
			cout << "Edit Diet or Exercise plans:" << endl;
			cout << "1. Edit Diet Plan." << endl;
			cout << "2. Edit Exercise Plan." << endl;
			cin >> option;
			option = abs(option);
			switch (option)
			{
			case 1:
				pCur->FObj.DietOBJ.editName();
				pCur->FObj.DietOBJ.editGoal();
				pCur->FObj.DietOBJ.editDate();
				break;
			case 2:
				pCur->FObj.ExerciseOBJ.editName();
				pCur->FObj.ExerciseOBJ.editGoal();
				pCur->FObj.ExerciseOBJ.editDate();
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					system("cls");
				} while (option < 1 || option > 2);
				if (option == 1)
				{
					pCur->FObj.DietOBJ.editName();
					pCur->FObj.DietOBJ.editGoal();
					pCur->FObj.DietOBJ.editDate();
				}
				else
				{
					pCur->FObj.ExerciseOBJ.editName();
					pCur->FObj.ExerciseOBJ.editGoal();
					pCur->FObj.ExerciseOBJ.editDate();
				}
			}

			break;
		case 8: 
			break;
		default:
			cout << "This will never be accessed, EVER!" << endl;
			break;
		}
	} while (input != 8);
	
}

void List::AssembleList(fstream & Dietfile, fstream & Exercisefile, List & obj)
{
	Node * pMem = nullptr;
	string Dname;
	string Ename;
	int Dgoal;
	int Egoal;
	string Ddate;
	string Edate;
	string voidspace;
	while (!(Dietfile.eof() && Exercisefile.eof()))
	{
		pMem = obj.makeNode();
		Dietfile >> Dname;
		Dietfile >> Dgoal;
		Dietfile >> Ddate;
		Dietfile >> voidspace;
		Exercisefile >> Ename;
		Exercisefile >> Egoal;
		Exercisefile >> Edate;
		Exercisefile >> voidspace;
		pMem->FObj.DietOBJ.setName(Dname);
		pMem->FObj.DietOBJ.setGoal(Dgoal);
		pMem->FObj.DietOBJ.setDate(Ddate);
		pMem->FObj.ExerciseOBJ.setName(Ename);
		pMem->FObj.ExerciseOBJ.setGoal(Egoal);
		pMem->FObj.ExerciseOBJ.setDate(Edate);
		obj.insertInEnd(pMem, &headnode);
	}
}

Node * List::getHead() const
{
	return headnode;
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
