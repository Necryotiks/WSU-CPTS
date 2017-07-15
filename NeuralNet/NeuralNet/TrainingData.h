#pragma once
class TrainingData
{
public:
	explicit TrainingData(string inputfile, string outputfile);
	bool isEof() const;
	bool isOpen() const;
	int getInputs(vector<double> &inputs);
	int getTargetOutput(vector<double> &targetOutput);
private:
	fstream mTrainingDataInputFile;
	fstream mTargetOutputFile;
};

