#include "Header.h"
//OPENS save file
FILE * savefile(void)
{
	FILE * save = fopen("save.txt", "r+");
	return save;
}
void load(FILE* save, char name[], int * score, int * challenge)
{
	char temp[100] = { '\0' };
	char swap[3] = { '\0' };
	char cswap[3] = { '\0' };
	while (!feof(save))
	{
		fgets(temp, 100, save);
		for (int i = 0; i < 3; i++)
		{
			name[i] = temp[i + 6];
		}
		fgets(temp, 100, save);
		for (int j = 0; j < 2; j++)
		{
			swap[j] = temp[j + 7];
		}
		swap[2] = '\0';
		int c = atoi(swap);
		*score = c;
		fgets(temp, 100, save);
		for (int k = 0; k < 2; k++)
		{
			cswap[k] = temp[k + 12];
		}
		cswap[2] = '\0';
		c = atoi(cswap);
		*challenge = c;
	}
}
//Prints Tutorial
void tutorial(int challenge, int score, char name[])
{
	char intro[] = { "This program will generate mathmatical problems based on difficulty with five levels of difficuly:\n\na. Level 1 - Easy: Includes addition and subtraction problems, with positive single digit operands and up to three terms only (i.e. d1 + d2 - d3  = ) \n\nb.Level 2 - Fair: Includes multiplication problems, with positive single digit operands and up to two terms only(i.e.d1 x d2 = )\n\nc.Level 3 - Intermediate : Includes division problems, with positive single digit operands and up to two terms only(i.e.d1 / d2 = );Note: results should be shown in the form Num R Remainder, i.e. if the problem is 5 / 3, then the answer should be provided as 1 R 2.\n\nd.Level 4 - Hard : Includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative single digit operands and up to three terms only(i.e.d1 + -d2 / d3 = ); Hint: you may have to first find a common denominator.\n\ne.Level 5 - Impossible : Includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative two and three digit operands and up to four terms only(i.e.dd1 + -ddd2 x ddd3 / dd4 = );Hint: you may have to first find a common denominator. You will gain 1 point for each correct answer and lose 1 point for each incorrect answer." };
	puts(intro);
	system("pause");
}
//Receives user initals
void name_write(FILE * savefile, int challenge, int score, char name[])
{
	printf("Enter your initals(First,Middle,Last):\n");
	char letter = '\0';
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		scanf(" %c", &letter);
		name[i] = letter;
	}
	name[3] = '\0';
	system("pause");
}
//Changes difficulty
void difficulty(int *challenge, int score, char name[])
{
	int diff = 0;
	do
	{

		printf("Select a difficulty:\n");
		printf("1.Easy\n");
		printf("2.Fair\n");
		printf("3.Intermediate\n");
		printf("4.Hard\n");
		printf("5.Impossible\n");
		scanf("%d", &diff);
		printf("Confirm by pressing a key");
		scanf("%*s", &diff);
		system("cls");


	} while (diff < 1 || diff>5);
	*challenge = diff;

}
//Generates problems
void problem_generation(int challenge, int *score, char name[])
{
	if (challenge == 1)
	{
		int num_prob = 0;
		int count = 1;
		int cpu_answer;
		int usr_answer;
		int term1, term2, term3 = 0;
		printf("Level 1\-Easy\n");
		printf("How many problems would you like to solve?\n");
		scanf("%d", &num_prob);
		while (count <= num_prob)
		{
			term1 = rand() % 10;
			term2 = rand() % 10;
			term3 = rand() % 10;
			int selector = rand() % 9;
			if (selector == 1)
			{
				cpu_answer = term1 + term2;
				printf("%d + %d = ", term1, term2);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
					*score += 1;

				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
					*score -= 1;
				}

			}
			else if (selector == 2)
			{
				cpu_answer = term1 - term2;
				printf("%d - %d = ", term1, term2);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
					*score += 1;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
					*score -= 1;

				}
			}
			else if (selector == 3)
			{
				cpu_answer = term1 + term2 + term3;
				printf("%d + %d + %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
					*score += 1;

				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
					*score -= 1;

				}
			}
			else if (selector == 4)
			{
				cpu_answer = term1 + term2 - term3;
				printf("%d + %d - %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
					*score += 1;

				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
					*score -= 1;

				}
			}
			else if (selector == 5)
			{
				cpu_answer = term1 - term2 + term3;
				printf("%d - %d + %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
					*score += 1;

				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
					*score -= 1;

				}
			}
			else if (selector == 6)
			{
				cpu_answer = term1 - term2 - term3;
				printf("%d - %d - %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
					*score += 1;

				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
					*score -= 1;

				}
			}

		}

	}
	else if (challenge == 2)
	{
		int num_prob = 0;
		int count = 1;
		int cpu_answer;
		int usr_answer;
		int term1, term2, term3 = 0;
		printf("Level 2\-Fair\n");
		printf("How many problems would you like to solve?/n");
		scanf("%d", &num_prob);
		while (count <= num_prob)
		{
			term1 = rand() % 10;
			term2 = rand() % 10;
			cpu_answer = term1*term2;
			printf("%d * %d =", term1, term2);
			scanf("%d", &usr_answer);
			if (usr_answer == cpu_answer)
			{
				printf("Correct Answer\n");
				count++;
			}
			else
			{
				printf("Incorrect Answer\n");
				printf("Answer: %d", cpu_answer);
				count++;
			}
		}
	}
	else if (challenge == 3)
	{
		int num_prob = 0;
		int count = 1;
		int cpu_answer;
		int usr_answer;
		int cpu_mod_answer;
		int usr_mod_answer;
		int term1, term2, term3 = 0;
		printf("Level 3\-Intermediate\n");
		printf("How many problems would you like to solve?/n");
		scanf("%d", &num_prob);
		while (count <= num_prob)
		{
			term1 = rand() % 10;
			term2 = rand() % 10;
			cpu_answer = term1 / term2;
			cpu_mod_answer = term1 % term2;
			printf("%d / %d =", term1, term2);
			scanf("%d\n", &usr_answer);
			printf("Remainder: \n");
			scanf("%d\n", &usr_mod_answer);
			if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
			{
				printf("Correct Answer\n");
				count++;
			}
			else
			{
				printf("Incorrect Answer\n");
				printf("Answer: %d", cpu_answer);
				printf("Remainder %d", cpu_mod_answer);
				count++;
			}
		}
	}
	else if (challenge == 4)
	{
		int num_prob = 0;//FINISH
		int count = 1;
		int cpu_answer;
		int usr_answer;
		int term1, term2, term3 = 0;
		printf("Level 4\-Hard\n");
		printf("How many problems would you like to solve?/n");
		scanf("%d", &num_prob);
		while (count <= num_prob)
		{
			term1 = rand() % 19 + (-9);
			term2 = rand() % 19 + (-9);
			term3 = rand() % 19 + (-9);
			int selector = rand() % 13;
			if (selector == 1)
			{
				cpu_answer = term1 + term2 + term3;
				printf("%d + %d + %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}

			}
			else if (selector == 2)
			{
				cpu_answer = term1 - term2 - term3;
				printf("%d - %d - %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 3)
			{
				cpu_answer = term1 + term2 + term3;
				printf("%d + %d + %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 4)
			{
				cpu_answer = term1 + term2 - term3;
				printf("%d + %d - %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 5)
			{
				cpu_answer = term1 - term2 + term3;
				printf("%d - %d + %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 6)
			{
				cpu_answer = term1 - term2 - term3;
				printf("%d - %d - %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 7)
			{
				cpu_answer = (term1 * term2) - term3;
				printf("%d * %d - %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 8)
			{
				cpu_answer = term1 * (term2 - term3);
				printf("%d * (%d - %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 9)
			{
				cpu_answer = term1 * (term2 + term3);
				printf("%d * (%d + %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 10)
			{
				cpu_answer = term1 * (term2 * term3);
				printf("%d * (%d * %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 10)
			{
				cpu_answer = term1 / (term2 * term3);
				int cpu_mod_answer = term1 % (term2 * term3);
				int usr_mod_answer;
				printf("%d / (%d * %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND inside then mod outside): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 11)
			{
				cpu_answer = term1 / (term2 / term3);
				int cpu_mod_answer = term1 % (term2 / term3);
				int usr_mod_answer;
				printf("%d / (%d / %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				printf("Remainder(integer division inside, mod outside): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 12)
			{
				cpu_answer = term1 * (term2 / term3);
				int cpu_mod_answer = (term2 % term3);
				int usr_mod_answer;
				printf("%d * (%d / %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				printf("Remainder(mod inside only): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}

		}
	}
	else if (challenge == 5)
	{
		int num_prob = 0;
		int count = 1;
		int cpu_answer;
		int usr_answer;
		int term1, term2, term3, term4 = 0;
		printf("Level 5\-Impossible\n");
		printf("How many problems would you like to solve?/n");
		scanf("%d", &num_prob);
		while (count <= num_prob)
		{
			term1 = rand() % 199 + (-99);
			term2 = rand() % 199 + (-99);
			term3 = rand() % 199 + (-99);
			term4 = rand() % 199 + (-99);
			int selector = rand() % 34;
			if (selector == 1)
			{
				cpu_answer = term1 + term2 + term3;
				printf("%d + %d + %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}

			}
			else if (selector == 2)
			{
				cpu_answer = term1 - term2 - term3;
				printf("%d - %d - %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 3)
			{
				cpu_answer = term1 + term2 + term3;
				printf("%d + %d + %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 4)
			{
				cpu_answer = term1 + term2 - term3;
				printf("%d + %d - %d = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 5)
			{
				cpu_answer = term1 - term2 + term3;
				printf("%d - %d + %d = ", term1, term2, term3);
				scanf("%d\n", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 6)
			{
				cpu_answer = term1 - term2 - term3;
				printf("%d - %d - %d = ", term1, term2, term3);
				scanf("%d\n", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 7)
			{
				cpu_answer = (term1 * term2) - term3;
				printf("%d * %d - %d = ", term1, term2, term3);
				scanf("%d\n", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 8)
			{
				cpu_answer = term1 * (term2 - term3);
				printf("%d * (%d - %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 9)
			{
				cpu_answer = term1 * (term2 + term3);
				printf("%d * (%d + %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 10)
			{
				cpu_answer = term1 * (term2 * term3);
				printf("%d * (%d * %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 10)
			{
				cpu_answer = term1 / (term2 * term3);
				int cpu_mod_answer = term1 % (term2 * term3);
				int usr_mod_answer;
				printf("%d / (%d * %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND inside first then mod): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 11)
			{
				cpu_answer = term1 / (term2 / term3);
				int cpu_mod_answer = term1 % (term2 / term3);
				int usr_mod_answer;
				printf("%d / (%d / %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				printf("Remainder(integer division inside brackets with mod outside): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 12)
			{
				cpu_answer = term1 * (term2 / term3);
				int cpu_mod_answer = term1 * (term2 % term3);
				int usr_mod_answer;
				printf("%d / (%d * %d) = ", term1, term2, term3);
				scanf("%d", &usr_answer);
				printf("Remainder: ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			if (selector == 13)
			{
				cpu_answer = term1 + term2 + term3 + term4;
				printf("%d + %d + %d + %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}

			}
			else if (selector == 14)
			{
				cpu_answer = term1 - term2 - term3 - term4;
				printf("%d - %d - %d- %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 15)
			{
				cpu_answer = (term1 * term2) + term3 - term4;
				printf("(%d * %d) + %d - %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 16)
			{
				cpu_answer = term1 + term2 - term3 + term4;
				printf("%d + %d - %d + %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 17)
			{
				cpu_answer = term1 - term2 + term3*term4;
				printf("%d - %d + (%d * %d) = ", term1, term2, term3, term4);
				scanf("%d\n", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 18)
			{
				cpu_answer = term1 - term2 - term3 + term4;
				printf("%d - %d - %d + %d = ", term1, term2, term3, term4);
				scanf("%d\n", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 19)
			{
				cpu_answer = (term1 * term2) - term3 *term4;
				printf("%d * %d - %d * %d = ", term1, term2, term3, term4);
				scanf("%d\n", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 20)
			{
				cpu_answer = term1 * (term2 - term3)*term4;
				printf("%d * (%d - %d) * %d= ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 21)
			{
				cpu_answer = term1 * (term2 + term3)* term4;
				printf("%d * (%d + %d) * %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 22)
			{
				cpu_answer = term1 * (term2 * term3) - term4;
				printf("%d * (%d * %d) - %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 23)
			{
				cpu_answer = term1 / (term2 * term3) + term4;
				int cpu_mod_answer = term1 % (term2 * term3) + term4;
				int usr_mod_answer;
				printf("(%d / (%d * %d)) + %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND mod of inside group): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 24)
			{
				cpu_answer = term1 / (term2 / term3) + term4;
				int cpu_mod_answer = term1 % (term2 % term3);
				int usr_mod_answer;
				printf("%d / (%d / %d) + %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(Hint: Mod inside then outside): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 25)
			{
				cpu_answer = term1 * (term2 / term3) - term4;
				int cpu_mod_answer = (term2 % term3);
				int usr_mod_answer;
				printf("%d * (%d / %d) - %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(Hint: Only mod inside group): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 26)
			{
				cpu_answer = term1 - (term2 / term3) - term4;
				int cpu_mod_answer = (term2 % term3);
				int usr_mod_answer;
				printf("%d - (%d / %d) - %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND remainder inside only): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 27)
			{
				cpu_answer = (term1 * term2) * term3 * term4;
				printf("%d * %d * %d * %d = ", term1, term2, term3, term4);
				scanf("%d\n", &usr_answer);
				if (usr_answer == cpu_answer)
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					count++;
				}
			}
			else if (selector == 28)
			{
				cpu_answer = term1 / (term2 / term3) / term4;
				int cpu_mod_answer = (term1 % (term2 % term3)) % term4;
				int usr_mod_answer;
				printf("(%d / (%d / %d)) / %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND remainder inside out first,MOD EVERYTHING): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 29)
			{
				cpu_answer = term1 / (term2 / term3) * term4;
				int cpu_mod_answer = (term1 % (term2 % term3));
				int usr_mod_answer;
				printf("(%d / (%d / %d)) * %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND remainder inside brackets only): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 30)
			{
				cpu_answer = term1 / (term2 / term3) + term4;
				int cpu_mod_answer = (term1 % (term2 % term3));
				int usr_mod_answer;
				printf("(%d / (%d / %d)) + %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND remainder inside out first): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 31)
			{
				cpu_answer = (term1 + (term2 / term3)) + term4;
				int cpu_mod_answer = (term2 % term3);
				int usr_mod_answer;
				printf("(%d +(%d / %d)) + %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND remainder inside ): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 32)
			{
				cpu_answer = (term1 - (term2 / term3)) + term4;
				int cpu_mod_answer = (term2 % term3);
				int usr_mod_answer;
				printf("(%d -(%d / %d)) + %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND remainder inside): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
			else if (selector == 33)
			{
				cpu_answer = (term1 * (term2 / term3)) * term4;
				int cpu_mod_answer = (term2 % term3);
				int usr_mod_answer;
				printf("(%d * (%d / %d)) * %d = ", term1, term2, term3, term4);
				scanf("%d", &usr_answer);
				printf("Remainder(FIND remainder inside): ");
				scanf("%d", &usr_mod_answer);
				if ((usr_answer == cpu_answer) && (usr_mod_answer == cpu_mod_answer))
				{
					printf("Correct Answer\n");
					count++;
				}
				else
				{
					printf("Incorrect Answer\n");
					printf("Answer: %d", cpu_answer);
					printf("Remainder %d", cpu_mod_answer);
					count++;
				}
			}
		}

	}
	system("pause");
}
// Menu
void menu(int challenge, int score, char name[], FILE* save)
{

	int option = 0;


	while ((option < 1) || (option > 5))
	{
		system("cls");
		printf("MATH HELP\n");
		printf("MENU\n");
		printf("Current Difficulty Level : %d\n", challenge);
		printf("Current Score: %d \n", score);
		printf("1. Learn about how to use the program\n");
		printf("2. Enter your first 3 initials\n");
		printf("3. Difficulty selection\n");
		printf("4. Start a new sequence of problems\n");
		printf("5. Save and Quit\n");
		scanf("%d", &option);
		printf("Press any key to confirm\n");
		scanf("%*s", &option);
		switch (option)
		{
		case 1: tutorial(challenge, score, name);
			option = 0;
			break;
		case 2:name_write(save, challenge, score, name);
			option = 0;
			break;
		case 3:difficulty(&challenge, score, name);
			option = 0;
			break;
		case 4:problem_generation(challenge, &score, name);
			option = 0;
			break;
		case 5:save_quit(save, score, challenge, name);
			break;
		}
		system("cls");
	}
}

//Saves data
void save_quit(FILE * save, int score, int challenge, char name[])
{
	fprintf(save, "Name: ");
	fputs(name, save);
	fprintf(save, "\nScore: %d", score);
	fprintf(save, "\nDifficulty: %d", challenge);
	fclose(save);
}
