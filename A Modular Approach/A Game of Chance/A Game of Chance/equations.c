//* Programmer: Elliott Villars
//* Class : CptS 121; Lab Section 2
//* Programming Assignment : Programming Project [4]
//*
//* Date : 10/6/16
//	*
//	* Description : Craps 
//	*
//	* Relevant Formulas :N/a

#include "equation.h"


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
	printf("The players take turn rolling two dice. The player that is rolling the dice is considered the shooter. The shooter MUST bet at least the table minimum on either the pass line or do not pass line.\n");
	printf("\n");
	printf("The game is played in rounds consisting of two phases : come out and point.\n");
	printf("\n");
	printf("To start a round, the shooter makes a \'come out' roll\n");
	printf("\n");
	printf("If the come out roll is a 2, 3, or 12, then the round ends.The rules of craps state that the shooter is said to \'crap out' and players lose their pass line bets.\n");
	printf("\n");
	printf("If the come out roll is a 7 or 11, this results in a win for pass line bets.\n");
	printf("\n");
	printf("The shooter continues to make come out rolls until he rolls 4, 5, 6, 8, 9, or 10. This number becomes the point and in turn the point phase begins.\n");
	printf("\n");
	printf("During this phase, if the shooter rolls a point number then it\'s a win for the pass line bets.If the shooter rolls a seven, it\'s a loss for the pass line bets and the round is over.\n");
	printf("\n");
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
	case 2:play_game();
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
void play_game(void)
{
	int option = 0, die1 = 0, die2 = 0, count = 0, point_value = 0;



	srand((unsigned int)time(NULL));
	double balance = get_bank_balance();
	double initial_balance = balance;

	do
	{
		double wager = get_wager_amount();
		system("cls");
		int check_wager = check_wager_amount(wager, balance);
		if (check_wager == 0)
		{
			printf("Out of Shekels.\n");
			printf("Balance: %lf\n", balance);
			Sleep(3 * 1000);
			break;
		}
		if (check_wager == 1)
		{
			die1 = roll_die();
			die2 = roll_die();
			count++;
			int sum_dice = calculate_sum_dice(die1, die2);
			int add_sub = is_win_loss_or_point(sum_dice, &point_value);
			system("cls");
			if (add_sub == -1)
			{
				do
				{
					system("cls");
					printf("Rolling\n");
					print_dice(sum_dice);
					Sleep(1 * 1000);
					printf(".");
					Sleep(1 * 1000);
					printf(".");
					Sleep(1 * 1000);
					printf(".\n");
					Sleep(1 * 1000);
					print_dice(sum_dice);
					add_sub = is_point_loss_or_neither(sum_dice, point_value, &count, &sum_dice);
					system("cls");
				} while (add_sub == -1);
			}

			balance = adjust_bank_balance(balance, wager, add_sub);
			do
			{
				system("cls");
				printf("Starting Balance:%.2lf\n", initial_balance);
				printf("Balance: %.2lf\n", balance);
				chatter_messages(count, initial_balance, balance);
				printf("\nContinue: \n1. Yes \n2. No\n");
				scanf("%d", &option);
				system("cls");
			} while ((option < 1) || (option > 2));
		}
	} while (option == 1);//edit541
	menu();
}


