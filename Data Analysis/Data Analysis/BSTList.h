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
	int findSmallest();
	int findLargest();
private:
	std::shared_ptr<BSTNode> rootNode;
	void insert(std::shared_ptr<BSTNode>&rootNode, std::shared_ptr<BSTNode>& Node) const;
	static void BSTDeleteTree(std::shared_ptr<BSTNode>& rootNode);
	void inOrder(std::shared_ptr<BSTNode>&rootNode) const;
	int findSmallest(std::shared_ptr<BSTNode>&rootNode) const;
	int findLargest(std::shared_ptr<BSTNode>&rootNode) const;
	
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

inline int BSTList::findSmallest()
{
	return findSmallest(this->rootNode);
}

inline int BSTList::findLargest()
{
	return findLargest(this->rootNode);
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
	//why allocation new transaction node
	if (rootNode == nullptr)
	{
		rootNode = Node;
	}
	else if (Node->getTnode()->getUnits() < rootNode->getTnode()->getUnits())
	{
		insert(rootNode->getLeft(), Node);
	}
	else if (Node->getTnode()->getUnits() > rootNode->getTnode()->getUnits())
	{
		insert(rootNode->getRight(), Node);
	}
	else// could make new data structure. like linked list
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
		rootNode->getTnode()->printData();
		inOrder(rootNode->getRight());

	}
}

inline int BSTList::findSmallest(std::shared_ptr<BSTNode>& rootNode) const
{
	if(rootNode != nullptr)
	{
		static auto check = 999999;
		findSmallest(rootNode->getLeft());
		if(check > rootNode->getTnode()->getUnits())
		{
			check = rootNode->getTnode()->getUnits();
		}
		findSmallest(rootNode->getRight());
		return check;
	}
	return -1;
}

inline int BSTList::findLargest(std::shared_ptr<BSTNode>& rootNode) const
{
	if (rootNode != nullptr)
	{
		static auto check = 0;
		findSmallest(rootNode->getLeft());
		if (check < rootNode->getTnode()->getUnits())
		{
			check = rootNode->getTnode()->getUnits();
		}
		findSmallest(rootNode->getRight());
		return check;
	}
	return -1;
}
