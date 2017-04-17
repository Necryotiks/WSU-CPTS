#pragma once
#include "BSTList.h"


class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();
	void runAnalysis();

private:
	void openFile();
	void parseString(string &inputLine, vector<string> &output) const;
	void parseFile();
	void sortData(std::shared_ptr<BSTNode> &Node,string choice);
	void outputData();

	BSTList mTreeSold;
	BSTList mTreePurchased;
	std::ifstream mCSVStream;

};

inline DataAnalysis::DataAnalysis()
{

}
inline DataAnalysis::~DataAnalysis()
{

}

inline void DataAnalysis::runAnalysis()
{
	openFile();
	parseFile();
	outputData();
}

inline void DataAnalysis::openFile()
{
	mCSVStream.open("data.csv");
	assert(mCSVStream.is_open());
}

inline void DataAnalysis::parseString(string & inputLine, vector<string>& output) const
{
	std::stringstream temp(inputLine);
	string token;
	while (getline(temp, token, ','))
	{
		output.push_back(token);
	}
}

inline void DataAnalysis::parseFile()
{
	vector<string> output;
	string inputLine;
	getline(mCSVStream,inputLine);
	while (getline(mCSVStream, inputLine))
	{
		
		assert(inputLine != "");
		output.clear();
		parseString(inputLine, output);
		std::shared_ptr<BSTNode>Node(new TransactionNode(output[1],stoi(output[0])));
		//dynamic_cast<TransactionNode>(Node)->setUnits(stoi(output[0]));//must implement custom smart pointer dynamic cast
		sortData(Node, output[2]);
	}
	mTreeSold.inOrder();
	mTreePurchased.inOrder();
}

inline void DataAnalysis::sortData(std::shared_ptr<BSTNode> &Node, string choice)
{
	if(choice == "Purchased")
	{
		mTreePurchased.insert(Node);
	}
	else if(choice == "Sold")
	{
		mTreeSold.insert(Node);
	}
}

inline void DataAnalysis::outputData()
{
	cout << "Least Purchased: " << mTreePurchased.findSmallest() << endl;
	cout << "Most Purchased: " << mTreePurchased.findLargest() << endl;
	cout << endl;
	cout << "Least Sold: " << mTreeSold.findSmallest() << endl;
	cout << "Most Sold: " << mTreeSold.findLargest() << endl;
}

