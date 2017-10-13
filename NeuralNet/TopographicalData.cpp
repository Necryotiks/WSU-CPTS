#include "stdafx.h"
#include "TopographicalData.h"

TopographicalData::TopographicalData(string filename)
{
	mTopographicalDataFile.open(filename);
	if (mTopographicalDataFile.is_open() == false)
	{
		throw std::experimental::filesystem::filesystem_error("Topographical data file failed to open!");//add errror string
	}
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


			netData.push_back(j);
		}
	}
}


