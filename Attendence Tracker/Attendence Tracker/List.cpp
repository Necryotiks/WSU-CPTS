#include "List.h"

List::List(fstream &infile)
{
	AssembleList(infile);
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
		headNode = move(Node);//
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
void List::AssembleList(fstream & infile)//modify this for update list.
{
	string temp;
	string token = "Dubs Check 'Em";

	assert(infile.is_open());
	getline(infile, temp);
	while (!infile.eof())
	{
		try
		{
			auto k = 0;
			std::unique_ptr<Listnode> Node(new Listnode);
			getline(infile, temp);
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
					if (i == 8)
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
					default:
						break;

					}

				}
				catch (std::exception &e)
				{
					cout << "Exception: " << e.what() << endl;
				}

			}
			insertAtFront(Node);
		}
		catch (std::bad_alloc)
		{
			cout << "Fucking R.I.P. : Out of Memory" << endl;
		}

	}
}
void List::DeleteList()
{
	headNode.reset();//sends remains of list out of scope which then autodeallocates because smart ptr.
	assert(headNode == nullptr);
}
