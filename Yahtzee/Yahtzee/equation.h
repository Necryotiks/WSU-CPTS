//* Programmer: Elliott Villars
//* Class : CptS 121; Lab Section 2
//* Programming Assignment : Programming Project [5]
//*
//* Date : 10/21/16
//	*
//	* Description : Yahtzee
//	*
//	* Relevant Formulas :N/a
#pragma once
#ifndef YAHTZEE
#define YAHTZEE
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>

FILE*scorecardp1(void);
FILE*scorecardp2(void);
void print_game_rules(void);
void menu();
void play_game_p1(void);
void roll_dice(int dice[], int size);
int roll_die(void);
void reroll_dice(int dice[], int reroll);
void print_dice(int *dice_ptr, int size);
void count_dice(int dice[], int size, int dice_value_count[], int size_count);
void print_scorecard(FILE*scorecard, int dice_value_count[], int choice[]);
int choice_track(int choice[], int choice_size, int value);//call this within score_allocation()
void score_allocation(int choice[], int dice_value_count[], int *sum,int dice[]);
void purge_array(int dice_value_count[],int size);
int three_of_kind_check(int dice_value_count[]);
int four_of_kind_check(int dice_value_count[]);
int full_house_check(int dice_value_count[]);
int small_straight_check(int dice_value_count[]);
int large_straight_check(int dice_value_count[]);
int yahtzee(int dice_value_count[]);
void print_score_p1(FILE*scorecard, int dice_value_count_p1[], int sum_p1, int dice_p1[]);
void print_score_p2(FILE*scorecard, int dice_value_count_p2[], int sum_p2, int dice_p2[]);
void winner(int sum_p1, int sum_p2);
#endif