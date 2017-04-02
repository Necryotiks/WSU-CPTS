#pragma once
#include "Master.h"
#include "Listnode.h"

class List
{
public:
	explicit List(std::fstream &infile);
	~List();

	void insertAtEnd(std::unique_ptr<Listnode> &Node);
	void insertAtFront(std::unique_ptr<Listnode> &Node);
	void AssembleList(std::fstream &infile);
	void DeleteList();
private:
	std::unique_ptr<Listnode> headNode;
};

