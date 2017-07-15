#include "stdafx.h"
#include "Net.h"


Net::Net(const vector<int>& Netdata)
{
	mError = 0;
	mRSF = 0;
	mRecentErrorAvg = 0;
	int numOutputs;
	int numLayers = Netdata.size();
	for (auto layerNum = 0; layerNum < numLayers; layerNum++)
	{
		mLayers.push_back(Layer());//makes new Layers.

		//now needs to fill with neurons and add a bias neuron
		if (layerNum == Netdata.size() - 1) //if output layer then the number of outputs is zero(i.e. no more Neuron Synapses).
		{
			numOutputs = 0;
		}
		else
		{
			numOutputs = Netdata[layerNum + 1];//number of Synapse decrease by one each layer.
		}
		for (auto neuronNum = 0; neuronNum < Netdata[layerNum]; neuronNum++)
		{
			mLayers.back().push_back(Neuron(numOutputs, neuronNum));//Finds most recent Layer vector and then does push back.
			cout << "Constructed a Neuron:" << neuronNum << '\n';
		}
		mLayers.back().back().setOutput(1.0);
	}
}



void Net::feedForward(const vector<double> & inputs)
{
	assert(inputs.size() == mLayers[0].size() );//checks to see if the net constructed proper.if not kill the program/

	//Assign input values in to respective neurons.

	for (unsigned i = 0; i < inputs.size(); i++)
	{
		mLayers[0][i].setOutput(inputs[i]);
	}

	//forward propagation
	//loops through each neuron and tells each neuron to feed forward
	for (unsigned layerNum = 1; layerNum < mLayers.size(); ++layerNum)
	{
		auto &prevLayer = mLayers[layerNum - 1];//Layer type
		for (unsigned n = 0; n < mLayers[layerNum].size() - 1; ++n)
		{
			mLayers[layerNum][n].feedForward(prevLayer);
		}
	}

}

void Net::backProp(const vector<double>& targetOutputs)
{
	//Calculate overall net error(Root Mean Square of output neuron errors)
	auto &outputLayer = mLayers.back();//is of Layer type.
	mError = 0.0;
	for (unsigned n = 0; n < outputLayer.size() ; ++n)//n for neurons
	{
		auto delta = targetOutputs[NEURON_NUMBER] - outputLayer[NEURON_NUMBER].getOutput();//final minus inital
		mError += pow(delta, 2);
	}
	mError = mError / outputLayer.size() ;
	mError = sqrt(mError);//RMS

	//Implement a recent average measurement
	mRecentErrorAvg = (mRecentErrorAvg * mRSF + mError) / (mRSF + 1.0);//mRSF = most recent smoothing factor

	//Calculate output layer gradients
	for (unsigned n = 0; NEURON_NUMBER < outputLayer.size(); NEURON_NUMBER++)
	{
		outputLayer[NEURON_NUMBER].calcOutputGradients(targetOutputs[NEURON_NUMBER]);
	}
	//calculate gradients on hidden layers
	for (auto layerNum = mLayers.size() - 2; layerNum > 0; layerNum--)//right most hidden layer excluding input and output layer
	{
		auto &hiddenLayer = mLayers[layerNum];
		auto &nextLayer = mLayers[layerNum + 1];
		for (unsigned NEURON_NUMBER = 0; NEURON_NUMBER < hiddenLayer.size(); NEURON_NUMBER++)
		{
			hiddenLayer[NEURON_NUMBER].calcHiddenGradients(nextLayer);
		}

	}
	//update Synapse weights
	for (auto layerNum = mLayers.size() - 1; layerNum > 0; layerNum--)//excludes input layer as there are no weights going in.
	{
		auto &currentLayer = mLayers[layerNum];//reference to mLayers
		auto &prevLayer = mLayers[layerNum - 1];
		for (unsigned NEURON_NUMBER = 0; NEURON_NUMBER < currentLayer.size(); NEURON_NUMBER++) //TODO: maybe fix somehow(current size minus one for some reason)
		{
			currentLayer[NEURON_NUMBER].updateInputWeights(prevLayer);//FIX
		}
	}

}

void Net::getResults(vector<double>& results) const
{
	results.clear();
	for (unsigned NEURON_NUMBER = 0; NEURON_NUMBER < mLayers.back().size(); ++NEURON_NUMBER)
	{
		results.push_back(mLayers.back()[NEURON_NUMBER].getOutput());
	}
}

double Net::getRecentAVGerror() const
{
	return mRecentErrorAvg;
}
