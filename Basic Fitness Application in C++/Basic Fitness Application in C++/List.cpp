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
	return new Node;
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
	int input;
	do
	{
		system("cls");
		cout << "Select a day: " << endl;
		cout << "1. Monday" << endl;
		cout << "2. Tuesday" << endl;
		cout << "3. Wednesday" << endl;
		cout << "4. Thursday" << endl;
		cout << "5. Friday" << endl;
		cout << "6. Saturday" << endl;
		cout << "7. Sunday" << endl;
		cout << "8. Exit" << endl;
		cin >> input;
		cin.clear();
		cin.ignore();
		switch (userErrorCorrection(input))
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
		cout << "1. Monday" << endl;
		cout << "2. Tuesday" << endl;
		cout << "3. Wednesday" << endl;
		cout << "4. Thursday" << endl;
		cout << "5. Friday" << endl;
		cout << "6. Saturday" << endl;
		cout << "7. Sunday" << endl;
		cout << "8. Exit" << endl;
		cin >> input;
		cin.clear();
		cin.ignore();
		switch (userErrorCorrection(input))
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
			cout << Color(TEXT_RED, "Improper value entered!") << endl;
			Color();
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
	system("pause");
}

void List::displayWeeklyExercisePlan() const
{
	auto pCur = headnode;
	while (pCur != nullptr)
	{
		cout << pCur->FObj.ExerciseOBJ;
		pCur = pCur->pNext;
	}
	system("pause");
}

void List::storeDailyDietPlan(fstream& Dietfile) const//needs more
{
	auto * pCur = headnode;
	Dietfile.seekg(std::ios::beg);
	int input;//maybe do-while
	do
	{
		system("cls");
		cout << "Select a day: " << endl;
		cout << "1. Monday" << endl;
		cout << "2. Tuesday" << endl;
		cout << "3. Wednesday" << endl;
		cout << "4. Thursday" << endl;
		cout << "5. Friday" << endl;
		cout << "6. Saturday" << endl;
		cout << "7. Sunday" << endl;
		cout << "8. Exit" << endl;
		cin >> input;
		cin.clear();
		cin.ignore();
		switch (userErrorCorrection(input))
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
			system("cls");
			cout << Color(TEXT_RED, "Improper value entered!") << endl;
			Color();
			input = 0;
			break;
		}
	} while (input !=8);
	
}

void List::storeDailyExercisePlan(fstream& Exercisefile) const//needs more 
{
	auto pCur = headnode;
	Exercisefile.seekg(std::ios::beg);
	int input;//maybe do-while
	do
	{
		system("cls");
		cout << "Select a day: " << endl;
		cout << "1. Monday" << endl;
		cout << "2. Tuesday" << endl;
		cout << "3. Wednesday" << endl;
		cout << "4. Thursday" << endl;
		cout << "5. Friday" << endl;
		cout << "6. Saturday" << endl;
		cout << "7. Sunday" << endl;
		cout << "8. Exit" << endl;
		cin >> input;
		cin.clear();
		cin.ignore();
		switch (userErrorCorrection(input))
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
			cout << Color(TEXT_RED,"Improper value entered!") << endl;
			Color();
			input = 0;
			break;
		}
	} while (input != 8);
	
}

void List::storeWeeklyDietPlan(fstream& Dietfile) const
{
	auto * pCur = headnode;
	Dietfile.seekg(std::ios::beg);
	while (pCur->pNext != nullptr)
	{
		Dietfile << pCur->FObj.DietOBJ;
		cout << pCur->FObj.DietOBJ;
		pCur = pCur->pNext;
	}
	system("pause");

}

void List::storeWeeklyExercisePlan(fstream& Exercisefile) const
{
	auto * pCur = headnode;
	Exercisefile.seekg(std::ios::beg);
	while (pCur->pNext != nullptr)
	{
		Exercisefile << pCur->FObj.ExerciseOBJ << endl;
		pCur = pCur->pNext;
	}
}

