#include "header.h"
FILE * openFileRead(void)
{
	FILE * infile = fopen("musicPlayList.csv", "r");
	return infile;
}
//test
FILE * openFileForOverWrite(void)
{
	FILE * infile = fopen("musicPlayList.csv", "w+");
	return infile;
}

void menu(void)
{
	int switch1 = 0;
	int loadcheck = 0;
	int option = 0;
	ListNode *headnode = NULL;

	while (option == 0)
	{
		system("cls");
		puts("Please select an option:");
		puts("1. Load(USE THIS FIRST)");
		puts("2. Store");
		puts("3. Display");
		puts("4. Insert");
		puts("5. Delete");
		puts("6. Edit");
		puts("7. Sort(BROKEN)");
		puts("8. Rate(UNECESSARY)");
		puts("9. Play");
		puts("10. Shuffle");
		puts("11. Exit");
		if ((switch1 == 1) && (headnode != NULL) && (loadcheck == 1))
		{
			puts("");
			puts("List Loaded!");
		}
		if ((switch1 == 1) && (headnode != NULL) && loadcheck > 1)
		{
			puts("");
			puts("List Already Loaded!");
		}
		scanf("%d", &option);
		switch (option)
		{
		case 1:loadFunction(&headnode, loadcheck);//adding and subtracting nodes need & and **pHead
			switch1 = 1;
			loadcheck++;
			option = 0;
			break;
		case 2:storeFunction(headnode, loadcheck);
			option = 0;
			break;
		case 3:printList(headnode, loadcheck);
			option = 0;
			break;
		case 4:insertFunction(&headnode);
			option = 0;
			break;
		case 5:deleteFunction(&headnode, loadcheck);
			option = 0;
			break;
		case 6:editFunction(headnode, loadcheck);
			option = 0;
			break;
		case 7:sortFunction(headnode, loadcheck);
			option = 0;
			break;
		case 8:rateFunction(headnode, loadcheck);
			option = 0;
			break;
		case 9:playFunction(headnode, loadcheck);
			option = 0;
			break;
		case 10:shuffleFunction(headnode, loadcheck);
			option = 0;
			break;
		case 11:storeFunction(headnode, loadcheck);
			option = 1;
			break;

		}
	}
}

ListNode * makeNode()
{
	ListNode * pMem = (ListNode *)malloc(sizeof(ListNode));
	pMem->pPrev = NULL;
	pMem->pNext = NULL;
	if (pMem == NULL)
	{
		return NULL;
	}
	return pMem;
}

void loadFunction(ListNode **headnode, int loadCheck)
{
	if (loadCheck == 0)
	{
		FILE * infile = openFileRead();
		while (!feof(infile))
		{
			char temp[100] = { '\0' };
			ListNode *pMem = NULL;
			fgets(temp, sizeof(temp), infile);
			if (temp[0] == '\0')
			{
				break;
			}
			pMem = makeNode();//store data in pmem //
			char * token;
			if (temp[0] == '"')
			{
				token = strtok(temp, ",");
				strcpy(pMem->data.artist, token);
				token = strtok(NULL, ",");
				strcat(pMem->data.artist, ",");
				strcat(pMem->data.artist, token);
				token = strtok(NULL, ",");
				strcpy(pMem->data.albumTitle, token);
				token = strtok(NULL, ",");
				strcpy(pMem->data.songTitle, token);
				token = strtok(NULL, ",");
				strcpy(pMem->data.genre, token);
				token = strtok(NULL, ":");
				pMem->data.songLength.minutes = atoi(token);
				token = strtok(NULL, ",");
				pMem->data.songLength.seconds = atoi(token);
				token = strtok(NULL, ",");
				pMem->data.numberOfPlays = atoi(token);
				token = strtok(NULL, ",");
				pMem->data.songRating = atoi(token);
			}
			else
			{
				token = strtok(temp, ",");
				strcpy(pMem->data.artist, token);
				token = strtok(NULL, ",");
				strcpy(pMem->data.albumTitle, token);
				token = strtok(NULL, ",");
				strcpy(pMem->data.songTitle, token);
				token = strtok(NULL, ",");
				strcpy(pMem->data.genre, token);
				token = strtok(NULL, ":");
				pMem->data.songLength.minutes = atoi(token);
				token = strtok(NULL, ",");
				pMem->data.songLength.seconds = atoi(token);
				token = strtok(NULL, ",");
				pMem->data.numberOfPlays = atoi(token);
				token = strtok(NULL, ",");
				pMem->data.songRating = atoi(token);
			}
			InsertInFront(pMem, headnode);
		};//pass in address of address
		loadCheck = 1;
		printList(*headnode, loadCheck);
		fclose(infile);
	}
}

