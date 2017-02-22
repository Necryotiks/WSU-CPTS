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

typedef struct queueNode
{
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

	struct queueNode *pNext;
} QueueNode;
typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;
void run(void);
Queue * makeNode(void);
void timeNormalization(int *etime, int *ltime);
void insertInQueue(Queue ** headnode,QueueNode * PMem);
void removeFromQueue(Queue ** headnode);
int isEmpty(Queue * headnode);
void printQueue(Queue * headnode);

#endif // !GROCERY_STORE