void List::displayMenu(fstream& Dietfile, fstream& Exercisefile) const
{
	auto inval = 0;
	do
	{
		system("cls");
		cout << "Select an option: " << endl;
		cout << "1. Load weekly diet plan from file" << endl;
		cout << "2. Load weekly exercise plan from file." << endl;
		cout << "3. Store weekly diet plan to file." << endl;
		cout << "4. Store weekly exercise plan to file." << endl;
		cout << "5. Display weekly diet plan to screen." << endl;
		cout << "6. Display weekly exercise plan to screen." << endl;
		cout << "7. NULL" << endl;
		cout << "8. NULL" << endl;
		cout << "9. Edit Node." << endl;
		cout << "10. Exit" << endl;
		cin >> inval;
		switch (userErrorCorrection(inval))
		{
		case 1:
			system("cls");
			cout << Color(TEXT_GREEN,"File preloaded for your convenience.") << endl;
			Color();
			inval = 0;
			system("pause");
			break;
		case 2:
			system("cls");
			cout << Color(TEXT_GREEN, "File preloaded for your convenience.") << endl;
			Color();
			inval = 0;
			system("pause");
			break;
		case 3: storeWeeklyDietPlan(Dietfile);
			break;
		case 4:storeWeeklyExercisePlan(Exercisefile);
			break;
		case 5:displayWeeklyDietPlan();
			break;
		case 6: displayWeeklyExercisePlan();
			break;
		case 7:
			system("cls");
			cout << Color(TEXT_RED, "NULL") << endl;
			Color();
			inval = 0;
			break;
		case 8:
			system("cls");
			cout << Color(TEXT_RED, "NULL") << endl;
			Color();
			inval = 0;
			break;
		case 9:editNode(Dietfile, Exercisefile);
			break;
		case 10: 
			break;
		default:
			system("cls");
			cout << Color(TEXT_RED, "Improper value entered!") << endl;
			Color();
			inval = 0;
			break;
		}
	} while (inval != 10);
	

}

void List::editNode(fstream& Dietfile, fstream& Exercisefile) const
{
	auto * pCur = headnode;
	auto option = 0;//fix data entry
	int input;
	do
	{
		system("cls");
		cout << "Select a day: " << endl;
		cout << "1. Monday" << endl;
		cout << "2. Tuesday" << endl;
		cout << "3. Wednesday" << endl;
		cout << "4. Thursday" << endl;
		cout << "5. Friday" << endl;
		cout << "6. Saturday" << endl;
		cout << "7. Sunday" << endl;
		cout << "8. Exit" << endl;
		cin >> input;
		cin.clear();
		cin.ignore();
		switch (userErrorCorrection(input))
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
			cin.clear();
			cin.ignore();
			option = userErrorCorrection(option);
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
				break;
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					cin.clear();
					cin.ignore();
					option = userErrorCorrection(option);
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
			cin.clear();
			cin.ignore();
			option = userErrorCorrection(option);
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
				break;
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					cin.clear();
					cin.ignore();
					option = userErrorCorrection(option);
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
			cin.clear();
			cin.ignore();
			option = userErrorCorrection(option);
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
				break;
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					cin.clear();
					cin.ignore();
					option = userErrorCorrection(option);
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
			cin.clear();
			cin.ignore();
			option = userErrorCorrection(option);
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
				break;
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					cin.clear();
					cin.ignore();
					option = userErrorCorrection(option);
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
			cin.clear();
			cin.ignore();
			option = userErrorCorrection(option);
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
				break;
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					cin.clear();
					cin.ignore();
					option = userErrorCorrection(option);
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
			cin.clear();
			cin.ignore();
			option = userErrorCorrection(option);
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
				break;
			default:
				do
				{
					cout << "Let's try this again..." << endl;
					cout << "1. Edit Diet Plan." << endl;
					cout << "2. Edit Exercise Plan." << endl;
					cin >> option;
					cin.clear();
					cin.ignore();
					option = userErrorCorrection(option);
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
			cin.clear();
			cin.ignore();
			option = userErrorCorrection(option);
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
					cin.clear();
					cin.ignore();
					option = userErrorCorrection(option);
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
	while (!(Dietfile.eof() && Exercisefile.eof()))
	{
		pMem = obj.makeNode();
		Dietfile >> pMem->FObj.DietOBJ;
		Exercisefile >> pMem->FObj.ExerciseOBJ;
		obj.insertInEnd(pMem, &headnode);
	}
}

Node * List::getHead() const
{
	return headnode;
}

std::ostream & operator<<(std::ostream& lhs, FitnessAppWrapper & rhs)
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
