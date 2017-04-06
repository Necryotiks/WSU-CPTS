#include "Menu.h"
#include <iostream>
#include "List.h"


Menu::Menu()
{
	std::cout << "THIS CLASS IS DEPRECATED: HOMEBREW MENU W/ REGEX." << endl;;
}


Menu::~Menu()
{
}

void Menu::runapp()const
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
	if (OBJ.getHead() == nullptr)
	{
		cout << "Head broke" << endl;
		system("pause");
		exit(1);
	}
	infile.close();

	while (i != true)
	{
		system("cls");
		cout << "1. Import course list(DEPRECATED)." << endl;
		cout << "2. Load master list(DEPRECATED)." << endl;
		cout << "3. Edit master list." << endl;
		cout << "4. Store list to file." << endl;
		cout << "5. Attendence" << endl;
		cout << "6. Generate report" << endl;
		cout << "7. Exit" << endl;
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
			i = false;
		}
		else if (switch1 == "2")
		{
			i = false;
		}
		else if (switch1 == "3")
		{
			OBJ.EditList();
			i = false;
		}
		else if (switch1 == "4")
		{
			infile.open("classList.csv", std::ios::out);
			OBJ.outputNode(infile);
			infile.close();
			i = false;
		}
		else if (switch1 == "5")
		{
			OBJ.ABSloop();
			i = false;
		}
		else if (switch1 == "6")
		{
			string inputsx;
			std::smatch res2;
			string regkey = "[1-2]";
			std::regex regky(regkey, std::regex_constants::ECMAScript);
			auto y = false;
			while (y != true)
			{
				system("cls");
				cout << "1. Print student list." << endl;
				cout << "2. Print chronic absent students." << endl;
				cout << "3. Exit" << endl;
				cin >> inputsx;
				y = regex_match(inputsx, res2, regky);
				if (res2[0] == "1")
				{
					OBJ.genReport();
					system("pause");

				}
				else if (res2[0] == "2")
				{

					string inputsy;
					std::smatch res3;
					regkey = "[0-9]{1,2}";
					std::regex regkay(regkey, std::regex_constants::ECMAScript);
					auto d = false;
					while (d != true)
					{
						system("cls");
						cout << "Search for students with X number of absences." << endl;
						cout << "Enter a number: ";
						cin >> inputsy;
						d = regex_match(inputsy, res3, regkay);
					}
					string temp = res3[0];
					OBJ.genAbsReport(temp);
					system("pause");

				}
				else if (res2[0] == "3")
				{
					break;
				}
			}

			i = false;
		}
		else if (switch1 == "7")
		{
			break;
		}

	}
}



