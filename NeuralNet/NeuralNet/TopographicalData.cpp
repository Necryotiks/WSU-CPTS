#include "stdafx.h"
#include "TopographicalData.h"

TopographicalData::TopographicalData(string filename)
{
	mTopographicalDataFile.open(filename);
}

bool TopographicalData::isEof()const
{
	return mTopographicalDataFile.eof();
}

bool TopographicalData::isOpen() const
{
	if (mTopographicalDataFile.is_open() == true)
	{
		return true;
	}
	return false;
}

void TopographicalData::getNetData(vector<int>& netData)
{
	string tempstr;
	auto j = 0;
	string token;
	assert(mTopographicalDataFile.is_open());
	while (getline(mTopographicalDataFile, tempstr))
	{
		stringstream temp(tempstr);
		while (!temp.eof())
		{
			temp >> token;
			j = stoi(token);

			//assert(std::isdigit(j) == 1);//this is a true assert yet it fails...FIX LATER
			netData.push_back(j);
		}
	}
}


