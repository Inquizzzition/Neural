#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "inqumath.h"

const double learningRate = 0.3;

class Perceptron {
private:
	double output;
	double delta;
	double sum;
	double offset;
	double error;
	std::vector<double> weight;
	std::vector<double> inputs;
public:
	int index;
	Perceptron(int index);
	Perceptron(int nInputs, int index);
	double getWi(int i);
	void outLayerError(double ideal);
	void zeroError();
	void plusError(double er);
	double gerError();
	void changeWeight();
	double process(std::vector<double> v);
	double getOutput();

};

#endif