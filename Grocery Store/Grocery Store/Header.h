#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#ifndef GROCERY_STORE
#define GROCERY_STORE


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
typedef enum expresslanestime
{
	ELANEONE = 1,
	ELANETWO = 2,
	ELANETHREE = 3,
	ELANEFOUR = 4,
	ELANEFiVE = 5
}ExpressTime;
typedef enum normallanestime
{
	NLANETHREE = 3,
	NLANEFOUR = 4,
	NLANEFIVE = 5,
	NLANESIX = 6,
	NLANESEVEN = 7,
	NLANEEIGHT = 8
}NormalTime;
void menu(void);
Queue * makeNode(void);
void insertInQueue(Queue ** headnode,Queue * PMem);
void removeFromeQueue(Queue ** headnode);

#endif // !GROCERY_STORE

