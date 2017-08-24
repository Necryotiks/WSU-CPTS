//ELLIOTT VILLARS
#ifndef MATHHELP
#define MATHHELP
#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS 1

FILE * savefile(void);
void load(FILE* save, char name[], int * score, int* challenge);
void tutorial(int challenge, int score, char name[]);
void name_write(FILE*savefile, int challenge, int score, char name[]);
void difficulty(int *challenge, int score, char name[]);
void problem_generation(int challenge, int * score, char name[]);
void menu(int challenge, int score, char name[],FILE *save);
void save_quit(FILE* save, int score, int challenge, char name[]);

#endif
