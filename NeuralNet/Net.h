#pragma once
#include "stdafx.h"
#include "Neuron.h"

//A 2d vector of vector of Neurons could be declared:
//vector<vector<Neuron>> layers of Neurons.
//
//defines Layer object as a vector of Neurons

class Net
{
public:
	typedef vector<Neuron> Layer;
	explicit Net(const vector<int>& Netdata);
	void feedForward(const vector<double> &inputs);
	void backProp(const vector<double> &targetOutputs);
	void getResults(vector<double> &results) const;
	double getRecentAVGerror()const;
private:
	vector<Layer> mLayers;//2d vector: mLayers[LayerNum][NeuronNum] i.e vector of vector of Neurons
	double mError;
	double mRecentErrorAvg;
	double mRSF;
};

