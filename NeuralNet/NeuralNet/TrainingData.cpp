#include "stdafx.h"
#include "TrainingData.h"


TrainingData::TrainingData(string inputfile, string outputfile)
{
	mTrainingDataInputFile.open(inputfile);
	if(mTrainingDataInputFile.is_open() == false)
	{
		throw std::filesystem::filesystem_error("Input file failed to open!");
	}
	mTargetOutputFile.open(outputfile);
	if(mTargetOutputFile.is_open() == false)
	{
		throw std::filesystem::filesystem_error("Output file failed to open!");
	}
}

bool TrainingData::isEof() const
{
	return mTrainingDataInputFile.eof();//TODO: apply to both files.
}

bool TrainingData::isOpen() const
{
	if (mTrainingDataInputFile.is_open() == true && mTargetOutputFile.is_open() == true)
	{
		return true;
	}
	if (mTrainingDataInputFile.is_open() == false)
	{
		//TODO: FINISH
	}
	return false;
}



int TrainingData::getNextInput(vector<double>& inputs)
{
	string temp;
	inputs.clear();
	assert(inputs.empty());
	while (getline(mTrainingDataInputFile, temp))
	{
		auto stoi_temp = stoi(temp);//converts input values into ints from strings.
		inputs.push_back(stoi_temp);//pushes values into input
	}
	return inputs.size();//returns number of inputs.
}

int TrainingData::getTargetOutput(vector<double>& targetOutput)
{
	string temp;
	targetOutput.clear();
	assert(targetOutput.empty());
	while (getline(mTargetOutputFile, temp))
	{
		auto stoi_temp = stoi(temp);//converts output values into ints from strings.
		targetOutput.push_back(stoi_temp);
	}
	return targetOutput.size();
}
