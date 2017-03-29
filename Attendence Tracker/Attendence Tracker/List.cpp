#include "List.h"

List::List()
{
}


List::~List()
{
}

void List::insertAtEnd(std::unique_ptr<Listnode> &Node)
{
	if(headNode == nullptr)
	{
		headNode = move(Node);//this might work.
	}
	else
	{
		headNode = headNode->getNextPtr();
		headNode = move(Node);//
	}
}
