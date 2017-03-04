#include "Header.h"
#include "List.h"
#include "FitnessAppWrapper.h"
#include "DietPlan.h"
#include "ExercisePlan.h"

void runapp()
{
	std::fstream Dietfile;
	Dietfile.open("Diet_File.txt", std::ios::in | std::ios::out);

	std::fstream Exercisefile;
	Exercisefile.open("Exercise_File.txt", std::ios::in | std::ios::out);

	List obj;
	Node * pMem = nullptr;
	//loop here
	pMem = obj.makeNode();
	string Dname;
	string Ename;
	int Dgoal;
	int Egoal;
	string Ddate;
	string Edate;
	string voidspace;
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
	obj.insertInFront(pMem);
}
