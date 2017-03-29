#pragma once
#include "Master.h"
#include "Listnode.h"

class List
{
public:
	List();
	~List();

	void insertAtEnd(std::unique_ptr<Listnode> &Node);
private:
	std::unique_ptr<Listnode> headNode;
};

