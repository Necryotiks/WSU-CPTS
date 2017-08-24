#include "Header.h"

void menu(void)
{

	int option = 0;


	while ((option < 1) || (option > 6))
	{
		system("cls");
		printf("Interview Questions.\n");
		printf("Please select an option\n");
		printf("1. String Copy\n");
		printf("2. Binary Search\n");
		printf("3. Bubble Sort\n");
		printf("4. Palindrome Check\n");
		printf("5. Sum Primes\n");
		printf("6. Maximum Occurences\n");
		printf("7. Smallest Sum\n");
		scanf("%d", &option);
		printf("Press any key to confirm\n");
		scanf("%*s", &option);
		switch (option)
		{
		case 1: strcall();
			option = 0;
			break;
		case 2:bi_call();
			option = 0;
			break;
		case 3:bubblecall();
			option = 0;
			break;
		case 4:pal_call();
			option = 0;
			break;
		case 5:prime_call();
			option = 0;
			break;
		case 6: max_occur_call();//DOESN'T USE STRUCTS
			option = 0;
			break;
		case 7:min_sum_call();//NEED TO LOOP THROUGH MULTIPLE TIMES
			option = 0;
			break;
		}
		system("cls");
	}
}

char * my_str_n_cpy(char *dest, char *source, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (*(source + i) != '\0')
		{
			*(dest + i) = *(source + i);
		}
	}
	return dest;
}
void strcall(void)
{
	system("cls");
	char destination[6] = { '\0' };
	char * x = destination;
	char source[] = "Hello";
	char * y = source;
	int n;
	puts(source);
	printf("Enter number of characters of the above string to copy.\n");
	scanf("%d", &n);
	int test = my_str_n_cpy(x, y, n);
	printf(test);
	printf("\n");
	system("pause");
}
int binary_search(int list[], int target, int size)
{
	int left = 0;
	int right = size;
	int found = 0;
	int target_index = -1;
	int mid = (left + right) / 2;
	while ((found == 0) && (left <= right))
	{
		if (list[left] == target)
		{
			found = 1;
			target_index = left;
		}
		else if (list[right] == target)
		{
			found = 1;
			target_index = right;
		}

		else if (list[mid] == target)
		{
			found = 1;
			target_index = mid;
		}
		else if (list[mid] < target)
		{
			right = mid++;
		}
		else if (list[mid] > target)
		{
			left = mid--;
		}
		else if ((target < list[left]) || (target > list[right]))
		{
			target_index = -1;
		}
	}
	return(target_index);
}

void bi_call(void)
{
	int list[5] = { 1,2,3,4,5 };
	int target;
	printf("Enter a number between 1 and 5 to search for.\n");
	scanf("%d", &target);
	int size = sizeof(list) / sizeof(list[0]);
	int check = binary_search(list, target, size);
	if (check == -1)
	{
		printf("Target not found!\n");
	}
	else
	{
		printf("Target found at index: %d\n", check);
	}
	system("pause");
}

void bubble_sort(char *ptrarray[], int num_str)
{
	//ELLIOTT VILLARS
	int i = 0;
	char *swaparray = NULL;
	for (i = 0; i < num_str; i++)
	{
		for (int k = 0; k < num_str - i - 1; k++)
		{
			if (strcmp(ptrarray[k], ptrarray[k + 1]) > 0)
			{
				swaparray = ptrarray[k];
				ptrarray[k] = ptrarray[k + 1];
				ptrarray[k + 1] = swaparray;
			}
		}
	}
	for (int j = 0; j < num_str; j++)
	{
		puts(ptrarray[j]);
	}
}

void bubblecall(void)
{
	char alpha[] = "TEST";
	char * a = alpha;
	char alpha2[] = "DOG";
	char * b = alpha2;
	char alpha3[] = "BAT";
	char * c = alpha3;
	char *list_array[3] = { a,b,c };
	bubble_sort(list_array, 3);
	system("pause");
}

int is_palindrome(char * strptr, int i, int j)
{
	int palindrome = 0;
	if ((strptr[i] == ' ') && (i != j))
	{
		i++;
	}
	if ((strptr[j] == ' ') && (j != i))
	{
		j--;
	}
	if (strptr[i] != strptr[j])
	{
		printf("Is not palindrome.");
	}
	if (strptr[i] == strptr[j])
	{
		if (i == j)
		{
			printf("Is palindrome.");
			palindrome = 1;

		}
		else
		{
			return palindrome = is_palindrome(strptr, i + 1, j - 1);
		}
	}
	return palindrome;
}

void pal_call(void)
{
	char testarray[] = "race car";
	char * strptr = testarray;
	int i = 0;
	int j = strlen(testarray);
	int check = is_palindrome(strptr, i, j - 1);
	system("pause");
}

