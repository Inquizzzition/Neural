#include "perceptron.h"

Perceptron::Perceptron() :
	sum(0), output(0), delta(0),
	inputs(std::vector<double>(2)),
	weight(std::vector<double>(2))
{
	for (int i = 0; i < weight.size(); i++)
		weight[i] = (double)(rand() % 1000 - 500) / 1000;
	offset = (double)(rand() % 1000 - 500) / 1000;
}

Perceptron::Perceptron(int nInputs) :
	sum(0), output(0), delta(0),
	inputs(std::vector<double>(nInputs)),
	weight(std::vector<double>(nInputs))
{
	for (int i = 0; i < weight.size(); i++)
		weight[i] = (double)(rand() % 1000 - 500) / 1000;
	offset = (double)(rand() % 1000 - 500) / 1000;
}

void Perceptron::secChangeWeight(double ideal) {

}

void Perceptron::changeWeight(double ideal) {

}

double Perceptron::process(std::vector<double> v) {
	inputs = v;
	sum = dot(inputs, weight) + offset;

}

double Perceptron::getOutput() {
	return output;
}
