#pragma once
<<<<<<< HEAD
#include "Header.h"

=======
#include "FitnessAppWrapper.h"
typedef struct node
{
	FitnessAppWrapper FObj;
	struct node * pNext = nullptr;
}Node;
>>>>>>> 7c0c1a78917cb87994111e6f727516900940ecc5
class List
{
public:
	List();
	~List();// fix this
	//i think we need a node obj
	Node * makeNode();
	void insertInFront(Node * pMem);
	void deleteNode();//will only delete selected node
	void nukeList();//will finish at fiz
	

	friend std::ostream& operator<<(std::ostream lhs, FitnessAppWrapper&rhs);

	void displayDailyDietPlan();
	void displayDailyExercisePlan();
	void displayWeeklyDietPlan();
	void displayWeeklyExercisePlan();
	void storeDailyDietPlan(fstream& Dietfile);//needs parameters
	void storeDailyExercisePlan(fstream& Exercisefile);//needs parameters
	void storeWeeklyDietPlan(fstream& Dietfile);//needs parameters
	void storeWeeklyExercisePlan(fstream& Exercisefile);
	void displayMenu(); //does this even need parameters
	void editNode();



private:
	Node headnode;

};