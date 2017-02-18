#include "Header.h"
void menu(void)
{

}
Queue * makeNode()
{
	Queue * pMem = malloc(sizeof(Queue));
	return pMem;
}

void insertInQueue(Queue ** headnode,Queue * PMem)
{
	Queue * pCur = NULL;
	pCur = *headnode;// * headnode = pRoot

	if (pCur == NULL)
	{
		pCur->pHead = PMem;
		pCur->pTail = pCur->pHead;
		//pCur->pNext->pPrev = pCur;
	}
	else if (pCur != NULL)
	{
		while (pCur->pHead->pNext != NULL)
		{
			pCur->pHead = pCur->pHead->pNext;
		}
		pCur->pHead->pNext = PMem; 
		pCur->pTail = pCur->pHead->pNext;
		pCur = PMem;
	}
}
