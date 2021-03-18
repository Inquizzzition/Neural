#include "perceptron.h"

Perceptron::Perceptron(int index) :
	sum(0), output(0), delta(0), error(0),
	inputs(std::vector<double>(2)),
	weight(std::vector<double>(2))
{
	this->index = index;
	for (int i = 0; i < weight.size(); i++)
		weight[i] = (double)(rand() % 1000 - 500) / 1000;
	offset = (double)(rand() % 1000 - 500) / 1000;
}

Perceptron::Perceptron(int nInputs, int index) :
	sum(0), output(0), delta(0), error(0),
	inputs(std::vector<double>(nInputs)),
	weight(std::vector<double>(nInputs))
{
	this->index = index;
	for (int i = 0; i < weight.size(); i++)
		weight[i] = (double)(rand() % 1000 - 500) / 1000;
	offset = (double)(rand() % 1000 - 500) / 1000;
}

void Perceptron::outLayerError(double ideal) {
	error = ideal - output;
}

void Perceptron::zeroError() {
	error = 0;
}

void Perceptron::plusError(double er) {
	error += er;
}

double Perceptron::gerError() {
	return error;
}

double Perceptron::getWi(int i) {
	return weight[i];
}

void Perceptron::changeWeight() {
	for (int i = 0; i < inputs.size(); i++) {
		weight[i] += inputs[i] * error * dActivation(sum) * learningRate;
	}
}

double Perceptron::process(std::vector<double> v) {
	inputs = v;
	sum = dot(inputs, weight) + offset;
	output = activation(sum);
	return output;
}

double Perceptron::getOutput() {
	return output;
}
