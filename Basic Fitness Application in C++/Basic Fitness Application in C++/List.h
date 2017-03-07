#pragma once
#include "Header.h"
#include "FitnessAppWrapper.h"
typedef struct node
{
	FitnessAppWrapper FObj;
	struct node * pNext = nullptr;
}Node;
class List
{
public:
	List();
	~List();// fix this
	//i think we need a node obj
	Node * makeNode();
	void insertInFront(Node * pMem);
	
	friend std::ostream& operator<<(std::ostream lhs, FitnessAppWrapper&rhs);

	void displayDailyDietPlan();
	void displayDailyExercisePlan();
	void displayWeeklyDietPlan();
	void displayWeeklyExercisePlan();
	void storeDailyDietPlan(fstream& Dietfile);//needs parameters
	void storeDailyExercisePlan(fstream& Exercisefile);//needs parameters
	void storeWeeklyDietPlan(fstream& Dietfile);//needs parameters
	void storeWeeklyExercisePlan(fstream& Exercisefile);
	void displayMenu(fstream& Dietfile,fstream& Exercisefile); //does this even need parameters
	void editNode(fstream& Dietfile, fstream& Exercisefile);



private:
	Node headnode;

};
