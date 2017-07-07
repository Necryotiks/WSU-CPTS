#include "stdafx.h"
#include "Net.h"
#include "TopographicalData.h"
#include "TrainingData.h"


int main()
{
//TODO: Exception handling, Auto size Neural net based on input size,close file
	vector <double> inputs;
	vector<double> targetOutputs;
	vector<double> results;
	vector<int> Netdata;//net structure defined as 3,2,1. i.e. 3 input neurons, 2 hidden neurons, 1 output neuron
	auto TrainingEpoch = 0;
	TopographicalData topographyData("NetTopography.txt");
	TrainingData tData("TrainingData.txt","TargetOutputs.txt");//opens input data file and target outputs file.
	assert(tData.isOpen());
	assert(topographyData.isOpen());//checks if file opens properly
	topographyData.getNetData(Netdata);//reads net topography
	Net myNet(Netdata);//builds net
	//NEEDS TO STORE DATA INTO INPUT VECTOR
	while (!tData.isEof())
	{
		++TrainingEpoch;
		cout << "Epoch: " << TrainingEpoch << endl;
		if (tData.getNextInput(inputs) != Netdata[0])//checks if number of inputs matches number of available(sic) input neurons.
		{
			break;
		}
		printVector("Inputs: ", inputs);
		myNet.feedForward(inputs);

		myNet.getResults(results);
		printVector("Output: ", results);

		tData.getTargetOutput(targetOutputs);
		assert(targetOutputs.size() == Netdata.back());

		myNet.backProp(targetOutputs);//TODO: FIX THIS

		cout << "Net Recent Average Error: " << myNet.getRecentAVGerror() << endl;
	}
}
	
