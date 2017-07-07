#include "stdafx.h"
#include "Neuron.h"


Neuron::Neuron(int numOutputs, int MyIndex)
{
	mOutput = 0;
	mGradient = 0;
	overallNetLearningRate = 0.15;
	momentum = 0.5;
	for (auto i = 0; i < numOutputs; i++)
	{
		auto temp = randomWeight();//temp variable for weight
		mOuputWeights.push_back(Synapse());
		mOuputWeights.back().setWeight(temp);
	}
	mMyIndex = MyIndex;
}

void Neuron::setOutput(double val)
{
	mOutput = val;
}

double Neuron::getOutput()const
{
	return mOutput;
}

void Neuron::feedForward(Layer & prevLayer)
{
	auto sum = 0.0;
	for (unsigned NEURON_NUMBER = 0; NEURON_NUMBER < prevLayer.size(); NEURON_NUMBER++) //where n is the neuron number
	{
		//sum previous layers output(with bias node) times Synapse weights.
		sum += prevLayer[NEURON_NUMBER].mOutput*prevLayer[NEURON_NUMBER].mOuputWeights[mMyIndex].getWeight();

	}
	mOutput = transferFunction(sum);//performs the Function on the sum.
}

void Neuron::calcOutputGradients(double targetOutputs)
{
	auto delta = targetOutputs - mOutput;
	mGradient = delta * transferFunctionDerivative(mOutput);
}

void Neuron::calcHiddenGradients(const Layer & nextLayer)
{
	auto DOW = sumDOW(nextLayer);
	mGradient = DOW*transferFunctionDerivative(mOutput);
}

void Neuron::updateInputWeights(Layer & prevLayer) const //TODO: FIX THIS 
{
	//weights are stored in synapse vector in the preceding layer
	for (unsigned NEURON_NUMBER = 0; NEURON_NUMBER < prevLayer.size(); NEURON_NUMBER++)
	{
		auto oldDeltaWeight = prevLayer[NEURON_NUMBER].mOuputWeights[mMyIndex].getWeightDelta();//vector subscript out of range

		auto newDeltaWeight = ETA * prevLayer[NEURON_NUMBER].getOutput()*mGradient + ALPHA * oldDeltaWeight;

		auto x = prevLayer[NEURON_NUMBER].mOuputWeights[mMyIndex].getWeight();

		prevLayer[NEURON_NUMBER].mOuputWeights[mMyIndex].setWeightDelta(newDeltaWeight);

		x += newDeltaWeight;//incremental temp

		prevLayer[NEURON_NUMBER].mOuputWeights[mMyIndex].setWeight(x);

	}
}

double Neuron::randomWeight()
{
	//this is unseeded
	auto r = static_cast<double> (rand()) / RAND_MAX;
	return r;
}

double Neuron::sumDOW(const Layer & nextLayer)
{
	auto sum = 0.0;
	//sum our contribution of the erros at the nodes we feed.
	for (unsigned NEURON_NUMBER = 0; NEURON_NUMBER < nextLayer.size() - 1; ++NEURON_NUMBER)
	{
		sum += mOuputWeights[NEURON_NUMBER].getWeight() * nextLayer[NEURON_NUMBER].mGradient;
	}
	return sum;
}

double Neuron::transferFunction(double sum)
{
	//tanh - output range -1 to 1

	return tanh(sum);
}

double Neuron::transferFunctionDerivative(double sum)
{
	return 1 - tanh(sum)*tanh(sum);//derivative of tanh
}
