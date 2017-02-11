#include "header.h"
FILE * openFileRead(void)
{
	FILE * infile = fopen("musicPlayList.csv", "r");
	return infile;
}

void menu(void)
{

	int option = 0;
	ListNode *headnode = NULL;//init to null?? maybe pointer?

	while (option == 0)
	{
		system("cls");
		puts("Please select an option:");
		puts("1. Load(WIP)");
		puts("2. Store(NULL)");
		puts("3. Display(NULL)");
		puts("4. Insert(NULL)");
		puts("5. Delete(WIP)");
		puts("6. Edit(NULL)");
		puts("7. Sort(NULL)");
		puts("8. Rate(NULL)");
		puts("9. Play(NULL)");
		puts("10. Shuffle(NULL)");
		puts("11. Exit(NULL");
		scanf("%d", &option);
		switch (option)
		{
		case 1:loadFunction(&headnode);
			option = 0;
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

void loadFunction(ListNode **headnode)
{
	FILE * infile = openFileRead();
	char temp[100] = { '\0' };
	while (fgets(temp, sizeof(temp), infile))
		//while(!feof(infile))
	{
		ListNode *pMem = NULL;
		pMem = makeNode();//store data in pmem? //pointer connect to nothing
		char * token;
		if (temp[0] == '"')
		{
			token = strtok(temp, ",");
			strcpy(pMem->data.artist, token);
			token = strtok(NULL, ",");
			strcat(pMem->data.artist, token);
			token = strtok(NULL, ",");
			strcpy(pMem->data.albumTitle, token);
			token = strtok(NULL, ",");
			strcpy(pMem->data.songTitle, token);
			token = strtok(NULL, ",");
			strcpy(pMem->data.genre,token);
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
			strcpy(pMem->data.artist,token);
			token = strtok(NULL, ",");
			strcpy(pMem->data.albumTitle,token);
			token = strtok(NULL, ",");
			strcpy(pMem->data.songTitle,token);
			token = strtok(NULL, ",");
			strcpy(pMem->data.genre,token);
			token = strtok(NULL, ":");
			pMem->data.songLength.minutes = atoi(token);
			token = strtok(NULL, ",");
			pMem->data.songLength.seconds = atoi(token);
			token = strtok(NULL, ",");
			pMem->data.numberOfPlays = atoi(token);
			token = strtok(NULL, ",");
			pMem->data.songRating = atoi(token);
		}
		InsertInFront(pMem, &headnode);
	};//pass in address of address
	printList(&headnode);
	fclose(infile);
}

void InsertInFront(ListNode * PMem, ListNode ** headnode)//FIX
{
	ListNode * pCur = NULL;
	pCur = *headnode;// * headnode = pRoot

	if (pCur == NULL)
	{
		*headnode = PMem; //connect pointers somehow.
		//pCur->pNext->pPrev = pCur;
	}
	else if (pCur != NULL)
	{
		(*headnode)->pPrev = PMem;//moves root pointer to find empty spot
		PMem->pNext = *headnode;
		*headnode = PMem;
	}
}
void deleteFunction(ListNode ** headnode)
{
	ListNode * pCur = *headnode;
	//delete at front, check if users requests front list deletion. move root node if whatever user is deleting isnt there
	*headnode = pCur->pNext;
	pCur->pPrev = NULL;
	free(pCur);
	//if not front(delete at middle)
	pCur->pPrev = pCur->pNext;
	pCur->pNext->pPrev = pCur->pPrev;
	free(pCur);

}

void printList(ListNode ** headnode)
{
	ListNode * pCur = *headnode;
	while (pCur != NULL)//overprints
	{
		if (pCur == NULL)
		{
			break;
		}
		printf("----->%s", pCur->data.artist);
		pCur = pCur->pNext;
	}
}

//while (sizeof(pCur->data) < sizeof(PMem))
/*else//maybe else? under while loop? get rid of this. if statement to check node order?
{
	pCur->pPrev->pNext = PMem;//order check
	PMem->pPrev = pCur->pPrev;
	PMem = pCur;
	pCur->pPrev = PMem;
}*/// insert in order.