#include "Header.h"

FILE * log(void)
{
	FILE * log = fopen("battleship.log", "w");
	return log;
}

void print_game_rules(void)
{
	char rules_objective[] = ("The object of Battleship is to try and sink all of the other player's before they sink all of your ships. All of the other player's ships are somewhere on his/her board.  You try and hit them by calling out the coordinates of one of the squares on the board.  The other player also tries to hit your ships by calling out coordinates.  Neither you nor the other player can see the other's board so you must try to guess where they are.  Each board in the physical game has two grids:  the lower (horizontal) section for the player's ships and the upper part (vertical during play) for recording the player's guesses.");
	char rules_new_game[] = ("Each player places the 5 ships somewhere on their board.  The ships can only be placed vertically or horizontally. Diagonal placement is not allowed. No part of a ship may hang off the edge of the board.  Ships may not overlap each other.  No ships may be placed on another ship. Once the guessing begins, the players may not move the ships.The 5 ships are : Carrier(occupies 5 spaces), Battleship(4), Cruiser(3), Submarine(3), and Destroyer(2).  ");
	char rules_play[] = ("Player's take turns guessing by calling out the coordinates. The opponent responds with \"hit\" or \"miss\" as appropriate.  Both players should mark their board with pegs:  red for hit, white for miss. For example, if you call out F6 and your opponent does not have any ship located at F6, your opponent would respond with \"miss\".  You record the miss F6 by placing a white peg on the lower part of your board at F6.  Your opponent records the miss by placing.When all of the squares that one your ships occupies have been hit, the ship will be sunk.You should announce \"hit and sunk\".In the physical game, a red peg is placed on the top edge of the vertical board to indicate a sunk ship.As soon as all of one player's ships have been sunk, the game ends.");
	puts(rules_objective);
	printf("\n");
	puts(rules_new_game);
	printf("\n");
	puts(rules_play);
	system("pause");
	menu();
}

void menu()
{
	int option;
	do
	{
		system("cls");
		printf("*****BATTLESHIP*****\n");
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
	//IDIOT PROOF MENU
}

void play_game(void)
{
	char p1_board[10][10] = { { '\0', '~' },{ '~' } }, p2_board[10][10] = { '\0' };

	init_board(p1_board, 10, 10); // set each cell in the 2-D array to the water '~' symbol
	init_board(p2_board, 10, 10);
	putchar('\n');
	print_board(p1_board, 10, 10);
	putchar('\n');
	print_board(p2_board, 10, 10);
}

void init_board(char board[][10], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < rows; ++row_index) // controls which row
	{
		for (col_index = 0; col_index < cols; ++col_index) // controls which column
		{
			board[row_index][col_index] = '~';
		}
	}
}

void print_board(char board[][10], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < rows; ++row_index) // controls which row
	{
		for (col_index = 0; col_index < cols; ++col_index) // controls which column
		{
			printf("%c ", board[row_index][col_index]);
		}
		putchar('\n');
	}
}
