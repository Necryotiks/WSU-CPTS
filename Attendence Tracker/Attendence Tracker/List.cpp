#include "List.h"

List::List(fstream &infile)
{
	headNode = nullptr;
	UpdateList(infile);
}
List::~List()
{
	DeleteList();
}

void List::insertAtEnd(std::shared_ptr<Listnode> &Node)
{
	if (headNode == nullptr)
	{
		headNode = Node;
	}
	else
	{
		auto Prev = headNode;
		while (Prev->getNextPtr())
		{
			Prev = Prev->getNextPtr();
		}
		Prev->getNextPtr() = Node;
	}
}
void List::insertAtFront(std::shared_ptr<Listnode> &Node)
{
	insertAtFront(this->headNode, Node);
}
void List::insertAtFront(std::shared_ptr<Listnode> &headNode, std::shared_ptr<Listnode>& Node)
{
	auto temp = headNode;
	if (headNode == nullptr)
	{
		headNode = Node;
	}
	else
	{
		temp = Node;
		temp->getNextPtr() = headNode;
		headNode = temp;

	}
}

void List::EditList()
{
	EditList(this->headNode);
}

void List::UpdateList(fstream & updatefile)
{
	string temp;
	auto i = 0;
	string token = "Dubs Check 'Em";
	assert(updatefile.is_open());
	while (!updatefile.eof())
	{
		try
		{
			auto k = 0;
			std::shared_ptr<Listnode> Node(new Listnode);
			getline(updatefile, temp);
			if (temp == "")
			{
				break;
			}
			while (temp[k] != '\0')
			{

				if (temp[k] == '"')
				{
					while (temp[k] != ',')
					{
						if (temp[k] == '"')
						{
							break;
						}
						k++;
					}
					if (temp[k] == ',')
					{
						temp[k] = '_';
						break;
					}
				}
				k++;
			}
			std::stringstream temp_s(temp);
			while (true)
			{
				try
				{
					getline(temp_s, token, ',');
					if (token == "")
					{
						break;
					}
					i++;
					switch (i)
					{
					case 1:
						Node->setRecord(token);
						break;
					case 2:
						Node->setID(token);
						break;
					case 3:
						Node->setName(token);
						break;
					case 4:
						Node->setEmail(token);
						break;
					case 5:
						Node->setCreds(token);
						break;
					case 6:
						Node->setProgram(token);
						break;
					case 7:
						Node->setLevel(token);
						break;
					case 8:
						Node->setNumAbs(token);
						break;
					default:
						Node->setAbsDate(token);
						break;
					}
					if (temp_s.eof())
					{
						break;//reads until end of string stream
					}
				}
				catch (std::exception &e)
				{
					cout << "Exception: " << e.what() << endl;
				}
			}
			i = 0;
			insertAtFront(Node);
			//insertAtEnd(Node);
		}
		catch (std::bad_alloc)
		{
			cout << "Fucking R.I.P. : Out of Memory" << endl;
		}

	}
}
void List::EditList(std::shared_ptr<Listnode>& headNode)
{
	string regex_key = "[0-9]";
	std::regex rgx_top(regex_key, std::regex_constants::ECMAScript);
	std::smatch match_str;
	auto x = false;
	auto z = 0;
	auto v = false;
	string input1;
	auto pCur = headNode;//need to reset headnode
	while (x != true)
	{
		system("cls");
		cout << "1. Add student" << endl;
		cout << "2. Remove student" << endl;
		cout << "3. Edit students" << endl;
		cout << "4. Exit" << endl;
		cin >> input1;
		x = regex_match(input1, match_str, rgx_top);
		if (match_str[0] == "1")
		{
			cout << "Do you wish to add empty node? Y/N" << endl;
			cin >> input1;
			if (input1 == "Y" || input1 == "y")
			{
				std::shared_ptr<Listnode> Node(new Listnode);
				insertAtFront(Node);
				cout << "Node inserted" << endl;
				x = false;
			}
			if (x == true)
			{


				string input2;
				std::smatch match_str2;
				std::shared_ptr<Listnode> Node(new Listnode);
				while (v != true)
				{
					system("cls");
					cout << "Select a field to edit: " << endl;
					cout << "0. Exit" << endl;
					cout << "1. Record" << endl;
					cout << "2. ID" << endl;
					cout << "3. Name" << endl;
					cout << "4. Email" << endl;
					cout << "5. Credits" << endl;
					cout << "6. Program" << endl;
					cout << "7. Level" << endl;
					cout << "8. Number of absences" << endl;
					cout << "9. Absences dates" << endl;
					cin >> input2;
					v = regex_match(input2, match_str2, rgx_top);
					if (match_str2[0] == "0")
					{
						if (Node->getRecord() == "")
						{
							cout << "Field left blank: Record. Please fill all fields." << endl;
							system("pause");
							v = false;

						}
						else if (Node->getID() == "")
						{
							cout << "Field left blank: ID. Please fill all fields." << endl;
							system("pause");
							v = false;
						}
						else if (Node->getName() == "")
						{
							cout << "Field left blank: Name. Please fill all fields." << endl;
							system("pause");
							v = false;
						}
						else if (Node->getEmail() == "")
						{
							cout << "Field left blank: Email. Please fill all fields." << endl;
							system("pause");
							v = false;
						}
						else if (Node->getCreds() == "")
						{
							cout << "Field left blank: Credits. Please fill all fields." << endl;
							system("pause");
							v = false;
						}
						else if (Node->getProgram() == "")
						{
							cout << "Field left blank: Program. Please fill all fields." << endl;
							system("pause");
							v = false;
						}
						else if (Node->getLevel() == "")
						{
							cout << "Field left blank: Level. Please fill all fields." << endl;
							system("pause");
							v = false;
						}
						else if (Node->getNumAbs() == "")
						{
							cout << "Field left blank: Number of Absences. Please fill all fields." << endl;
							system("pause");
							v = false;
						}
						else
						{
							insertAtFront(Node);
							break;
						}
					}
					if (match_str2[0] == "1")
					{
						while (pCur != nullptr)
						{
							z++;
							pCur = pCur->getNextPtr();

						}
						pCur = headNode;
						z = z + 1;
						auto token = std::to_string(z);
						Node->setRecord(token);
						cout << "Record number incremented." << endl;
						system("pause");
						v = false;
					}
					else if (match_str2[0] == "2")
					{
						string temp;
						cout << "Enter an ID number." << endl;
						cin >> temp;
						Node->setID(temp);
						cout << "ID added" << endl;
						system("pause");
						v = false;
					}
					else if (match_str2[0] == "3")
					{
						string temp;
						cout << "Enter a name." << endl;
						cin.ignore();
						getline(cin, temp);
						Node->setName(temp);
						cout << "Name added" << endl;
						system("pause");
						v = false;
					}
					else if (match_str2[0] == "4")
					{
						string temp;
						cout << "Enter an email." << endl;
						cin >> temp;
						Node->setEmail(temp);
						cout << "Email added" << endl;
						system("pause");
						v = false;
					}
					else if (match_str2[0] == "5")
					{
						string temp;
						cout << "Enter number of credits." << endl;
						cin >> temp;
						Node->setCreds(temp);
						cout << "Credits added" << endl;
						system("pause");
						v = false;
					}
					else if (match_str2[0] == "6")
					{
						string temp;
						cout << "Enter program." << endl;
						cin >> temp;
						Node->setProgram(temp);
						cout << "Program added" << endl;
						system("pause");
						v = false;
					}
					else if (match_str2[0] == "7")
					{
						string temp;
						cout << "Enter Level." << endl;//enumerate later
						cin >> temp;
						Node->setLevel(temp);
						cout << "Level added" << endl;
						system("pause");
						v = false;
					}
					else if (match_str2[0] == "8")
					{
						string temp;
						cout << "Enter number of absences." << endl;//enumerate later
						cin >> temp;
						Node->setNumAbs(temp);
						cout << "Number of absences added" << endl;
						system("pause");
						v = false;
					}
					else if (match_str2[0] == "9")
					{
						string tstr;
						auto temp = currentTime();
						cout << "Is student absent: " << endl;
						cout << "Y/N";
						cin >> tstr;
						if (tstr == "Y" || tstr == "y")
						{
							cout << "Absence date entered via system time." << endl;//enumerate later
							Node->setAbsDate(temp);
							cout << "Absence date added" << endl;
							system("pause");
							v = false;
						}

						v = false;
					}
					else
					{
						v = false;
					}
				}
			}
		}
		else if (match_str[0] == "2")
		{
			string regexthing = "[0-9]{1,2}";
			std::regex rgxc(regexthing, std::regex_constants::ECMAScript);
			std::smatch match_str2;
			string xyz;
			pCur = headNode;
			auto _bool = false;
			while (_bool != true)
			{
				system("cls");
				cout << "Enter a student record number: " << endl;
				while (pCur != nullptr)
				{
					auto i = 0;
					cout << *pCur;
					while (!pCur->getAbsDate(i).empty())//maybe
					{

						cout << pCur->getAbsDate(i) << ",";
						if (pCur->getAbsDate(i).empty())
						{
							break;
						}
						i++;
					}
					pCur = pCur->getNextPtr();
					cout << endl;
				}
				cout << "0. Exit" << endl;
				pCur = headNode;//fix lator
				cin >> xyz;
				_bool = regex_match(xyz, match_str2, rgxc);
				string temp2 = match_str2[0];

				if (temp2 != "0")
				{
					DeleteNode(temp2);
					cout << "Entry deleted";
					pCur = headNode;
					while (pCur != nullptr)
					{
						auto i = 0;
						cout << *pCur;
						while (!pCur->getAbsDate(i).empty())//maybe
						{

							cout << pCur->getAbsDate(i) << ",";
							if (pCur->getAbsDate(i).empty())//ash josh
							{
								break;
							}
							i++;
						}
						pCur = pCur->getNextPtr();
						cout << endl;
					}
					_bool = false;
				}
				if (temp2 == "0")
				{
					_bool = true;
				}
			}
		}
		else if (match_str[0] == "3")
		{
			string regexthing = "[0-9]{1,2}";
			std::regex rgxc(regexthing, std::regex_constants::ECMAScript);
			std::smatch match_str3;
			string xkcd;
			bool b = false;
			pCur = headNode;
			while (b != true)
			{
				pCur = headNode;
				system("cls");
				cout << "Enter a student record number: " << endl;
				while (pCur != nullptr)
				{
					auto i = 0;
					cout << *pCur;
					while (!pCur->getAbsDate(i).empty())//maybe
					{

						cout << pCur->getAbsDate(i) << ",";
						if (pCur->getAbsDate(i).empty())
						{
							break;
						}
						i++;
					}
					pCur = pCur->getNextPtr();
					cout << endl;
				}
				cout << "0. Exit" << endl;
				pCur = headNode;
				cin >> xkcd;
				b = regex_match(xkcd, match_str3, rgxc);
				string tempx = match_str3[0];
				editNode(tempx);
				b = false;
				if (tempx == "0")
				{
					b = true;
				}
			}
		}
		else if (match_str[0] == "4")
		{
			x = true;
		}
	}
}
void List::DeleteList()
{
	headNode.reset();//sends remains of list out of scope which then autodeallocates because smart ptr.
	assert(headNode == nullptr);
}
void List::DeleteNode(string &temp2) const
{
	auto pCur = headNode;
	while (pCur->getNextPtr() != nullptr)
	{
		if (temp2 == pCur->getNextPtr()->getRecord())
		{
			pCur->getNextPtr() = pCur->getNextPtr()->getNextPtr();
			break;
		}
		pCur = pCur->getNextPtr();
	}

}
void List::editNode(string & temp3)const
{
	string regex_key = "[0-9]";
	std::regex rgx_top(regex_key, std::regex_constants::ECMAScript);
	auto pCur = headNode;
	auto v = false;
	auto z = 0;
	auto i = 0;
	while (pCur != nullptr)
	{
		if (temp3 == pCur->getRecord())
		{
			string input2;
			std::smatch match_str2;
			while (v != true)
			{
				system("cls");
				cout << "Select a field to edit: " << endl;
				cout << "0. Exit" << endl;
				cout << "1. Record" << endl;
				cout << "2. ID" << endl;
				cout << "3. Name" << endl;
				cout << "4. Email" << endl;
				cout << "5. Credits" << endl;
				cout << "6. Program" << endl;
				cout << "7. Level" << endl;
				cout << "8. Number of absences" << endl;
				cout << "9. Absences dates" << endl;
				cout << "Current profile:" << *pCur;
				while (!pCur->getAbsDate(i).empty())//maybe
				{

					cout << pCur->getAbsDate(i) << ",";
					if (pCur->getAbsDate(i).empty())
					{
						break;
					}
					i++;
				}
				cin >> input2;
				v = regex_match(input2, match_str2, rgx_top);
				if (match_str2[0] == "0")
				{

					break;

				}
				if (match_str2[0] == "1")
				{
					while (pCur != nullptr)
					{
						z++;
						pCur = pCur->getNextPtr();

					}
					pCur = headNode;
					z = z + 1;
					auto token = std::to_string(z);
					pCur->setRecord(token);
					cout << "Record number incremented." << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "2")
				{
					string temp;
					cout << "Enter an ID number." << endl;
					cin >> temp;
					pCur->setID(temp);
					cout << "ID added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "3")
				{
					string temp;
					cout << "Enter a name." << endl;
					cin.ignore();
					getline(cin, temp);
					pCur->setName(temp);
					cout << "Name added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "4")
				{
					string temp;
					cout << "Enter an email." << endl;
					cin >> temp;
					pCur->setEmail(temp);
					cout << "Email added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "5")
				{
					string temp;
					cout << "Enter number of credits." << endl;
					cin >> temp;
					pCur->setCreds(temp);
					cout << "Credits added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "6")
				{
					string temp;
					cout << "Enter program." << endl;
					cin >> temp;
					pCur->setProgram(temp);
					cout << "Program added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "7")
				{
					string temp;
					cout << "Enter Level." << endl;//enumerate later
					cin >> temp;
					pCur->setLevel(temp);
					cout << "Level added" << endl;
					system("pause");
					v = false;
				}
				else if (match_str2[0] == "8")
				{
					string choice;
					cout << "Add or Remove absences:" << endl;
					cout << "1. Add" << endl;
					cout << "2. Remove" << endl;
					cin >> choice;
					if (choice == "1")
					{


						string temp;
						cout << "Enter number of absences." << endl;//enumerate later
						cout << "Current absences" << pCur->getNumAbs();
						cin >> temp;
						pCur->setNumAbs(temp);
						cout << "Number of absences added" << endl;
						system("pause");
						v = false;
					}
					else if (choice == "2")
					{
						string ccc;
						string rmv = "-2";
						auto bbb = 0;
						auto g = 1;
						cout << "Select entry number: " << endl;
						while (!pCur->getAbsDate().empty())
						{
							cout << g << "." << pCur->getAbsDate() << "," << endl;
						}
						cin >> ccc;
						bbb = stoi(ccc);
						pCur->removeDate(bbb);
						pCur->setNumAbs(rmv);

					}
				}
				else if (match_str2[0] == "9")
				{
					string tstr;
					auto temp = currentTime();
					cout << "Is student absent: " << endl;
					cout << "Y/N" << endl;
					cin >> tstr;
					if (tstr == "Y" || tstr == "y")
					{
						cout << "Absence date entered via system time." << endl;//enumerate later
						pCur->setAbsDate(temp);
						cout << "Absence date added" << endl;
						system("pause");
						v = false;
					}
				}
				else
				{
					v = false;
				}
			}
			break;
		}
		pCur = pCur->getNextPtr();
	}
}
void List::outputNode(fstream & infile)const
{
	auto pCur = headNode;//fix
	while (pCur != nullptr)
	{
		auto i = 0;
		infile << *pCur;
		while (!pCur->getAbsDate(i).empty())//maybe
		{

			infile << pCur->getAbsDate(i) << ",";
			if (pCur->getAbsDate(i).empty())//
			{
				break;
			}
			i++;
		}
		pCur = pCur->getNextPtr();
		infile << endl;
	}
}
void List::genReport()const
{
	auto pCur = headNode;
	system("cls");
	while (pCur != nullptr)
	{
		cout << *pCur << pCur->peekMostRecentDate();
		pCur = pCur->getNextPtr();
		cout << endl;
	}
}
void List::genAbsReport(string i) const
{
	auto pCur = headNode;
	system("cls");
	while (pCur != nullptr)
	{
		if (pCur->getNumAbs() == i)
		{
			cout << *pCur;
			cout << pCur->peekMostRecentDate();
			cout << endl;
		}
		pCur = pCur->getNextPtr();
	}
}
void List::ABSloop()const
{
	string inputsz;
	std::smatch res5;
	string regkey = "[YNyn]{1,1}";
	std::regex regky(regkey, std::regex_constants::ECMAScript);
	auto pCur = headNode;
	auto k = false;

	while (pCur != nullptr)
	{
		while (k != true)
		{
			system("cls");
			cout << *pCur << pCur->peekMostRecentDate() << endl;
			cout << "Is this student absent? Y/N" << endl;
			cin >> inputsz;
			k = regex_search(inputsz, res5, regky);
		}
		if (res5[0] == "Y" || res5[0] == "y")
		{
			auto temp = currentTime();
			pCur->setAbsDate(temp);
			k = false;
		}
		else
		{
			k = false;
		}
		pCur = pCur->getNextPtr();
		cout << endl;
	}
}
std::shared_ptr<Listnode>& List::getHead()
{
	return headNode;
}

std::ostream & operator<<(std::ostream & lhs, Listnode & rhs)//fix
{
	lhs << rhs.getRecord() << ",";
	lhs << rhs.getID() << ",";
	lhs << rhs.getName() << ",";
	lhs << rhs.getEmail() << ",";
	lhs << rhs.getCreds() << ",";
	lhs << rhs.getProgram() << ",";
	lhs << rhs.getLevel() << ",";
	lhs << rhs.getNumAbs() << ",";

	return lhs;
}
