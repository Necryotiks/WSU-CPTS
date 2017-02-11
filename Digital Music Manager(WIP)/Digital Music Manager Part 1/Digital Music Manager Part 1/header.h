#pragma once
#ifndef DMM
#define DMM 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct duration
{
	int seconds;
	int minutes;
}Duration;
typedef enum rating
{
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5
}Rating;
typedef struct records
{
	char  artist[20];
	char  albumTitle[20];
	char  songTitle[20];
	char  genre[20];
	Duration songLength;
	int numberOfPlays;
	Rating songRating;
}Records;
typedef struct listnode
{
	Records data;
	struct listnode * pNext;
	struct listnode * pPrev;
}ListNode;

FILE * openFileRead(void);
void menu(void);
ListNode * makeNode(void);
void loadFunction(ListNode **headNode);
void InsertInFront(ListNode *PMem, ListNode ** headnode);
void deleteFunction(ListNode **headnode);
void printList(ListNode ** headnode);




#endif // !DMM

