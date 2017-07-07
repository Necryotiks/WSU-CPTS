#pragma once
#include "stdafx.h"



typedef struct Synapse
{
	Synapse()
	{
		weight = 0;
		changeInWeight = 0;
	}
	double getWeight() const
	{
		return weight;
	}
	double getWeightDelta() const
	{
		return changeInWeight;
	}
	void setWeight(double &newWeight)
	{
		weight = newWeight;
	}
	void setWeightDelta(double &newWeightDelta)
	{
		changeInWeight = newWeightDelta;
	}
private:
	double weight;
	double changeInWeight;
}Synapse;
class Neuron
{
public:
	Neuron(int numOutputs, int MyIndex);
	typedef vector<Neuron> Layer;
	void setOutput(double val);
	double getOutput()const;
	void feedForward(Layer &prevLayer);
	void calcOutputGradients(double targetOutputs);
	void calcHiddenGradients(const Layer &nextLayer);
	void updateInputWeights(Layer &prevLayer) const;
private:
	double mOutput;
	vector<Synapse> mOuputWeights;
	static double randomWeight();
	double sumDOW(const Layer &nextLayer);
	int mMyIndex;
	static double transferFunction(double sum);
	static double transferFunctionDerivative(double sum);
	double mGradient;
	double overallNetLearningRate;//0.0 through 1.0
	double momentum;//0.0 through 1.0,multiplyer of last weight change
};

