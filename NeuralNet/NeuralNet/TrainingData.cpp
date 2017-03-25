#include "TrainingData.h"

TrainingData::TrainingData(string filename)
{
	mTrainingDataFile.open(filename);
}

bool TrainingData::isEof()const
{
	return mTrainingDataFile.eof();
}

void TrainingData::getNetData(vector<int>& netData)
{
	string temp;

	auto i = 0;
	auto j = 0;
	assert(mTrainingDataFile.is_open());
	getline(mTrainingDataFile, temp);
	auto * tempstr = new char[temp.length() - 1];
	strncpy(tempstr, temp.c_str(), temp.length() - 1);
	while (temp[i] != '\0')
	{
		auto token = strtok(tempstr, " ");
		j = atoi(token);

		//assert(std::isdigit(j) == 1);//this is a true assert yet it fails...
		netData.push_back(j);

		i++;
	}
}

int TrainingData::getNextInput(vector<double>& inputs)
{
	string temp;
	auto i = 0;
	inputs.clear();
	assert(inputs.empty());
	getline(mTrainingDataFile, temp);
	while (temp[i] != '\0')
	{
		inputs.push_back(temp[i]);
	}
	return inputs.size();
}

int TrainingData::getTargetOutput(vector<double>& targetOutput)
{
	string temp;
	auto i = 0;
	targetOutput.clear();
	assert(targetOutput.empty());
	getline(mTrainingDataFile, temp);
	while (temp[i] != '\0')
	{
		targetOutput.push_back(temp[i]);
	}
	return targetOutput.size();
}
