#pragma once
#include "BSTNode.h"
#include "TransactionNode.h"

class BSTList
{
public:
	BSTList();
	~BSTList();

	

	std::shared_ptr<BSTNode>& getRoot();

	void setRoot(std::shared_ptr<BSTNode> const newRoot);
	void insert(std::shared_ptr<BSTNode>&Node);//fix

	static std::shared_ptr<BSTNode> makeNode();
	void BSTDeleteTree();

	void inOrder();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();
private:
	std::shared_ptr<BSTNode> rootNode;
	void insert(std::shared_ptr<BSTNode>&rootNode, std::shared_ptr<BSTNode>& Node) const;//WHAT DO
	static void BSTDeleteTree(std::shared_ptr<BSTNode>& rootNode);
	void inOrder(std::shared_ptr<BSTNode>&rootNode) const;
	
};


inline BSTList::BSTList()
{
}


inline BSTList::~BSTList()
{
	BSTDeleteTree();
	cout << "Tree deconstructed" << endl;
}

inline void BSTList::BSTDeleteTree()
{
	BSTDeleteTree(this->rootNode);
}

inline void BSTList::inOrder()
{
	inOrder(this->rootNode);
}


inline std::shared_ptr<BSTNode>& BSTList::getRoot()
{
	return rootNode;
}


inline void BSTList::setRoot(std::shared_ptr<BSTNode> const newRoot)
{
	rootNode = newRoot;
}


inline void BSTList::insert(std::shared_ptr<BSTNode>& Node)
{
	insert(this->rootNode, Node);
}


inline std::shared_ptr<BSTNode> BSTList::makeNode()
{
	string temp;
	return std::make_shared<BSTNode>(temp);
}


inline void BSTList::insert(std::shared_ptr<BSTNode>& rootNode, std::shared_ptr<BSTNode>& Node) const
{
	auto temp = std::make_shared<TransactionNode>();
	temp = Node;//????
	if (rootNode == nullptr)
	{
		rootNode = temp;
	}
	else if (temp->getUnits() < /*wtf goes here*/ )
	{
		insert(rootNode->getLeft(), Node);
	}
	else if (temp->getUnits() > )
	{
		insert(rootNode->getRight(), Node);
	}
	else
	{
		cout << "duplicate" << endl;
	}
}

inline void BSTList::BSTDeleteTree(std::shared_ptr<BSTNode>& rootNode)
{
	rootNode.reset();
}

inline void BSTList::inOrder(std::shared_ptr<BSTNode>& rootNode) const
{
	if (rootNode != nullptr)
	{
		inOrder(rootNode->getLeft());
		cout << "Data: " << endl; 
		rootNode->printData();
		inOrder(rootNode->getRight());

	}
}