int sum_primes(unsigned int n)
{
	int sum;
	int i = 0;
	int prime_check = false;
	if (i = 1)
	{
		sum = 0;
	}
	if (n == 2)
	{
		sum = 2;
	}
	else
	{
		for (i = 2; i <= ((n / 2)+1); i++)
		{
			if (n%i == 0)
			{
				prime_check = false;
				break;
			}
			else
			{
				prime_check = true;
			}
		}
		if (prime_check == false)
		{

			sum += sum_primes(n - 1);
		}
		if (prime_check == true)
		{
			sum += sum_primes(n - 1) + n;
		}
	}
	return sum;
}
//BROKE AS FUCK
void prime_call(void)
{
	int num = 0;
	int sum = 0;
	printf("Enter a positive number: \n");
	scanf("%d", &num);
	int sp = sum_primes(num);
	printf("%d\n", sp);
	system("pause");
}

void maximum_occurences(char * strptr, Occurences * structptrarray, int * intptr, char * charptr)
{
	int i = 0;
	int length = strlen(strptr);
	for (i = 0; strptr[i] != '\0'; i++)
	{
		if (strptr[i] == ' ')
		{
			i++;
		}
		if (strptr[i] == *charptr)
		{
			*intptr += 1;
		}

	}
}

void max_occur_call(void)
{
	//Didnt use structures.
	system("cls");
	char teststring[] = "XENO PHOBIA";
	for (int i = 0; i < strlen(teststring); i++)
	{
		char * strptr = teststring;
		Occurences * num_occur = NULL;
		Occurences * freq = NULL;
		Occurences* structarray[2] = { num_occur,freq };
		int num = 0;
		int * intptr = &num;
		char c = '\0';
		c = teststring[i];
		char * charptr = &c;
		maximum_occurences(strptr, structarray, intptr, charptr);
		printf("\n");
		printf("Target: %c\n", c);
		printf("Number of Occurences: %d\n", num);
		printf("Frequency: %d/%d\n", num, strlen(teststring));
	}
	system("pause");
}

int smallest_sum_sequence(int numarray[], int size)
{
	int i, j, k, l = 0;
	int sum0 = 0;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sumend = numarray[size - 1];
	for (i = 0; i < size; i++)
	{
		sum0 += numarray[i];
	}
	for (j = 1; j < size; j++)
	{
		sum1 += numarray[j];
	}
	for (k = 2; k < size; k++)
	{
		sum2 += numarray[k];
	}
	for (l = 3; l < size; l++)
	{
		sum3 += numarray[l];
	}
	if ((sum0 <= sum1) && (sum0 <= sum2) && (sum0 <= sum3))
	{
		printf("Sum 0 is smallest: %d", sum0);
		return sum0;
	}
	if ((sum1 <= sum0) && (sum1 <= sum2) && (sum1 <= sum3))
	{
		printf("Sum 1 is smallest: %d", sum1);
		return sum1;
	}
	if ((sum2 <= sum0) && (sum2 <= sum1) && (sum2 <= sum3))
	{
		printf("Sum 2 is smallest: %d", sum2);
		return sum2;
	}
	if ((sum3 <= sum0) && (sum3 <= sum1) && (sum3 <= sum2))
	{
		printf("Sum 3 is smallest: %d", sum3);
		return sum3;
	}
	if ((sumend <= sum0) && (sumend <= sum1) && (sumend <= sum2) && (sumend <= sum3))
	{
		printf("The final term is the smallest: %d", sumend);
		return sumend;
	}
}
void min_sum_call(void)
{
	int array1[5] = { 5,-1,-2,-6,-3 };
	int smallnum = smallest_sum_sequence(array1, 5);
	system("pause");
}

//int smallest_sum_sequence(int nums[], int length)
//{
//	int i = 0, j = length - 1, smallest = 99999999;
//	while (i < j)
//	{
//		if (nums[i] < smallest)
//		{
//			smallest = nums[i];
//		}
//		if (nums[j] < smallest)
//		{
//			smallest = nums[j];
//		}
//		for (int k = 0; k <= j; k++)
//		{
//			int seq_total = 0;
//			for (int l = 0, m = j; l <= m; l++)
//			{
//				seq_total += nums[l];
//				if (seq_total < smallest)
//				{
//					smallest = seq_total;
//				}
//			}
//		}
//		for (int k = 0; k <= j; j--)
//		{
//			int seq_total = 0;
//			for (int l = 0, m = j; l <= m; m--)
//			{
//				seq_total += nums[m];
//				if (seq_total < smallest)
//				{
//					smallest = seq_total;
//				}
//			}
//		}
//		i++;
//		j--;
//	}
//	return smallest;
//}
