#include "Neuron.h"

//rename Synapse to sysnapse
Neuron::Neuron(int numOutputs, int MyIndex)
{ 
	mOutput = 0;
	mGradient = 0;
	overallNetLearningRate = 0.15;
	momentum = 0.5;
	for (auto i = 0; i < numOutputs; ++i)
	{
		mOuputWeights.push_back(Synapse());
		mOuputWeights.back().weight = randomWeight();
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
	for (auto n = 0; n < prevLayer.size(); ++n) //where n is the neuron number
	{
		//sum previous layers output(with bias node) times Synapse weights.
		sum += prevLayer[n].mOutput*prevLayer[n].mOuputWeights[mMyIndex].weight;

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
	double DOW = sumDOW(nextLayer);
	mGradient = DOW*transferFunctionDerivative(mOutput);
}

void Neuron::updateInputWeights(Layer & prevLayer)
{
	//weights are stored in synapse vector in the preceding layer
	for (auto NEURON_NUMBER = 0; NEURON_NUMBER < prevLayer.size(); ++NEURON_NUMBER)
	{
		Neuron &neuron = prevLayer[NEURON_NUMBER];
		auto oldDeltaWeight = neuron.mOuputWeights[mMyIndex].changeInWeight;
		auto newDeltaWeight = ETA * neuron.getOutput()*mGradient + ALPHA * oldDeltaWeight;
		neuron.mOuputWeights[mMyIndex].changeInWeight = newDeltaWeight;
		neuron.mOuputWeights[mMyIndex].weight += newDeltaWeight;

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
	for (auto NEURON_NUMBER = 0; NEURON_NUMBER < nextLayer.size() - 1; ++NEURON_NUMBER)
	{
		sum += mOuputWeights[NEURON_NUMBER].weight * nextLayer[NEURON_NUMBER].mGradient;
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
