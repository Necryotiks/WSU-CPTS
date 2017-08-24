//* Programmer: Elliott Villars
//* Class : CptS 121; Lab Section 2
//* Programming Assignment : Programming Project 2
//*
//* Date :9/14/16
//	*
//	* Description : This program calculates 7 equations from PA 1 and modulates them.
//	*
//	* Relevant Formulas :
//Newton’s Second Law of Motion : force = mass * acceleration
//Volume of a cylinder : volume_cylinder = PI * radius2 * height
//Character encoding : encoded_character = (plaintext_character - 'A') + 'a' – shift(note : what happens if plaintext_character is uppercase ? What happens with various shift keys ? )
//Equivalent parallel resistance : parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors.R1, R2, and R3 are integers.
//Resistive divider : vout = R2 / (R1 + R2) * vin(note : be sure to prompt for new R values; do not use the ones provided for equation 4)
//Distance between two points : distance = square root of((x1 - x2)2 + (y1 - y2)2) (note : you will need to use sqrt() from <math.h>)
//General equation : y = -x * (3 / 4) - z + a / (a % 2) (recall : a is an integer; the 3 and 4 constants in the equation should be left as integers initially, but explicitly type - casted as floating - point values
#include "equations.h"

/*************************************************************
* Function: calculates_newtons_2nd_law()                    *
* Date Created:9/14/16                                      *
* Date Last Modified:                                       *
* Description: calculates newtons second law                *
* Input parameters: mass,acceleration                       *
* Returns: force											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
double calculate_newtons_2nd_law(double mass, double acc)
{
	return mass*acc;
}


/*************************************************************
* Function: calculate_volume_cylinder()						*
* Date Created: 9/14/2016                                   *
* Date Last Modified:                                       *
* Description: calculates cylinder volume					*
* Input parameters:radius,height   						    *
* Returns: volume											*
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
double calculate_volume_cylinder(double radius, double height)
{
	return PI * (radius*radius)*height;
}


/*************************************************************
* Function: preform_character_encoding()					*
* Date Created:9/14/16                                      *
* Date Last Modified:                                       *
* Description: Encodes an entered character                 *
* Input parameters:A character,Shift value					*
* Returns: New character                                    *
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
char perform_character_encoding(char plaintext_chara, int shift)
{
	return plaintext_chara - 'A' + 'a' - shift;
}


/*************************************************************
* Function: calculate_parallel_resistance()                 *
* Date Created:9/14/16                                      *
* Date Last Modified:                                       *
* Description:  calculates parallel resistance				*
* Input parameters: Resistor values	                        *
* Returns: Parrallel resistance                             *
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
double calculate_parallel_resistance(int resist1, int resist2, int resist3)
{
	double total_resist = (1 / (double)resist1) + (1 / (double)resist2) + (1 / (double)resist3);
	return 1 / total_resist;
}


/*************************************************************
* Function: calculate_resistive_divider()                   *
* Date Created:9/14/16                                      *
* Date Last Modified:                                       *
* Description: calculates voltage out                       *
* Input parameters: resis1,resist2,vin		                *
* Returns: Vout		                                        *
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
double calculate_resistive_divider(int r1, int r2, double vin)
{
	double vout= (((double)r2 / ((double)r1 + (double)r2)))*vin;
	return vout;
}


/*************************************************************
* Function: calculate_distance_between_2pts()               *
* Date Created:9/14/16                                      *
* Date Last Modified:                                       *
* Description: distance formula                             *
* Input parameters: x1,x2,y1,y2                             *
* Returns: distance between 2 points                        *
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2)
{
	double xelement = ((x2 - x1)*(x2 - x1));
	double yelement = ((y2 - y1)*(y2 - y1));
	return sqrt(xelement + yelement);
}


/*************************************************************
* Function: general_equation()                              *
* Date Created:9/14/16                                      *
* Date Last Modified:                                       *
* Description: an equation to divide by zero                *
* Input parameters: a,x,z                                   *
* Returns: inf                                              *
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/
double calculate_general_equation(int a, double x, double z)
{
	return (-x*.75) - z + (float)a / (a % 2);
}