#include "Net.h"
#include "TrainingData.h"


int main()
{

	vector <double> inputs;
	vector<double> targetOutputs;
	vector<double> results;
	vector<int> Netdata;//net structure defined as 3,2,1. i.e. 3 input neurons, 2 hidden neurons, 1 output neuron
	auto TrainningEpoch = 0;
	TrainingData tData("NetTrainingData.txt");

	tData.getNetData(Netdata);
	Net myNet(Netdata);

	
	myNet.feedForward(inputs);
	myNet.backProp(targetOutputs);
	myNet.getResults(results);
}
