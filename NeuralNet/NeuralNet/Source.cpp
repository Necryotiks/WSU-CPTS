#include "stdafx.h"
#include "Net.h"
#include "TopographicalData.h"
#include "TrainingData.h"


int main()
{
/*TODO: Exception handling, Auto size Neural net based on input size,close file,add necessary const/constexpr, 
add lambdas as needed,
optimize with /Ox in VS2017*/
	vector <double> inputs;
	vector<double> targetOutputs;
	vector<double> results;
	vector<int> Netdata;//net structure defined as 3,2,1. i.e. 3 input neurons, 2 hidden neurons, 1 output neuron
	auto TrainingEpoch = 0;
	try{
	TopographicalData topographyData("NetTopography.txt");
	TrainingData tData("TrainingData.txt","TargetOutputs.txt");//opens input data file and target outputs file.
	}
	catch(std::exception &e)
	{
		std::cerr<<e.what();
	}
	assert(tData.isOpen());
	assert(topographyData.isOpen());//checks if file opens properly
	topographyData.getNetData(Netdata);//reads net topography
	Net myNet(Netdata);//builds net
	//NEEDS TO STORE DATA INTO INPUT VECTOR
	while (!tData.isEof())
	{
		++TrainingEpoch;
		cout << "Epoch: " << TrainingEpoch << '\n';
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

		cout << "Net Recent Average Error: " << myNet.getRecentAVGerror() << '\n';
	}
}
	