/*************************************************************
* Function: get_banK_balance()                    			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [gets bank balance]             			    *
* Input parameters: []                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
double get_bank_balance(void)
{
	double initial_bank_bal = 0;
	printf("Enter a bank balance: ");
	scanf("%lf", &initial_bank_bal);
	if (initial_bank_bal >= 0)
	{
		return initial_bank_bal;
	}
	do
	{
		system("cls");
		printf("Please enter a positive balance.\n");
		printf("Enter a bank balance: ");
		scanf("%lf", &initial_bank_bal);
	} while (initial_bank_bal < 0);
		return initial_bank_bal;
	
}

/*************************************************************
* Function: get_wager_amount()                    			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [gets wager ]                			    *
* Input parameters: []                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
double get_wager_amount(void)
{
	double wager = 0;
	printf("Enter a wager amount: \n");
	scanf("%lf", &wager);
	return wager;
}

/*************************************************************
* Function: check_wager_amount()                   			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [checks wager ]                			    *
* Input parameters: [wager,balance]        				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
int check_wager_amount(double wager, double balance)
{
	if (wager > balance)
	{
		return 0;
	}
	else if (wager <= balance)
	{
		return 1;
	}
}


/*************************************************************
* Function: roll_die()                          			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [rolls dice ]                			    *
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
* Function: calculate_sum_dice()                          			*
* Date Created:[10/6/2016]                                  *
* Date Last Modified:                                       *
* Description: [sums dice]                  			    *
* Input parameters: [dice1,dice2]                     				    *
* Returns: [N/a]											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
int calculate_sum_dice(int die1_value, int die2_value)
{
	int d_sum = die1_value + die2_value;
	return d_sum;
}


//FIRST ROLL
int is_win_loss_or_point(int sum_dice, int*point_value)
{
	if ((sum_dice == 7) || (sum_dice == 11))
	{
		printf("SICK ROLL BRO: WAGER WON\n");
		print_dice(sum_dice);
		Sleep(3 * 1000);
		return 1;
	}
	else if ((sum_dice == 2) || (sum_dice == 3) || (sum_dice == 12))
	{

		printf("THE ODDS WERE NOT IN YOUR FAVOR: WAGER LOST\n");
		print_dice(sum_dice);
		Sleep(3 * 1000);
		return 0;
	}
	else
	{
		printf("POINT\n");
		print_dice(sum_dice);
		Sleep(3 * 1000);
		*point_value = sum_dice;
		return -1;
	}
}

//SECOND ROLL
int is_point_loss_or_neither(int sum_dice, int point_value, int *count, int *dice)
{
	sum_dice = roll_die() + roll_die();
	*dice = sum_dice;
	*count += 1;
	if (sum_dice == point_value)
	{
		system("cls");
		printf("\nPOINT MADE\n");
		print_dice(sum_dice);
		Sleep(3 * 1000);
		system("cls");
		return 1;

	}
	else if (sum_dice == 7)
	{
		system("cls");
		printf("\nTHE ODDS WERE NOT IN YOUR FAVOR: WAGER LOST\n");
		print_dice(sum_dice);
		Sleep(3 * 1000);
		system("cls");
		return 0;
	}
	else
	{
		return -1;
	}

}


//MANIPULATES BANK BALANCE
double adjust_bank_balance(double bank_balance, double wager_amount, int check_wager)
{
	if (check_wager == 1)
	{
		bank_balance += wager_amount;
		return bank_balance;
	}
	else if (check_wager == 0)
	{
		bank_balance -= wager_amount;
		return bank_balance;
	}
	else
	{
		return bank_balance;
	}
}


//PRINTS CHATTER
void chatter_messages(int number_rolls, double initial_bank_balance, double current_bank_balance)
{
	if (number_rolls > 15)
	{
		printf("Number of Rolls Taken(so far): %d\n", number_rolls);
		printf("GOT A SLIGHT CASE OF GAMBLING ADDICTION\n");
		printf("\n");
	}
	else if (number_rolls >= 10)
	{
		printf("Number of Rolls Taken(so far): %d\n", number_rolls);
		printf("CAN\'T STOP, WON\'T STOP\n");
		printf("\n");
	}
	if (initial_bank_balance >= current_bank_balance)
	{
		printf("YOU DIDN\'T NEED THAT, DID YOU?\n");
		printf("\n");
	}
	else if (initial_bank_balance < current_bank_balance)
	{
		printf("QUIT WHILE YOU ARE AHEAD\n");
		printf("\n");
	}

}


//PRINTS DICE.
void print_dice(int sum_dice)
{
	if (sum_dice == 2)
	{
		printf("--------\n");
		printf("|      |\n");
		printf("|  ()  |\n");
		printf("|      |\n");
		printf("--------\n");
		printf("--------\n");
		printf("|      |\n");
		printf("|  ()  |\n");
		printf("|      |\n");
		printf("--------\n");



	}
	if (sum_dice == 3)
	{
		printf("--------\n");
		printf("|      |\n");
		printf("|  ()  |\n");
		printf("|      |\n");
		printf("--------\n");
		printf("--------\n");
		printf("|    ()|\n");
		printf("|      |\n");
		printf("|()    |\n");
		printf("--------\n");
	}
	if (sum_dice == 4)
	{
		printf("--------\n");
		printf("|    ()|\n");
		printf("|      |\n");
		printf("|()    |\n");
		printf("--------\n");
		printf("--------\n");
		printf("|    ()|\n");
		printf("|      |\n");
		printf("|()    |\n");
		printf("--------\n");
	}
	if (sum_dice == 5)
	{
		printf("--------\n");
		printf("|    ()|\n");
		printf("|      |\n");
		printf("|()    |\n");
		printf("--------\n");
		printf("--------\n");
		printf("|    ()|\n");
		printf("|  ()  |\n");
		printf("|()    |\n");
		printf("--------\n");
	}
	if (sum_dice == 6)
	{
		printf("--------\n");
		printf("|    ()|\n");
		printf("|  ()  |\n");
		printf("|()    |\n");
		printf("--------\n");
		printf("--------\n");
		printf("|    ()|\n");
		printf("|  ()  |\n");
		printf("|()    |\n");
		printf("--------\n");
	}
	if (sum_dice == 7)
	{
		printf("--------\n");
		printf("|    ()|\n");
		printf("|  ()  |\n");
		printf("|()    |\n");
		printf("--------\n");
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|      |\n");
		printf("|()  ()|\n");
		printf("--------\n");
	}
	if (sum_dice == 8)
	{
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|      |\n");
		printf("|()  ()|\n");
		printf("--------\n");
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|      |\n");
		printf("|()  ()|\n");
		printf("--------\n");
	}
	if (sum_dice == 9)
	{
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|      |\n");
		printf("|()  ()|\n");
		printf("--------\n");
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|  ()  |\n");
		printf("|()  ()|\n");
		printf("--------\n");
	}
	if (sum_dice == 10)
	{
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|  ()  |\n");
		printf("|()  ()|\n");
		printf("--------\n");
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|  ()  |\n");
		printf("|()  ()|\n");
		printf("--------\n");
	}
	if (sum_dice == 11)
	{
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|  ()  |\n");
		printf("|()  ()|\n");
		printf("--------\n");
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|()	 ()|\n");
		printf("|()  ()|\n");
		printf("--------\n");
	}
	if (sum_dice == 12)
	{
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|()	 ()|\n");
		printf("|()  ()|\n");
		printf("--------\n");
		printf("--------\n");
		printf("|()  ()|\n");
		printf("|()  ()|\n");
		printf("|()  ()|\n");
		printf("--------\n");
	}
}
