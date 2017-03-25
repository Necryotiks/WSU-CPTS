#include "header.h"

FILE * FitBitOpen(void)
{
	FILE * infile = fopen("FitbitData.csv", "r");//opens input file
	return infile;
}

FILE * resultsOpen(void)
{
	FILE * outfile = fopen("Results.csv", "w+");//opens output file
	return outfile;
}

void runParsingProgram(void)
{
	FitbitData storageArray[1440] = { '\0' };
	int currentLineplusOne = 0;
	double totaCalories = 0.00;
	double distanceTraveled = 0.00;//variable initialization
	int floorsWalked = 0;
	int totalHeartRate = 0;
	int stepsTaken = 0;
	char startarray[9], endarray[9];
	FILE* infile = FitBitOpen();
	FILE * outfile = resultsOpen();
	fseek(infile, 57, SEEK_SET);//sets cursor to line 2
	while (!feof(infile))
	{
		if (currentLineplusOne == 1440)
		{
			break;
		}
		parseLine(infile, storageArray, currentLineplusOne);//cant deal with double delims yet.(FIXED)
		SumTotalData(infile, storageArray, currentLineplusOne, &totaCalories, &distanceTraveled, &floorsWalked, &totalHeartRate, &stepsTaken);//after 1440 breaks ALL variables;(FIXED)
		currentLineplusOne++;
	}
	int avgHR = AverageHeartrate(totalHeartRate);
	int maxStepsTaken = maxStepsPerMinute(storageArray);
	int maxNoSleep = longestPoorSleep(storageArray,startarray,endarray);
	printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile,"Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	printf( "%lf,%lf,%d,%d,%d,%d,%d\n", totaCalories, distanceTraveled, floorsWalked,stepsTaken, avgHR, maxStepsTaken, maxNoSleep);
	fprintf(outfile, "%lf,%lf,%d,%d,%d,%d,%d\n", totaCalories, distanceTraveled,floorsWalked,stepsTaken,avgHR,maxStepsTaken,maxNoSleep);
	printf("Poor Sleep Start: %s\n", startarray);
	fprintf(outfile,"Poor Sleep Start: %s\n", startarray);
	printf("Poor Sleep End: %s", endarray);
	fprintf(outfile, "Poor Sleep End: %s", endarray);

	fclose(infile);
	fclose(outfile);

}

void parseLine(FILE * infile, FitbitData storageArray[], int currentLine)
{
	char bufferArray[100];
	int commaCount = 0;
	int skipCheckCal = 0;
	int skipCheckDis = 0;
	int skipCheckFloor = 0;
	int skipCheckHR = 0;
	int skipCheckStep = 0;
	int skipCheckSleep = 0;
	

	fgets(bufferArray, 100, infile);
	int i = 0;
	for ( i = 0; i <strlen(bufferArray)+1; i++)
	{
		if (bufferArray[i] == ',')
		{
			commaCount++;
			if (bufferArray[i + 1] == ',')//maybe off by one
			{

				switch (commaCount)
				{
				case 1: storageArray[currentLine].calories = 0;
					skipCheckCal = 1;//bool statement switch to avoid overtoken
					break;
				case 2: storageArray[currentLine].distance = 0;
					skipCheckDis = 1;
					break;
				case 3: storageArray[currentLine].floors = 0;
					skipCheckFloor = 1;
					break;
				case 4: storageArray[currentLine].heartRate = 0;
					skipCheckHR = 1;
					break;
				case 5: storageArray[currentLine].steps = 0;
					skipCheckStep = 1;
					break;
				}
								//storing values into array
			}
			if (bufferArray[i + 1] == '\0')
			{
				storageArray[currentLine].sleepLevel = 0;
				skipCheckSleep = 1;
			}
		}
	}
	char * token = strtok(bufferArray, ",");
	strcpy(storageArray[currentLine].minute, token);
	//cycles through tokens
	if ((storageArray[currentLine].calories == '\0') && (skipCheckCal == 0))
	{
		token = strtok(NULL, ",");
		storageArray[currentLine].calories = atof(token);
	}
	if ((storageArray[currentLine].distance == '\0') && (skipCheckDis == 0))
	{
		token = strtok(NULL, ",");
		storageArray[currentLine].distance = atof(token);
	}
	if ((storageArray[currentLine].floors == '\0') && (skipCheckFloor == 0))
	{
		token = strtok(NULL, ",");
		storageArray[currentLine].floors = atoi(token);
	}
	if ((storageArray[currentLine].heartRate == '\0') && (skipCheckHR == 0))//still continues because NULL = 0(FIXED)
	{
			token = strtok(NULL, ",");
			storageArray[currentLine].heartRate = atoi(token);
	}
	if ((storageArray[currentLine].steps == '\0')&&(skipCheckStep == 0))
	{
		token = strtok(NULL, ",");
		storageArray[currentLine].steps = atoi(token);
	}
	if ((storageArray[currentLine].sleepLevel == '\0') && (skipCheckSleep == 0))
	{
		token = strtok(NULL, ",");
		storageArray[currentLine].sleepLevel = atoi(token);
	}
}

void SumTotalData(FILE* infile, FitbitData storageArray[], int currentLine, double * totalCalories, double * distanceTraveled, int*floorsWalked, int * totalHeartrate, int* stepsTaken)
{

	*totalCalories += storageArray[currentLine].calories;
	*distanceTraveled += storageArray[currentLine].distance;
	*floorsWalked += storageArray[currentLine].floors;
	*totalHeartrate += storageArray[currentLine].heartRate;
	*stepsTaken += storageArray[currentLine].steps;
	//sums data
}

double AverageHeartrate(int totalHeartrate)
{
	double AvgHeartrate = 0.00;
	AvgHeartrate = totalHeartrate / MINUTES_PER_DAY;//calcs avg heartrate
	return AvgHeartrate;
}

int maxStepsPerMinute(FitbitData storageArray[])
{
	int i = 0;
	int maxStepTaken = 0;
	for (i = 0; i < 1440; i++)
	{
		if(maxStepTaken < storageArray[i].steps) 
		{
			maxStepTaken = storageArray[i].steps;
		}
	}
	return maxStepTaken;
}

int longestPoorSleep(FitbitData storageArray[], char startarray[], char endarray[])//report minutes;
{
	int currentNoSleepCount = 0;
	int maxNoSleepCount = 0;
	int j = 0;
	for (j = 0; j < 1440; j++)
	{
		if (storageArray[j].sleepLevel >= 1)
		{

			if (storageArray[j + 1].sleepLevel >= 2)
			{
				strcpy(endarray, storageArray[j+2].minute);
				currentNoSleepCount++;
				maxNoSleepCount = currentNoSleepCount;
				if (currentNoSleepCount == maxNoSleepCount)
				{
					strcpy(startarray, storageArray[j - maxNoSleepCount+2].minute);
				}
			}
			if (storageArray[j + 1].sleepLevel <= 1)
			{
				currentNoSleepCount = 0;
			}
		}
	}
	return maxNoSleepCount;
}