void InsertInFront(ListNode * PMem, ListNode ** headnode)//FIX
{
	ListNode * pCur = NULL;
	pCur = *headnode;// * headnode = pRoot

	if (pCur == NULL)
	{
		*headnode = PMem;
		//pCur->pNext->pPrev = pCur;
	}
	else if (pCur != NULL)
	{
		(*headnode)->pPrev = PMem;//moves root pointer to find empty spot
		PMem->pNext = *headnode;
		*headnode = PMem;
	}
}
void deleteFunction(ListNode ** headnode, int loadCheck)//UNFINISHED
{
	if (headnode != NULL)
	{
		ListNode * pCur = *headnode;
		char namearray[25];
		printList(*headnode, loadCheck);
		printf("Enter a song to delete: ");
		scanf("%*c", namearray);
		scanf("%[^\n]%*c", namearray);
		if (strcmp(pCur->data.songTitle, namearray) == 0)
		{
			*headnode = pCur->pNext;
			pCur->pPrev = NULL;
			free(pCur);
			puts("ENTRY DELETED!");
			system("pause");
		}
		else
		{
			while (pCur != NULL)//crashes fix tomorrow
			{
				if (strcmp(pCur->data.songTitle, namearray) == 0)
				{
					if (pCur->pNext != NULL)
					{
						pCur->pPrev->pNext = pCur->pNext;
						pCur->pNext->pPrev = pCur->pPrev;
						free(pCur);
						puts("ENTRY DELETED!");
						system("pause");
						break;
					}
					else
					{

						free(pCur);
						puts("ENTRY DELETED!");
						system("pause");
						break;
					}
				}
				else if (pCur->pNext != NULL)
				{
					pCur = pCur->pNext;
				}
				else
				{
					puts("NOTHING TO DELETE, RETURNING TO MAIN MENU!");
					system("pause");
					break;
				}

			}
		}
	}
	//**headnode = pCur->pNext;
	//pCur->pPrev = NULL;
	//free(pCur);*/
	////if not front(delete at middle)
	//pCur->pPrev = pCur->pNext;
	//pCur->pNext->pPrev = pCur->pPrev;
	//free(pCur);

}

void sortFunction(ListNode * headnode, int loadCheck)
{
	if (loadCheck >= 1)
	{

		int option = 0;
		ListNode * pCur = headnode;
		while (option != 5)
		{
			system("cls");
			puts("Select sort option: ");
			puts("1. Artist");
			puts("2. Album");
			puts("3. Rating");
			puts("4. Times played");
			puts("5. Quit");
			scanf("%d", &option);
			switch (option)
			{
			case 1:
				while (pCur != NULL)
				{
					while (strcmp(pCur->data.artist, pCur->pNext->data.artist) < 0)
					{
						sortfunctionAZ(&headnode);

					}
					pCur = pCur->pNext;
				}
				puts("SORT COMPLETE!");
				break;
			case 8: break;
			}
		}

	}
}

