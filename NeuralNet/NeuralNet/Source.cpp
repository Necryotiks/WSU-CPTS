#include "Net.h"
#include "TrainingData.h"


int main()
{

	vector <double> inputs;
	vector<double> targetOutputs;
	vector<double> results;
	vector<int> Netdata;//net structure defined as 3,2,1. i.e. 3 input neurons, 2 hidden neurons, 1 output neuron
	auto TrainingEpoch = 0;
	TrainingData tData("NetTrainingData.txt");

	tData.getNetData(Netdata);
	Net myNet(Netdata);

	while (tData.isEof())
	{
		++TrainingEpoch;
		cout << "Epoch: " << TrainingEpoch << endl;
		if (tData.getNextInput(inputs) != Netdata[0])//checks if inputs match.
		{
			break;
		}
		printVector("Inputs: ", inputs);
		myNet.feedForward(inputs);

		myNet.getResults(results);
		printVector("Output: ", results);

		tData.getTargetOutput(targetOutputs);
		assert(targetOutputs.size() == Netdata.back());

		myNet.backProp(targetOutputs);

		cout << "Net Recent Average Error: " << myNet.getRecentAVGerror() << endl;
	}
}
	
