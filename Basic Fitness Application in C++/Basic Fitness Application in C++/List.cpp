#include "DietPlan.h"
#include "ExercisePlan.h"
#include "FitnessAppWrapper.h"
#include "Header.h"
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
Node List::getNode()
{
	return headnode;//WILL FUCK WITH LATER
}
//call instructions
//List obj;
//List::Node * pMem =obj.makenode()
//obj.insertinfront(pMem);