void shuffleFunction(ListNode * headnode, int loadCheck)//STILL BROKE AS FUCK
{
	int i = 0;
	int looptimes = 0;
	srand(time(NULL));
	int listlength = 0;
	printList(headnode, loadCheck);
	ListNode * pCur = headnode;
	if (loadCheck >= 1)
	{
		pCur = headnode;
		while (pCur != NULL)
		{
			listlength++;
			pCur = pCur->pNext;
		}
		pCur = headnode;
		int * listarray = malloc(listlength * sizeof(int));
		for (i = 0; i < listlength; i++)
		{
			listarray[i] = rand() % listlength;
		}
		puts("Enter number of times to shuffle");
		scanf("%d", &looptimes);
		for (int f = 0; f < looptimes; f++)
		{
			for (i = 0; i < listlength; i++)
			{
				pCur = headnode;
				for (int j = 0; j < listarray[i]; j++)
				{

					pCur = pCur->pNext;
				}
				if (pCur != NULL)
					printf("----->%s\n", pCur->data.songTitle);
				Sleep(2000);
			}
		}
		puts("ALL SONGS PLAYED! RETURNING TO MAIN MENU.");
		system("pause");
	}
}
void sortfunctionAZ(ListNode ** headnode)
{
	ListNode * pCur = *headnode;
	if ((pCur->pPrev != NULL) && (pCur->pNext != NULL))
	{


		pCur->pPrev->pNext = pCur->pNext;
		pCur->pNext->pPrev = pCur->pPrev;
		pCur->pPrev = pCur->pNext;
		pCur->pNext = pCur->pPrev->pNext;
		pCur->pPrev->pNext = pCur;
		pCur->pNext->pPrev = pCur;
	}
	else if (pCur->pPrev == NULL)
	{
		pCur->pNext->pPrev = NULL;
		pCur->pNext = pCur->pNext->pNext;
		pCur->pPrev = pCur->pNext->pPrev;
		pCur->pNext->pPrev = pCur;
		pCur->pPrev->pNext = pCur;
	}
	else
	{
		pCur->pPrev->pNext = pCur->pNext;
		pCur->pNext->pPrev = pCur->pPrev;
		pCur->pNext->pNext = pCur;
		pCur->pPrev = pCur->pNext;
		pCur->pNext = NULL;
	}
}

