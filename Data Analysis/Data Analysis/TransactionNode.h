#pragma once
class TransactionNode : public BSTNode
{
public:
	explicit TransactionNode(string nData = "", int num = 0);
	~TransactionNode();
	void printData() override;
	int getUnits() const;
	void setUnits(int ndata);
private:
	int mUnits;
};

inline TransactionNode::TransactionNode(string nData, int num) : BSTNode(nData)
{
	mUnits = num;
}

inline TransactionNode::~TransactionNode()
{

}


inline void TransactionNode::printData()
{
	cout << "Data: " << data << endl;
	cout << "Units: " << mUnits << endl;
	cout << endl;
}

inline int TransactionNode::getUnits() const
{
	return mUnits;
}

inline void TransactionNode::setUnits(int ndata)
{
	mUnits = ndata;
	assert(mUnits == ndata);
}