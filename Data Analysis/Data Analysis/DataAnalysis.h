#pragma once
#include "BSTList.h"
class DataAnalysis
{
	DataAnalysis();
	~DataAnalysis();
public:
	void runAnalysis() const;

private:
	BSTList mTreeSold;
	BSTList mTreePurchased;
	std::ifstream mCSVStream;
	void openFile();

};

inline DataAnalysis::DataAnalysis()
{
	
}
inline DataAnalysis::~DataAnalysis()
{
	
}

inline void DataAnalysis::runAnalysis() const
{
	
}

inline void DataAnalysis::openFile()
{
	mCSVStream.open("data.csv");
	assert(mCSVStream.is_open());
}

