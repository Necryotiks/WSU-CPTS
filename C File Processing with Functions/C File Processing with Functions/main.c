//* Programmer: Elliott Villars
//* Class : CptS 121; Lab Section 2
//* Programming Assignment : Programming Project [3]
//*
//* Date :9/20/16
//	*
//	* Description : File Processor
//	*
//	* Relevant Formulas : N/A
#include "equations.h"
int main(void)
{
	FILE *infile = open_input_file();// Opens input file
	FILE *outfile_stats = open_output_file_stats();//opens output_stats file
	FILE *outfile_ascii = open_output_file_ascii();//opens output_ascii file
	int number_of_lines = 1, number_of_vowels = 0, number_of_digits = 0, number_of_alphas = 0, number_of_lowers = 0, number_of_uppers = 0, number_of_spaces = 0, number_of_alnums = 0, number_of_punct = 0;//defines variables
	//CYCLE 1
	char character = read_character(infile);
	int asc_value = determine_ascii_value(character);
	int line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	int vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	int digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	int alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	int lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	int upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	int space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	int alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	int punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 2
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 3
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 4
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 5
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 6
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 7
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 8
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 9
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 10
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 11
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//CYCLE 12
	character = read_character(infile);
	asc_value = determine_ascii_value(character);
	line = is_line(character);
	number_of_lines = number_lines(character, number_of_lines);
	vowel = is_vowel(character);
	number_of_vowels = number_vowels(character, number_of_vowels);
	digit = is_digit(character);
	number_of_digits = number_digits(character, number_of_digits);
	alfa = is_alpha(character);
	number_of_alphas = number_alphas(character, number_of_alphas);
	lower = is_lower(character);
	number_of_lowers = number_lowers(character, number_of_lowers);
	upper = is_upper(character);
	number_of_uppers = number_uppers(character, number_of_uppers);
	space = is_space(character);
	number_of_spaces = number_spaces(character, number_of_spaces);
	alnum = is_alnum(character);
	number_of_alnums = number_alnums(character, number_of_alnums);
	punct = is_punct(character);
	number_of_punct = number_puncts(character, number_of_punct);
	print_int(outfile_ascii, asc_value);
	//OUTPUT
	char header1[] = { "Number of Lines: " };
	print_stats(outfile_stats, header1, number_of_lines);
	char header2[] = { "Number of Vowels: " };
	print_stats(outfile_stats, header2, number_of_vowels);
	char header3[] = { "Number of digits: " };
	print_stats(outfile_stats, header3, number_of_digits);
	char header4[] = { "Number of Alphas: " };
	print_stats(outfile_stats, header4, number_of_alphas);
	char header5[] = { "Number of Lowers: " };
	print_stats(outfile_stats, header5, number_of_lowers);
	char header6[] = { "Number of uppers: " };
	print_stats(outfile_stats, header6, number_of_uppers);
	char header7[] = { "Number of Spaces: " };
	print_stats(outfile_stats, header7, number_of_spaces);
	char header8[] = { "Number of Alnum: " };
	print_stats(outfile_stats, header8, number_of_alnums);
	char header9[] = { "Number of punct: " };
	print_stats(outfile_stats, header9, number_of_punct);
	fclose(infile);//
	fclose(outfile_ascii);//CLOSE FILES
	fclose(outfile_stats);//
	return 0;
}