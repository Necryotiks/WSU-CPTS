#pragma once
#pragma once
#ifndef DMM
#define DMM 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#include <time.h>

//NAME: ELLIOTT VILLARS
//SID: 11463956
//CPTS 122
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
	char  artist[30];
	char  albumTitle[30];
	char  songTitle[30];
	char  genre[30];
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
FILE * openFileForOverWrite(void);
void menu(void);
ListNode * makeNode(void);
void loadFunction(ListNode **headNode, int loadCheck);
void InsertInFront(ListNode *PMem, ListNode ** headnode);
void printList(ListNode * headnode, int loadCheck);
void storeFunction(ListNode *headnode, int loadCheck);
void editFunction(ListNode *headnode, int loadCheck);
void rateFunction(ListNode *headnode, int loadCheck); //deprecated done with edit function
void playFunction(ListNode *headnode, int loadCheck);
void insertFunction(ListNode ** headnode);
void deleteFunction(ListNode ** headnode, int loadCheck);//BROKEN
void sortFunction(ListNode ** headnode, int loadCheck);//ALSO BROKEN
void shuffleFunction(ListNode * headnode, int loadCheck);//SEE ABOVE
void sortfunctionAZ(ListNode * headnode,ListNode * pNEXT);

														 //need debug




#endif // !DMM
