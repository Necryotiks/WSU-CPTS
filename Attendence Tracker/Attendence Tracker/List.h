#pragma once
#include "Master.h"
#include "Listnode.h"

class List
{
public:
	explicit List(std::fstream &infile);
	~List();

	void insertAtEnd(std::shared_ptr<Listnode> &Node);
	void insertAtFront(std::shared_ptr<Listnode> &Node);
	void UpdateList(fstream &updatefile);
	void EditList();
	void DeleteList();
private:
	std::shared_ptr<Listnode> headNode;
	void insertAtFront(std::shared_ptr<Listnode> &headNode,std::shared_ptr<Listnode> &Node);
	void EditList(std::shared_ptr<Listnode> &headNode);
};

