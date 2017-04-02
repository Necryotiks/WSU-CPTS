#include "Master.h"
#include "List.h"

void runapp()
{	
	fstream infile("classList.csv", std::ios::in);
	assert(infile.is_open());
	List OBJ(infile);
	std::fstream Updatefile("UpdateFile.csv", std::ios::in | std::ios::out);
	assert(Updatefile.is_open());
	string input;
	std::smatch results;
	string switch1;
	string regex_str = "[0-7]{1,2}";//regex 
	std::regex reg1(regex_str, std::regex_constants::ECMAScript);
	do
	{
		cout << "1. Load file update." << endl;
		cin >> input;
	} while (regex_search(input, results, reg1) == false);
	try
	{
		switch1 = results[0];
		//throw not needed, used for manual exception;
	}
	catch (string e)
	{
		cout << "Something broke." << endl;
	}
	if (switch1 == "1")
	{
		//load updated list
		cout << "test" << endl;
	}
}
