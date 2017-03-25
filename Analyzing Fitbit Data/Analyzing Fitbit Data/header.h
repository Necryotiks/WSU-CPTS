//* Programmer: Elliott Villars
//* Class : CptS 122; Lab Section
//* Programming Assignment : Programming Project [1]
//*
//* Date : 1/23/17
//	*
//	* Description : CSV Processing
//	*
//	* Relevant Formulas : N/A
#ifndef FITBIT
#define FITBIT
#define MINUTES_PER_DAY 1440
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;//definition

FILE * FitBitOpen(void);
FILE * resultsOpen(void);
void runParsingProgram(void);
void parseLine(FILE * infile, FitbitData storageArray[], int currentLine);
void SumTotalData(FILE* infile, FitbitData storageArray[], int currentLine, double * totalCalories, double * distanceTraveled, int*floorsWalked, int * totalHeartrate, int* stepsTaken);
double AverageHeartrate(int totalHeartrate);
int maxStepsPerMinute(FitbitData storageArray[]);//finish Arg list
int longestPoorSleep(FitbitData storageArray[],char startarray[], char endarray[]);

#endif // !FITBIT

