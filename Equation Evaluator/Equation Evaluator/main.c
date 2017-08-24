/*Name: Elliott Villars
  Date: 8/29/16
  SID: 11463956
  HW: 1
  Lab: 6
  Description: This program evaluates equations.*/

#include <stdio.h> 
#include <math.h>//need for sqrt()
#include <stdbool.h>// needed for True/False Statements
#define PI 3.1415926 //defines Pi

int main(void)
{
	while (true)// while loop
	{


		int usr = 0;
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
			printf("Newton's Second Law of Motion: \n");
			float mass = 0, acc = 0;//Defines mass and acceleration variables
			printf("Enter values for mass & acceleration: \n");
			printf("Mass: ");
			scanf("%f", &mass);//Prompts user for Mass
			printf("Acceleration: ");
			scanf("%f", &acc);//Prompts user for Acceleration
			float force = (mass*acc);
			printf("Newton's Second Law of Motion: Force = Mass * Acceleration = ");
			printf("%f", mass);// prints mass
			printf(" * ");
			printf("%f", acc);//prints acceleration
			printf(" = ");
			printf("%f\n", force);//displays force
			printf("\n");
			continue;//returns to MENU
		}
/*THIS PART OF THE PROGRAM COMPUTES VOLUME OF A CYLINDER*/
		else if (usr == 2)
		{
			printf("Volume of a cylinder: \n");
			float radius = 0, height = 0;//defines variables
			printf("Enter values for radius and height: \n");
			printf("Radius: ");
			scanf("%f", &radius);// prompts user for radius
			printf("Height: ");
			scanf("%f", &height);//prompt user for height
			float rad_squared = (radius * radius); // squares the radius
			float volume_cylinder = (PI * rad_squared* height);//calculates volume
			printf("Volume of a cylinder: Volume = PI * radius^2 * height = ");// lines 35-43 is printing the calculated formula to the screen.
			printf("%f", PI);
			printf(" * ");
			printf("%f", rad_squared);
			printf(" * ");
			printf("%f", height);
			printf(" = ");
			printf("%f", volume_cylinder);
			printf("\n");
			continue;//returns to MENU
		}
/*THIS PART OF PROGRAM COMPUTES CHARACTER ENCODING*/
		else if (usr == 3)
		{
			printf("Character Encoding: \n");
			char plaintext_chara = '\0'; //defines character variable
			printf("Enter a character: ");
			scanf(" %c", &plaintext_chara);
			char encoded_character = plaintext_chara - 'A' + 'a' - 5;//encodes character
			printf("Character Encoding: encoded_character = plaintex_character -'A'+'a'-shift = ");
			printf("Encoded character: %c", encoded_character);//prints the encoded characters  
			continue;//returns to MENU
		}
/*THIS PART OF THE PROGRAM COMPUTES TOTAL RESISTANCE FROM 3 PARALLEL RESISTORS*/
		else if (usr == 4)
		{
			float resist1 = 0, resist2 = 0, resist3 = 0;//defines variables
			printf("Equivalent parallel resistance: \n");
			printf("Enter resistor values: \n");
			printf("Resistor 1: \n");//lines 79-84 store resistor values.
			scanf("%f", &resist1);
			printf("Resistor 2: \n");
			scanf("%f", &resist2);
			printf("Resistor 3: \n");
			scanf("%f", &resist3);
			float total_resist = (1 / resist1) + (1 / resist2) + (1 / resist3);// calculates 1/ rt
			float parallel_resist = (1 / total_resist);// calculates parallel resistance
			printf("Eqivalent Parallel Resistance:  ");
			printf("EPR = 1 / (1 / R1 + 1 / R2 + 1 / R3) = ");
			printf("1/(");
			printf("%f", 1 / resist1);
			printf(" + ");
			printf("%f", 1 / resist2);
			printf(" + ");
			printf("%f", 1 / resist3);
			printf(")");
			printf(" = ");
			printf("%f", parallel_resist);
			printf("\n");
			continue;//returns to MENU
		}
/*THIS PART OF THE PROGRAM COMPUTES OUTGOING VOLTAGE*/
		else if (usr == 5)
		{
			float r1 = 0, r2 = 0, vin = 0;//defines variables
			printf("Resistive Divider: \n");
			printf("Enter Resistor Values: \n");
			printf("Resistor 1: \n");// lines 108-112 recieve user input
			scanf("%f", &r1);
			printf("Resistor 2: \n");
			scanf("%f", &r2);
			printf("Enter Incoming Voltage: ");
			scanf("%f", &vin);
			float vout = r2 / (r1 + r2)*vin;//calculates voltage out.
			printf("Resistive Divider: ");
			printf("vout = R2 / (R1 + R2) * vin = ");
			printf("%f", r2);
			printf(" / ");
			printf("(");
			printf("%f", r1);
			printf(" + ");
			printf("%f", r2);
			printf(") * ");
			printf("%f", vin);
			printf(" = ");
			printf("%f", vout);
			printf("\n");
			continue;//returns to MENU
		}
/*THIS PART OF THE PROGRAM COMPUTES DISTANCE BETWEEN 2 POINTS*/
		else if (usr == 6)
		{
			float x1 = 0, x2 = 0, y1 = 0, y2 = 0;//defines variables
			printf("Distance between two points: \n");
			printf("Enter x1 value: \n");//lines 133-139 store user input
			scanf("%f", &x1);
			printf("Enter x2 value: \n");
			scanf("%f", &x2);
			printf("Enter y1 value: \n");
			scanf("%f", &y1);
			printf("Enter y2 value: \n");
			scanf("%f", &y2);
			float xelement = ((x2 - x1)*(x2 - x1));//calculates (x2-x1)^2
			float yelement = ((y2 - y1)*(y2 - y1));//calculates (y2-y1)^2
			float ans = sqrt(xelement + yelement);//takes square root
			printf("Distance between two points: = square root of ((x1 - x2)^2 + (y1 - y2)^2) = ");
			printf("square root of (");
			printf("%f", xelement);
			printf(" + ");
			printf("%f", yelement);
			printf(") = ");
			printf("%f", ans);
			printf("\n");
			continue; //returns to MENU
		}
/*THIS PART OF THE PROGRAM DIVIDES BY ZERO*/
		else if (usr == 7)
		{
			int x, a, z = 0;//defines variables
			printf("Enter values for x,a,z: ");
			scanf("%d %d %d", &x, &a, &z); //recieves user data
			float y = (-x*.75) - z + (float)a / (a % 2);//general formula NOTE: Dividing by zero would normally crash the program, HOWEVER dividing floats by zero produces inf.
			printf("General Equation:  y = -x * (3 / 4) - z + a / (a % 2) = ");
			printf("%f\n", y);
			continue;//returns to MENU


		}
		else if (usr == 8)
		{
			break;//Ends program
		}
	}
	return(0);
}
