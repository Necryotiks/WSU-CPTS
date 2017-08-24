#pragma once
#ifndef INTERVIEW
#define INTERVIEW
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void menu(void);
char * my_str_n_cpy(char *dest, char *source, int n);
void strcall(void);
int binary_search(int list[], int target, int size);
void bi_call(void);
void bubble_sort(char *ptrarray[], int num_str);
void bubblecall(void);
int is_palindrome(char * strptr, int i, int j);
void pal_call(void);
int sum_primes(unsigned int n);
void prime_call(void);
typedef struct occurences
{
	int num_occurences;
	double frequency;
}Occurences;
void maximum_occurences(char * strptr, Occurences* structptrarray, int * intptr, char* charptr);
void max_occur_call(void);
int smallest_sum_sequence(int numarray[], int size);
void min_sum_call(void);
#endif