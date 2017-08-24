//* Programmer: Elliott Villars
//* Class : CptS 121; Lab Section 2
//* Programming Assignment : Programming Project [3]
//*
//* Date :9/20/16
//	*
//	* Description : File Processor
//	*
//	* Relevant Formulas : N/A
#pragma once
#include <stdio.h>
#define NEWLINE 1
#define NOT_NEWLINE 0
#define VOWEL 2
#define NOT_VOWEL 0
#define DIGIT 3
#define NOT_DIGIT 0
#define ALPHA 4
#define NOT_ALPHA 0
#define LOWER 5
#define NOT_LOWER 0
#define UPPER 6
#define NOT_UPPER 0
#define WHITESPACE 7
#define NOT_WHITESPACE 0
#define ALNUM 8
#define NOT_ALNUM 0 
#define PUNCT 9
#define NOT_PUNCT 0


FILE * open_input_file(void);


FILE * open_output_file_stats(void);


FILE * open_output_file_ascii(void);


char read_character(FILE *infile);


int determine_ascii_value(char character);


int is_line(char character);


int number_lines(char character, int current_number_lines);


int is_vowel(char character);


int number_vowels(char character, int current_number_vowels);


int is_digit(char character);


int number_digits(char character, int current_number_digits);


int is_alpha(char character);


int number_alphas(char character, int current_number_alphas);


int is_lower(char character);


int number_lowers(char character, int current_number_lowers);


int is_upper(char character);


int number_uppers(char character, int current_number_uppers);


int is_space(char character);


int number_spaces(char character, int current_number_spaces);


int is_alnum(char character);


int number_alnums(char character, int current_number_alnums);


int is_punct(char character);


int number_puncts(char character, int current_number_puncts);


void print_int(FILE *outfile, int number);


void print_stats(FILE *outfile, char header[], int number);



