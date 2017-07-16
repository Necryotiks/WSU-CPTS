#include "stdafx.h"
#include "Net.h"
#include "TopographicalData.h"
#include "TrainingData.h"

int main()
{
	try {
		/* TODO:  Auto size Neural net based on input size,close file,add necessary const/constexpr,readd bias neuron to input and hiddenlayers, add lambdas as needed, optimize with /Ox in VS2017*/
		vector <double> inputs;
		vector<double> targetOutputs;
		vector<double> results;
		vector<int> Netdata;//net structure defined as 3,2,1. i.e. 3 input neurons, 2 hidden neurons, 1 output neuron
		auto TrainingEpoch = 0;

		TopographicalData topographyData("NetTopography.txt");
		TrainingData tData("TrainingData.txt", "TargetOutputs.txt");//opens input data file and target outputs file.

		//checks if file opens properly
		topographyData.getNetData(Netdata);//reads net topography
		Net myNet(Netdata);//builds net
		tData.getInputs(inputs);
		tData.getTargetOutput(targetOutputs);
		//NEED BIAS NEURONS
		while (TrainingEpoch != 10)
		{
			++TrainingEpoch;
			cout << "Epoch: " << TrainingEpoch << '\n';
			if (inputs.size() != Netdata[0])//checks if number of inputs matches number of available(sic) input neurons.
			{
				break;
			}
			printVector("Inputs: ", inputs);
			myNet.feedForward(inputs);//fix this

			myNet.getResults(results);
			printVector("Output: ", results);


			if(targetOutputs.size() == Netdata.back())
			{
				throw std::runtime_error("Output mismatch!");
			}

			printVector("Expected Outputs: ", targetOutputs);
			myNet.backProp(targetOutputs);//TODO: FIX THIS

			cout << "Net Recent Average Error: " << myNet.getRecentAVGerror() << '\n';
		}
	}
	catch (std::exception &e)
	{
		system("cls");
		cerr << "Exception: "<< e.what() << '\n';
		//return?
	}
}


