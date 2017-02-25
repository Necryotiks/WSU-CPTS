#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#ifndef GROCERY_STORE
#define GROCERY_STORE
#define _CRT_SECURE_NO_WARNINGS 1

/*NAME: ELLIOTT VILLARS
SID: 11463956
ASSSIGNMENT: PA 4
HELP: JOSH CROSS and ANDY O'FALLON CODE
DATE: 2/22/17*/
typedef struct queueNode
{
	int customerNumber; 
	int serviceTime;   
	int totalTime;     

	struct queueNode *pNext;
} QueueNode;
typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;
void run(void);
QueueNode * makeNode();
void timeNormalization(int *etime, int *ltime);
void insertInQueue(Queue * headnode,QueueNode * PMem);
void removeFromQueue(Queue * headnode);
int isEmpty(Queue * headnode);
void printQueue(Queue * headnode);

#endif // !GROCERY_STORE

