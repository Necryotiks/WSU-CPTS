#pragma once
#ifndef BATTLESHIP
#define BATTLESHIP
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>
#include <string.h>

FILE* log(void);
void print_game_rules(void);
void menu();
void play_game(void);
void init_board(char board[][10], int rows, int cols);
void print_board(char board[][10], int rows, int cols);


#endif