//* Programmer: Elliott Villars
//* Class : CptS 121; Lab Section 2
//* Programming Assignment : Programming Project [4]
//*
//* Date : 10/6/16
//	*
//	* Description : Craps 
//	*
//	* Relevant Formulas :N/a

#pragma once
#ifndef EQUATIONS
#define EQUATIONS

//included functions
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>

void print_game_rules(void);
void menu();
void play_game(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice,int *point_value);
int is_point_loss_or_neither(int sum_dice, int point_value, int *count, int *dice);
double adjust_bank_balance(double bank_balance, double wager_amount, int check_wager);
void chatter_messages(int number_rolls, double initial_bank_balance, double current_bank_balance);
void print_dice(int sum_dice);
#endif