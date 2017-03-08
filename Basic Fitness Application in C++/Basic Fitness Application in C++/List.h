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
	static Node * makeNode();
	void insertInEnd(Node * pMem, Node ** headnode);//FIX THIS
	
	friend std::ostream& operator<<(std::ostream lhs, FitnessAppWrapper&rhs);

	void displayDailyDietPlan() const;
	void displayDailyExercisePlan() const;
	void displayWeeklyDietPlan()  const;
	void displayWeeklyExercisePlan() const;
	void storeDailyDietPlan(fstream& Dietfile) const;//needs parameters
	void storeDailyExercisePlan(fstream& Exercisefile) const;//needs parameters
	void storeWeeklyDietPlan(fstream& Dietfile) const ;//needs parameters
	void storeWeeklyExercisePlan(fstream& Exercisefile) const;
	void displayMenu(fstream& Dietfile,fstream& Exercisefile) const; //does this even need parameters
	void editNode(fstream& Dietfile, fstream& Exercisefile) const;

	void AssembleList(fstream& Dietfile, fstream& Exercisefile, List &obj);
	Node * getHead() const;



private:
	Node *headnode;

};
