#include "Header.h"
void run(void)
{
	int runtime = 0;
	int cust1 = 1;
	int cust2 = 1;
	int EtotalTime = 0;
	int NtotalTime = 0;
	unsigned int T_TIME = 0;
	Queue  ExpressLane;
	ExpressLane.pHead = ExpressLane.pTail = NULL;
	Queue  NormalLane;
	NormalLane.pHead = NormalLane.pTail = NULL;
	QueueNode * pMem_E = NULL;
	QueueNode * pMem_N = NULL;
	int ExpressArrivalTime = (rand() % 5) + 1;
	int NormalArrivalTime = (rand() % 6) + 3;
	//timeNormalization(&ExpressArrivalTime, &NormalArrivalTime);
	pMem_E = makeNode();
	pMem_E->customerNumber = cust1;
	pMem_E->serviceTime = ExpressArrivalTime;
	EtotalTime = 0;
	pMem_E->totalTime = EtotalTime;
	insertInQueue(&ExpressLane, pMem_E);

	pMem_N = makeNode();
	pMem_N->customerNumber = cust2;
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
		printf("RUNTIME: %d\n", T_TIME);

		printf("Lane: Express\n");
		printQueue(&ExpressLane);
		removeFromQueue(&ExpressLane);
		printf("\n");


		printf("Lane: Normal\n");
		printQueue(&NormalLane);
		removeFromQueue(&NormalLane);
		printf("\n");


	}
	system("pause");

}
QueueNode * makeNode()
{
	QueueNode * pMem = malloc(sizeof(QueueNode));
	pMem->totalTime = 0;
	pMem->serviceTime = 0;
	pMem->customerNumber = 0;
	pMem->pNext = NULL;
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

void removeFromQueue(Queue * headnode)
{
	QueueNode * pCur = headnode->pHead;//confirm this

	if (!isEmpty(headnode))
	{
		if (headnode->pHead == headnode->pTail)
		{
			headnode->pHead = NULL;
			headnode->pTail = NULL;
		}
		else
		{
			headnode->pHead = pCur->pNext;
		}
		free(pCur);
	}
}
int isEmpty(Queue * headnode)
{
	int empty = false;
	if (headnode->pHead == NULL)
	{
		empty = true;
	}
	return empty;
}
void printQueue(Queue * headnode)
{
	Queue * pCur = headnode;
	printf("customerNumber: %d\n", pCur->pTail->customerNumber);
	printf("serviceTime: %d\n", pCur->pTail->serviceTime);
	printf("totalTime: %d\n", pCur->pTail->totalTime);
}
void insertInQueue(Queue * headnode, QueueNode * PMem)
{//FIX THIS
	// * headnode = pRoot

	if (isEmpty((headnode)))
	{
		(headnode)->pHead = PMem;
		(headnode)->pTail = PMem;
		//pCur->pNext->pPrev = pCur;
	}
	else //CHECK THIS
	{
		(headnode)->pTail->pNext = PMem;
		(headnode)->pTail = PMem;
		//check this
	}
}
