#pragma once
#include "Source.h"
class TransactionNode;

class BSTNode
{
public:
	explicit BSTNode(string setData ="");
	virtual ~BSTNode();
	string getData() const;
	void setData(string &newData);
	std::shared_ptr<BSTNode>& getLeft();
	std::shared_ptr<BSTNode>& getRight();
	std::shared_ptr<TransactionNode>& getTnode();
	virtual void printData() = 0;
protected:
	std::shared_ptr<TransactionNode> tNode;
	string data;
	std::shared_ptr<BSTNode> LPTR;
	std::shared_ptr<BSTNode> RPTR;
};


inline BSTNode::BSTNode(string setData)
{
	tNode = nullptr;
	data = setData;
	LPTR = nullptr;
	RPTR = nullptr;
}


inline BSTNode::~BSTNode()
{
}


inline string BSTNode::getData() const
{
	return data;
}

inline void BSTNode::setData(string &newData)
{
	data = newData;
	assert(data == newData);
}

inline std::shared_ptr<BSTNode> &BSTNode::getLeft()
{
	return LPTR;
}


inline std::shared_ptr<BSTNode> &BSTNode::getRight()
{
	return RPTR;
}

inline std::shared_ptr<TransactionNode>& BSTNode::getTnode()
{
	return tNode;
}


