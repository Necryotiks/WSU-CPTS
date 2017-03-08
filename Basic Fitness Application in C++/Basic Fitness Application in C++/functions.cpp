#include "Header.h"
#include "List.h"

void runapp()
{
	fstream Dietfile;
	Dietfile.open("Diet_File.txt", std::ios::in | std::ios::out);

	fstream Exercisefile;
	Exercisefile.open("Exercise_File.txt", std::ios::in | std::ios::out);

	List obj;
	obj.AssembleList(Dietfile, Exercisefile, obj);
	obj.displayMenu(Dietfile, Exercisefile);
	Dietfile.close();
	Exercisefile.close();
}

int userErrorCorrection(int target)
{
	return target;
}

int userErrorCorrection(char target)
{

	return static_cast<int> (target);
}

int userErrorCorrection(double target)
{
	return static_cast<int> (target);//casts as int
}


