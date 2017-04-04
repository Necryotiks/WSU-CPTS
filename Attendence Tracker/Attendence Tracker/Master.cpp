#include "Master.h"
#include "List.h"
#include <chrono>

void runapp()
{


	fstream infile("classList.csv", std::ios::in);
	assert(infile.is_open());
	List OBJ(infile);
	string input;
	std::smatch results;
	string switch1;
	string regex_str = "[0-7]{1,2}";//regex 
	std::regex reg1(regex_str, std::regex_constants::ECMAScript);
	auto i = false;
	if(OBJ.getHead() == nullptr)
	{
		cout << "head broke" << endl;
		system("pause");
	}
	while (i != true)
	{
		system("cls");
		cout << "1. Import course list(DEPRECATED)." << endl;
		cout << "2. Load master list(DEPRECATED)." << endl;
		cout << "3. Store master list." << endl;
		cout << "4. Mark absenses" << endl;
		cout << "5. Edit absences" << endl;
		cout << "6. Generate report" << endl;
		cin >> input;
		i = regex_match(input, results, reg1);

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
			//OBJ.UpdateList(infile);
			cout << "test" << endl;
			system("pause");
			i = false;
		}
		else if (switch1 == "2")
		{
			cout << "test" << endl;
			system("pause");
			i = false;
		}
		else if (switch1 == "3")
		{
			OBJ.EditList();
		}
	}
}

string currentTime()
{
	system_clock::time_point t = system_clock::now();
	time_t time = system_clock::to_time_t(t);
	return ctime(&time);
}
