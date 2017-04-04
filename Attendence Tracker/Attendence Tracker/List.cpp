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
		headNode = headNode->getNextPtr();
		headNode = Node;
	}
}
void List::insertAtFront(std::shared_ptr<Listnode> &Node)
{
	insertAtFront(this->headNode, Node);
}
void List::insertAtFront(std::shared_ptr<Listnode> &headNode,std::shared_ptr<Listnode>& Node)
{
	std::shared_ptr<Listnode> temp;
	temp = headNode;
	if (temp == nullptr)
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
{//only stores first node
	string temp;
	auto i = 0;
	string token = "Dubs Check 'Em";
	assert(updatefile.is_open());
	getline(updatefile, temp);
	while (!updatefile.eof())
	{
		try
		{
			auto k = 0;
			std::shared_ptr<Listnode> Node(new Listnode);
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
			i = 0;
			insertAtFront(Node);
		}
		catch (std::bad_alloc)
		{
			cout << "Fucking R.I.P. : Out of Memory" << endl;
		}
		
	}
}
void List::EditList(std::shared_ptr<Listnode>& headNode)
{
	string regex_key = "[A-Za-z]{4,8}";
	std::regex rgx(regex_key, std::regex_constants::ECMAScript);
	std::smatch match_str;
	auto x = false;
	static auto z = 0;
	string input;
	std::shared_ptr<Listnode>pCur = headNode;//need to reset headnode
	while (x != true)
	{
		system("cls");
		cout << "Select a student:" << endl;
		while (pCur->getNextPtr() != nullptr)
		{
			z++;
			cout << z << pCur->getName() << endl;

		}
		pCur = headNode;
		cin >> input;
		x = regex_match(input, match_str, rgx);
	}
}
void List::DeleteList()
{
	headNode.reset();//sends remains of list out of scope which then autodeallocates because smart ptr.
	assert(headNode == nullptr);
}
