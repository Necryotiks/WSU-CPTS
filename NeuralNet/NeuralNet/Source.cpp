#include "Net.h"


int main()
{
	
	vector <double> inputs;
	vector<double> targetOutputs;
	vector<double> results;
	vector<int> Netdata;//net structure defined as 3,2,1. i.e. 3 input neurons, 2 hidden neurons, 1 output neuron

	Netdata.push_back(3);
	Netdata.push_back(2);//defines the neural net structure.
	Netdata.push_back(1);

	Net myNet(Netdata);
	myNet.feedForward(inputs);
	myNet.backProp(targetOutputs);
	myNet.getResults(results);
}
