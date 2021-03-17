#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "inqumath.h"

const learningRate = 0.2;

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
	Perceptron();
	Perceptron(int nInputs);
	void outLayerError(double ideal);
	void zeroError();
	void plusError(double er);
	double gerError();
	void secChangeWeight();
	void changeWeight();
	double process(std::vector<double> v);
	double getOutput();

};

#endif