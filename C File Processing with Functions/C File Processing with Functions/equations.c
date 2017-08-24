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

/*************************************************************
* Function: open_input_file()                    			*
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: opens input file            					*
* Input parameters: []                     					*
* Returns: FILE*infile										*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
FILE * open_input_file(void)
{
	FILE * infile = NULL;
	infile = fopen("input.dat", "r");
	return infile;

}

/*************************************************************
* Function: open_output_file_stats()              			*
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: opens output file            				*
* Input parameters: [void]                     				*
* Returns: FILE*outfile										*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
FILE * open_output_file_stats(void)
{
	FILE * outfile = NULL;
	outfile = fopen("output_stats.dat", "w");
	return outfile;
}

/*************************************************************
* Function: open_output_file_ascii()              			*
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: opens output file            				*
* Input parameters: [void]                     				*
* Returns: FILE*outfile										*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
FILE * open_output_file_ascii(void)
{

	FILE * outfile = NULL;
	outfile = fopen("output_ascii.dat", "w");
	return outfile;
}

/*************************************************************
* Function: read_character()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: reads character from file
* Input parameters: [infile]                   				*
* Returns: character   										*
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
char read_character(FILE * infile)
{
	char letter = '\0';
	fscanf(infile, "%c", &letter);
	return letter;

}

/*************************************************************
* Function: determine_ascii_value()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determines ascii value
* Input parameters: [character]
* Returns: ascii value
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int determine_ascii_value(char character)
{
	int asc_val = character;
	return asc_val;

}

/*************************************************************
* Function: is_line()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is \n
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_line(char character)
{
	if (character == '\n')
	{
		return NOT_NEWLINE;
	}
	else
	{
		return NEWLINE;
	}
}

/*************************************************************
* Function: number_lines()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of lines
* Input parameters: [character,current_number_lines]
* Returns: number of lines
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_lines(char character, int number_of_lines)
{
	if (character == '\n')
	{
	    number_of_lines += 1;
		return number_of_lines;
	}
	else
	{
		return number_of_lines;
	}
}

/*************************************************************
* Function: is_vowel()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is vowel
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_vowel(char character)
{
	if ((character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U') || (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'))
	{
		return VOWEL;
	}
	else
	{
		return NOT_VOWEL;
	}
}

/*************************************************************
* Function: number_vowels()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of vowels
* Input parameters: [character,current_number_vowels]
* Returns: number of vowels
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_vowels(char character, int current_number_vowels)
{
	if ((character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U') || (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'))
	{
		(int)current_number_vowels += 1;
		return current_number_vowels;
	}
	else
	{
		return current_number_vowels;
	}
}

/*************************************************************
* Function: is_digit()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is digit
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_digit(char character)
{
	if (character >= '0' && character <= '9')
	{
		return DIGIT;
	}
	else
	{
		return NOT_DIGIT;
	}
}

/*************************************************************
* Function: number_digits()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of digits
* Input parameters: [character,current_number_digits]
* Returns: number of digits
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_digits(char character, int current_number_digits)
{
	if (character >= '0' && character <= '9')
	{
		current_number_digits += 1;
		return current_number_digits;
	}
	else
	{
		return current_number_digits;
	}
}

/*************************************************************
* Function: is_alpha()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is alpha
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_alpha(char character)
{
	if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))
	{
		return ALPHA;
	}
	else
	{
		return NOT_ALPHA;
	}
}

/*************************************************************
* Function: number_alphas()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of alphas
* Input parameters: [character,current_number_alphas]
* Returns: number of alphas
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_alphas(char character, int current_number_alphas)
{
	if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))
	{
		current_number_alphas += 1;
		return current_number_alphas;
	}
	else
	{
		return current_number_alphas;
	}
}

/*************************************************************
* Function: is_lower()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is lowercase
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_lower(char character)
{
	if (character >= 'a' && character <= 'z')
	{
		return LOWER;
	}
	else
	{
		return NOT_LOWER;
	}
}

/*************************************************************
* Function: number_lowers()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of lowers
* Input parameters: [character,current_number_lowers]
* Returns: number of lowers
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_lowers(char character, int current_number_lowers)
{
	if (character >= 'a' && character <= 'z')
	{
		current_number_lowers += 1;
		return current_number_lowers;
	}
	else
	{
		return current_number_lowers;
	}
}

/*************************************************************
* Function: is_upper()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is uppercase
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_upper(char character)
{
	if (character >= 'A' && character <= 'Z')
	{
		return UPPER;
	}
	else
	{
		return NOT_UPPER;
	}
}

/*************************************************************
* Function: number_uppers()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of upper
* Input parameters: [character,current_number_uppers]
* Returns: number of uppers
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_uppers(char character, int current_number_uppers)
{
	if (character >= 'A' && character <= 'Z')
	{
		current_number_uppers += 1;
		return current_number_uppers;
	}
	else
	{
		return current_number_uppers;
	}
}

/*************************************************************
* Function: is_space()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is space
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_space(char character)
{
	if (character == '\n' || character == '\t' || character == '\f' || character == '\v' || character == '\r' || character == ' ')
	{
		return WHITESPACE;
	}
	else
	{
		return NOT_WHITESPACE;
	}
}

/*************************************************************
* Function: number_spaces()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of spaces
* Input parameters: [character,current_number_spaces]
* Returns: number of spaces
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_spaces(char character, int current_number_spaces)
{
	if (character == '\n' || character == '\t' || character == '\f' || character == '\v' || character == '\r' || character == ' ')
	{
		current_number_spaces += 1;
		return current_number_spaces;
	}
	else
	{
		return current_number_spaces;
	}
}

/*************************************************************
* Function: is_alnum()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is alnum
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_alnum(char character)
{
	if ((character >= '0' && character <= '9') || ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')))
	{
		return ALNUM;
	}
	else
	{
		return NOT_ALNUM;
	}
}

/*************************************************************
* Function: number_alnums()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of alnums
* Input parameters: [character,current_number_alnums]
* Returns: number of alnums
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_alnums(char character, int current_number_alnums)
{
	if ((character >= '0' && character <= '9') || ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z')))
	{
		current_number_alnums += 1;
		return current_number_alnums;
	}
	else
	{
		return current_number_alnums;
	}
}

/*************************************************************
* Function: is_punct()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine if character is punct
* Input parameters: [character]
* Returns: TRUE/FALSE
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int is_punct(char character)
{
	if (character == '!' || character == '"' || character == ',' || character == '.' || character == ':' || character == ';'||character == '?')
	{
		return PUNCT;
	}
	else
	{
		return NOT_PUNCT;
	}
}

/*************************************************************
* Function: number_puncts()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: determine number of puncts
* Input parameters: [character,current_number_puncts]
* Returns: number of puncts
* Preconditions: input file must be open
* Postconditions:                                           *
*************************************************************/
int number_puncts(char character, int current_number_puncts)
{
	if (character == '!' || character == '"' || character == ',' || character == '.' || character == ':' || character == ';' || character == '?')
	{
		current_number_puncts += 1;
		return current_number_puncts;
	}
	else
	{
		return current_number_puncts;
	}
}

/*************************************************************
* Function: print_int()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: prints ascii value to file
* Input parameters: [outfile_ascii,ascii_value]
* Returns: void
* Preconditions: output file must be open
* Postconditions:                                           *
*************************************************************/
void print_int(FILE * outfile, int number)
{
	fprintf(outfile, "%d\n", number);
}

/*************************************************************
* Function: print_stats()
* Date Created:9/18/16                                  	*
* Date Last Modified:  9/20/16                              *
* Description: prints stats to file
* Input parameters: [outfile_stats,header[],value
* Returns: void
* Preconditions: output file must be open
* Postconditions:                                           *
*************************************************************/
void print_stats(FILE * outfile, char header[], int number)
{
	fprintf(outfile, "%s", header);
	fprintf(outfile, "%d\n", number);
}

