#pragma once
#include "Header.h"
class TrainingData
{
public:
	explicit TrainingData(string filename);
	void getNetData(vector<int> &netData);
	int getNextInput(vector<double> &inputs);
	int getTargetOutput(vector<double> &targetOutput);
private:
	fstream mTrainingDataFile;
};

