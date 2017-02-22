#include "Header.h"
void run(void)
{
	int runtime = 0;
	int cust1 = 1;
	int cust2 = 1;
	int EtotalTime = 0;
	int NtotalTime = 0;
	unsigned int T_TIME = 0;
	Queue * ExpressLane = NULL;
	Queue * NormalLane = NULL;
	QueueNode * pMem_E = NULL;
	QueueNode * pMem_N = NULL;
	int ExpressArrivalTime = (rand() % 6);
	int NormalArrivalTime = (rand() % 6)+3;
	timeNormalization(&ExpressArrivalTime, &NormalArrivalTime);
	pMem_E = makeNode();
	pMem_E->customerNumber = cust1;
	pMem_E->serviceTime = ExpressArrivalTime;
	EtotalTime = 0;
	pMem_E->totalTime = EtotalTime;
	insertInQueue(&ExpressLane, pMem_E);

	pMem_N = makeNode();
	pMem_N->customerNumber += cust2;
	pMem_N->serviceTime = NormalArrivalTime;
	NtotalTime = 0;
	pMem_N->totalTime = NtotalTime;
	insertInQueue(&NormalLane, pMem_N);

	puts("Enter simulation runtime(in minutes): ");
	fscanf(stdin, "%d", &runtime);
	for (int i = 0; i <= runtime; i++)
	{
		T_TIME++;
		pMem_E = makeNode();
		ExpressArrivalTime = (rand() % 6);
		pMem_E->customerNumber = cust1++;
		pMem_E->serviceTime = ExpressArrivalTime;
		EtotalTime += ExpressArrivalTime;
		pMem_E->totalTime = EtotalTime;
		insertInQueue(&ExpressLane, pMem_E);

		pMem_N = makeNode();
		NormalArrivalTime = (rand() % 6) + 3;
		pMem_N->customerNumber = cust2++;
		pMem_N->serviceTime = NormalArrivalTime;
		NtotalTime += NormalArrivalTime;
		pMem_N->totalTime = NtotalTime;
		insertInQueue(&NormalLane, pMem_N);

		if (T_TIME == ExpressArrivalTime)
		{
			removeFromQueue(&ExpressLane);
		}
		if (T_TIME == NormalArrivalTime)
		{
			removeFromQueue(&NormalLane);
		}

	}

}
Queue * makeNode()
{
	Queue * pMem = malloc(sizeof(Queue));
	pMem->pHead = NULL;
	pMem->pTail = NULL;
	return pMem;
}

void timeNormalization(int *ExpressArrivalTime, int *NormalArrivalTime)
{
	if (*ExpressArrivalTime > 5)
	{
		*ExpressArrivalTime--;
	}
	if (*ExpressArrivalTime < 1)
	{
		*ExpressArrivalTime++;
	}
	if (*NormalArrivalTime > 8)
	{
		*NormalArrivalTime--;
	}
	if (*NormalArrivalTime < 3)
	{
		*NormalArrivalTime++;
	}
}

void removeFromQueue(Queue ** headnode)
{
	Queue * pCur = *headnode;//confirm this
	
	if (pCur->pHead == pCur->pTail)
	{
		pCur->pHead = NULL;
		pCur->pTail = NULL;
	}
	else
	{
		pCur->pHead = pCur->pHead->pNext;
	}
	free(pCur);
}
int isEmpty(Queue * headnode)
{
	int empty = false;
	if (headnode == NULL)
	{
		empty = true;
	}
	return empty;
}
void printQueue(Queue * headnode)
{
	Queue * pCur = headnode;
	printf("customerNumber: %d\n", pCur->pTail->customerNumber);
	printf("serviceTime: %d", pCur->pTail->serviceTime);
	printf("totalTime: %d", pCur->pTail->totalTime);
}
void insertInQueue(Queue ** headnode,QueueNode * PMem)
{//FIX THIS
	Queue * pCur = NULL;
	pCur = *headnode;// * headnode = pRoot

	if (pCur->pHead == NULL)
	{
		pCur->pHead = PMem;
		pCur->pTail = PMem;
		//pCur->pNext->pPrev = pCur;
	}
	else //CHECK THIS
	{
		pCur->pTail->pNext = PMem; 
		pCur->pTail = PMem;
		//check this
	}
}
