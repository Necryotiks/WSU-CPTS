#include "Header.h"

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
int binary_search(int list[], int target, int size)
{
	int left = 0;
	int right = size;
	int found = 0;
	int target_index = -1;
	while ((found == 0) && (left <= right))
	{
		int mid = (left + right) / 2;
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
			right = mid + 1;
		}
		else if (list[mid] > target)
		{
			left = mid - 1;
		}
	}
	return(target_index);
}

void bubble_sort(int ptrarray[], int num_str)
{
	int j = 0;
	int i = 0;
	char swaparray[2] = { '\0' };
	for (i = 0; i < num_str; i++)
	{
			if (strcmp(ptrarray[i],ptrarray[i+1]) > 0)
			{ 
				swaparray[0] = ptrarray[i];
				ptrarray[i] = ptrarray[i+1];
				ptrarray[i+1] = swaparray[0];
			}

	}
}
//UNFINSIHED
int is_palindrome(char * strptr, int i, int j)
{
	// i !=j
	if ((strptr[i] == " ") && (i != j))
	{
		i++;
	}
	if ((strptr[j] == " ") && (j != i))
	{
		j--;
	}
	if (strptr[i] != strptr[j])
	{
		printf("Is not palindrome.");
		return 0;
	}
	if (strptr[i] == strptr[j])
	{
		if (i = j)
		{
			return 1;
		}
		else
		{
			return is_palindrome(strptr, i++, j--);
		}
	}

}

int sum_primes(unsigned int n)
{
	;
}

/*int alt_binary_search(int list[], int target, int n, int i, int j)
{
int found = 0;
if ((target==list[i]) || (target==list[j]))
{
found = 1;
printf("found at %d", i);
return i;
}
else
{
alt_binary_search(list, target, n, i++, j--);
if ((i == j) && (target != list[i]) && (target != list[j]))
{
printf("not found");
}
}
}
*/