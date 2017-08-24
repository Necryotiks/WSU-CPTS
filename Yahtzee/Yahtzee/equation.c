//* Programmer: Elliott Villars
//* Class : CptS 121; Lab Section 2
//* Programming Assignment : Programming Project [5]
//*
//* Date : 10/21/16
//	*
//	* Description : Yahtzee
//	*
//	* Relevant Formulas :N/a
#include "equation.h"
FILE * scorecardp1(void)
{
	FILE*infile1 = fopen("scorecardp1.txt", "w");
	return infile1;
}
FILE * scorecardp2(void)
{
	FILE*infile2 = fopen("scorecardp2.txt", "w");
	return infile2;
}
/*************************************************************
* Function: print_game_rules()                    			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [prints rules]                			    *
* Input parameters: []                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
void print_game_rules(void)
{
	printf("Each game of yahtzee can consist of between 1 and 6 rounds.\n");
	printf("That is a choice the players must make before they begin a new game.\n");
	printf("Each round always consists of 13 turns per player, who take one turn at a time;\n");
	printf("so player 1 has his first turn, then player 2 has his first turn, and so on, until all players have completed the round.\n");
	printf("all rounds have been completed, the game is over and the player with the highest total shall be the winner!\n");
	printf("Each player's turn consists of three dice rolls. On the first roll, the player must roll all five of the dice.\n");
	printf("He may then choose to roll some or all of the dice a second time. After this roll, he has the choice again to roll some or all of the dice again,\n");
	printf("for his final third roll. After this final roll, the player must choose whereabouts on his yahtzee scorecard he would like to place his score.\n");
	system("pause");
	menu();
}

/*************************************************************
* Function: menu()			                    			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [menu]			               			    *
* Input parameters: []                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
void menu()
{
	int option;
	do
	{
		system("cls");
		printf("MENU(INTEGER INPUT ONLY)\n");
		printf("1. Print game rules\n");
		printf("2. Play game\n");
		printf("3. Exit game\n");
		scanf("%d", &option);
		system("cls");
	} while ((option < 1) || (option > 3));

	switch (option)
	{
	case 1:print_game_rules();
		break;
	case 2:play_game_p1();
		break;
	case 3:break;
	}
}
/*************************************************************
* Function: play_game()		                    			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [runs program]                			    *
* Input parameters: []                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
void play_game_p1(void)
{
	FILE*infile1 = scorecardp1();
	FILE*infile2 = scorecardp2();
	srand((unsigned int)time(NULL));
	int round_count = 1;
	int select = 0;
	int score_total_p1 = 0;
	int score_total_p2 = 0;
	int dice_num = 1;
	int dice_p1[5] = { 0 };
	int dice_p2[5] = { 0 };
	int choice_p1[14] = { 0 };
	int choice_p2[14] = { 0 };
	int dice_value_track_p1[7] = { 0 };
	int dice_value_track_p2[7] = { 0 };
	int save_array[7] = { 0 };
	int a = 0;
	int b = 0;
	char dec = '\0';
	while (round_count < 14)
	{
		int d_count = 1;
		char dec = '\0';
		purge_array(dice_value_track_p1, 7);
		roll_dice(dice_p1, 5);
		print_dice(&dice_p1, 5);
		count_dice(dice_p1, 5, dice_value_track_p1, 7);
		while (d_count <= 3)
		{
			printf("\nRound count: %d", round_count);
			printf("\nPlayer1: \n");
			printf("\nDo you wish to reroll? Y/N\n");
			printf("\nRoll count(YOU MUST CHOOSE IF ROLL COUNT IS 3): %d\n", d_count);
			scanf(" %c", &dec);
			if (dec == 'n' || dec == 'N')
			{
				do
				{
					printf("Select an option(POSITIVE INTERGERS ONLY):\n");
					printf("1.Sum of 1\'s\n");
					printf("2.Sum of 2\'s\n");
					printf("3.Sum of 3\'s\n");
					printf("4.Sum of 4\'s\n");
					printf("5.Sum of 5\'s\n");
					printf("6.Sum of 6\'s\n");
					printf("7.Three of a kind\n");
					printf("8.Four of a kind\n");
					printf("9.Full house\n");
					printf("10.Small straight\n");
					printf("11.Large straight\n");
					printf("12.Yahtzee\n");
					printf("13.Chance");
					scanf("%d", &select);
				} while (select < 1 || select > 13);
				choice_p1[a++] = select;
				system("cls");
				score_allocation(choice_p1, dice_value_track_p1, &score_total_p1, dice_p1);
				print_dice(&dice_p1, 5);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				int num_dice = 0;
				int roll = 0;
				printf("How many dice(1-5) do you wish to reroll:");
				scanf("%d", &num_dice);
				purge_array(dice_value_track_p1, 7);
				reroll_dice(dice_p1, num_dice);
				print_dice(&dice_p1, 5);
				count_dice(dice_p1, 5, dice_value_track_p1, 7);
				d_count++;
			}
		}
		d_count = 1;
		dec = '\0';
		purge_array(dice_value_track_p1, 7);
		roll_dice(dice_p2, 5);
		print_dice(&dice_p2, 5);
		count_dice(dice_p2, 5, dice_value_track_p2, 7);
		while (d_count <= 3)
		{
			printf("\nRound count: %d", round_count);
			printf("\nPlayer2: \n");
			printf("\nDo you wish to reroll? Y/N\n");
			printf("\nRoll count(YOU MUST CHOOSE IF ROLL COUNT IS 3): %d\n", d_count);
			scanf(" %c", &dec);
			if (dec == 'n' || dec == 'N')
			{
				do
				{
					printf("Select an option(POSITIVE INTERGERS ONLY):\n");
					printf("1.Sum of 1\'s\n");
					printf("2.Sum of 2\'s\n");
					printf("3.Sum of 3\'s\n");
					printf("4.Sum of 4\'s\n");
					printf("5.Sum of 5\'s\n");
					printf("6.Sum of 6\'s\n");
					printf("7.Three of a kind\n");
					printf("8.Four of a kind\n");
					printf("9.Full house\n");
					printf("10.Small straight\n");
					printf("11.Large straight\n");
					printf("12.Yahtzee\n");
					printf("13.Chance");
					scanf("%d", &select);
				} while (select < 1 || select > 13);
				choice_p2[b++] = select;
				system("cls");
				score_allocation(choice_p2, dice_value_track_p2, &score_total_p2, dice_p2);
				print_dice(&dice_p2, 5);
				system("pause");
				system("cls");
				round_count++;
				break;
			}
			else
			{
				int num_dice = 0;
				int roll = 0;
				printf("How many dice(1-5) do you wish to reroll:");
				scanf("%d", &num_dice);
				purge_array(dice_value_track_p2, 7);
				reroll_dice(dice_p1, num_dice);
				print_dice(&dice_p2, 5);
				count_dice(dice_p2, 5, dice_value_track_p2, 7);
				d_count++;
			}
		}
	}
	print_score_p1(infile1, dice_value_track_p1, score_total_p1, dice_p1);
	print_score_p2(infile2, dice_value_track_p2, score_total_p2, dice_p2);
	fclose(infile1);
	fclose(infile2);
	winner(score_total_p1, score_total_p2);
}
/*************************************************************
* Function: roll_dice()                          			*
* Date Created:[10/21/2016]                                  *
* Date Last Modified:                                       *
* Description: [rolls dice ]                			    *
* Input parameters: []                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
void roll_dice(int dice[], int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		dice[index] = rand() % 6 + 1;
	}
}
/*************************************************************
* Function: roll_die()                          			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [rolls die ]                 			    *
* Input parameters: []                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
int roll_die(void)
{
	int die_value = 0;

	die_value = rand() % 6 + 1;

	return die_value;
}
/*************************************************************
* Function: reroll_die()                          			*
* Date Created:[10/21/2016]                                 *
* Date Last Modified:                                       *
* Description: [rerolls dice ]                			    *
* Input parameters: []                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
void reroll_dice(int dice[], int reroll)
{
	int die_loc;
	for (int i = 0; i < reroll; i++)
	{
		printf("Please select which die to reroll(1-5)");
		scanf("%d", &die_loc);
		dice[die_loc - 1] = roll_die();
	}
}
//PRINTS OUT DICE
void print_dice(int * dice_ptr, int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		printf("die %d: %d\n", index + 1, *(dice_ptr + index));
	}
}
//KEEPS TRACK OF DICE
void count_dice(int dice[], int size, int dice_value_count[], int size_count)
{
	int index = 0, new_index = 0;

	while (index < size)
	{
		new_index = dice[index++];
		dice_value_count[new_index] += 1;
	}
}
//TRACKS USER CHOICES
int choice_track(int choice[], int choice_size, int value)//sourced from http://stackoverflow.com/questions/25143224/count-the-number-of-times-a-number-appears-in-an-array
{
	int i, count = 0;
	for (i = 0; i < choice_size; i++)
	{
		if (choice[i] == value)
		{
			++count;
		}
	}
	return(count);
}
//ALLOCATES POINTS
void score_allocation(int choice[], int dice_value_count[], int *sum, int dice[])
{
	int choice1 = choice_track(choice, 14, 1);
	int choice2 = choice_track(choice, 14, 2);
	int choice3 = choice_track(choice, 14, 3);
	int choice4 = choice_track(choice, 14, 4);
	int choice5 = choice_track(choice, 14, 5);
	int choice6 = choice_track(choice, 14, 6);
	int choice7 = choice_track(choice, 14, 7);
	int choice8 = choice_track(choice, 14, 8);
	int choice9 = choice_track(choice, 14, 9);
	int choice10 = choice_track(choice, 14, 10);
	int choice11 = choice_track(choice, 14, 11);
	int choice12 = choice_track(choice, 14, 12);
	int choice13 = choice_track(choice, 14, 13);
	if (choice1 >= 1)
	{
		int dice_sum = (dice_value_count[1] * 1);
		*sum += dice_sum;
		printf("Points allocated: %d\n", dice_sum);
		printf("Total Score: %d\n", *sum);
	}
	else if (choice2 >= 1)
	{
		int dice_sum = (dice_value_count[2] * 2);
		*sum += dice_sum;
		printf("Points allocated: %d\n", dice_sum);
		printf("Total Score: %d\n", *sum);
	}
	else if (choice3 >= 1)
	{
		int dice_sum = (dice_value_count[3] * 3);
		*sum += dice_sum;
		printf("Points allocated: %d\n", dice_sum);
		printf("Total Score: %d\n", *sum);
	}
	else if (choice4 >= 1)
	{
		int dice_sum = (dice_value_count[4] * 4);
		*sum += dice_sum;
		printf("Points allocated: %d\n", dice_sum);
		printf("Total Score: %d\n", *sum);
	}
	else if (choice5 >= 1)
	{
		int dice_sum = (dice_value_count[5] * 5);
		*sum += dice_sum;
		printf("Points allocated: %d\n", dice_sum);
		printf("Total Score: %d\n", *sum);
	}
	else if (choice6 >= 1)
	{
		int dice_sum = (dice_value_count[6] * 6);
		*sum += dice_sum;
		printf("Points allocated: %d\n", dice_sum);
		printf("Total Score: %d\n", *sum);
	}
	if (choice7 == 1)
	{
		int dice_sum = three_of_kind_check(dice_value_count);
		if (dice_sum == 1)
		{
			*sum += dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
			int alloc = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
			printf("Points allocated %d\n", alloc);
			printf("Total Score: %d\n", *sum);
		}
	}
	else if (choice7 > 1)
	{
		printf("Already selected. Points allocated: 0\n");
		*sum += 0;
		printf("Total Score: %d\n", *sum);
	}
	else if (choice8 == 1)
	{
		int dice_sum = four_of_kind_check(dice_value_count);
		if (dice_sum == 1)
		{
			int alloc= dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
			*sum += dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
			printf("Points allocated %d\n", alloc);
			printf("Total Score: %d\n", *sum);
		}
	}
	else if (choice8 > 1)
	{
		printf("Already selected. Points allocated: 0\n");
		*sum += 0;
		printf("Total Score: %d\n", *sum);
	}
	if (choice9 == 1)
	{
		int dice_sum = full_house_check(dice_value_count);
		if (dice_sum == 1)
		{
			*sum += 25;
			printf("Points allocated:25\n");
			printf("Total Score: %d\n", *sum);
		}
	}
	else if (choice9 > 1)
	{
		printf("Already selected. Points allocated: 0\n");
		*sum += 0;
		printf("Total Score: %d\n", *sum);
	}
	if (choice10 == 1)
	{
		int dice_sum = small_straight_check(dice_value_count);
		if (dice_sum == 1)
		{
			*sum += 30;
			printf("Points allocated:30\n");
			printf("Total Score: %d\n", *sum);
		}
	}
	else if (choice10 > 1)
	{
		printf("Already selected. Points allocated: 0\n");
		*sum += 0;
		printf("Total Score: %d\n", *sum);
	}
	if (choice11 == 1)
	{
		int dice_sum = large_straight_check(dice_value_count);
		if (dice_sum == 1)
		{
			*sum += 40;
			printf("Points allocated:40\n");
			printf("Total Score: %d\n", *sum);
		}
	}
	else if (choice11 > 1)
	{
		printf("Already selected. Points allocated: 0\n");
		*sum += 0;
		printf("Total Score: %d\n", *sum);
	}
	if (choice12 >= 1)
	{
		int dice_sum = yahtzee(dice_value_count);
		if (dice_sum == 1)
		{
			*sum += 50;
			printf("YAHTZEE!\n Points allocated:50\n");
			printf("Total Score: %d\n", *sum);
		}
	}
	else if (choice12 > 1)
	{
		printf("Already selected. Points allocated: 0\n");
		*sum += 0;
		printf("Total Score: %d\n", *sum);
	}
	if (choice13 >= 1)
	{
		int alloc = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
		*sum += dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
		printf("Points allocated %d\n", alloc);
		printf("Total Score: %d\n", *sum);
	}
}
//PURGES DICE_VALUE_COUNT ARRAY
void purge_array(int dice_value_count[], int size)
{
	int a = 0, b = 0;
	for (b = 0; b < size; b++)
	{

		dice_value_count[b] = 0;
	}
}
//CHECKS FOR THREE OF KIND
int three_of_kind_check(int dice_value_count[])
{
	if (dice_value_count[1] == 3)
	{
		return 1;
	}
	if (dice_value_count[2] == 3)
	{
		return 1;
	}
	if (dice_value_count[3] == 3)
	{
		return 1;
	}
	if (dice_value_count[4] == 3)
	{
		return 1;
	}
	if (dice_value_count[5] == 3)
	{
		return 1;
	}
	if (dice_value_count[6] == 3)
	{
		return 1;
	}
	if (dice_value_count[7] == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//CHECKS IF FOUR OF KIND
int four_of_kind_check(int dice_value_count[])
{
	if (dice_value_count[1] == 4)
	{
		return 1;
	}
	if (dice_value_count[2] == 4)
	{
		return 1;
	}
	if (dice_value_count[3] == 4)
	{
		return 1;
	}
	if (dice_value_count[4] == 4)
	{
		return 1;
	}
	if (dice_value_count[5] == 4)
	{
		return 1;
	}
	if (dice_value_count[6] == 4)
	{
		return 1;
	}
	if (dice_value_count[7] == 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//CHECKS IF FULL HOUSE
int full_house_check(int dice_value_count[])
{
	if ((dice_value_count[1] == 3) && ((dice_value_count[2] == 2) || (dice_value_count[3] == 2) || (dice_value_count[4] == 2) || (dice_value_count[5] == 2) || (dice_value_count[6] == 2)))
	{
		return 1;
	}
	else if ((dice_value_count[2] == 3) && ((dice_value_count[1] == 2) || (dice_value_count[3] == 2) || (dice_value_count[4] == 2) || (dice_value_count[5] == 2) || (dice_value_count[6] == 2)))
	{
		return 1;
	}
	else if ((dice_value_count[3] == 3) && ((dice_value_count[1] == 2) || (dice_value_count[2] == 2) || (dice_value_count[4] == 2) || (dice_value_count[5] == 2) || (dice_value_count[6] == 2)))
	{
		return 1;
	}
	else if ((dice_value_count[4] == 3) && ((dice_value_count[1] == 2) || (dice_value_count[2] == 2) || (dice_value_count[3] == 2) || (dice_value_count[5] == 2) || (dice_value_count[6] == 2)))
	{
		return 1;
	}
	else if ((dice_value_count[5] == 3) && ((dice_value_count[1] == 2) || (dice_value_count[2] == 2) || (dice_value_count[3] == 2) || (dice_value_count[4] == 2) || (dice_value_count[6] == 2)))
	{
		return 1;
	}
	else if ((dice_value_count[6] == 3) && ((dice_value_count[1] == 2) || (dice_value_count[2] == 2) || (dice_value_count[3] == 2) || (dice_value_count[4] == 2) || (dice_value_count[5] == 2)))
	{
		return 1;
	}
}
//CHECEKS IF SMALL STRAIGHT
int small_straight_check(int dice_value_count[])
{
	if (((dice_value_count[1] == 1) && (dice_value_count[2] == 1) && (dice_value_count[3] == 1) && (dice_value_count[4] == 1)) || ((dice_value_count[3] == 1) && (dice_value_count[4] == 1) && (dice_value_count[5] == 1) && (dice_value_count[6] == 1)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//CHECEKS IF LARGE STRAIGHT
int large_straight_check(int dice_value_count[])
{
	if (((dice_value_count[1] == 1) && (dice_value_count[2] == 1) && (dice_value_count[3] == 1) && (dice_value_count[4] == 1) && (dice_value_count[5] == 1)) || ((dice_value_count[2] == 1) && (dice_value_count[3] == 1) && (dice_value_count[4] == 1) && (dice_value_count[5] == 1) && (dice_value_count[6] == 1)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//CHECKS IF YAHTZEE
int yahtzee(int dice_value_count[])
{
	if (dice_value_count[1] == 5)
	{
		return 1;
	}
	if (dice_value_count[2] == 5)
	{
		return 1;
	}
	if (dice_value_count[3] == 5)
	{
		return 1;
	}
	if (dice_value_count[4] == 5)
	{
		return 1;
	}
	if (dice_value_count[5] == 5)
	{
		return 1;
	}
	if (dice_value_count[6] == 5)
	{
		return 1;
	}
	if (dice_value_count[7] == 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//PRINTS SCORE TO FILE PLAYER 1
void print_score_p1(FILE * scorecard, int dice_value_count_p1[], int sum_p1, int dice_p1[])
{
	if (((dice_value_count_p1[1] * 1) && (dice_value_count_p1[2] * 2) && (dice_value_count_p1[3] * 3) && (dice_value_count_p1[4] * 4) && (dice_value_count_p1[5] * 5) && (dice_value_count_p1[6] * 6)) >= 63)
	{
		sum_p1 += 35;

	}
	fprintf(scorecard, "SCORE: %d", sum_p1);
}
//PRINTS SCORE TO FILE PLAYER 2
void print_score_p2(FILE * scorecard, int dice_value_count_p2[], int sum_p2, int dice_p2[])
{
	if (((dice_value_count_p2[1] * 1) && (dice_value_count_p2[2] * 2) && (dice_value_count_p2[3] * 3) && (dice_value_count_p2[4] * 4) && (dice_value_count_p2[5] * 5) && (dice_value_count_p2[6] * 6)) >= 63)
	{
		sum_p2 += 35;

	}
	fprintf(scorecard, "SCORE: %d", sum_p2);
}
//PRINTS WINNER
void winner(int sum_p1, int sum_p2)
{
	if (sum_p1 > sum_p2)
	{
		system("cls");
		printf("PLAYER 1 Wins");
		menu();
	}
	else if (sum_p1 < sum_p2)
	{
		system("cls");
		printf("PLAYER 2 Wins");
		menu();
	}
	else
	{
		system("cls");
		printf("TIE");
		menu();
	}
}

