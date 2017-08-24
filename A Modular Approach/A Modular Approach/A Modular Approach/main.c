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
//General equation : y = -x * (3 / 4) - z + a / (a % 2) (recall : a is an integer; the 3 and 4 constants in the equation should be left as integers initially, but explicitly type - casted as floating - point values)
#include "equations.h"

int main(void)
{
	while (true)// while loop
	{
		int usr = 0;
		printf("");
		printf("Please select a to run: \n");//MENU
		printf("1. Newton's Second Law\n");//
		printf("2. Volume Of A Cylinder\n");//
		printf("3. Character encoding\n");//
		printf("4. Equivalent Parallel Resistance\n");//
		printf("5. Resistive Divider\n");//
		printf("6. Distance Between Two Points\n");//
		printf("7. General equation\n");//
		printf("8. END\n");
		scanf("%d", &usr);//

		/*THIS PART OF THE PROGRAM COMPUTES NEWTONS SECOND LAW*/
		if (usr == 1)
		{
			double mass, acc = 0.00;
			printf("Newton's Second Law of Motion: \n");
			printf("Enter values for mass & acceleration: \n");
			printf("Mass: ");
			scanf("%lf", &mass);//Prompts user for Mass
			printf("Acceleration: ");
			scanf("%lf", &acc);//Prompts user for Acceleration
			printf("Newton's Second Law of Motion: Force = Mass * Acceleration = ");
			printf("%lf", mass);// prints mass
			printf(" * ");
			printf("%lf", acc);//prints acceleration
			printf(" = ");
			double force = calculate_newtons_2nd_law(mass, acc);
			printf("%.2lf Newtons\n", force);//displays force
			printf("\n");
			continue;//returns to MENU
		}
		/*THIS PART OF THE PROGRAM COMPUTES VOLUME OF A CYLINDER*/
		else if (usr == 2)
		{
			printf("Volume of a cylinder: \n");
			double radius, height = 0.00;//defines variables
			printf("Enter values for radius and height: \n");
			printf("Radius: ");
			scanf("%lf", &radius);// prompts user for radius
			printf("Height: ");
			scanf("%lf", &height);//prompt user for height
			double rad_squared = (radius * radius); // squares the radius
			double volume_cylinder = calculate_volume_cylinder(radius, height);
			printf("Volume of a cylinder: Volume = PI * radius^2 * height = ");// lines 35-43 is printing the calculated formula to the screen.
			printf("%f", PI);
			printf(" * ");
			printf("%lf", rad_squared);
			printf(" * ");
			printf("%lf", height);
			printf(" = ");
			printf("%.2lf\n", volume_cylinder);
			printf("\n");
			continue;//returns to MENU
		}
		/*THIS PART OF PROGRAM COMPUTES CHARACTER ENCODING*/
		else if (usr == 3)
		{
			printf("Character Encoding: \n");
			int shift = 0;
			char plaintext_chara = '\0'; //defines character variable
			printf("Enter a character: ");
			scanf(" %c", &plaintext_chara);
			printf("Enter a shift value: ");
			scanf("%d", &shift);
			char encoded_character = perform_character_encoding(plaintext_chara, shift);//encodes character
			printf("Character Encoding: encoded_character = plaintex_character -'A'+'a'-shift = \n");
			printf("Encoded character: %c\n\n", encoded_character);//prints the encoded characters  
			continue;//returns to MENU
		}
		/*THIS PART OF THE PROGRAM COMPUTES TOTAL RESISTANCE FROM 3 PARALLEL RESISTORS*/
		else if (usr == 4)
		{
			int resist1, resist2, resist3 = 0;//defines variables
			printf("Equivalent parallel resistance: \n");
			printf("Enter resistor values: \n");
			printf("Resistor 1: \n");//lines 79-84 store resistor values.
			scanf("%d", &resist1);
			printf("Resistor 2: \n");
			scanf("%d", &resist2);
			printf("Resistor 3: \n");
			scanf("%d", &resist3);
			double parallel_resist = calculate_parallel_resistance(resist1, resist2, resist3);// calculates parallel resistance
			printf("Eqivalent Parallel Resistance:  ");
			printf("EPR = 1 / (1 / R1 + 1 / R2 + 1 / R3) = ");
			printf("1/(");
			printf("1/%d", resist1);
			printf(" + ");
			printf("1/%d", resist2);
			printf(" + ");
			printf("1/%d", resist3);
			printf(")");
			printf(" = ");
			printf("%.2lf Ohms\n", parallel_resist);
			printf("\n");
			continue;//returns to MENU
		}
		/*THIS PART OF THE PROGRAM COMPUTES OUTGOING VOLTAGE*/
		else if (usr == 5)
		{
			int r1, r2 = 0;
			double vin = 0.00;
			printf("Resistive Divider: \n");
			printf("Enter Resistor Values: \n");
			printf("Resistor 1: \n");// lines 108-112 recieve user input
			scanf("%d", &r1);
			printf("Resistor 2: \n");
			scanf("%d", &r2);
			printf("Enter Incoming Voltage: ");
			scanf("%lf", &vin);
			double vout = calculate_resistive_divider(r1, r2, vin);//calculates voltage out.
			printf("Resistive Divider: ");
			printf("vout = R2 / (R1 + R2) * vin = ");
			printf("%d", r2);
			printf(" / ");
			printf("(");
			printf("%d", r1);
			printf(" + ");
			printf("%d", r2);
			printf(") * ");
			printf("%lf", vin);
			printf(" = ");
			printf("%.2lf Volts\n", vout);
			printf("\n");
			continue;//returns to MENU
		}
		/*THIS PART OF THE PROGRAM COMPUTES DISTANCE BETWEEN 2 POINTS*/
		else if (usr == 6)
		{
			double x1, x2, y1, y2 = 0.00;//defines variables
			printf("Distance between two points: \n");
			printf("Enter x1 value: \n");//lines 133-139 store user input
			scanf("%lf", &x1);
			printf("Enter x2 value: \n");
			scanf("%lf", &x2);
			printf("Enter y1 value: \n");
			scanf("%lf", &y1);
			printf("Enter y2 value: \n");
			scanf("%lf", &y2);
			double xelement = ((x2 - x1)*(x2 - x1));//calculates (x2-x1)^2
			double yelement = ((y2 - y1)*(y2 - y1));//calculates (y2-y1)^2
			double ans = calculate_distance_between_2pts(x1, x2, y1, y2);//takes square root
			printf("Distance between two points: = square root of ((x2 - x1)^2 + (y2 - y1)^2) = ");
			printf("square root of (");
			printf("%lf", xelement);
			printf(" + ");
			printf("%lf", yelement);
			printf(") = ");
			printf("%.2lf\n", ans);
			printf("\n");
			continue; //returns to MENU
		}
		/*THIS PART OF THE PROGRAM DIVIDES BY ZERO*/
		else if (usr == 7)
		{
			int a=0;//defines variables
			double x, z = 0.00;
			printf("Enter values for a,x,z: \n");
			scanf("%a %lf %lf", &a, &x, &z); //recieves user data
			double y = calculate_general_equation(a,x,z);//general formula NOTE: Dividing by zero would normally crash the program, HOWEVER dividing floats by zero produces inf.
			printf("General Equation:  y = -x * (3 / 4) - z + a / (a %% 2) = ");
			printf("%.2lf\n\n", y);
			continue;//returns to MENU


		}
		else if (usr == 8)
		{
			break;//Ends program
		}
	}
	return(0);
}
