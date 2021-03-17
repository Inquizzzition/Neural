#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "inqumath.h"

class Perceptron {
private:
	double output;
	double delta;
	double sum;
	double offset;
	std::vector<double> weight;
	std::vector<double> inputs;
public:
	Perceptron();
	Perceptron(int nInputs);
	void secChangeWeight(double ideal);
	void changeWeight(double ideal);
	double process(std::vector<double> v);
	double getOutput();

};

#endif