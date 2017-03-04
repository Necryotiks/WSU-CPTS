#pragma once
#include "DietPlan.h"
#include "FitnessAppWrapper.h"
#include "Header.h"

class List
{
public:
	List();
	~List();// fix this
	
	Node * makeNode();
	void insertInFront(Node * pMem);
	void deleteNode();//will finish at fiz
	void sortNode();
	Node getNode();


private:
	Node headnode;

};
