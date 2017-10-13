#pragma once
#include "stdafx.h"
class TopographicalData
{
public:
	explicit TopographicalData(string filename);
	bool isEof() const;
	bool isOpen() const;
	void getNetData(vector<int> &netData);
private:
	fstream mTopographicalDataFile;
};

