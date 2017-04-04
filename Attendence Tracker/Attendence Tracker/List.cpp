#include "List.h"

List::List(fstream &infile)
{
	UpdateList(infile);
}
List::~List()
{
	DeleteList();
}

void List::insertAtEnd(std::unique_ptr<Listnode> &Node)
{
	if (headNode == nullptr)
	{
		headNode = move(Node);
	}
	else
	{
		headNode = headNode->getNextPtr();
		headNode = move(Node);
	}
}
void List::insertAtFront(std::unique_ptr<Listnode>& Node)
{
	std::unique_ptr<Listnode> temp;
	if (headNode == nullptr)
	{
		headNode = move(Node);
	}
	else
	{
		temp->getNextPtr() = move(headNode);
		headNode = move(temp);
	}
}

void List::UpdateList(fstream & updatefile)
{//only stores first node
	string temp;
	string token = "Dubs Check 'Em";
	assert(updatefile.is_open());
	getline(updatefile, temp);
	while (!updatefile.eof())
	{
		try
		{
			auto k = 0;
			std::unique_ptr<Listnode> Node(new Listnode);
			getline(updatefile, temp);
			while (temp[k] != '\0')
			{

				if (temp[k] == '"')
				{
					while (temp[k] != ',')
					{
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
					static auto i = 0;
					getline(temp_s, token, ',');
					if(temp_s.eof())
					{
						break;//reads until end of string stream
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
					default://beyond 9, read absences dates;
							Node->setAbsDate(token);
						break;

					}

				}
				catch (std::exception &e)
				{
					cout << "Exception: " << e.what() << endl;
				}

			}
			
		}
		catch (std::bad_alloc)
		{
			cout << "Fucking R.I.P. : Out of Memory" << endl;
		}
		insertAtFront(Node);
	}
}
void List::EditList()
{
	string regex_key = "[A-Za-z]{4,8}";
	std::regex rgx(regex_key, std::regex_constants::ECMAScript);
	std::smatch match_str;
	auto x = false;
	static auto z = 0;
	string input;
	std::unique_ptr<Listnode>pCur = move(headNode);//need to reset headnode
	while(x != true)
	{
		system("cls");
		cout << "Select a student:" << endl;
		while(pCur->getNextPtr() != nullptr)
		{
			z++;
			cout << z << pCur->getName() << endl;
			
		}
		pCur = move(headNode);
		cin >> input;
		x = regex_match(input, match_str, rgx);
	}
}
void List::DeleteList()
{
	headNode.reset();//sends remains of list out of scope which then autodeallocates because smart ptr.
	assert(headNode == nullptr);
}