void printList(ListNode * headnode, int loadCheck)//prints all loaded nodes
{
	if (loadCheck >= 1)
	{
		ListNode * pCur = headnode;
		while (pCur->data.artist != NULL)
		{
			if (pCur->data.artist[1] >= 'A')
			{
				printf("%s,%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre, pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.numberOfPlays, pCur->data.songRating);

				pCur = pCur->pNext;
			}
			else
			{
				break;
			}
		}
		system("pause");
	}
	else
	{
		puts("FILE NOT LOADED!");
		system("pause");
	}
}

void storeFunction(ListNode * headnode, int loadCheck)//probably fixed(see above)
{
	if (loadCheck >= 1)
	{
		FILE * infile = openFileForOverWrite();
		ListNode * pCur = headnode;
		while (pCur->data.artist != NULL)
		{
			if (pCur->data.artist[1] >= 'A')
			{
				printf("%s,%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre, pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.numberOfPlays, pCur->data.songRating);
				fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.albumTitle, pCur->data.songTitle, pCur->data.genre, pCur->data.songLength.minutes, pCur->data.songLength.seconds, pCur->data.numberOfPlays, pCur->data.songRating);
				pCur = pCur->pNext;
			}
			else
			{
				break;
			}
		}
		system("pause");
		fclose(infile);
	}
	else
	{
		puts("FILE NOT LOADED!");
		system("pause");
	}
}

void editFunction(ListNode * headnode, int loadCheck)
{
	if (loadCheck >= 1)
	{
		ListNode * pCur = NULL;
		int ANFSwitch = 0;//artist not found boolean switch
		char namelist[30];
		char namecheck[30];
		char songlist[30];
		pCur = headnode;//headnode is null?
		printList(headnode, loadCheck);
		printf("Select an artist(Enter as displayed on screen): ");
		scanf("%*c", namelist);
		scanf("%[^\n]%*c", namelist);

		namelist[strlen(namelist - 1)] = '\0';
		for (int i = 0; i < strlen(namelist) + 1; i++)
		{
			if ((isalnum(namelist[i]) == 0) && (ispunct(namelist[i] == 0)))//prevent nonalnum characters from being entered
			{
				memset(namelist, '\0', sizeof(namelist));//purges whole array
				puts("NON ALPHANUMERIC CHARACTER DETECTED. ARRAY HAS BEEN PURGED.");
				puts("Reenter search query(no quotes or spaces):");
				scanf("%*c", namelist);
				scanf("%[^\n]%*c", namelist);
				namelist[strlen(namelist - 1)] = '\0';
				i = 0;

			}
		}
		pCur = headnode;
		while ((strcmp(pCur->data.artist, namelist)) != 0)
		{
			if (pCur->pNext != NULL)
			{
				pCur = pCur->pNext;
			}
			else
			{
				puts("ARTIST NOT FOUND, RETURNING TO MAIN MENU");
				system("pause"); \
					ANFSwitch = 1;
				break;
			}
		}
		if (ANFSwitch == 0)//print list in here
		{
			int select = 0;
			//memset(namelist, '\0', sizeof(namelist));
			int temp = 0;
			char * waypoint;
			while (select != 8)
			{
				system("cls");
				puts("Select a field to edit: \n");
				printf("1. Artist: %s\n", pCur->data.artist);
				printf("2. Album Title: %s\n", pCur->data.albumTitle);
				printf("3. Song Title: %s\n", pCur->data.songTitle);
				printf("4. Genre: %s\n", pCur->data.genre);//JUST A MENU
				printf("5. Song Length: %d:%d\n", pCur->data.songLength.minutes, pCur->data.songLength.seconds);
				printf("6. Number of Plays: %d\n", pCur->data.numberOfPlays);
				printf("7. Song Rating: %d\n", pCur->data.songRating);
				printf("8. Exit\n");
				printf("9. Next Song By Artist\n");
				scanf("%d", &select);
				switch (select)
				{
				case 1:system("cls");
					puts("CURRENTLY EDITING: NAME\n");
					printf("CURRENT: %s\n", pCur->data.artist);
					puts("Enter a name: ");
					scanf("%*c", namelist);
					scanf("%[^\n]%*c", namelist);
					namelist[strlen(namelist)] = '\0';//ignores enter command.
					strcpy(pCur->data.artist, namelist);
					break;
				case 2:system("cls");
					puts("CURRENTLY EDITING: ALBUM TITLE\n");
					printf("CURRENT: %s\n", pCur->data.albumTitle);
					puts("Enter an Album title: ");
					scanf("%*c", namelist);
					scanf("%[^\n]%*c", namelist);
					namelist[strlen(namelist) - 1] = '\0';//ignores enter command.
					strcpy(pCur->data.albumTitle, namelist);
					break;
				case 3:system("cls");
					puts("CURRENTLY EDITING: SONG TITLE\n");
					printf("CURRENT: %s\n", pCur->data.songTitle);
					puts("Enter a Song title: ");
					scanf("%*c", namelist);
					scanf("%[^\n]%*c", namelist);
					namelist[strlen(namelist) - 1] = '\0';//ignores enter command.
					strcpy(pCur->data.songTitle, namelist);
					break;
				case 4:system("cls");
					puts("CURRENTLY EDITING: GENRE\n");
					printf("CURRENT: %s\n", pCur->data.genre);
					puts("Enter a Genre: ");
					scanf("%*c", namelist);
					scanf("%[^\n]%*c", namelist);
					namelist[strlen(namelist) - 1] = '\0';//ignores enter command.
					strcpy(pCur->data.genre, namelist);
					break;
				case 5:system("cls");
					puts("CURRENTLY EDITING: SONG LENGTH\n");
					printf("CURRENT: %d:%d\n", pCur->data.songLength.minutes, pCur->data.songLength.seconds);
					puts("Enter Minutes: ");
					scanf("%d", &temp);
					pCur->data.songLength.minutes = temp;
					puts("Enter Seconds(if less than 10, enter as 0x): ");
					scanf("%d", &temp);
					pCur->data.songLength.seconds = temp;
					break;
				case 6:system("cls");
					puts("CURRENTLY EDITING: NUMBER OF PLAYS\n");
					puts("CURRENT: %s\n", pCur->data.numberOfPlays);
					puts("Enter number of plays");
					scanf("%d", &temp);
					pCur->data.numberOfPlays = temp;
					break;
				case 7:system("cls");
					puts("CURRENTLY EDITING: SONG RATING\n");
					printf("CURRENT: %d\n", pCur->data.songRating);
					puts("Enter rating from 1-5");
					scanf("%d", &temp);
					if (temp > 5)
					{
						puts("AUTO ASSIGNING HIGHEST POSSIBLE RAING OF 5");
						temp = 5;
						system("pause");
					}
					if (temp < 1)
					{
						puts("AUTO ASSIGNING LOWEST POSSIBLE RAING OF 1");
						temp = 1;
						system("pause");
					}
					pCur->data.songRating = temp;
					break;
				case 9:
					waypoint = pCur;//remembers current node
					while (pCur->pNext != NULL)
					{
						if ((strcmp(pCur->pNext->data.artist, namelist) != 0))
						{
							pCur = pCur->pNext;
							if (pCur->pNext == NULL)
							{
								pCur = waypoint;
								puts("NO MORE SONGS BY ARTIST");

								system("pause");
								break;
							}
						}
						else if (strcmp(pCur->pNext->data.artist, namelist) == 0)
						{
							pCur = pCur->pNext;
							waypoint = pCur;//moves waypoint
							puts("Next Song Loaded!");
							system("pause");
							break;
						}

					}

					break;

				}
			}
		}
	}
	else
	{
		puts("FILE NOT LOADED!");
		system("pause");
	}
}

void rateFunction(ListNode * headnode, int loadCheck)
{
	if (loadCheck >= 1)
	{
		ListNode * pCur = NULL;
		int ANFSwitch = 0;//artist not found boolean switch
		char namelist[30];
		char namecheck[30];
		char songlist[30];
		pCur = headnode;//headnode is null?

		printList(headnode, loadCheck);
		printf("Select an artist(Enter as displayed on screen): ");
		scanf("%*c");
		scanf("%[^\n]%*c", namelist);

		namelist[strlen(namelist - 1)] = '\0';
		for (int i = 0; i < strlen(namelist) + 1; i++)
		{
			if ((isalnum(namelist[i]) == 0) && (ispunct(namelist[i] == 0)))//prevent nonalnum characters from being entered
			{
				memset(namelist, '\0', sizeof(namelist));//purges whole array
				puts("NON ALPHANUMERIC CHARACTER DETECTED. ARRAY HAS BEEN PURGED.");
				puts("Reenter search query(no quotes or spaces):");
				scanf("%*c", namelist);
				scanf("%[^\n]%*c", namelist);
				namelist[strlen(namelist - 1)] = '\0';
				i = 0;

			}
		}
		pCur = headnode;
		while ((strcmp(pCur->data.artist, namelist)) != 0)
		{
			if (pCur->pNext != NULL)
			{
				pCur = pCur->pNext;
			}
			else
			{
				puts("ARTIST NOT FOUND, RETURNING TO MAIN MENU");
				system("pause"); \
					ANFSwitch = 1;
				break;
			}
		}
		if (ANFSwitch == 0)//print list in here
		{
			int select = 0;
			//memset(namelist, '\0', sizeof(namelist));
			int temp = 0;
			char * waypoint;
			while (select != 8)
			{
				system("cls");
				puts("Select a field to edit: \n");
				printf("N/A. Artist: %s\n", pCur->data.artist);
				printf("N/A. Album Title: %s\n", pCur->data.albumTitle);
				printf("N/A. Song Title: %s\n", pCur->data.songTitle);
				printf("N/A. Genre: %s\n", pCur->data.genre);//JUST A MENU
				printf("N/A. Song Length: %d:%d\n", pCur->data.songLength.minutes, pCur->data.songLength.seconds);
				printf("N/A. Number of Plays: %d\n", pCur->data.numberOfPlays);
				printf("7. Song Rating: %d\n", pCur->data.songRating);
				printf("8. Exit\n");
				printf("9. Next Song By Artist\n");
				scanf("%d", &select);
				if (select > 9)
				{
					select = 9;
					puts("AUTO ASSIGNING HIGHEST POSSIBLE RAING OF 5");
					Sleep(2000);
				}
				if (select < 7)
				{
					select = 7;
					puts("AUTO ASSIGNING LOWEST POSSIBLE RAING OF 5");
					Sleep(2000);
				}
				switch (select)
				{
				case 7:system("cls");
					puts("CURRENTLY EDITING: SONG RATING\n");
					printf("CURRENT: %d\n", pCur->data.songRating);
					puts("Enter rating from 1-5");
					scanf("%d", &temp);
					if (temp > 5)
					{
						puts("AUTO ASSIGNING HIGHEST POSSIBLE RAING OF 5");
						temp = 5;
						system("pause");
					}
					if (temp < 1)
					{
						puts("AUTO ASSIGNING LOWEST POSSIBLE RAING OF 1");
						temp = 1;
						system("pause");
					}
					pCur->data.songRating = temp;
					break;
				case 9:
					waypoint = pCur;//remembers current node
					while (pCur->pNext != NULL)
					{
						if ((strcmp(pCur->pNext->data.artist, namelist) != 0))
						{
							pCur = pCur->pNext;
							if (pCur->pNext == NULL)
							{
								pCur = waypoint;
								puts("NO MORE SONGS BY ARTIST");

								system("pause");
								break;
							}
						}
						else if (strcmp(pCur->pNext->data.artist, namelist) == 0)
						{
							pCur = pCur->pNext;
							waypoint = pCur;//moves waypoint
							puts("Next Song Loaded!");
							system("pause");
							break;
						}

					}

					break;

				}
			}
		}
	}
	else
	{
		puts("FILE NOT LOADED!");
		system("pause");
	}
}
void playFunction(ListNode * headnode, int loadCheck)
{
	char songlist[30];
	printList(headnode, loadCheck);
	ListNode * pCur = headnode;
	if (loadCheck >= 1)
	{
		pCur = headnode;
		printf("Enter a song: ");
		scanf("%*c");
		scanf("%[^\n]%*c", songlist);
		while ((strcmp(pCur->data.songTitle, songlist)) != 0)
		{
			if (pCur->pNext != NULL)
			{
				pCur = pCur->pNext;
			}
			else
			{
				puts("SONG NOT FOUND, RETURNING TO MAIN MENU");
				system("pause");
				exit(1);
			}
		}
		system("cls");
		while (pCur->data.songTitle != NULL)
		{
			if (pCur->data.songTitle[1] >= 'A')
			{
				printf("----->%s\n", pCur->data.songTitle);
				Sleep(2000);
				if (pCur->pNext != NULL)
				{
					pCur = pCur->pNext;
				}
				else
				{
					puts("ALL SONGS PLAYED!");
					break;
				}
			}
		}
		system("pause");
	}
	else
	{
		puts("FILE NOT LOADED!");
		system("pause");
	}
}
void insertFunction(ListNode ** headnode)
{
	char wordarray[25];
	int temp;
	ListNode * PMem = makeNode();
	printf("Enter an artist: ");
	scanf("%*c", wordarray);
	scanf("%[^\n]%*c", wordarray);
	strcpy(PMem->data.artist, wordarray);
	memset(wordarray, '\0', sizeof(wordarray));
	printf("Enter an Album: ");
	//scanf("%*c",wordarray);
	scanf("%[^\n]%*c", wordarray);
	strcpy(PMem->data.albumTitle, wordarray);
	memset(wordarray, '\0', sizeof(wordarray));
	printf("Enter a song name: ");
	//scanf("%*c", wordarray);
	scanf("%[^\n]%*c", wordarray);
	strcpy(PMem->data.songTitle, wordarray);
	memset(wordarray, '\0', sizeof(wordarray));
	printf("Enter an genre: ");
	//scanf("%*c", wordarray);
	scanf("%[^\n]%*c", wordarray);
	strcpy(PMem->data.genre, wordarray);
	printf("Enter song length(minutes): ");
	scanf("%d", &temp);
	PMem->data.songLength.minutes = temp;
	printf("Enter song length(seconds): ");
	scanf("%d", &temp);
	PMem->data.songLength.seconds = temp;
	printf("Enter number of plays: ");
	scanf("%d", &temp);
	PMem->data.numberOfPlays = temp;
	printf("Enter song rating: ");
	scanf("%d", &temp);
	if (temp > 5)
	{
		puts("AUTO ASSIGNING HIGHEST POSSIBLE RAING OF 5");
		temp = 5;
		system("pause");
	}
	else if (temp < 1)
	{
		puts("AUTO ASSIGNING LOWEST POSSIBLE RAING OF 1");
		temp = 1;
		system("pause");
	}
	PMem->data.songRating = temp;
	InsertInFront(PMem, headnode);

}

//while (sizeof(pCur->data) < sizeof(PMem))
/*else//maybe else? under while loop? get rid of this. if statement to check node order?
{
pCur->pPrev->pNext = PMem;//order check
PMem->pPrev = pCur->pPrev;
PMem = pCur;
pCur->pPrev = PMem;
}*/// insert in order.